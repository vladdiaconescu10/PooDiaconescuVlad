#pragma once
class student
{
	private:
		char name[100];
		 

		float grade_math;
		float grade_english;
		float grade_history;
	public:
		void SetName(const char* name);
		void SetGradeMath(float n);
		void SetGradeEnglish(float n);
		void SetGradeHistory(float n);
		void GetName(char s[]);
		float GetGradeMath();
		float GetGradeEnglish();
		float GetGradeHistory();
		


};