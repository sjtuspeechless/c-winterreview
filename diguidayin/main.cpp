#include <iostream>

using namespace std;
void printInt(int);

int main()
{
    int num;

    cout<<"请输入一个整数:"<<endl;
    cin>>num;
    printInt(num);
    cout<<endl;

    return 0;
}
void printInt(int num)
{
    if(num<10)
        cout<<static_cast<char>(num+'0');
    else {
        printInt(num/10);
        cout<<static_cast<char>(num%10+'0');
    }
}
