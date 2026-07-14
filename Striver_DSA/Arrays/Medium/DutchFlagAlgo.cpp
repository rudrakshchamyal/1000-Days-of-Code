#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
class Solution{

public:
    void sortColors(vector<int>& nums){
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n-1;

        while( mid <= high){
            if (nums[mid] == 1){
                mid++;
            }

            else if( nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }

            else if( nums[mid] == 2){
                swap( nums[mid], nums[high]);
                mid++;
                high--;
            }

            
        }

    }
};

int main(){

    Solution s;
    vector<int> v1 = {2,0,2,1,1,0};
    s.sortColors(v1);

    return 0;
}