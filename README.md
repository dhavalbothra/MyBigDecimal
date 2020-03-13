# MyBigDecimal
This is MyBigDecimal for C ! There are some bugs which can be fixed. The logic is that is for eg there is a no. 3.141 then the digits after dot will be stored in an array.

```
#include <iostream>
#include "BigDecimal.hpp"

int main(int argc, char** argv) {
	
	BigDecimal a = 4;
	BigDecimal b;
	for(int i=1;i<=1000;i++)
	{
		//b.divide(4,2*i+1);
		b = BigDecimal(4) / (2*i+1);
		if(i%2==1)
		{
			//a.sub(a,b);
			a = a-b;
		}
		else
		{
			//a.add(a,b);
			a = a+b;	
		}
	}
	a.print();
}
```
This was my simple code to find PI in C.
Here i have used an Leibenz series to find PI.
Formulae of Leibenz :- ![alt text](https://d2vlcm61l7u1fs.cloudfront.net/media%2F0ee%2F0eeaa57b-570b-4444-93bc-7bc2f4d83931%2FphpHCRPXf.png)

Now lets discuss about what I have done in the Header File . Here I have use Operator Overloading in a class BigDecimal.
There I have writter Logic for Addition , Subtraction and Division of two numbers. The Logic can be optimized . 

While Adding two numbers we need to make count of the Carry Over occuring while adding two numbers. If the addition exceeds 9 that the
first digit will be the Carry Over and second digit will be Kept. So this is a simple stuff with the Time - Complexity of n. 

In Subtraction i have implemented the elementry method of subtraction taught in Schools where we have to use the Borrow rule. This was
a bit hard for me to implement in the code. A better way will be Two's compliment but it very complicated to do it for arrays.

The division is also Simmilar to subtraction . Here i have just implemeted our Long Division Method so simple enough to understatnd so
now I think you have understand what I have done in the code.


I was facing problems while writing the Logic for multiplication because then Time - Complexity will be of nXn. If there is anything which can be Improved than please tell me by sending me Mail at coderbpython@gmail.com or give it In Pull Requests section.See the karatsuba Multiplication algorithm and try to implement it in the Code.
