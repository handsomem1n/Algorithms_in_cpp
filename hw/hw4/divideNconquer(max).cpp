#include <iostream>

using namespace std;

#define MAXSIZE 100
#define max(a,b) ((a) > (b) ? (a) : (b))

int DnCmax(int a[], int left, int right);

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int a[MAXSIZE];
        for(int i = 0 ; i< n ; i ++){
            cin >> a[i];
        }
        int left = 0;
        int right = n-1;

        cout << DnCmax(a, left, right) << endl;

    }
    return 0;
}

int DnCmax(int a[], int left, int right){

    int half = (left + right) / 2;

    if (left == right){ // 
        return a[left];
    }

    return max(DnCmax(a, left, half), DnCmax(a, half+1, right));
}
