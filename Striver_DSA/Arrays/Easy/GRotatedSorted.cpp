#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>& nums) {
    int count_drops = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        // (i + 1) % n seamlessly connects the last element back to the first element
        if (nums[i] > nums[(i + 1) % n]) {
            count_drops++;
        }
        
        // If it drops more than once, it cannot be a rotated sorted array
        if (count_drops > 1) {
            return false;
        }
    }
    
    return true;
}

int main() {
    vector<int> nums1 = {3, 4, 5, 1, 2};
    vector<int> nums2 = {2, 1, 3, 4};

    cout << boolalpha; // Prints true/false instead of 1/0
    cout << "Test 1 (Expected: true): " << check(nums1) << endl;
    cout << "Test 2 (Expected: false): " << check(nums2) << endl;

    return 0;
}