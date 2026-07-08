#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr1 = {1, 2, 3, 5};
    vector<int> arr2 = {2, 3, 4, 65, 77};

    vector<int> nums;
    
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i = 0, j = 0 ;

    while( i < n1 && j < n2 ){
        if( arr1[i] <= arr2[j]){
            if (nums.empty() || nums.back() != arr1[i])
            {
                nums.push_back(arr1[i]);
            }
            i++;          
        }

        else{
            if(nums.empty() || nums.back() != arr2[j]){
                nums.push_back(arr2[j]);
            }
            j++;
        }
    }

    while( i < n1){
        if (nums.empty() || nums.back() != arr1[i])
            {
                nums.push_back(arr1[i]);
            }
            i++;

    }

    while( j < n2){
        if(nums.empty() || nums.back() != arr2[j]){
                nums.push_back(arr2[j]);
            }
            j++;
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

    return 0;
}