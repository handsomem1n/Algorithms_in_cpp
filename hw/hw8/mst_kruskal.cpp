/*
idea :
    간선들을 고려하면서(오름차순가중치 /순서대로) 트리에 추가(싸이클을 형성하지 않는 간선만)
핵) 간선추가될때 싸이클을 형성하는지 여부를 판별해야함
    - 동일한 집합에 속하지 않는 경우 - mst에포함 + union()
        두 끝점이 연결되어있는지 파악하는게 핵심 -  find -> merge

Q) undirected? 
*/
#include <iostream>

#include <vector>
#include <utility> // map
#include <algorithm> // sw()

using namespace std;

class union_find {
    vector<int> parent, rank;

public:
    union_find(int n) : parent(n + 1), rank(n + 1, 0) {
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) { // 두 끝점 연결여부 확인  
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void merge(int u, int v) {
        u = find(u);
        
        v = find(v);

        if (u == v) {
            return;
        }
        if (rank[u] > rank[v]) {
            swap(u, v);
        }
        parent[u] = v;
        if (rank[u] == rank[v]) {
            rank[v]++;
        }
    }
};

int MST_Kruskal(int n, const vector<pair<int, pair<int, int> > > &edges) {
    int weight_sum = 0;

    union_find union_find(n);

    vector<pair<int, pair<int, int> > > sorted_edge = edges;
    sort(sorted_edge.begin(), sorted_edge.end());

    for (int i = 0; i < sorted_edge.size(); ++i) {
        int weight = sorted_edge[i].first;
        int u = sorted_edge[i].second.first;
        int v = sorted_edge[i].second.second;

        if (union_find.find(u) != union_find.find(v)) {
            union_find.merge(u, v);
            weight_sum += weight;
        }
    }

    return weight_sum;
}

int main() {
    int t;
    cin >> t;
    int n;
    int k, m, u, v, w;

    while (t--) {
        cin >> n;
        vector<pair<int, pair<int, int> > > edges;

        for (int i = 0; i < n; ++i) {
            cin >> u;
            cin >> m;
            while (m--) {
                cin >> v >> w;
                edges.push_back(make_pair(w, make_pair(u, v)));
            }
        }

        cout << MST_Kruskal(n, edges) << endl;
    }

    return 0;
}
