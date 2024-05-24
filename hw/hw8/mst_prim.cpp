// 각 노드가 MST에 이미 포함되었는지 여부를 추적 base
/*
idea :
    간선들의 가중치의 합을 계산
    항상 가장 낮은 가중치의 간선을 선택(priority queue 사용)
    가장 가까운 노드를 선택하여 MST에 추가 (among not visited)

        포함되지않았거나 && 현재까지의 smallest 가중치보다 더 가벼운지파악해서 모두충족시 Mst넘김
*/
#include <iostream>

#include <queue>
#include <vector>
#include <functional>
#include <climits> // int_max

using namespace std;

int MST_Prim(int n, vector<pair<int, int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorQ;
    vector<bool> inMST(n + 1, false); // 각 노드가 MST에 이미 포함되었는지 여부를 추적 / false로 초기화하여 아직 MST에 포함되지 않았다고 가정
    vector<int> key(n + 1, INT_MAX);

    // 시작 노드 선택 (1로 가정)
    key[1] = 0;
    priorQ.push({0, 1});

    int weight_sum = 0;

    while (priorQ.empty() == false) // 큐에 아직 처리할 노드가 남아있는 동안 계속함
    {
        int u = priorQ.top().second;
        priorQ.pop();

        if (inMST[u] == true) // 노드 u가 이미 최소 신장 트리(MST)에 포함되어 있을 때
        {
            continue; // 계속
        }

        inMST[u] = true;

        weight_sum += key[u];

        for (int i = 0; i < adj[u].size(); i++)
        {
            int v = adj[u][i].first;
            int weight = adj[u][i].second;

            if (inMST[v] == false && key[v] > weight) // current node V의 mst 구성가능성 파악
            // 포함되지않았거나 && 현재까지의 smallest 가중치보다 더 가벼운지파악해서 모두충족시 Mst
            {
                key[v] = weight;
                priorQ.push({key[v], v});
            }
        }
    }

    return weight_sum;
}

int main()
{
    int t;
    cin >> t;
    int n;
    int k, m, v, w;

    while (t--)
    {
        cin >> n;
        vector<pair<int, int> > adj[n + 1];

        for (int i = 0; i < n; ++i) // 
        {
            cin >> k >> m;
            while (m--)
            {
                cin >> v;
                cin >> w;
                adj[k].push_back({v, w});
                adj[v].push_back({k, w}); // 양쪽에 추가 (undiredtctd이므로)
            }
        }

        cout << MST_Prim(n, adj) << endl;
    }

    return 0;
}
