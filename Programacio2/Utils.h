#pragma once
#include <windows.h>
#include <stdio.h>

#define LOG(format, ...) log(__FILE__, __LINE__, format, __VA_ARGS__);

void log(const char file[], int line, const char* format, ...);

#define CAP(n) ((n <= 0.0f) ? n=0.0f : (n >= 1.0f) ? n=1.0f : n=n)

int factorial(int number){
	int ret = 1;
	for (int i = 1; i <= number; i++)
	{
		ret *= i;
	}

	return ret;
}
//D.Hernandez
int factorial2(int num){

	if (num > 1)
	{
		return num * factorial2(num - 1);
	}
	else{
		return 1;
	}
}

template<class TYPE>
void swap(TYPE &a, TYPE & b){
	TYPE tmp = a;
	a = b;
	b = tmp;
}