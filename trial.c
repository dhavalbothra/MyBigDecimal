#include<stdio.h>
#include"myBigDecimal.h"
void main()
{

	long * arr=divide1(15,1,100000);
	long * arr1 = divide1(14,1,100000);
	long i;

	arr1 = sub3(arr,arr1,100000);
	print(arr1,10);
}
