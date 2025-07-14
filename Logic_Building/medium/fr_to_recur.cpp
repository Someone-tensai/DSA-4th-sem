#include<iostream>
#include<unordered_map>
using namespace std;


// First calculate the integral quotient

string frac_to_dec(int a, int b)
{
    if(a == 0)
    {
        return "0";
    }
    string result;
    //Negative if any of the number less than 0
    if(a < 0 || b < 0)
    {
        result += "-";
    }
    a = abs(a);
    b = abs(b);

    // Appending the Integral Part
    result += to_string(a/b);

    int rem = a%b;

    // If no remainer then directly return the result
    if(rem == 0)
    {
        return result;
    }
    // Starting the decimal part
    result.append(".");

    // Using a Hash Map to see if the decimal is recurring
    unordered_map<int, int> map;
    while(rem > 0)
    {
        // If the remainder is in the hash map already, its recurring hence stop
        if(map.find(rem) != map.end())
        {
            result.insert(map[rem], "(");
            result.append(")");
            break;
        }

        // Putting the remainder into the map 
        // result.size() just gives the number of characters till now. Using it as a position tracker.
        map[rem] = result.size();
        rem = rem * 10;

        // Append the quotient to the result and calculate next remainder
        result += to_string(rem / b);
        rem = rem % b;
    }
    return result;
}
int main()
{
    int a,b;
    cout << "Enter numerator: ";
    cin >> a;
    cout << "Enter denominator: ";
    cin >> b;
    cout << frac_to_dec(a,b);
}