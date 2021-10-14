
#include "CIntN.h"


int main()
{
	int N = 3;

	CIntN a(N);
	CIntN b(N);
	CIntN c(N);
	
	At_1();
	At_2();
	At_3();

	a.enter_data('a');
	printf("a = ");
	a.print();
	b.enter_data('b');
	printf("b = ");
	b.print();
	c = a - b;
	printf("\na - b = ");
	c.print();
	c = a + b;
	printf("\na + b = ");
	c.print();

	return 0;
}
