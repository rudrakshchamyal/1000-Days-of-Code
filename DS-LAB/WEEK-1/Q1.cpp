/*
Question -->

Q1. Given a string ‘s’ containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid. Assume that the string can contain
parentheses only i.e., only '()[]{}' characters are allowed; and the maximum
length of string can be, say, 20 characters.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets. 2.
Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same
type.
Example 1:
Input: s = "()"
Output: true
Example 2:
Input: s = "()[]{}"
Output: true
Example 3:
Input: s = “((]”
Output: false 


*/
#include<iostream>
#include<string>
#include<stack>

using namespace std;

bool isValid(string s){
    stack<char> myStack;
    int n = s.length();

    for( int i = 0 ; i < n ; i++){
        if( s[i] == '(' || s[i] == '{' || s[i] == '['){
            myStack.push(s[i]);
        }

        else{
            if( myStack.empty() ){
                return false;
            }

            else if( ( s[i] == ')' && myStack.top() == '('  ) || ( s[i] == '}' && myStack.top() == '{' ) || ( s[i] == ']' && myStack.top() == '[')  ){
                myStack.pop();
            }

            else{
                return false;
            }

        }
    }

    return myStack.empty();
}

int main(){
    string s1 = "(){}[]";

    cout << boolalpha << isValid(s1);

    return 0;
}