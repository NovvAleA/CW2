#include "CIntN.h"


CIntN::CIntN(int N) {
	 this->dim = N;
	 this->arr = new int[dim];
	 this->sign = 0;
}
CIntN::CIntN() {
	this->dim = 0;
	this->arr = nullptr;;
	this->sign = 0;
}

CIntN::CIntN(const CIntN& other) {
	this->dim = other.dim;
	this->arr = new int[dim];
	for (int i = 0; i < dim; i++) {
		this->arr[i] = (other.arr)[i];
	}
	this->sign = other.sign;
}

void CIntN::enter_data(char name){
	if (dim == 0) {
		printf("Error! dim == 0");
	}
	else {
		char* str;
		str = new char[dim + 2];//excess "1" for sign of number
		int offset = 0;
		printf("Enter %c\n", name);
		if (scanf("%s", str)) {
						
			if (str[0] != '-') {
				offset = dim - Strlen(str);
				sign = 1;// sign == 1 := sign == '+'
				for (int i = 0; i < offset; i++) {
					arr[i] = 0;
				}
				for (int i = offset; i < dim; i++) {
					//printf("%c_%i", str[i], i);
					arr[i] = (int)str[i - offset] - 48;
				}
			}
			if (str[0] == '-') {
				offset = dim + 1 - Strlen(str);
				sign = -1;// sign == -1 := sign == '-'
				for (int i = 0; i < offset; i++) {
					arr[i] = 0;
				}
				for (int i = offset; i < dim; i++) {
					arr[i] = (int)str[i + 1 - offset] - 48;
				}
			}
			delete[] str;
		}
	}
	
}
/*
void CIntN::enter_data_from_file(FILE* inp, int dim){
	char* str = new char[dim + 1];
	if (str == nullptr) {
		printf("Error! str == nullptr");
	}
	
	if (!fscanf(inp, "%s", str)) {
		printf("Error fscanf!");
	}

	int offset = 0;

	if (str[0] != '-') {
		offset = dim - Strlen(str);
		sign = 1;// sign == 1 := sign == '+'
		for (int i = 0; i < offset; i++) {
			arr[i] = 0;
		}
		for (int i = offset; i < dim; i++) {
			//printf("%c_%i", str[i], i);
			arr[i] = (int)str[i - offset] - 48;
		}
	}
	if (str[0] == '-') {
		offset = dim + 1 - Strlen(str);
		sign = -1;// sign == -1 := sign == '-'
		for (int i = 0; i < offset; i++) {
			arr[i] = 0;
		}
		for (int i = offset; i < dim; i++) {
			arr[i] = (int)str[i + 1 - offset] - 48;
		}
	}
		
	

	delete[] str;
	fclose(inp);
}

*/

int Strlen( char*& str) {
	int i = 0;
	while (str[i] != '\0') {
		i++;
	}
	return i;
}

int CIntN::ffnn() {
	int i = 0;
	while (this->arr[i] == 0) {
		i++;
	}
	return i;
}

void CIntN::ffnn(int* fnn) {
	int i = 0;
	while (this->arr[i] == 0) {
		i++;
	}
	*fnn = i;
}

CIntN CIntN:: operator=(const CIntN& other) {
	if (arr == nullptr) {
		printf("Memory error in <CIntN(const CIntN& other)>");
		dim = other.dim;
		arr = new int[dim];
		//	delete arr;
	}
	sign = other.sign;
	for (int i = 0; i < dim; i++) {
		arr[i] = (other.arr)[i];
	}
	return *this;
}
CIntN::~CIntN() {
	delete[] arr;
}

int CIntN::o_r_bigger(const CIntN& other) {
	for (int i = 0; i < dim; i++) {
		if (this->arr[i] > other.arr[i]) {
			return 1;
		}
		if (this->arr[i] < other.arr[i]) {
			return -1;
		}
	}
	return 1;
}
int CIntN::operator==(const CIntN& other){
	for (int i = 0; i < dim; i++) {
		if (this->arr[i] != other.arr[i]) {
			return 0;
		}
	}
	return 1;
}

