// Implementaion of Tower of Hanoi using recursion
#include<iostream>
using namespace std;

void TOH(int n, char s, char d, char a)
{

    if(n == 1)
    {
        cout << "Move " << s << " to " << d << "\n";
        return;
    }
    TOH(n-1, s,a,d);
    cout << "Move " << s << " to " << d << "\n";
    TOH(n-1, a,d,s);
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    TOH(n, 's' , 'd' , 'a');
}