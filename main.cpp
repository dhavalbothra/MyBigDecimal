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
