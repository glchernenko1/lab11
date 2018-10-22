#pragma once
#include <iostream>
#include "Error.h"
#include "dyn_array.h"
#include <cmath>

class my_vector:private dyn_array
{



public:
	my_vector(int size) : dyn_array(size) {};
	my_vector(int size, int *a) :dyn_array(size)
	{
		for (int i = 0; i < this->count(); ++i)
			this->operator[](i)= a[i];
	}
	my_vector(const my_vector &a) : dyn_array(a) {};
	double norma()const 
	{
		int sum=0;
		for (int i = 0; i < this->count(); ++i)
			sum += this->operator[](i)*this->operator[](i);
		return sqrt(sum);
	}

	my_vector &operator=(const my_vector& d)
	{
		this->operator=(d);
	}

	my_vector operator +(const my_vector& d) const
	{
		try
		{
			if (this->count() != d.count()) throw Error("Не совпадают размеры ");
			my_vector A(*this);
			for (int i = 0; i < d.count(); ++i)
				A[i] += d[i];
			return A;
		}
		catch (Error & e)
		{
			std::cout << e.What();
		}
	}

	my_vector operator -(const my_vector& d) const
	{
		try
		{
			if (this->count() != d.count()) throw Error("Не совпадают размеры ");
			my_vector A(*this);
			for (int i = 0; i < d.count(); ++i)
				A[i] -= d[i];
			return A;
		}
		catch (Error & e)
		{
			std::cout << e.What();
		}
	}
	my_vector operator *(const int d) const
	{
		
			
			my_vector A(*this);
			for (int i = 0; i < A.count(); ++i)
				A[i] *=d;
			return A;
		}
		

	bool operator ==(const my_vector& d) const
	{
		bool a = dyn_array(d)  == dyn_array (*this); ;
		return a;
	}

	bool operator > (const my_vector& d) const
	{
		return this->norma() > d.norma();
	}

	bool operator < (const my_vector& d) const
	{
		return this->norma() < d.norma();
	}

	int operator *(const my_vector &a) const //Алгебраическое
	{
		try
		{
			if (this->count() != a.count()) throw Error("Не совпадают размеры ");
			int sum = 0;
			for (int i = 0; i < a.count(); ++i)
				sum += this->operator[](i)*a[i];
			return sum;

		}
		catch (Error & e)
		{
			std::cout << e.What();
		}
	}

}
;
/*
		try
		{
			if (this->count() != d.count()) throw Error("Не совпадают размеры ");
		}
		catch (Error & e)
		{
			std::cout << e.What();
		}
		*/