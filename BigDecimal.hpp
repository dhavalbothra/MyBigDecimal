#include<iostream>
#include<malloc.h>
#include<cstring>
#include<vector>
#include<cstdlib>
using namespace std;

class BigDecimal
{
public:
        long Int_part;
        int prec = 10;
        bool sign = false; // false indicates that integer is positive
        vector<int> Dec_part;

        BigDecimal(){};
        // Memset is not used for vectors or any other container it is just used for arrays
        BigDecimal(int n){Int_part = abs(n);Dec_part.resize(prec,0);if(n<0){sign = true;}}
        BigDecimal(long n){Int_part = abs(n);Dec_part.resize(prec,0);if(n<0){sign = true;}}

        void set_precision(int x){
            Dec_part.resize(x,0);
        }

        BigDecimal operator + (BigDecimal othr){return add(*this,othr);}
        // BigDecimal operator - (BigDecimal othr){return sub(*this,othr);}
        // BigDecimal operator / (long n){return divide(*this,n);}
        // BigDecimal operator * (long n){return mul(*this,n);}
        bool operator < (BigDecimal othr){
            if(Int_part >= othr.Int_part){
                return false;
            }
            for(int i=0;i<min(prec,othr.prec);i++){
                if(Dec_part[i] >= othr.Dec_part[i]){
                    return false;
                }
            }
            if(prec > othr.prec){
                for(int i=othr.prec - 1;i<prec;i++){
                    if(Dec_part[i] > 0)return false;
                }
            }
            else{
                for(int i=prec - 1;i<othr.prec;i++){
                    if(othr.Dec_part[i] > 0)return false;
                }
            }
	    return true;
        }
	bool operator >= ( BigDecimal othr){return !(*this < othr);}
		BigDecimal add(BigDecimal a_, BigDecimal b_)
		{
            // indicates either both are positive or negative
			if(!(a_.sign ^ b_.sign))
			{
                int ans_prec = max(a_.prec,b_.prec);
				BigDecimal ans(0);
                ans.set_precision(ans_prec);
				vector<int> a = a_.Dec_part;
				vector<int> b = b_.Dec_part;
                if(a_.prec != b_.prec){
                    for(int i=ans_prec - 1;i>=min(a_.prec,b_.prec);i--){
                        if(a_.prec > b_.prec) ans.Dec_part[i] = a[i];
                        else ans.Dec_part[i] = b[i];
                    }
                }
				for(int i=min(a_.prec,b_.prec)-1;i>0;i--)
				{
					ans.Dec_part[i] += (a[i] + b[i])%10;
					ans.Dec_part[i-1] += (a[i] + b[i])/10;
				}
				ans.Dec_part[0] += (a[0] + b[0]);
                ans.Int_part += (ans.Dec_part[0]/10);
				ans.Dec_part[0] = ans.Dec_part[0] % 10;
				ans.Int_part = a_.Int_part + b_.Int_part;
				ans.sign = a_.sign & b_.sign;
				return ans;
			}
            return BigDecimal(0);
            // both are of oposite signs
            // else{
            //     // if(a_ < b_){
            //     //     return sub(b_,a_);
            //     // }
            //     // else{
            //     //     return sub(a_,b_);
            //     // }
            // }
		}

        // BigDecimal sub(BigDecimal a_, BigDecimal b_){

        // }
        void print()
        {
            if(sign) cout << "-";
            cout << Int_part<<".";
            for(int i = 0;i < prec;i++)
            {
                cout << Dec_part[i];
            }
            cout<<endl;
        }
};
