// binary search 
#include <iostream>
#include <vector>
using namespace std;

// Binary Search Function
int binarySearch(const vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;              // Target found
        else if (arr[mid] < target)
            low = mid + 1;          // Search right half
        else
            high = mid - 1;         // Search left half
    }

    return -1; // Target not found
}

int main() {
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    int target = 10;

    int result = binarySearch(arr, target);

    if (result != -1)
        cout << "
