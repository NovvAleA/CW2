#include "CIntN.h"


void At_1() {
	CIntN a(3);
	CIntN b(3);
	CIntN c(3);
	CIntN d(3);

	a.sign = 1;
	a.arr[0] = 1;//a = 110
	a.arr[1] = 1;
	a.arr[2] = 0;

	b.sign =- 1;
	b.arr[0] = 0;//b = -11
	b.arr[1] = 1;
	b.arr[2] = 1;

	c.sign = 1;
	c.arr[0] = 1;//c = a - b = 121
	c.arr[1] = 2;
	c.arr[2] = 1;

	d.sign = 1;
	d.arr[0] = 0;//c = a + b = 99
	d.arr[1] = 9;
	d.arr[2] = 9;

	if ((c == a - b) && (d == a + b)) {
		printf("At_1 passed!\n");
	}
	else {
		printf("At_1 failled!\n");
	}

}

void At_2() {

	CIntN a(3);
	CIntN b(3);
	CIntN c(3);
	CIntN d(3);

	a.sign = -1;
	a.arr[0] = 1;//a = -111
	a.arr[1] = 1;
	a.arr[2] = 1;

	b.sign = 1;
	b.arr[0] = 1;//b = 111
	b.arr[1] = 1;
	b.arr[2] = 1;

	c.sign = 1;
	c.arr[0] = 2;//c = a - b = 222
	c.arr[1] = 2;
	c.arr[2] = 2;

	d.sign = -1;
	d.arr[0] = 0;//c = a + b = 0
	d.arr[1] = 0;
	d.arr[2] = 0;

	if ((c == a - b) && (d == a + b)) {
		printf("At_1 passed!\n");
	}
	else {
		printf("At_1 failled!\n");
	}

}

void At_3() {

	CIntN a(3);
	CIntN b(3);
	CIntN c(3);
	CIntN d(3);

	a.sign = 1;
	a.arr[0] = 8;//a = 812
	a.arr[1] = 1;
	a.arr[2] = 2;

	b.sign = 1;
	b.arr[0] = 9;//b = 913
	b.arr[1] = 1;
	b.arr[2] = 3;

	c.sign = -1;
	c.arr[0] = 1;//c = a - b = -101
	c.arr[1] = 0;
	c.arr[2] = 1;

	d.sign = 1;
	d.arr[0] = 9;//c = a + b > 999 = 999
	d.arr[1] = 9;
	d.arr[2] = 9;

	if ((c == a - b) && (d == a + b)) {
		printf("At_1 passed!\n");
	}
	else {
		printf("At_1 failled!\n\n");
	}

}