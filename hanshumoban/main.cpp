#include <iostream>

using namespace std;
template <class T>
T max(T a,T b)
{
    return a>b ? a : b;
}

int main()
{
    cout <<"max(3,5)="<<max(3,5)<<endl;
    cout <<"max(3.2,5.5)="<<max(3.2,5.5)<<endl;
    cout <<"max('d','r')="<<max('r','d')<<endl;
    return 0;
}
