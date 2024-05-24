#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 치즈 정보를 저장할 구조체
struct Cheese {
    int volume;
    int price;
    int value_per_volume;  // 단위 부피당 가치

    Cheese(int v, int p) : volume(v), price(p) {
        value_per_volume = p / v;
    }
};
// 단위 부피당 가치에 따라 내림차순 정렬을 위한 비교 함수
bool compare_cheese(const Cheese &a, const Cheese &b) {
    return a.value_per_volume > b.value_per_volume;
}

int get_max_value_can_cut(vector<Cheese> &cheeses, int max_volume) {
    sort(cheeses.begin(), cheeses.end(), compare_cheese); // 큰순서에서 작은순서로의, 내림차순 정렬

    int total_value = 0;
    for (auto &cheese : cheeses) {
        if (max_volume <= 0){
            break;
        }
        int take_volume = min(cheese.volume, max_volume); // 이 라인은 가져갈 치즈의 부피를 결정합니다. 이는 현재 치즈의 부피와 남은 최대 부피 중 더 작은 값을 선택합니다. 이렇게 하면, 치즈를 부분적으로만 가져갈 수 있고, 남은 부피를 초과하지 않도록 할 수 있습니다.

        total_value = total_value + (take_volume * cheese.value_per_volume); // 고른 치즈의 현재가져간값어치 = 현재가져간값어치 + 가져갈부피 * 부피당가격 
        max_volume -= take_volume; // 훔쳐갈수있는 잔여부피 차감하여 갱신
    }

    return total_value;
}

int get_max_value_cannot_cut(const vector<Cheese>& cheeses, int max_volume) {
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
    int n;
    cin >> n; // n개의 치즈
    vector<Cheese> cheeses;
    
    int max_volume; // 훔칠수있는 가능부피
    cin >> max_volume;

    for (int i = 0; i < n; ++i) {
        int volume, price;
        cin >> volume >> price;
        // cheeses.emplace_back(volume, price);
        cheeses.push_back(Cheese(volume, price));
    }

    int max_value1 = get_max_value_can_cut(cheeses, max_volume);
    cout << "Maximum value of cheese(cut): " << max_value1 << endl;
    int max_value2 = get_max_value_cannot_cut(cheeses, max_volume);
    cout << "Maximum value of cheese(no cut): " << max_value2 << endl;

    return 0;
}
