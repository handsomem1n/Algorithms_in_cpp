#include <iostream>
#include <algorithm>
#include <stack> // stack
#include <vector>

using namespace std;

int dfs_number, child, root, bcc_count;

vector<vector<int>> adj_list;
vector<bool> articulation_vertex;
vector<int> dfs_low, dfs_num, parent;
stack<pair<int, int>> S;

void articulation_point_bridge(int cur_node)
{
    dfs_low[cur_node] = dfs_num[cur_node] = dfs_number++;
    for (int j = 0; j < adj_list[cur_node].size(); j++)
    {
        int adj_u = adj_list[cur_node][j];

        if (dfs_num[adj_u] == -1)
        {
            parent[adj_u] = cur_node;
            if (cur_node == root)
            {
                child++;
            }

            S.push(make_pair(cur_node, adj_u));
            articulation_point_bridge(adj_u);

            if (dfs_low[adj_u] >= dfs_num[cur_node])
            {
                if (cur_node != root || child > 1)
                {
                    articulation_vertex[cur_node] = true;
                }

                // 추출하는 과정에서 새로운 BCC가 완성됨
                bcc_count++;
                while (S.empty() == false && S.top() != make_pair(cur_node, adj_u))
                {
                    S.pop();
                }
                S.pop();
            }
            dfs_low[cur_node] = min(dfs_low[cur_node], dfs_low[adj_u]);
        }
        else if (adj_u != parent[cur_node])
        {
            dfs_low[cur_node] = min(dfs_low[cur_node], dfs_num[adj_u]);
            if (dfs_num[adj_u] < dfs_num[cur_node])
            {
                S.push(make_pair(cur_node, adj_u));
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        adj_list.assign(n + 1, vector<int>());
        parent.assign(n + 1, -1); //
        dfs_num.assign(n + 1, -1);
        dfs_low.assign(n + 1, 0);

        articulation_vertex.assign(n + 1, false);
        bcc_count = 0;
        dfs_number = 0;

        for (int i = 1; i <= n; i++)
        {
            int cur_node;
            int adj_node;
            cin >> cur_node;
            cin >> adj_node;
            while (adj_node--)
            {
                int adj_u;
                cin >> adj_u;
                adj_list[cur_node].push_back(adj_u);
            }
        }

        vector<int> articulation_points;
        for (int i = 1; i <= n; i++)
        {
            if (dfs_num[i] == -1)
            {
                child = 0;
                root = i;
                articulation_point_bridge(i);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (articulation_vertex[i])
            {
                articulation_points.push_back(i);
            }
        }

        cout << bcc_count << endl;

        sort(articulation_points.begin(), articulation_points.end());
        cout << articulation_points.size() << " ";
        for (int i = 0; i < articulation_points.size(); i++)
        {
            cout << articulation_points[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
