#include<stdio.h>
#include<malloc.h>

#define SIZE 100000

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
	
	BigDecimal()       : arr({})  {}
	BigDecimal(int n)  : arr({n}) {}
	BigDecimal(long n) : arr({n}) {}
	
	BigDecimal operator + (BigDecimal othr)
	{
		BigDecimal ans;
		ans.add(*this, othr);
		return ans;
	}
	
	BigDecimal operator - (BigDecimal othr)
	{
		BigDecimal ans;
		ans.sub(*this, othr);
		return ans;
	}
	
	BigDecimal operator / (long n)
	{
		BigDecimal ans;
		ans.divide(*this, n);
		return ans;
	}
	
	BigDecimal& add(BigDecimal a_,BigDecimal b_)
	{
		long len = SIZE;
		long* a = a_.arr;
		long* b = b_.arr;
		long c=0;
		long i;
		for(i=len-1;i>=0;i--)
		{
			if(a[i]+b[i]+c<=9 || i == 0)
			{
				arr[i]=a[i]+b[i]+c;
				c=0;
			}
			else
			{
				arr[i] = (a[i]+b[i]+c)%10;
				c=(a[i]+b[i]+c)/10;
			}
		}
		return *this;
	}
	BigDecimal& sub(BigDecimal a_,BigDecimal b_)
	{
		long len = SIZE;
		long* a = a_.arr;
		long* b = b_.arr;

		long i;

		for(i=len-1;i>=0;i--)
		{
			if(a[i]>=b[i]){ arr[i] = a[i] - b[i]; }
			if(a[i]<b[i]) { arr[i] = 10 + a[i] - b[i]; a[i-1] = a[i-1] -1;}
		}
		return *this;
	}
	BigDecimal& divide(BigDecimal a_, long b)
	{
		long len = SIZE;
		long* a = a_.arr;

		long count=0,c=0,temp=a[0];
		long i;
		for(i=0;i<10*len;i++)
		{
			if(c==len){break;}
			if(temp>=b){ temp=temp-b; count++;}
			if(temp <b){ temp=10*temp+a[c+1];arr[c]=count;count=0;c++;}
		}
		return *this;
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

