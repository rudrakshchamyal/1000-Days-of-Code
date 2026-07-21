#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    void print(vector<int> nums, int start, int end){
        int n = nums.size();
        cout << "{";
        for( int i = start ; i < end-1 ; i++){
            cout << nums[i] << ", ";
        }
        cout << nums[end-1] << "}";
    }

    void max_subarray_sum( vector<int> nums){   

        int n = nums.size();
        int sum = 0;
        int max_sum = nums[0];
        int temp_start = 0, start, stop;

        for( int i = 0 ; i < n ; i++){
            sum += nums[i];
            if( sum > max_sum){
                max_sum = sum;
                start = temp_start;
                stop = i;
                
            }
            if( sum < 0){

                sum = 0;
                temp_start = i + 1;
            }

        }
        
        cout << "Maximum Subarray Sum = " << max_sum << endl;
        cout << "Maximum Subarray ==>" << endl;

        cout << "{";
        for( int i = start ; i < stop ; i++ ){
            cout << nums[i] << " ,";
        }
        cout << nums[stop] << "}";

    }
};

int main(){
    Solution s;

    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    s.max_subarray_sum(v);
    
    return 0;
}