// Program to Find the k-th digit in a^b(From Right)
#include<iostream>
#include<math.h>
using namespace std;

//Using Modular Exponentiation(as a^b can be very large and we only need the kth digit)
int find_kth_digit(int a, int b, int k)
{
    long long mod = pow(10LL, k);
    long long i = 1;
    long long base = a;

    while(b>0)
    {
        //Treating b as a binary number
        //This works cuz any number can be written as powers of 2. 
        // if b = 13 = 8 + 4 + 1 = 2^3 + 2^2 + 2^1
        // a^b = a^13 = a^(2^3 + 2^2 + 2^1) = a^(2^3) * a^(2^2) * a(2^1) = a^8 * a^4 * a^1
        // So we calculate only in squares i.e. a^1 then a^2 then a^4 and so on.
        // By then checking if the current bit is 1 , we know whether to include it in the result.
        if(b&1)
        {
            i = (i*base) % mod;
        }
        // If current last bit is 0, do not update the result and go to the next power of 2
        base = (base*base) % mod;

        // Move to next bit
        b >>= 1;
    }

    for(int i = 1; i < k; i++)
    {
        i /= 10;
    }
    return (int)(i);
}
int main()
{
    int a, b,k;
    cout << "Enter the Base: ";
    cin >> a;
    cout << "Enter the Exponent: ";
    cin >> b;
    cout << "Enter the Place: ";
    cin >> k;

    find_kth_digit(a, b,k);
}