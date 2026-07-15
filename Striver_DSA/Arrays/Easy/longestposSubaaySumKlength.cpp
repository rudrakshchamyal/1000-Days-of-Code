#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {
        int n = nums.size();

        int i = 0, j = 0, max_len = 0, sum = 0, current_len;
        
        while( j < n){
            sum += nums[j];

            while(i <= j && sum > k){
                sum -= nums[i];
                i++;
            }

            if ( sum == k)
            {
                current_len = j-i+1;
                max_len = max(max_len, current_len);
            }

            j++;
            
        }

        return max_len;
    }
};

// ========================================================
// DRIVER CODE / TESTING SUITE
// ========================================================
int main() {
    Solution solver;

    // Test Case: Longest subarray with sum 10 is {1, 2, 5, 2} (Length 4)
    vector<int> nums = {1, 2, 5, 2, 3, 1, 1}; 
    int k = 10;

    cout << "--- VS Code Sliding Window Runner ---" << endl;
    cout << "Input Array : {";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << (i < nums.size() - 1 ? ", " : "");
    }
    cout << "}" << endl;
    cout << "Target K    : " << k << endl;
    cout << "-------------------------------------" << endl;

    int result = solver.longestSubarray(nums, k);

    cout << "Your Output (Max Length): " << result << endl;
    cout << "Expected Output         : 4" << endl;

    return 0;
}