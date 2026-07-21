#include <bits/stdc++.h>

using namespace std;

/* ==========================================
 * Problem: 121. Best Time to Buy and Sell Stock
 * Link: URL
 * TC: O(N) | SC: O(1)
 * ========================================== */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int min_prices = prices[0];
        int max_profit = 0;

        for( int i = 1 ; i < n ; i++){
            if( prices[i] < min_prices){
                min_prices = prices[i];
            }
            max_profit = max(max_profit, prices[i] - min_prices);
        } 
    
        return max_profit;
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