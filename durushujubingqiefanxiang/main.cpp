#include <iostream>

using namespace std;
const int MAX=10;
int ReadIntegeraArray(int array[ ],int MAX,int flag);
void ReverseIntegerArray(int array[ ],int size);
void PrintIntegerarray(int array[ ],int size);


int main()
{
    int IntegerArray[MAX],flag,CurrentSize;

    cout<<"������������:";
    cin>>flag;
     CurrentSize=ReadIntegeraArray(IntegerArray,MAX,flag);
     ReverseIntegerArray(IntegerArray,CurrentSize);
     PrintIntegerarray(IntegerArray,CurrentSize);

    return 0;
}

int ReadIntegeraArray(int array[],int max,int flag)
{
    int size=0;

    cout<<"����������Ԫ�أ���"<<flag<<"������";
    while(size<max)
    {
        cin>>array[size];
        if(array[size]==flag) break;else ++size;
    }
    return size;
}

void ReverseIntegerArray(int array[],int size)
{
    int i,tmp;

    for(i=0;i<size/2;i++)
    {
        tmp=array[i];
        array[i]=array[size-1-i];
        array[size-1-i]=tmp;
    }
}

void PrintIntegerarray(int array[],int size)
{
    int i;
    if(size==0) return;
    cout<<"������:"<<endl;
    for(i=0;i<size;++i)  cout<<array[i]<<'\t';
    cout<<endl;
}
