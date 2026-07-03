#include <iostream>
#include <vector>
#include <utility> // Required for std::swap

using namespace std;

// Your LeetCode Solution Class
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};

// Main function to run and test your code locally
int main() {
    Solution solver;
    
    // Test Case: feel free to change these numbers!
    vector<int> nums = {0, 1, 0, 3, 12};
    
    cout << "Original vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    // Call your function
    solver.moveZeroes(nums);
    
    cout << "Modified vector: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}