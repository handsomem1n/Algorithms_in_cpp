#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int CC_queue(int start, const vector<vector<int> >& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int cc_count = 0;

    while (q.empty() == false) {
        int node = q.front();
        q.pop();
        cc_count++;

        for (int i = 0; i < graph[node].size(); ++i) {
            int adjNode = graph[node][i];
            if (visited[adjNode]== false) {
                visited[adjNode] = true;
                q.push(adjNode);
            }
        }
    }
    return cc_count;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n; // node 갯수
        cin >> n;
        vector<vector<int> > graph(n + 1);
        vector<bool> visited(n + 1, false);

        for (int i = 1; i <= n; i++) {
            int which_node;
            cin >> which_node;
            int howmany_adj;
            cin >> howmany_adj;
            graph[which_node].resize(howmany_adj);

            for (int j = 0; j < howmany_adj; j++){
                int adj_node;
                cin >> adj_node;
                graph[which_node][j] = adj_node;
            }
        }

        vector<int> component_sizes;
        for (int i = 1; i <= n; ++i) {
            if (visited[i] == false){
                int cc_count = CC_queue(i, graph, visited);
                component_sizes.push_back(cc_count);
            }
        }

        sort(component_sizes.begin(), component_sizes.end());
        cout << component_sizes.size() << " ";
        for (int i = 0; i < component_sizes.size(); i++) {
            cout << component_sizes[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
