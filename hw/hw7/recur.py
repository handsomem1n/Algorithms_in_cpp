def CC_recur(which_node, graph, visited, cc_count):
    visited[which_node] = True
    cc_count[0] += 1

    for adjNode in graph[which_node]:
        if not visited[adjNode]:
            CC_recur(adjNode, graph, visited, cc_count)

def main():
    t = int(input())
    for case in range(t):
        n = int(input())  # 노드의 개수
        graph = [[] for i in range(n + 1)]
        visited = [False] * (n + 1)

        for i in range(1, n + 1):
            which_node, howmany_adj = map(int, input().split())
            adj_nodes = list(map(int, input().split()))
            graph[which_node] = adj_nodes

        component_sizes = []
        for i in range(1, n + 1):
            if not visited[i]:
                cc_count = [0]
                CC_recur(i, graph, visited, cc_count)
                component_sizes.append(cc_count[0])

        component_sizes.sort()
        print(len(component_sizes), *component_sizes)

if __name__ == "__main__":
    main()
