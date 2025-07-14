#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;

void tower_of_hanoi(int n, char source, char destination, char auxillary)
{
    static int iteration_counter = 1;

    // if(iteration_counter > 10000)
    // {
    //     cout << "Maximum Iterations Reached\n";
    //     exit(1);
    // }
    if(n == 1)
    {
        iteration_counter++;
        cout << "Move " << source << " to " << destination << "\n";
        return;
    }
    tower_of_hanoi(n-1, source, auxillary, destination);
    iteration_counter++;
    cout <<"Move " << source << " to " << destination << "\n";
    tower_of_hanoi(n-1, auxillary, destination, source);
    
}
int main()
{
    int n;
    ofstream outfile;
    cout << "Enter the number of disks: ";
    cin >> n;
    auto start_time = chrono::high_resolution_clock::now();
    tower_of_hanoi(n, 's', 'd', 'a');
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = end_time - start_time;
    double seconds = std::chrono::duration_cast<std::chrono::duration<double>>(duration).count();
    cout << "Time Elapsed: " << seconds;
    outfile.open("tower_of_hanoi_timed.txt", ios::app);
    if(outfile.is_open())
    {
        outfile << "Disks: " << n << ", Time: " << seconds << "\n";
    }
}