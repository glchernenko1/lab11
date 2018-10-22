// Integer.cpp: определяет точку входа для консольного приложения.
//


#include <iostream>
#include "my_vector.h"
#include "test.h"
; using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int d[4] = { 1,2,3,4 };
	my_vector A(4, d);
	my_vector B(4, d);
	cout << (A == B) <<endl;
	testAll();
	system("pause");
	return 0;
}

