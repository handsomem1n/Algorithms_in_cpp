#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 치즈 정보를 저장할 구조체
struct Cheese {
    int volume;
    int price;
    int value_per_volume;  // 단위 부피당 가치

    Cheese(int v, int p) : volume(v), price(p) { // 구조체의 constructor(C++에서 생성자(constructor)의 이름은 클래스 또는 구조체의 이름과 동일해야함.) 
        value_per_volume = p / v;
    }
    /*
    Cheese(int v, int p) {
        volume = v;
        price = p;
        value_per_volume = p / v;
    }
    얘처럼 구조체의 생성자를 정의해도 됨. 하지만 이 경우, 멤버 변수의 초기화와 관련된 로직이 생성자 외부로 노출되기 때문에 생성자 초기화 목록을 사용하는 방법보다 좀 더 복잡하고 오류가 발생할 가능성이 높아질 수 있음.
    */
};
// 단위 부피당 가치에 따라 내림차순 정렬을 위한 비교 함수
bool compare_cheese(const Cheese &a, const Cheese &b) {
    return a.value_per_volume > b.value_per_volume;
}

int get_max_value(vector<Cheese> &cheeses, int max_volume) {
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
        cheeses.push_back(Cheese(volume, price)); // 생성자 이름과 객체를 생성할 때 사용되는 클래스 또는 구조체의 이름은 일치해야 함.
    }

    int maxValue = get_max_value(cheeses, max_volume);
    cout << "Maximum value of cheese(cut): " << maxValue << endl;
    

    return 0;
}
