#include <iostream>

using namespace std;
void Hanoi (int n,char start,char finish,char temp);

int main()
{
    int n;
    cin>>n;
    Hanoi(n,'a','b','c');
    return 0;
}

void Hanoi(int n,char start,char finish,char temp)
{
    if(n==1) cout<<start<<"->"<<finish<<' ';
    else
    {
        Hanoi(n-1,start,temp,finish);
        cout<<start<<"->"<<finish<<' ';
        Hanoi(n-1,temp,finish,start);
    }
}
