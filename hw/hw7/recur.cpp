// undirected graph의 connected component 구하는 algorithm
'''
vertex 갯수만큼의 visited 배열 생성 
하나의 노드에 인접한 k개의 노드 수를 고려한 k번 반복을 통해 graph 생성 - adj
'''
#include <iostream>

using namespace std;

int CC_by_recur(int n, int k, int adj_count, int adj_node);
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n; // node 갯수
        cin >> n;
        int k; // which node number
        cin >> k ; 
        int howmany_adj; // k와 adjacent한 node number - m==0 -> 인접노드가 없는 것
        cin >> howmany_count ; 
        int adj_node;
        cin >> adj_node;
        CC_by_recur();
        
        //출력
        // 1 : 그래프에서 cc의 갯수
        // 2 : 각 cc에서 노드의 갯수
        
    }
}

int CC_by_recur(int n, int k, int adj_count, int adj_node){
    
}

