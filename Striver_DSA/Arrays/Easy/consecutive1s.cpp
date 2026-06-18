#include <iostream>
#include <vector>
#include <algorithm> // for std::max

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
    int max_ones = 0;
    int current_streak = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            current_streak++;
            // std::max keeps the larger of the two values
            max_ones = max(max_ones, current_streak); 
        } else {
            // We hit a 0, reset the current streak
            current_streak = 0;
        }
    }

    return max_ones;
}

int main() {
    // Test Case 1: Mixed 1s and 0s
    vector<int> test1 = {1, 1, 0, 1, 1, 1};
    cout << "Max consecutive 1s (Test 1): " << findMaxConsecutiveOnes(test1) << endl; 
    // Expected Output: 3

    // Test Case 2: Array with only 0s (This is what crashed your old code!)
    vector<int> test2 = {0, 0, 0, 0};
    cout << "Max consecutive 1s (Test 2): " << findMaxConsecutiveOnes(test2) << endl; 
    // Expected Output: 0

    return 0;
}