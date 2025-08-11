#include<iostream>
#include<vector>
using namespace std;

// Function to Move Pivot Index to the Right Place and Partition
int partition(vector<int> &a, int low, int high)
{
    int pivot = a[high];
    int i = low;
    for(int j = low; j < high; j++)
    {
        if(a[j] <= pivot)
        {
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[high]);
    return i;
}

void quick_sort(vector<int> &a, int low, int high)
{
    if(low < high)
    {
        int pivot_index = partition(a, low, high);
        quick_sort(a, low, pivot_index-1);
        quick_sort(a, pivot_index+1,high);
    }
}

void display(const vector<int> &a)
{
    for(int item: a)
    {
        cout << item << " ";
    }
    cout << "\n";
}
int main()
{
    vector<int> a = {5,2,3,8,1,6,7};
    cout << "Array Before Sorting: ";
    display(a);
    quick_sort(a, 0, a.size());
    cout << "Array After Sorting Using Quick Sort: ";
    display(a);
}