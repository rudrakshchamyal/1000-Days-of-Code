#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<int> arr1 = {4,4,4,5,6,7};
    vector<int> arr2 = {1,2,3,4,5,5,5};

    vector<int> nums;

    int n1 = arr1.size();
    int n2 = arr2.size();

    
    for( int i = 0 ; i < n1 ; i++){
        for( int j = 0 ; j < n2 ; j++){
            if(arr1[i] == arr2[j] && (nums.empty() || nums.back() != arr1[i] )){
                
                nums.push_back(arr1[i]);
                break;

            }  
        }
    }
    

    if (!nums.empty()) {
        cout << "{";
        for (size_t k = 0; k < nums.size(); k++) {
            cout << nums[k];
            if (k < nums.size() - 1) {
                cout << ", "; // Prevent a trailing comma at the end
            }
        }
        cout << "}" << endl;
    } else {
        cout << "{}" << endl;
    }


}