#include <iostream>
#include "BigDecimal.hpp"

int main(int argc, char** argv) {
	
	BigDecimal a = 4;
	BigDecimal b = 3;
	a.print();
	b.print();
	b = b + a;
	b.print();
}
