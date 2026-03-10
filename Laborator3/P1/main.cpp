#include <iostream>
#include <cstring>
#include "Math.h";
#pragma warning(disable : 4996)
using namespace std;
int main()
{	
	cout << Math::Add(2, 2) << endl;
	cout << Math::Add(2, 2, 5) << endl;

	cout << Math::Add(1.2, 2.3) << endl;
	cout << Math::Add(1.2, 2.3, 4.7) << endl;

	cout << Math::Mul(2, 2) << endl;
	cout << Math::Mul(2, 2, 5) << endl;

	cout << Math::Mul(1.2, 2.3) << endl;
	cout << Math::Mul(1.2, 2.3, 4.7) << endl;

	cout << Math::Add(5, 4, 5, 6, 2, 3) << endl;

	char s1[256] = "ABC";
	char s2[256] = "DEF";
	
	cout <<Math::Add(s1,s2);
}
