#include<iostream>
using namespace std;

int main(){

    string str;
    cout << "Enter a string: ";
    cin >> str;

    int hash['a'+25] = {0};

    for( int i = 0 ; i < str.size() ; i++){
        hash[str[i]] += 1;
    }

    int q;
    cout << "Enter total number of queries: ";
    cin >> q;

    while(q--){

        char chr;
        cout << "Enter char to know frequency: ";
        cin >> chr;
        cout << "Frequency of " << chr << " = " << hash[chr] << endl;
        
    }

    return 0;
}