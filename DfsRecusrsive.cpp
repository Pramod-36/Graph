#include<iostream> 
#include<vector>
using namespace std;
vector<int> ans;
void dfs(int curr_node, vector<vector<int>> &adj_list, vector<int> &visited) {
    visited[curr_node] = 1;
    ans.push_back(curr_node);
    for(int i = 0; i < adj_list[curr_node].size(); ++i) {
        if(!visited[adj_list[curr_node][i]]) {
            dfs(adj_list[curr_node][i], adj_list, visited);
        } 
    }
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges; 
    vector<vector<int>> adj_list(nodes);
    int node1, node2;
    for(int i = 0; i < edges; ++i) {
        cin >> node1 >> node2;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }
    vector<int> visited(nodes);
    dfs(0, adj_list, visited);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
} 
