#include <iostream>
#include <cstring>
using namespace std;
int getInput();
int main()
{
    int num(0);
    num=getInput();
    cout<<num;
    return 0;
}

int getInput()
{
    int a;
    while(true){
    cin>>a;
    if(a<10&&a>0)
        return a;
    }
}
