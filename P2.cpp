#include <iostream>
#include <cstring>
using namespace std;
int my_strlen(char s[256]) {
    int i = 0, count = 0;
    while (s[i] != '\0') {
        count++;
    }
    return count;
}
int my_strcmp(char s1[256], char s2[256]) {
    int i = 0;
    while (s1[i] != '\0' && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];

}



void my_strcpy(char s1[256], char s2[256]) {
    //s1 = sursa si s2 = destinatia
    int i = 0;
    while (s1[i] != '\0') {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0';
}
int main() {
    char words[100][100];
    int count = 0;
    // salvam cuvintele intr-o lista de cuvinte pe care o vom sorta mai apoi folosind functiile creeate mai sus
    while (scanf("%s", words[count]) == 1) {
        count++;

    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            int lenI = my_strlen(words[i]);
            int lenJ = my_strlen(words[j]);

            bool trebuieSchimbat = false;


            if (lenI < lenJ) {
                trebuieSchimbat = true;
            }

            else if (lenI == lenJ) {
                if (my_strcmp(words[i], words[j]) > 0) {
                    trebuieSchimbat = true;
                }
            }

            if (trebuieSchimbat) {
                char aux[100];
                my_strcpy(aux, words[i]);
                my_strcpy(words[i], words[j]);
                my_strcpy(words[j], aux);
            }
        }
    }
    printf("\nCuvintele sortate:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}