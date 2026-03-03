#include <iostream>
#include "Global.h"
#include "Student.h"
void my_strcpy(char s1[256],const char s2[256]) {
    //s1 = sursa si s2 = destinatia
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}
int my_strcmp(char s1[256], char s2[256]) {
    int i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];

}
int compare_name(student s1, student s2) {
    char n1[256], n2[256];
    s1.GetName(n1);
    s2.GetName(n2);
    int result = my_strcmp(n1, n2);
    if (result == 0)
        return 0;  
    if (result > 0)
        return 1;   
    return -1;                  
}

int compare_math (student s1, student s2) {
    if (s1.GetGradeMath() == s2.GetGradeMath())
        return 0;
    else if (s1.GetGradeMath() > s2.GetGradeMath())
        return 1;
    else
        return 0;
}

int compare_english (student s1, student s2) {
    if (s1.GetGradeEnglish() == s2.GetGradeEnglish())
        return 0;
    else if (s1.GetGradeEnglish() > s2.GetGradeEnglish())
        return 1;
    else
        return 0;
}

int compare_history (student s1, student s2) {
    if (s1.GetGradeHistory() == s2.GetGradeHistory())
        return 0;
    else if (s1.GetGradeHistory() > s2.GetGradeHistory())
        return 1;
    else
        return 0;
}

float GetAvarage(student s)
{
    return (s.GetGradeHistory() + s.GetGradeEnglish() + s.GetGradeMath()) / 3;
}

int compare_avarage(student s1, student s2)
{
    if (GetAvarage(s1) == GetAvarage(s2))
        return 0;
    else if (GetAvarage(s1) > GetAvarage(s2))
        return 1;
    else
        return 0;
}