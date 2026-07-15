#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int hash[3] = {0};

        // Pass 1: Count the occurrences of each color
        for (int num : nums) {
            hash[num]++;
        }

        // Pass 2: Overwrite nums based on the counts
        int idx = 0;
        for (int color = 0; color < 3; color++) {
            while (hash[color] > 0) {
                nums[idx++] = color;
                hash[color]--;
            }
        }
    }
};