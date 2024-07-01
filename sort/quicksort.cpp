#include <iostream>
using namespace std;


// Helper function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(vector<int>& arr, int start, int end) {
    int pivot = arr[end];  // Choose the last element as pivot
    int i = start - 1;     // Index of the smaller element

    for (int j = start; j <= end - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[end]);
    return (i + 1);
}

// Quicksort function
void quicksort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int pi = partition(arr, start, end);  // Partitioning index

        // Recursively sort elements before and after partition
        quicksort(arr, start, pi - 1);
        quicksort(arr, pi + 1, end);
    }
}

int main() {
  vector<int> arr = {24, 2, 45, 20, -67, 56, 75, 2, 56, 99, 53, 12};
  sort(arr, 0, arr.size()-1);
  for (int a : arr) {
    cout << a << endl;
  }
}
