#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Cheese {
    int volume;
    int price;
    Cheese(int v, int p) : volume(v), price(p) {}
};

pair<int, set<int>> cheese_with_combination(const vector<Cheese>& cheeses, int max_volume) {
    int n = cheeses.size();
    vector<vector<int>> dp(n + 1, vector<int>(max_volume + 1, 0));
    vector<vector<bool>> selected(n + 1, vector<bool>(max_volume + 1, false));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= max_volume; w++) {
            if (cheeses[i - 1].volume <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - cheeses[i - 1].volume] + cheeses[i - 1].price);
                if (dp[i][w] == dp[i - 1][w - cheeses[i - 1].volume] + cheeses[i - 1].price) {
                    selected[i][w] = true;
                }
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int max_price = dp[n][max_volume];
    set<int> selected_cheeses;

    // 선택된 치즈 구하기
    int i = n, w = max_volume;
    while (i > 0 && w > 0) {
        if (selected[i][w]) {
            selected_cheeses.insert(i - 1); // 0부터 시작하므로 i에서 1을 뺍니다.
            w -= cheeses[i - 1].volume;
        }
        i--;
    }

    return make_pair(max_price, selected_cheeses);
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

    pair<int, set<int>> result = cheese_with_combination(cheeses, max_volume);
    cout << "Maximum value of cheese(no cut): " << result.first << endl;

    cout << "Selected cheeses: ";
    for (int cheese_index : result.second) {
        cout << cheese_index+1 << " ";
    }
    cout << endl;

    return 0;
}
