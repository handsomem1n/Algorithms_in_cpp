#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

using namespace std;


void DFS(map<char, vector<char>> &adjacencyList, char start_node, map<char, bool> &visited) {
    stack<char> s;
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
void find_cc(map<char, vector<char>> &adjacencyList) {
    map<char, bool> visited;
    for (const auto &pair : adjacencyList) {
        if (!visited[pair.first]) {
            DFS(adjacencyList, pair.first, visited);
            cout << endl; // 연결 요소가 끝나면 줄바꿈
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
        if (adjacent_num_nodes != 0) {
            for (int j= 0 ; j < adjacent_num_nodes; j++){
                char adjacent_node;
                cin >> adjacent_node;
                adjacencyList[node].push_back(adjacent_node);
                adjacencyList[adjacent_node].push_back(node);
            }
        }
        else if(adjacent_num_nodes == 0 ){
            continue;
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

    cout << "Connected Components : " << endl;
    find_cc(adjacencyList);

    return 0;
}
