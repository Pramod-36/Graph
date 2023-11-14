/*
direct negative edges
*/ 
#include<iostream> 
#include<vector>
#include<stack>
using namespace std;
void displayAdjacencyList(int nodes, vector<vector<int> > adj_list[]) {
     for(int i = 0; i < nodes; ++i) {
        cout << i << ": ";
        for(int j = 0; j < adj_list[i].size(); ++j) {
            cout << adj_list[i][j][0] << " " << adj_list[i][j][1] << ", ";
        }
        cout << "\n";
    }
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int> > adj_list[nodes];
    for(int i = 0; i < edges; ++i) {
        int node1, node2, cost;
        cin >> node1 >> node2 >> cost;
        vector<int> edge;
        edge.push_back(node2);
        edge.push_back(cost);
        adj_list[node1].push_back(edge); 
    }
    // displayAdjacencyList(nodes, adj_list);
    int source;
    cin >> source;
    vector<int> dist(nodes, 1e8);
    dist[source] = 0;
    stack<int> s;
    s.push(source);
    for(int i = 0; i < nodes - 1; ++i) {
        while(!s.empty()) {
            int top = s.top();
            s.pop();
            for(int j = 0; j < adj_list[top].size(); ++j) {
                if( dist[adj_list[top][j][0]]   > (adj_list[top][j][1] + dist[top])) {
                    dist[adj_list[top][j][0]] =  adj_list[top][j][1] + dist[top];
                    s.push(adj_list[top][j][0]);
                }
            }
        }
    }
    for(int i = 0; i < nodes; ++i) cout << dist[i] << " "; 
    return 0;
}

/*
5 8
0 1 -1
0 2 4
1 2 3
1 3 2
1 4 2 
3 1 1
3 2 5
4 3 -3
0
ans - 0 -1 2 -2 1

5 7
0 1 6
0 2 7
1 3 5
1 4 -4
2 4 9
3 1 -2
4 0 2
0

ans - 0 6 7 11 2
*/