#include <iostream>
#include <algorithm> // max()

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int maxlen = 0;
        int start = 0, end = 0;

        while (end < n) {
            if (a[start] <= a[end]) {
                maxlen = max(maxlen, end - start + 1);
                end++;
            } else {
                start++;
            }
        }

        cout << maxlen << endl;
    }   
        return 0;
}
