#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cheese {
    int volume;
    int price;
    Cheese(int v, int p) : volume(v), price(p) {}
};

int cheese_no_cut(const vector<Cheese>& cheeses, int max_volume) {
    int n = cheeses.size();
    vector<vector<int>> dp(n + 1, vector<int>(max_volume + 1, 0) );
    // dp[0][max_volume]은 아무 치즈도 고려하지 않는 초기 상태를 나타내므로, 치즈의 수보다 한 행 더 많이 필요합니다.
    // dp[n][0]은 부피 제한이 0인 상태, 즉 아무것도 담을 수 없는 상태를 나타내므로 부피의
    // vector<int>(max_volume + 1, 0) : 각 행의 모든 값을 0으로 초기화합니다. 이는 처음에는 어떤 치즈도 선택하지 않았으며, 따라서 최대 가치는 0이라는 것을 나타냅니다.

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= max_volume; w++) { // w : 부피 제한
            if (cheeses[i - 1].volume <= w) { // cheese[0]은 첫번째 치즈임. 왜냐하면 dp[0][아무값] != cheese[0] 이기에.
                dp[i][w] = max(dp[i - 1][w],         dp[i - 1][w - cheeses[i - 1].volume] + cheeses[i - 1].price); // dp[0][...] 행은 아무 치즈도 고려하지 않는 초기 상태를 의미
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][max_volume];
}

int main() {
    int n, max_volume;
    cin >> n >> max_volume;
    vector<Cheese> cheeses;

    for (int i = 0; i < n; i++) {
        int volume, price;
        cin >> volume >> price;
        cheeses.push_back(Cheese(volume, price));
    }

    cout << "Maximum value of cheese(no cut): " << cheese_no_cut(cheeses, max_volume) << endl;

    return 0;
}

/*

예시 :
치즈 1: 부피 6, 가격 600 / 
치즈 2: 부피 3, 가격 150 / 
치즈 3: 부피 4, 가격 160 / 
치즈 4: 부피 8, 가격 160 / 

치즈 \ 최대 부피  0	 1	 2	 3	 4	  5	  6   7    8  9   10
0 (치즈 없음)	 0	0	0	0	0	 0	 0	 0 	  0	 0	 0
1 (치즈 1~1)	0  0   0   0   0    0   600	600	600	600	600
2 (치즈 1~2)	0	0	0	150	150	150	600	600	600	750	750
3 (치즈 1~3)	0	0	0	150	160	160	600	600	600	750	760
4 (치즈 1~4)	0	0	0	150	160	160	600	600	600	750	760

*/