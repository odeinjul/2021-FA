//gpa
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    printf("Please enter your score:");
    float gpa;
    int score,gpa1;
    string grade;
    scanf("%d",&score);
    if(score >= 101) gpa = -1;
    else if(score >=95) gpa = 4.3;
    else if(score >=90) gpa = 4.0;
    else if(score >=85) gpa = 3.7;
    else if(score >=82) gpa = 3.3;
    else if(score >=78) gpa = 3.0;
    else if(score >=75) gpa = 2.7;
    else if(score >=72) gpa = 2.3;
    else if(score >=68) gpa = 2.0;
    else if(score >=65) gpa = 1.7;
    else if(score >=64) gpa = 1.5;
    else if(score >=61) gpa = 1.3;
    else if(score >=60) gpa = 1.0;
    else gpa = 0;

    gpa*=10;
    gpa1=gpa;
    switch (gpa1)
    {
    case 43:
        grade = "A+";
        break;
    case 40:
        grade = "A";
        break;
    case 37:
        grade = "A-";
        break;
    case 33:
        grade = "B+";
        break;
    case 30:
        grade = "B";
        break;
    case 27:
        grade = "B-";
        break;
    case 23:
        grade = "C+";
        break;
    case 20:
        grade = "C";
        break;
    case 17:
        grade = "C-";
        break;
    case 15:
        grade = "D+";
        break;
    case 13:
        grade = "D";
        break;
    case 10:
        grade = "D-";
        break;
    default:
        grade = "F";
        break;
    }

    printf("%s: %.2f\n", grade.c_str(), gpa/10.0);
    return 0;
}