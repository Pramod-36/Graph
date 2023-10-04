#include<iostream> 
#include<vector>
#include<queue>
using namespace std;
int main() {
    int nodes, edges;
    cin >> nodes >> edges; 
    vector<vector<int> > adj_list(nodes + 1);
    int node1, node2;
    for(int i = 0; i < nodes; ++i) {
        cin >> node1 >> node2;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }
    vector<int> visited(nodes + 1);
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    vector<int> bfs_route;
    while(!q.empty()) {
        int front = q.front();
        bfs_route.push_back(front);
        q.pop();
        for(int i = 0; i < adj_list[front].size(); ++i) {
            if (!visited[adj_list[front][i]]) {
                q.push(adj_list[front][i]);
                visited[adj_list[front][i]] = 1;
            }
        } 
    }
    for(int i = 0; i < nodes; ++i) {
        cout << bfs_route[i] << " ";     
    }
    return 0;
}