#include<iostream>
#include<malloc.h>
#include<cstring>
#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

class BigDecimal
{
public:
        int Int_part;
        int prec = 100;
        int len = prec
        bool sign = false;
        vector<uint8_t> Dec_part;

        BigDecimal(){};
        BigDecimal(int n){memset(Dec_part,0,prec*sizeof(uint8_t));Int_part = abs(n);if{abs(n) == n}{sign = true;}}
        BigDecimal(long n){memset(Dec_part,0,prec*sizeof(uint8_t));Int_part = abs(n);if{abs(n) == n}{sign = true;}}

        BigDecimal operator + (BigDecimal othr){return add(*this,othr);}
        BigDecimal operator - (BigDecimal othr){return sub(*this,othr);}
        BigDecimal operator / (long n){return divide(*this,n);}
        BigDecimal operator * (long n){return mul(*this,n);}
		BigDecimal add(BigDecimal a_, BigDecimal b_)
		{
			if(a_.sign && b_.sign)
			{

				BigDecimal ans(0);
				vector<uint8_t> a = a_.Dec_part;
				vector<uint8_t> b = b_.Dec_part;
				int i;
				int c
				for(i=len-1;i>0;i--)
				{
					ans.Dec_part[i] += (a[i] + b[i])%10;
					ans.Dec_part[i-1] += (a[i] + b[i])/10;
				}
				ans.Dec_part[0] += (a[0] + b[0]);
				ans.Dec_part[0] = ans.Dec_part[0] % 10;
				ans.Int_part = a_.Int_part + b_.Int_part + ans.Dec_part[0] / 10;
				ans.sign = true;
				return ans;
			}

			else if(a_.sign)
            {
                if(a_ > b_)
                {
                    BigDecimal ans(0);
                    vector<uint8_t> a = a_.Dec_part;
                    vector<uint8_t> b = b_.Dec_part;
                    int i;
                    for(i=len-1;i>0;i--)
                    {
                        if(a[i]>=b[i]){ ans.Dec_part[i] = a[i] - b[i]; }
                        if(a[i]<b[i]) { ans.Dec_part[i] = 10 + a[i] - b[i]; a[i-1] = a[i-1] -1;}
                    }
                    if(a[0] >= b[0])
                        ans.Dec_part[0] = a[0] - b[0];
                        ans.Int_part = a_.Int_part - b_.Int_part;
                    else
                        ans.Dec_part[0] = a[0] - b[0] + 10;
                        ans.Int_part = a_.Int_part - b_.Int_part -1;
                    ans.sign = true;
                    return ans;
                }
                else
                {
                    BigDecimal ans(0);
                    vector<uint8_t> a = a_.Dec_part;
                    vector<uint8_t> b = b_.Dec_part;
                    int i;
                    for(i=len-1;i>0;i--)
                    {
                        if(a[i]<=b[i]){ ans.Dec_part[i] = b[i] - a[i]; }
                        if(a[i]>b[i]) { ans.Dec_part[i] = 10 + b[i] - a[i]; b[i-1] = b[i-1] -1;}
                    }
                    if(b[0] >= a[0])
                        ans.Dec_part[0] = b[0] - a[0];
                        ans.Int_part = b_.Int_part - a_.Int_part;
                    else
                        ans.Dec_part[0] = b[0] - a[0] + 10;
                        ans.Int_part = b_.Int_part - a_.Int_part -1;
                    ans.sign = false;
                    return ans;
                }
            }

            else if(b_.sign)
            {
                if(b_ > a_)
                {
                    BigDecimal ans(0);
                    vector<uint8_t> a = a_.Dec_part;
                    vector<uint8_t> b = b_.Dec_part;
                    int i;
                    for(i=len-1;i>0;i--)
                    {
                        if(a[i]<=b[i]){ ans.Dec_part[i] = b[i] - a[i]; }
                        if(a[i]>b[i]) { ans.Dec_part[i] = 10 + b[i] - a[i]; b[i-1] = b[i-1] -1;}
                    }
                    if(b[0] >= a[0])
                        ans.Dec_part[0] = b[0] - a[0];
                        ans.Int_part = b_.Int_part - a_.Int_part;
                    else
                        ans.Dec_part[0] = b[0] - a[0] + 10;
                        ans.Int_part = b_.Int_part - a_.Int_part -1;
                    ans.sign = true;
                    return ans;
                }

                else
                {
                    BigDecimal ans(0);
                    vector<uint8_t> a = a_.Dec_part;
                    vector<uint8_t> b = b_.Dec_part;
                    int i;
                    for(i=len-1;i>0;i--)
                    {
                        if(a[i]>=b[i]){ ans.Dec_part[i] = a[i] - b[i]; }
                        if(a[i]<b[i]) { ans.Dec_part[i] = 10 + a[i] - b[i]; a[i-1] = a[i-1] -1;}
                    }
                    if(a[0] >= b[0])
                        ans.Dec_part[0] = a[0] - b[0];
                        ans.Int_part = a_.Int_part - b_.Int_part;
                    else
                        ans.Dec_part[0] = a[0] - b[0] + 10;
                        ans.Int_part = a_.Int_part - b_.Int_part -1;
                    ans.sign = false;
                    return ans;
                }
            }
			else
			{

				BigDecimal ans(0);
				vector<uint8_t> a = a_.Dec_part;
				vector<uint8_t> b = b_.Dec_part;
				int i;
				int c
				for(i=len-1;i>0;i--)
				{
					ans.Dec_part[i] += (a[i] + b[i])%10;
					ans.Dec_part[i-1] += (a[i] + b[i])/10;
				}
				ans.Dec_part[0] += (a[0] + b[0]);
				ans.Dec_part[0] = ans.Dec_part[0] % 10;
				ans.Int_part = a_.Int_part + b_.Int_part + ans.Dec_part[0] / 10;
				ans.sign = false;
				return ans;
			}
		}

        BigDecimal sub(BigDecimal a_, BigDecimal b_)
        void print(BigDecimal num)
        {
            if(sign == false)
                cout << "-";
            cout << Int_part + ".";
            for(int i = 0;i < len;i++)
            {
                cout << Dec_part[i];
            }
        }
};
