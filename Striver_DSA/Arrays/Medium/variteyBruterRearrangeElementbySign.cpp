#include <bits/stdc++.h>

using namespace std;

/* ==========================================
 * Problem: Alternate Sign
 * Link: URL
 * TC: O(N) | SC: O(n)
 * ========================================== */

class Solution {
public:
    void solve(vector<int> nums) {
        int n = nums.size();
        int pos_num = 0;
        for( int i = 0 ; i < n ; i++){
            if( nums[i] > 0){
                pos_num++;
            }
        }
        int neg_num = n - pos_num;

        vector<int> v(n, 0);
        if( pos_num > neg_num){
            int i = 0;
            int pos_pointer = 0;
            int neg_pointer = 1;
            

            for( int i = 0 ; i < n ; i++){
                while(i < n){
                    if(nums[i] > 0 && pos_pointer < n){
                        v[pos_pointer] = nums[i];
                        pos_pointer += 2;
                    }

                    else if( nums[i] < 0 && neg_pointer <= 2*neg_num){
                        v[neg_pointer] = nums[i];
                        neg_num += 2;
                    }
                }
            }

        }

        else{
            int i = 0;
            int pos_pointer = 0;
            int neg_pointer = 1;
            

            for( int i = 0 ; i < n ; i++){
                while(i < n){
                    if(nums[i] > 0 && pos_pointer <= 2*pos_num){
                        v[pos_pointer] = nums[i];
                        pos_pointer += 2;
                    }

                    else if( nums[i] < 0 && neg_pointer <= n){
                        v[neg_pointer] = nums[i];
                        neg_num += 2;
                    }
                }
            }

        }

        
    }
};

int main() {
    // 1. Define Test Cases
    // Example: vector<int> nums = {1, 2, 3};
    
    // 2. Test Solution
    Solution sol;
    // auto res = sol.solve();
    // cout << "Result: " << res << "\n";
    
    return 0;
}