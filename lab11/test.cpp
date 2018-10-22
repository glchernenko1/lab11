#include "test.h"
#include "my_vector.h"



bool test_equally()
{
	
		my_vector A(4);
		my_vector B(4);
		assert(A == B);
		my_vector C(4);
		my_vector D(3);
		assert(!(C == D));
	std::cout << "Test equally OK" << std::endl;
	return true;
}
	
bool test_assign()
{
	my_vector A(4);
	my_vector B(A);
	assert(A == B);
	my_vector C=A;
	assert(C == B);
	std::cout << "Test assign OK" << std::endl;
	return true;
}

bool test_sum()
{
	int d[4] = { 1,1,1,1 };
	my_vector A(4, d);
	my_vector B(4, d);
	int c[4] = { 2,2,2,2 };
	my_vector C(4, c);
	assert(C == B + A);
	assert(A == C - A);
	std::cout << "Test sum OK" << std::endl;
	return true;
}

bool test_multiplication()
{
	int d[4] = { 1,1,1,1 };
	my_vector A(4, d);
	int c[4] = { 2,2,2,2 };
	my_vector C(4, c);
	assert(C == A*2);
	assert( 4==A*A);
	std::cout << "Test multiplication OK" << std::endl;
	return true;
}



void testAll()
{
	if(test_equally() && test_assign() && test_sum() && test_multiplication() )
		std::cout << "Test ALL OK" << std::endl;
}
