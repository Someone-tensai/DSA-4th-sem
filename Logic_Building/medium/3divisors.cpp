//Program to find numbers with exactly 3 divisors within a certain range
#include<iostream>
using namespace std;

bool is_prime(int n)
{
    for(int i = 2; i*i <=n ; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}
void find_numbers(int n)
{
    for(int i = 2 ; i * i <=n ; i++)
    {
        if(is_prime(i))
        {
            cout << i*i << " ";
        }
    }
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    find_numbers(n);
}