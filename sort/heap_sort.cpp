#include<iostream>
#include<vector>
using namespace std;


void heapify(vector<int> &arr, int n, int i) {
    int largest = i;       
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); 
    }
}

void heap_sort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);      
        heapify(arr, i, 0);        
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
    heap_sort(a);
    cout << "Array After Sorting Using Heap Sort: ";
    display(a);
}