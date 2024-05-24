#include <iostream>

using namespace std;

const int limit = 100;

int pick[limit +  1];
bool picked[limit + 1];

int findteam(int student) {
    if (picked[student]){
        return 0;
    }

    picked[student] = true;

    int n_student = pick[student];

    if (!picked[n_student]) {
        return findteam(n_student) + 1;
    }
    return 1;
}

int main() {
    int t;
    cin >> t;
    while (t-- ) {
        int n;
        cin >> n;

        for (int i = 1; i <= n; ++i) {
            cin >> pick[i];
        }

        for (int i = 1; i <= n; ++i) {
            picked[i] = false;
        }

        int count = 0;

        for (int i = 1; i <= n; ++i) {
            if (picked[i] == false) {
                findteam(i);
                count= count+1;
            }
        }
        cout << count << endl;
    }
    return 0;
}

