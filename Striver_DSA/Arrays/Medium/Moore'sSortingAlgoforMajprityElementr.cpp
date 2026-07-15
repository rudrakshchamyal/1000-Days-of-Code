#include<iostream>
#include<vector>

using namespace std;

class Solution{

    int majorityElement( vector<int> nums){
        int n = nums.size();
        int a = nums[0];
        int count = 0;
        for( int i = 0 ; i < n ; i++){
            if( count == 0 ){
                a = nums[i];
            }

            if( a == nums[i]){
                count++;
            }

            else{
                count--;
            }       

            //Question states that majority element is always there i.e frequency > n/2 
            
        }
        return a;
    }

};