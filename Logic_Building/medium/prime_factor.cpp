#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> prime_factors(int n)
{
    // Exclude Edge Cases
    if(n == 0)
    {
        cout << "All Numbers Divide Zero\n";
        exit(-2);
    }

    if(n == 1)
    {
        cout << "No prime Factors\n";
        exit(-1);
    }

    vector<int> factors;

    // If divisible by 2 , push back 2 and then repeatedly divide by 2 till its not divisible..
    if(n % 2 == 0)
    {
        factors.push_back(2);
        while(n % 2 == 0)
        {
            n/=2;
        }
    } 

    // Check for odd prime factors
    for(int i = 3; i <= sqrt(n); i+=2)
    {
        // If prime factor , push back and repeatedly divide
        if(n % i == 0)
        {
            factors.push_back(i);
            while(n % i == 0)
            {
                n /= i;
            }
        }
    }
    if(n > 2)
    {
        factors.push_back(n);
    }

    return factors;
}
int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    vector<int> result = prime_factors(n);
    for(auto factor: result)
    {
        cout << factor << " ";
    }
}