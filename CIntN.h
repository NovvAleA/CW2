#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <cmath>


class CIntN{
private:
	int* arr;
	int dim;
	int sign;
public:
	CIntN();
	CIntN(int N);
	CIntN(const CIntN& other);
	void enter_data(char name);
	//void enter_data_from_file(FILE* inp, int dim);

	CIntN operator=(const CIntN& other);
	CIntN operator+(const CIntN& other);
	CIntN operator-(const CIntN& other);
	int operator==(const CIntN& other);

	int o_r_bigger(const CIntN& other);
	int ffnn();
	void ffnn(int* fnn);
	void print();
	~CIntN();
	friend CIntN diffrence(int sgn,  CIntN* a, const CIntN& b);
	friend CIntN diffrence(int sgn, const CIntN& b, CIntN* a);
	friend CIntN sum(int sgn, CIntN* a, const CIntN& b);
	friend void At_1();
	friend void At_2();
	friend void At_3();
};

CIntN diffrence(int sgn,  CIntN* a, const CIntN& b);
CIntN diffrence(int sgn, const CIntN& b, CIntN* a);
CIntN sum(int sgn, CIntN* a, const CIntN& b);
int Strlen( char*& str);
void At_1();
void At_2();
void At_3();