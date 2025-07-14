#include<iostream>
#include<vector>
using namespace std;

vector<int> primes(int n)
{
    // Initialise a boolean array of size n with all true except at 0 and 1.
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    
    // Loop till sqrt of n
    for(int p = 2; p * p <= n ; p++)
    {
        if(prime[p] == true)
        {
            // For each number, mark all of its multiples greater than its square as false
            // Starting from the square as if there are multiples smaller than the square, they are already marked by smaller numbers.
            for(int i = p*p; i <= n ; i+=p)
            {
                prime[i] = false;
            }
        }
    }
    
    // Result array with numbers where prime is still true
    vector<int> result;
    for(int p = 2; p <= n ; p++)
    {
        if(prime[p]) result.push_back(p);
    }

    return result;

}
int main()
{
    int n;
    cout << "Enter the upper limit: ";
    cin >> n;
    vector<int> prime_nums = primes(n);
    for(auto x: prime_nums)
    {
        cout << x << " ";
    }
}