#include<iostream>
#include<vector> 
#include<stack> 
using namespace std;
void displayAdjList(vector<vector<int>> v) {
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int> > adj_list(nodes);
    int node1, node2;
    for(int i = 0; i < edges; ++i) {
        cin >> node1 >> node2;
        adj_list[node1].push_back(node2);
        adj_list[node2].push_back(node1);
    }
  //  displayAdjList(adj_list);
    vector<int> visited(nodes), ans;
    stack<int> stk;
    stk.push(0);
    while(!stk.empty()) {
        int top_node = stk.top();
        stk.pop();
        if(!visited[top_node]) {
            visited[top_node] = 1;
            ans.push_back(top_node);
        }
        for(int i = adj_list[top_node].size() - 1; i >= 0; --i) {
            if(!visited[adj_list[top_node][i]]) {
                stk.push(adj_list[top_node][i]);
            }
        }
    }
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}