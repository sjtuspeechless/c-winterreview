#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num,*p,e(0),jun(0);
    cout<<"������ѧ������:";
    cin>>num;
    p=new int[num];
    cout<<"������ѧ���ɼ�:";
    for(int i=0;i<num;i++)
        {
            cin>>p[i];
            e+=p[i];
        }
        e/=num;
        cout<<"ƽ���ɼ�Ϊ:"<<e;
        for(int i=0;i<num;i++)
        {
            jun+=(p[i]-e)*(p[i]-e);
        }
        jun/=num;
        jun=sqrt(jun);
        cout<<"������Ϊ:"<<jun;

    return 0;
}
