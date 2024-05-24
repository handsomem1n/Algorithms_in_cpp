// undirected graph의 connected component 구하는 algorithm
/*
2차원 배열로 n+1 x n+1 만들고 adj한 부분만 채움. 나머지는 nulll
vertex 갯수만큼의 visited 배열 false로 채워서 생성 - 방문할때마다 flag로 True -> true되어있으면 재방문X
하나의 노드에 인접한 k개의 노드 수를 고려한 k번 반복을 통해 graph 생성 - adj

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void CC_recur(int which_node, const vector<vector<int> > graph, vector<bool>& visited, int& cc_count) {
    visited[which_node] = true;
    cc_count++;

    for (int i = 0; i < graph[which_node].size(); ++i) {
        int adjNode = graph[which_node][i];
        if (visited[adjNode] == false) {
            CC_recur(adjNode, graph, visited, cc_count);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n; // node 갯수
        cin >> n;
        vector<vector<int> > graph(n + 1); // 숫자 노드가 아닌 문자 노드면 n x n 행렬도 가능
        vector<bool> visited(n + 1, false); 

        for (int i = 1; i <= n; i++) {
            int which_node;
            cin >> which_node;
            int howmany_adj;
            cin >> howmany_adj;
            graph[which_node].resize(howmany_adj);

            for (int j = 1; j <= howmany_adj; j++){
                int adj_node;
                cin >> adj_node;
                graph[which_node][j-1] = adj_node;
            }
        }

        vector<int> component_sizes;
        for (int i = 1; i <= n; ++i) {
            if (visited[i] == false){
                int cc_count = 0;
                CC_recur(i, graph, visited, cc_count);
                component_sizes.push_back(cc_count);
            }
        }

        sort(component_sizes.begin(), component_sizes.end());
        cout << component_sizes.size() << " ";
        for (int i = 1; i <= component_sizes.size(); i++) {
            cout << component_sizes[i-1] << " ";
        }
        cout << endl;
    }

    return 0;
}
