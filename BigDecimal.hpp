#include<stdio.h>
#include<malloc.h>
#include<cstring>

#define SIZE 100

class BigDecimal{
	long arr[SIZE];
public:
	// long * add1(long a,long b){  long * arr = (long *)malloc(sizeof(long)*SIZE); arr[0] = a+b; return arr;}
	/*long * add2(long a,long b[],long len)
	{
		long i;
		long * arr = (long *)malloc(sizeof(long)*SIZE);
		arr[0] = a + b[0];
		for(i=1;i<len;i++)
		{
			arr[i] = b[i];
		}
		return arr;
	}*/
	BigDecimal(){};
	BigDecimal(int n){memset(arr,0,SIZE*sizeof(long));arr[0]=n;} 
	BigDecimal(long n){memset(arr,0,SIZE*sizeof(long));arr[0]=n;}

	BigDecimal operator + (BigDecimal othr){return add(*this,othr);}
	BigDecimal operator - (BigDecimal othr){return sub(*this,othr);}
	BigDecimal operator / (long n){return divide(*this,n);}
	BigDecimal operator * (long n){return mul(*this,n);}

	BigDecimal add(BigDecimal a_,BigDecimal b_)
	{
		BigDecimal ans(0);
		long len = SIZE;
		long* a = a_.arr;
		long* b = b_.arr;
		long c=0;
		long i;
		for(i=len-1;i>0;i--)
		{
			ans.arr[i] += (a[i] + b[i])%10;
			ans.arr[i-1] += (a[i] + b[i])/10;
		}
		ans.arr[0] += (a[0] + b[0]);
		return ans;
	}
	BigDecimal mul(BigDecimal a_,long n)
	{
		BigDecimal ans(0);
		long len = SIZE;
		long* a = a_.arr;
		long c=0;
		long i;
		for(i=len-1;i>0;i--)
		{
			ans.arr[i] += (a[i] * n)%10;
			ans.arr[i-1] += (a[i] * n)/10;
		}
		ans.arr[0] += (a[0] * n);
		return ans;
	}
	BigDecimal sub(BigDecimal a_,BigDecimal b_)
	{
		BigDecimal ans(0);
		long len = SIZE;
		long* a = a_.arr;
		long* b = b_.arr;

		long i;

		for(i=len-1;i>=0;i--)
		{
			if(a[i]>=b[i]){ ans.arr[i] = a[i] - b[i]; }
			if(a[i]<b[i]) { ans.arr[i] = 10 + a[i] - b[i]; a[i-1] = a[i-1] -1;}
		}
		return ans;
	}
	BigDecimal divide(BigDecimal a_, long b)
	{
		BigDecimal ans(0);
		long len = SIZE;
		long* a = a_.arr;
		long count=0,c=a[0];
		long i;
		long x = a[0]/b;
		ans.arr[0] = x;
		for(i=0;i<len;i++)
		{	
			c -= (b*x);
			if(c == 0){break;}
			c *= 10;
			x = c/b;
			ans.arr[i+1] = x;
		}
		return ans;
	}
	
	/*long * sub1(long a,long b){  long * arr = (long *)malloc(sizeof(long)*100);arr[0] = a-b; return arr;}
	long * sub2(long a,long b[],long len)
	{
		long * arr = (long *)malloc(sizeof(long)*100);
		arr[0] = b[0] - a;
		long i;
		for(i=1;i<len;i++)
		{
			arr[i] = b[i];
		}
		return arr;
	}
	long * mul1(long a,long b){  long * arr = (long *)malloc(sizeof(long)*SIZE);arr[0] = a*b;return arr; }
	long * mul2(long a,long b[])
	{
		long * arr = (long *)malloc(sizeof(long)*SIZE);
		long c=0,i,len=SIZE;
		for(i=len-1;i>=0;i--)
		{
			if((b[i]*a+c)>9)
			{
				arr[i]=(b[i]*a)%10;
				c = (b[i]*a)/10;
			}
			else
			{
				c = 0;
				arr[i] = (b[i]*a);
			}
		}
		return arr;
	}
	long * divide2(long a[],long b,long len)
	{
		long * arr = (long *)malloc(sizeof(long)*SIZE);
		long count=0,c=0,temp=a[0];
		long i;
		for(i=0;i<10*len;i++)
		{
			if(c==len){break;}
			if(temp>=b){ temp=temp-b; count++;}
			if(temp <b){ temp=10*temp+a[c+1];arr[c]=count;count=0;c++;}
		}
		return arr;
	}
	long * divide1(long a,long b,long len)
	{
		long * arr = (long *)malloc(sizeof(long)*SIZE);
		long count = 0,c=0;
		long i;
		for(i=0;i<10*len;i++)
		{
			if(c == len){	break;  }
			if(a>=b){count = a / b;a = a % b;}
			if(a<b){   a = 10 *a;   arr[c] = count;  count = 0;   c ++;}
		}
		return arr;
	
	}*/
	
	void print()
	{
		long len = SIZE;
		printf("\n%ld.",arr[0]);
		long i;
		for(i=1;i<len;i++) { printf("%ld",arr[i]); }
	}
};

