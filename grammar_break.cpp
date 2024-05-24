#include <iostream>

int main() {
    for (int i = 1; i <= 5; i++) { // 첫 번째 루프
        std::cout << "첫 번째 루프, i = " << i << std::endl;
        for (int p = 1; p <= 3; p++) { // 두 번째 루프
            std::cout << "두 번째 루프, p = " << p << std::endl;
            if (i == 3 && p == 2) {
                break; // 두 번째 루프 종료
            }
        }
    }
    return 0;
}
