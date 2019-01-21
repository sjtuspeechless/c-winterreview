#include <iostream>

using namespace std;
void printInt(int,int);

int main()
{
    int num,base;

    cout<<"请输入一个整数:";
    cin>>num;
    cout<<"请输入进制:";
    cin>>base;
    printInt(num,base);
    cout<<endl;
    return 0;
}

void printInt(int num,int base)
{
    static char DIGIT[17]="0123456789abcdef";
    if(num<base) cout<<DIGIT[num];
    else{
        printInt(num/base,base);
        cout<<DIGIT[num%base];
    }
}
