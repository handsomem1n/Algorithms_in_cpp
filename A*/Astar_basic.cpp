#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

// 각 노드의 좌표를 나타내는 구조체
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

// 각 노드의 정보를 나타내는 구조체
struct Node {
    Point point;
    int f, g, h; // f = g + h
    Node* parent;

    Node(Point _point, int _g, int _h, Node* _parent)
        : point(_point), g(_g), h(_h), f(_g + _h), parent(_parent) {}
};

// 비교 함수 정의 (우선순위 큐에서 사용)
struct CompareNode {
    bool operator()(const Node* a, const Node* b) {
        return a->f > b->f;
    }
};

// A* algorithm
vector<Point> astar(vector<vector<int>>& grid, Point start, Point goal) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<bool>> visited(rows, vector<bool>(cols, false)); // 방문 여부 체크
    Node* startNode = new Node(start, 0, 0, nullptr); // 스타트 노드
    // open 리스트(priority queuee)
    priority_queue<Node*, vector<Node*>, CompareNode> openList;
    openList.push(startNode);
    // 이웃 노드의 상대 좌표
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    while (!openList.empty()) {
        // 현재 노드 선택
        Node* current = openList.top();
        openList.pop();
        // 목표에 도달하면 경로 반환
        if (current->point.x == goal.x && current->point.y == goal.y) {
            vector<Point> path;
            while (current != nullptr) {
                path.push_back(current->point);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }
        visited[current->point.x][current->point.y] = true; // 방문 체크
        
        // adjacent node 탐색
        for (int i = 0; i < 4; ++i) {
            int nx = current->point.x + dx[i];
            int ny = current->point.y + dy[i];
            
            if ((nx >= 0 && nx < rows) && (ny >= 0 && ny < cols) && !visited[nx][ny] && grid[nx][ny] == 0) { // 유효 범위 : 
                int g = current->g + 1;
                int h = abs(nx - goal.x) + abs(ny - goal.y);
                Node* neighbor = new Node(Point(nx, ny), g, h, current);
                openList.push(neighbor);// open 리스트에 추가
            }
        }
    }
    
    return vector<Point>(); // 도착 불가능할때 빈벡터 반환
}
int main() {
    // 예제 그리드 생성 (0은 통로, 1은 벽)
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    // 시작점과 목표점 설정
    Point start(0, 0);
    Point goal(4, 4);

    // A* 알고리즘 호출
    vector<Point> path = astar(grid, start, goal);

    // 결과 출력
    if (path.empty()) {
        cout << "경로를 찾을 수 없습니다." << endl;
    } else {
        cout << "최단 경로:" << endl;
        for (const Point& p : path) {
            cout << "(" << p.x << ", " << p.y << ") ";
        }
        cout << endl;
    }

    return 0;
}
