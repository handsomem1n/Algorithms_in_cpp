#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;

void DFS(map<char, vector<char>> &adjacencyList, char start_node) {
    stack<char> s;
    map<char, bool> visited;  // map<노드, 방문한 노드를 추적하는 bool>

    s.push(start_node);

    while (s.empty() == false) {
        char current_node = s.top();
        s.pop();

        if (visited[current_node] == false) {// 현재 노드를 방문하지 않았다면
            cout << current_node << " "; // 방문
            visited[current_node] = true; // 방문하고, 방문 체크

            // 인접 노드를 스택에 추가
            for (char neighbor : adjacencyList[current_node]) { // // 현재 노드의 모든 인접 노드를 순회 
                if (visited[neighbor] == false) { // 방문 안했으면
                    s.push(neighbor); // 꺼낸다.
                }
            }
        }
    }
}


void BFS(map<char, vector<char>> &adjacencyList, char start_node){
    queue<char> q;
    map<char, bool> visited; // map에 visited라는 변수로 조작

    q.push(start_node);
    visited[start_node] = true;

    while(q.empty() == false){ // 빈 게 아니라면(뭐가 차있다면) 계속 반복
        char current_node = q.front();
        q.pop(); // 큐의 맨 앞에 있는 노드를 제거(이 노드는 이미 current_node로 복사되었으므로, 큐에서 더 이상 필요x)

        cout << current_node << " " ;

        for (char neighbor : adjacencyList[current_node]){ // 현재 노드의 모든 인접 노드를 순회 
            if(visited[neighbor] == false){ // 방문안한 것만
                q.push(neighbor); // 넣음
                visited[neighbor] = true; // 넣고, 방문한 것에 대한 체크
            }
        }
    }
}

int main() {
    int total_nodes; // 노드 수
    cin >> total_nodes;
    
    map<char, vector<char>> adjacencyList; // 인접 리스트를 저장하는 map

    for (int i =0 ; i<total_nodes ; i++){
        char node;
        cin >> node;
        
        int adjacent_num_nodes;
        cin >> adjacent_num_nodes;
        for (int j= 0 ; j < adjacent_num_nodes; j++){
            char adjacent_node;
            cin >> adjacent_node;
            adjacencyList[node].push_back(adjacent_node);
            adjacencyList[adjacent_node].push_back(node);
        }
    }
    
    // 인접 리스트 출력
    for (const auto& pair : adjacencyList) {
        cout << pair.first << " -> ";
        for (char neighbor : pair.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    // 스타트 노드 입력
    char start_node;
    cin >> start_node;
    cout << "BFS : " ;
    BFS(adjacencyList, start_node);
    cout << endl;
    cout << "DFS : " ;
    DFS(adjacencyList, start_node);
    cout << endl;   
    return 0;
}
