#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{

    int subarraySum( vector<int> nums){
        int n = nums.size();
        int sum = 0;
        int max_sum = nums[0];
        for( int i = 0 ; i < n ; i++){

            sum += nums[i];
            max_sum = max( max_sum, sum);

            if( sum < 0){
                sum = 0;
            }

        }
        return max_sum;
    }

};