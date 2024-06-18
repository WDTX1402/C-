#include <iostream>
#include <iomanip>
#include <ios>
#include <cstring>

using namespace std;

void mystery1(char *, const char *);
bool mystery2(char *, char *);

int main()
{
    char string1[80];
    char string2[80];
    int maxSize = 80;
    //test case 1
    cout << "case 1) Normal concat: " << endl;
    cout << "Enter two strings: ";
    cin >> string1 >> string2;
    mystery1(string1, string2);
    cout << "Concatenated String: " << string1 << endl << endl;

    //test case 2
    cout << "case 2) overflow:" << endl;
    cout << "Enter two strings: ";
    cin >> string1 >> string2;
    mystery1(string1, string2);
    cout << endl;

    //test case 3
    cout << "case 3) substring:" << endl;
    cout << "Enter two strings: ";
    cin >> string1 >> string2;
    bool isSubstring1 = mystery2(string1, string2);
    if (isSubstring1) {
        cout << "Is string 2 a substring of string1? Yes" << endl;
    } else {
        cout << "Is string 2 a substring of string1? No" << endl;
    }
    cout << endl;

    //test case 4
    cout << "case 4) nonsubstring:" << endl;
    cout << "Enter two strings: ";
    cin >> string1 >> string2;
    bool isSubstring2 = mystery2(string1, string2);
    if (isSubstring2) {
        cout << "Is string 2 a substring of string1? Yes" << endl;
    } else {
        cout << "Is string 2 a substring of string1? No" << endl;
    }
    cout << endl;
}

void mystery1(char *s1, const char *s2) {

    if(strlen(s1)+ strlen(s2) > 80){
        cout << "Error: Insufficient space for concatenation" << endl;
    }
    while (*s1 != '\0') ++s1;
    for (; (*s1 = *s2); ++s1, ++s2);
}


bool mystery2(char *s1, char *s2)
{
    int M = sizeof(*s1);
    int N = sizeof(*s2);
 
    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++)
            if (s2[i + j] != s1[j])
                break;
 
        if (j == M)
            return true;
    }
 
    return false;
}
