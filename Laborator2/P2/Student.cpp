#include <iostream>
#include "Student.h";
#include "Global.h";
using namespace std;
void student::SetName(const char* name)
{
	my_strcpy(this->name,(char*) name);
}


void student::SetGradeMath(float grade_math)
{
	this->grade_math = grade_math;
}
void student::SetGradeEnglish(float grade_english)
{
	this->grade_english = grade_english;
}
void student::SetGradeHistory(float n)
{
	this->grade_history = n;
}


void student::GetName(char s[]) 
{
	my_strcpy(s, this->name);
}
float student::GetGradeMath()
{
	return this->grade_math;
}
float student::GetGradeEnglish()
{
	return this->grade_english;
}
float student::GetGradeHistory()
{
	return this->grade_history;
}
