#include<iostream>
#include<vector>

using namespace std;

 int largestElement(vector<int>& nums){
        
        int le = nums[0];

        for(int i = 0 ; i < nums.size() ; i++){
            
            if( le < nums[i]){
                le = nums[i];
            }
        }

        return le;
    }

int main(){

    vector<int> nums = {1,2,3};

   
};