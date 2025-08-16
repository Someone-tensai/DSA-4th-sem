#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> left(n1);
    vector<int> right(n2);
    for (int i = 0; i < n1; i++) left[i] = arr[l + i];
    for (int j = 0; j < n2; j++) right[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
}

void merge_sort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    int b = 0;
    vector<int> a = {5,2,3,8,1,6,7};
    cout << "Array Before Sorting: ";
    display(a);
    merge_sort(a, 0, a.size()-1);
    cout << "Array After Sorting Using Merge Sort: ";
    display(a);
}