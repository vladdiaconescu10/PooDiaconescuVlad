#include <iostream>
#include <cstring>
#include "Global.h"
#include "Student.h"
using namespace std;
int main() {
	student s1, s2;
	s1.SetName("Ion");
	s1.SetGradeMath(10);
	s1.SetGradeEnglish(8.4);
	s1.SetGradeHistory(7.8);

	s2.SetName("Alex");
	s2.SetGradeMath(9);
	s2.SetGradeEnglish(7);
	s2.SetGradeHistory(7.5);


	cout << "Media lui Ion este: " << GetAvarage(s1) << endl;
	cout << "Media lui Alex este: " << GetAvarage(s2) << endl;
	cout << "Comparare medie: " << compare_avarage << endl;
	cout << "Comparare nume: " << compare_name << endl;
	cout << "Comparare Nota Mate: " << compare_math << endl;
	cout << "Comparare Nota English: " << compare_english << endl;
	cout << "Comparare Nota History: " << compare_history << endl;

	return 0;
}