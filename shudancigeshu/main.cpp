#include <iostream>

using namespace std;

int main()
{
    const int LEN=80;
    char sentense[LEN+1],prev=' ';
    int i=0,num=0;
     cin.getline(sentense,LEN+1);

     for(i=0;sentense[i]!='\0';i++){
        if (prev==' '&&sentense[i]!=' ')
        ++num;
     prev=sentense[i];}

     cout<<"单词个数为："<<num;
    return 0;
}
