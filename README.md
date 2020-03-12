# MyBigDecimal
This is MyBigDecimal for C ! There are some bugs which can be fixed. The logic is that is for eg there is a no. 3.141 then the digits after dot will be stored in an array.

```
#include<stdio.h>
#include<time.h>
#include"myBigDecimal.h"
int main()
{

	long * arr=divide1(4,1,100000);
	long * arr1;
	long i;
	time_t begin = time(NULL);
	for(i=1;i<=2000;i++)
	{
		long * arr1 = divide1(4,2*i+1,100000);
		if(i%2==1)
		{
		       arr=sub3(arr,arr1,100000);
		}
		else
		{
			arr = add3(arr,arr1,100000);
		}
		free(arr1);
	}
	time_t end = time(NULL);
	printf("Time took : %f",(float)(end-begin));
	return 1;
}
```
This was my simple code to find PI in C.
Here i have used an Leibenz series to find PI.
Formulae of Leibenz :- ![alt text](https://d2vlcm61l7u1fs.cloudfront.net/media%2F0ee%2F0eeaa57b-570b-4444-93bc-7bc2f4d83931%2FphpHCRPXf.png)
