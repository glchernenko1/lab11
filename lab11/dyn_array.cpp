#include "dyn_array.h"

void dyn_array::copy(const datatype * from, datatype * to, int size)
{
	for (int i = 0; i < size; ++i) to[i] = from[i];
}

dyn_array::dyn_array()
{
	size = 2;
	data = new datatype[size];
	data[0] = 0;
	data[1] = 0;
}

dyn_array::dyn_array(int size): size(size)
{
	data = new datatype[size];
	for (int i = 0; i < size; ++i) data[i] = 0;
}

dyn_array::~dyn_array()
{
	
	if (data!=nullptr)
	delete[] data;

}

dyn_array::dyn_array(const dyn_array & d)
{
	size = d.size;
	data = new datatype[size];
	for (int i = 0; i < size; ++i)
		data[i] = d.data[i];

}

dyn_array & dyn_array::operator=(const dyn_array & d)
{
	size = d.size;
	if (data) delete[] data;
	data = new datatype[size];
	for (int i = 0; i < size; ++i)
		data[i] = d.data[i];
	return *this;
}

void dyn_array::resize(int new_size)
{
	try {
		if (new_size <= 0) throw Error("отрицательный размер ");
		if (new_size == size) return;
		datatype *data_new;
		data_new = new datatype[new_size];
		if (new_size > size)
			copy(data, data_new, size);
		else
			copy(data, data_new, new_size);
		if (data) delete[] data;
		data = data_new;
		size = new_size;
	}
	catch (Error e)
	{
		std::cout << e.What();
	}
}

void dyn_array::append(const datatype & x)
{
	this->resize(size + 1);
	data[size - 1] = x;
}

void dyn_array::insert(int index, const datatype & x)
{
	try {
		if (index >= size+1) throw Error("¬ставка за приделы массива ");
	this->resize(size + 1);
	for (int i = size - 1; index < i; --i)
		std::swap (data[i], data[i - 1]);
	data[index] = x;
	}
	catch (Error e)
	{
		std::cout << e.What();
	}
}

void dyn_array::remove(int index)
{
	try {
		if (index >= size ) throw Error("”даление за приделами за приделы массива ");
	for (int i = index; i < size - 2; ++i)
		std::swap(data[i], data[i + 1]);
	this->resize(size - 1);
	}
	catch (Error e)
	{
		std::cout << e.What();
	}
}

int dyn_array::find(const datatype & x) const
{
	for (int i = 0; i < size; ++i)
		if (data[i] == x) return i;
	return -1;
}

std::istream & operator>>(std::istream & is, dyn_array & p)
{
	int a;
	is >> a;

	p.resize(a); std::cout << p.size << std::endl;
	for (int i = 0; i < p.size; ++i)
	{
		is >> p.data[i];
	}
	p.size = a;
	return is;
}

std::ostream & operator<<(std::ostream & os, const dyn_array & p)
{
	os << p.size;
	for (int i = 0; i < p.size; ++i)
	{
		os <<" "<< p.data[i];
	}
	return os;
}

