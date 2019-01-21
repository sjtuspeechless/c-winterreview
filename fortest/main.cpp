#include <iostream>

using namespace std;
struct Student{
int age;
char *sex;
double high;

};

int main()
{
    Student s1,s2;
    s1.age=1;
    s1.sex="female";
    s2.age=2;
    s1.age=s2.age;
    cout<<s1.age;
return 0;
}
