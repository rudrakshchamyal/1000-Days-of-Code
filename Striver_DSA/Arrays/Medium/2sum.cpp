#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Cleaned up print function that safely handles formatting
    void print(const vector<int>& v) {
        if (v.empty()) {
            cout << "{}" << endl;
            return;
        }
        cout << "{";
        for (size_t i = 0; i < v.size(); i++) {
            cout << v[i];
            if (i < v.size() - 1) {
                cout << ", "; // Add a nice comma between elements
            }
        }
        cout << "}" << endl;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            
            // FIX: Store the current number, NOT the complement
            numMap[nums[i]] = i; 
        }

        return {};
    }
};

int main() {
    Solution solver;
    vector<int> nums = {3, 2, 4};
    int target = 6;
    
    // FIX: Call methods using the 'solver' object
    vector<int> ans = solver.twoSum(nums, target);
    solver.print(ans);

    return 0;
}