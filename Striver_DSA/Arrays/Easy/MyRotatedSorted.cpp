#include <iostream>
#include <vector>
#include <algorithm> // Required for std::rotate

using namespace std;

// Helper function to check if the vector is sorted
bool checkSorted(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return false; // Found a break, not sorted
        }
    }
    return true;
}

// Main logic function
bool check(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (checkSorted(nums)) {
            return true;
        }
        // Rotate the vector left by 1 position
        rotate(nums.begin(), nums.begin() + 1, nums.end());
    }
    return false; 
}

int main() {
    vector<int> nums1 = {3, 4, 5, 1, 2};
    vector<int> nums2 = {2, 1, 3, 4};

    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Test 1 (Expected: true): " << check(nums1) << endl;
    cout << "Test 2 (Expected: false): " << check(nums2) << endl;

    return 0;
}