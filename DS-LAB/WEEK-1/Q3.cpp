#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int nextGreaterPosCircular(vector<int>& vec, int element) {
    int n = vec.size();
    int index = -1;

    // 1. Find the starting element's index
    for (int i = 0; i < n; i++) {
        if (vec[i] == element) {
            index = i;
            break;
        }
    }

    // Return -1 if element doesn't exist in the array
    if (index == -1) return -1;

    stack<int> myStack;

    // 2. Iterate up to n - 1 hops circularly
    for (int step = 1; step < n; step++) {
        int currIndex = (index + step) % n;

        if (vec[currIndex] > element) {
            // Found the next greater element!
            // The number of elements in stack + 1 gives the hop count
            return myStack.size() + 1;
        } else {
            // Push smaller or equal elements to track distance
            myStack.push(vec[currIndex]);
        }
    }

    // If we traversed all n-1 elements and found nothing greater
    return -1;
}

int main() {
    // Example 3 from PDF: arr[] = {10, 4, 2, 5, 0, 6, 7}, element = 7 -> Output: 1
    vector<int> v1 = {10, 4, 2, 5, 0, 6, 7};
    int ans1 = nextGreaterPosCircular(v1, 7);
    
    if (ans1 == -1) cout << "Not found" << endl;
    else cout << ans1 << endl;

    // Example 4 from PDF: arr[] = {10, 6, 7, 2, 5, 1, 0, 4}, element = 7 -> Output: 6
    vector<int> v2 = {10, 6, 7, 2, 5, 1, 0, 4};
    int ans2 = nextGreaterPosCircular(v2, 7);

    if (ans2 == -1) cout << "Not found" << endl;
    else cout << ans2 << endl;

    return 0;
}