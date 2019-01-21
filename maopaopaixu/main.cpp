#include <iostream>

using namespace std;

int main()
{
    int a[]={0,3,5,1,8,7,9,4,2,10,6};
    int i,j,tmp;
    bool flag;
     for(i=1;i<11;++i)
     {
         flag=false;
         for(j=0;j<11-i;++j)
            if(a[j+1]<a[j])
            {
                tmp=a[j];a[j]=a[j+1];a[j+1]=tmp;flag=true;
            }
         if(!flag) break;
     }

     cout<<endl;
     for(i=0;i<11;++i)  cout<<a[i]<<' ';
    return 0;
}