CIntN CIntN::operator+(const CIntN& other) {
	if (dim != other.dim) {
		printf("Error! dim(a) != dim(b)");
	}
	int tmp = 0;	
	tmp = this->o_r_bigger(other);

	if (this->sign * other.sign == 1) {//sum
		return sum(this->sign, this, other);
	}
	if (this->sign * other.sign == -1) {//dif
		if (tmp == 1) {
			return diffrence(this->sign, this, other);
		}
		if (tmp == -1) {
			return diffrence(-this->sign, other, this);
		}
	}
	printf("Error in operator +!");
}

CIntN diffrence(int sgn, CIntN* a,const CIntN& b) {
	int dif = 0;
	int dim = b.dim;
	CIntN temp = *a;
	temp.sign = sgn;
	int fnn_a = temp.ffnn();// First Not Null
	int fnn_b = 0;
	while (b.arr[fnn_b] == 0) {//
		fnn_b++;
	}

	//|a| - |b|//
	for (int i = dim - 1; i > -1; i--) {
		dif = temp.arr[i] - b.arr[i];
		if (dif < 0) {
			for (int j = i - 1; j > fnn_a - 1; j--) {
				if (temp.arr[j] != 0) {
					temp.arr[j] --;
					dif += 10;
					for (int k = j + 1; k < i; k++) {
						temp.arr[k] = 9;
					}
					temp.arr[i] = dif;
					break;
				}
			}
		}
		else {
			temp.arr[i] = dif;
		}
	}
	return temp;
}


CIntN diffrence(int sgn, const CIntN& b, CIntN* a) {
	int dif = 0;
	int dim = b.dim;
	CIntN temp = b;
	temp.sign = sgn;
	int fnn_a = temp.ffnn();// First Not Null

	//|a| - |b|//
	for (int i = dim - 1; i > -1; i--) {
		dif = temp.arr[i] - (*a).arr[i]  ;
		if (dif < 0) {
			for (int j = i - 1; j > fnn_a - 1; j--) {
				if (temp.arr[j] != 0) {
					temp.arr[j] --;
					dif += 10;
					for (int k = j + 1; k < i; k++) {
						temp.arr[k] = 9;
					}
					temp.arr[i] = dif;
				}
			}
		}
		else {
			temp.arr[i] = dif;
		}
	}
	return temp;
}


CIntN sum(int sgn, CIntN* a, const CIntN& b){
	CIntN temp = *a;
	temp.sign = sgn;
	int sum = 0;
	int tmp = 0;
	int dim = b.dim;
	int excess = 0;

	for (int i = 0; i < dim; i++) {
		sum = temp.arr[dim - i - 1] + (b.arr)[dim - i - 1] + excess;
		if (sum < 10) {
			(temp.arr)[dim - i - 1] = sum;
			excess = 0;
		}
		if (sum > 9) {
			excess = sum / 10;
			sum = sum - excess * 10;
			(temp.arr)[dim - i - 1] = sum;
		}
	}
	if (excess != 0) {
		for (int i = 0; i < dim; i++) {
			(temp.arr)[dim - i - 1] = 9;
		}
	}

	return temp;
}

CIntN CIntN::operator-(const CIntN& other) {
	if (dim != other.dim) {
		printf("Error! dim(a) != dim(b)");
	}
	int tmp = 0;
	
	tmp = this->o_r_bigger(other);
	if (this->sign * other.sign == 1) {// a*b > 0
		if (tmp == 1) {
			return diffrence(this->sign, this, other);
		}
		if (tmp == -1) {
			return diffrence(-this->sign, other, this);
		}
	}
	if (this->sign * other.sign == -1) {
		return sum(this->sign, this, other);
	}
}

void  CIntN::print() {
	int fnn = this->ffnn();
	
	if (sign == -1 && fnn!= dim) {
		printf("%c", '-');
	}
	for (int i = fnn; i <dim-1; i++) {		
		printf("%d", arr[i]);
	}
	printf("%d", arr[dim - 1]);// for case c = 00...00
	printf("\n");
}


