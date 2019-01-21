//str的长度不能是变量
#include <iostream>

using namespace std;
void List(char str[],int k);

int main()
{
    char str[];
    int k;
    List(str,k);
    return 0;
}

void List(char str[],int k);
{
    int i;
    if(k==strlen(str)) cout<<srr<<endl;
    else for(i=k;i<strlen(str);++i)
    {
        swap(str,k,i);
        List(str,k+1);
        swap(str,k,i);

    }
}

void swap(char str[],int k,int i)
{
    int tmp;

    tmp=str[k];
    str[k]=str[i];
    str[i]=tmp;
}
