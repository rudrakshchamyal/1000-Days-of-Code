#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

// ========================================================
// LEETCODE STYLE CLASS 
// Paste your custom logic inside the function below.
// ========================================================
class Solution {
public:
    int longestSubarray(vector<int> &nums, int k) {

        int n = nums.size();
        int maxLen = 0;

        int i = 0;
        int j = 0;

        while(j < n ){
            int sum = 0;
            for( int x = i ; x <=j ; x++){
                sum += nums[x];
            }

            if(sum == k){
                int currentLen = j-i+1;
                maxLen = max(currentLen, maxLen);
                j++;
            }

            else if( sum < k){
                j++;
            }

            else if(sum > k){
                i++;
                if( i > j){
                    i = j;
                }
            }
            
        }
        
        return maxLen; 
    }
};

// ========================================================
// DRIVER CODE / TESTING SUITE
// Modify the vector and target 'k' to test different cases.
// ========================================================
int main() {
    Solution solver;

    // 1. Define your test input parameters
    vector<int> nums = {1, 2, 3, 1, 1, 1, 1}; 
    int k = 3;

    // 2. Print inputs for visual tracking
    cout << "--- LeetCode Test Runner ---" << endl;
    cout << "Input Array : {";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i] << (i < nums.size() - 1 ? ", " : "");
    }
    cout << "}" << endl;
    cout << "Target K    : " << k << endl;
    cout << "----------------------------" << endl;

    // 3. Execute your class function
    int result = solver.longestSubarray(nums, k);

    // 4. Output the result
    cout << "Your Output : " << result << endl;

    return 0;
}