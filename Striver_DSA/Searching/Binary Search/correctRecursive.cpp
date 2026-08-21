#include <iostream>
#include <vector>

using namespace std;

// Removed hardcoded default parameter for 'high'
// Passed vector by reference (&) to stop copying memory
int BinarySearch(const vector<int>& arr, int val, int low, int high) {
    if (low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == val) {
        return mid;
    }
    else if (arr[mid] < val) {
        return BinarySearch(arr, val, mid + 1, high);
    }
    else {
        return BinarySearch(arr, val, low, mid - 1);
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Pass the correct bounds dynamically from main
    cout << BinarySearch(arr, 4, 0, arr.size() - 1) << endl;

    return 0;
}
