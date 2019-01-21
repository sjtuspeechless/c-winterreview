#include <iostream>

using namespace std;
const int MAX_SIZE=10;
int main()
{
    int a[MAX_SIZE][MAX_SIZE],b[MAX_SIZE][MAX_SIZE],c[MAX_SIZE][MAX_SIZE];
    int i(0),j(0),k(0),NumOfRowA,NumOfColA,NumOfColB;

    cout<<"\n输入A的行数、列数和B的列数:";
    cin>>NumOfRowA>>NumOfColA>>NumOfColB;

    cout<<"\n输入A：\n";
    for(i=0;i<NumOfRowA;++i)
        for(j=0;j<NumOfColA;++j)
    {
        cout<<"a["<<i<<"]["<<j<<"]=";
        cin>>a[i][j];
    }

    cout<<"\n输入B：\n";
    for(i=0;i<NumOfColA;++i)
        for(j=0;j<NumOfColB;++j)
    {
        cout<<"b["<<i<<"]["<<j<<"]=";
        cin>>b[i][j];
    }

    for(i=0;i<NumOfRowA;++i)
    for(j=0;j<NumOfColB;++j){
        c[i][j]=0;
        for(k=0;k<NumOfColA;++k)  c[i][j]+=a[i][k]*b[k][j];
    }

    cout<<"\n输出:";
    for(i=0;i<NumOfRowA;++i){
             cout<<endl;
    for(j=0;j<NumOfColB;++j)
        cout<<c[i][j]<<"\t";
    }
    return 0;
}
