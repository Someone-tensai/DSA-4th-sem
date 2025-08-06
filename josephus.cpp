// Given a list of N people to be executed with
// K-1 people from the starting position are skipped, and the kth one is executed
// Repeat from the same position where the execution happend
// Find the last survivor

#include<iostream>
#include<vector>
using namespace std;

// Using List
int josh_list(vector<int> person, int k, int index)
{
    // If only one person left, that's the survivor
    if(person.size() == 1)
    {
        return person[0];
    }

    // Find the First person to be executed
    // Each Kth person is killed
    // Modulus is to wrap around to the start
    index = (index+k-1) % person.size();

    cout << "Executed Person " << person[index] << "\n";
    // Erasing that position using iterator
    person.erase(person.begin() + index);

    // Recursive Call till only one survives
    return josh_list(person, k , index);

}


// 
int main()
{
    int n = 12 , k = 3, index = 0;

     vector<int> person;
    // fill the person vector
    for (int i = 1; i <= n; i++) {
        person.push_back(i);
    }
    int survivor = josh_list(person, k , index);
    cout << "Survivor: " << survivor ;
}