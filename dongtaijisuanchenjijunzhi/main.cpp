#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num,*p,e(0),jun(0);
    cout<<"请输入学生人数:";
    cin>>num;
    p=new int[num];
    cout<<"请输入学生成绩:";
    for(int i=0;i<num;i++)
        {
            cin>>p[i];
            e+=p[i];
        }
        e/=num;
        cout<<"平均成绩为:"<<e;
        for(int i=0;i<num;i++)
        {
            jun+=(p[i]-e)*(p[i]-e);
        }
        jun/=num;
        jun=sqrt(jun);
        cout<<"均方差为:"<<jun;

    return 0;
}
