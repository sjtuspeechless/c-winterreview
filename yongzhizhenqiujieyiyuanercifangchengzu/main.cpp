#include <iostream>
#include <cmath>

int Solve(double a,double b,double c,double*x1,double*x2);

using namespace std;

int main()
{
    double a,b,c,x1(0),x2(0);
    int result;
    cout<<"������a��b��c��ֵ:";
    cin>>a>>b>>c;
    result=Solve(a,b,c,&x1,&x2);
    switch (result)
    {
        case 0 :cout<<"������2����ͬʵ�����ֱ�Ϊ"<<x1<<' '<<x2;break;
        case 1: cout<<"����2����ͬ��Ϊ"<<x1;break;
        case 2 :cout<<"�����޽�";break;
        case 3: cout<<"����һԪ���η���";break;
    }


    return 0;
}

int Solve(double a,double b,double c,double*x1,double*x2)
{
    double disc,sqrt1;
    if(a==0) return 3;
    disc=b*b-4*a*c;
    if(disc<0)  return 2;
    if(disc==0) {*x1=-b/2/a;return 1;}
    else
        sqrt1=sqrt(disc);
    *x1=(-b+sqrt1)/2/a;
    *x2=(-b-sqrt1)/2/a;
    return 0;
}
