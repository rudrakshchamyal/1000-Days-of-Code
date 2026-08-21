/*
Q4. You are given a string ‘s’, find the first non-repeating character (a
character that occurs only once) in it and return its index (position). If it does
not exist, return -1. Implement using concepts of queues.
Example 1:
Input: s = "thisisDSlab"
Output: Character: t
Index: 0
Example 2:
Input: s = "CodeForDSlabClass"
Output: Character: d
(Assumption - ‘d’ and ‘D’ are considered as different characters)
Index: 2
Example 3:
Input: s = "The quick brown fox jumps over a lazy dog"
Output: Character: None
Index: -1 
*/
#include<iostream>
#include<string>
#include<queue>

using namespace std;

void nonRepElement( string s){

    queue<int> myq;
    int n = s.length();
    myq.push(s[0]);
    
    for( int i = 0 ; i < n ; i++){
        myq.push(s[i]);
    }
    char ch;

    for( int i = 0 ; i < n ; i++){
        char c = myq.front();
        for( int  j = i + 1; j < n ; j++){
            myq.pop();
            if( c == myq.front()){
                break;
            }

            else{
                ch = c;
            }
        }
    }

    cout  << ch;

}

int main(){
    string s = "HELLO";
    nonRepElement(s);
}