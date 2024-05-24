#include <iostream>
using namespace std;

void weight(string str, int &count);
void permuteString(string str, int begin, int end, int &count);

int main() {
    int t;
    cin >> t;
    while(t--) {
        string str;
        cin >> str;
        int count = 0;
        permuteString(str, 0, str.length(), count);
        cout<< count << endl;
    }

    return 0;
}

void weight(string str, int &count) {
    bool check = false;
    int sum = 0;
    for(int i = 0; i< str.length(); i++) {
        (check == false) ? sum += (int)str[i] - 97  : sum += -((int)str[i] - 97); // ascii 'a'는 97
        check = !check;
    }
    if(sum > 0){
        count++;
    }
}

void permuteString(string str, int begin, int end, int &count) {
    int i;
    int range = end - begin;

    if(begin == end-1) {
        weight(str, count);
    }
    else {
        for(int i = begin; i<end; i++) {
            int tmp = str[begin];
            str[begin] = str[i];
            str[i] = tmp;
            permuteString(str, begin+1, end, count);
            int tmp2 = str[begin];
            str[begin] = str[i];
            str[i] = tmp2;
        }
    }  
}
