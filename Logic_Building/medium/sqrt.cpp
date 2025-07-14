// Program to find the square root of a number
#include<iostream>
using namespace std;


int floor_sqrt_loop(int n)
{
    int i = 0;
    while(i*i <= n)
    {
        i++;
    }
    return i-1;
}

int floor_sqrt_bin(int n)
{
    int low = 1, high = n;
    int i = 1;

    while(low <= high)
    {
        int mid = (low + high)/2;
        
        if(mid*mid <= n)
        {
            i = mid;
            low = mid+1;
        }

        else
        {
            high = mid-1;
        }
    }
    return i;
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    cout << floor_sqrt_loop(n) << "\n" ;
    cout << floor_sqrt_bin(n) << "\n";
}