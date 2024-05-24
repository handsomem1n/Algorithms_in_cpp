#include <iostream>
#include <string>

using namespace std;

// reverseString(string str);
void reverseString(string str);

int main () {
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        reverseString(str);
    }
}

void reverseString(string str){
    int n = str.length();
    for(int i = 0; i< n/2 ; i++){
        // swap(str[i], str[n-i]);
        swap(str[i], str[n-i-1]);
    }
    cout << str << endl;
}

