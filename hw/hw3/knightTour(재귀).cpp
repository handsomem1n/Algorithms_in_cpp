#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int x, y; // global 선언해서 각 함수 별로 정의 안하게끔
vector<vector<int> > board;
// pair<>는 C++ 표준 library에서 제공하는 클래스 템플릿으로, 두 개의 서로 다른 데이터 요소를 하나의 쌍으로 묶어주는 역할
vector<pair<int, int> > moves = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}}; // 나이트의 가능한 이동 방향을 저장하는 벡터 moves를 선언

bool isInside(int i, int j)
{
    return (i >= 0 && i < x) && (j >= 0 && j < y);
}

bool knightTour(int i, int j, int move_num)
{
    if (move_num == x * y + 1)
    {
        // 모든 셀을 방문했다면 체스판 출력
        for (int r = 0; r < x; r++)
        {
            for (int c = 0; c < y; c++)
            {
                cout << board[r][c] << " ";
            }
            cout << endl;
        }
        return true;
    }

    for (int moveIndex = 0; moveIndex < moves.size(); moveIndex++) // 가능한 모든 이동 방향에 대해 반복합니다. moves.size() = 8
    {
        //.first와 .second는 pair의 요소에 접근할 때 사용되며, 이것은 C++ 표준 라이브러리의 pair 클래스의 일부로 정의된 멤버 변수
        int nextI = i + moves[moveIndex].first; // 현재 위치에서 특정 방향으로 이동했을 때의 다음 위치를 계산
        int nextJ = j + moves[moveIndex].second; // 현재 위치에서 특정 방향으로 이동했을 때의 다음 위치를 계산
        if (isInside(nextI, nextJ) && board[nextI][nextJ] == -1) // 다음 위치 (nextI, nextJ)가 체스판 내에 있고, 아직 방문하지 않은 위치라면 이동 가능. 
        {
            board[nextI][nextJ] = move_num; // 따라서 이동을 시도하고, 해당 위치에 move_num을 할당하여 이동 순서를 기록.
            if (knightTour(nextI, nextJ, move_num + 1)) // 이제 나이트가 다음 위치로 이동한 후에, knightTour 함수를 재귀적으로 호출하여 다음 위치에서 가능한 경로를 탐색. 이때, move_num을 1 증가시켜서 다음 이동 순서를 나타냄. 만약 재귀 호출에서 경로를 찾았다면(true를 반환했다면), 현재 함수도 바로 종료되고 이전 호출 스택으로 반환.
            {
                return true; // 경로를 찾았다면 종료
            }
            board[nextI][nextJ] = -1; // 이동할 수 없거나 경로를 찾지 못한 경우, 이전 위치로 돌아갈 필요가 있습니다. 따라서 다시 -1로 설정하여 해당 위치를 방문하지 않았음을 나타냄
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // int x, y;
        cin >> x >> y; // x는 체스판의 행(row) 수, y는 체스판의 열(column) 수
        int i, j;
        cin >> i >> j; // 시작위치 i : 행, j : 열

        i--; // 코드 내에서 board에 접근할 때 0-based 인덱싱을 사용하되, 사용자는 체스판의 좌표를 1부터 시작하는 방식으로 입력하게 됨.
        j--; // 코드 내에서 board에 접근할 때 0-based 인덱싱을 사용하되, 사용자는 체스판의 좌표를 1부터 시작하는 방식으로 입력하게 됨.

        //vector<int>(g, 5)는 g 크기의 1차원 벡터를 생성하며, 이 벡터의 모든 요소를 5로 초기화하는 코드임.
        board = vector<vector<int> >(x, vector<int>(y, -1));
        board[i][j] = 1; // 첫 번째 움직임

        if (!knightTour(i, j, 2)) // knightTour 함수에는 나이트의 현재 위치 (i, j)와 이동 순서 2를 전달합니다. 이동 순서 2는 이미 첫 번째 움직임을 한 상태를 나타냄
        {
            cout << 0 << endl; // 나이트 투어 경로를 찾지 못한 경우 (즉, knightTour 함수가 false를 반환한 경우) 0을 출력
        }
    }
    return 0;
}
