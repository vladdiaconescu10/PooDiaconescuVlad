#include <iostream>
#include <stdarg.h>
#include "Math.h"
#pragma warning(disable : 4996)
using namespace std;

int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b, double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double  b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}
int Math::Add(int count, ...)
{
	va_list args;
	va_start(args, count);
	int suma=0;
	for (int i = 1; i <= count; i++) {
		suma += va_arg(args, int);
	}
	va_end(args);
	return suma;
}
char* Math::Add(const char* a, const char* b)
{
	char* c = new char[strlen(a) + strlen(b) + 1];
	strcpy(c, a);
	strcat(c, b);
	return c;
}