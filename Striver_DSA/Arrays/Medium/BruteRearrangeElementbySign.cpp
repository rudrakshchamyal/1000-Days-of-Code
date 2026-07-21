#include <bits/stdc++.h>

using namespace std;

/* ==========================================
 * Problem: 2149. Rearrange Array Elements by Sign
 * Link: URL
 * TC: O(N) | SC: O(N)
 * ========================================== */

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }

            else{
                neg.push_back(nums[i]);
            }
        }

        nums.clear();

        for( int i = 0 ; i < n ; i++){

            if( i % 2 == 0){
                nums.push_back(pos[i/2]);
            }
            else{
                nums.push_back(neg[i/2]);
            }
        }
        return nums;
    }
};

int main() {
    // 1. Define Test Cases
    vector<int> nums = {3,1,-2,-5,2,-4};
    
    // 2. Test Solution
    Solution sol;
    sol.rearrangeArray(nums);
    for( int i = 0 ; i < nums.size() ; i++){
        cout << nums[i] << endl;
    }
    // cout << "Result: " << res << "\n";
    
    return 0;
}