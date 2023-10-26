#include<iostream> 
#include<vector> 
#include<queue> 
using namespace std;

void displayAdj(vector<vector<int> > adj[], int nodes) {
    for(int i = 0; i < nodes; ++i) {
        cout << i << "-> ";
        for(int j = 0; j < adj[i].size(); ++j) {
            cout << adj[i][j][0] << ": " << adj[i][j][1] << ", ";
        }
        cout << "\n";
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges; 
    vector<vector<int> > adj[nodes];
    for(int i = 0; i < edges; ++i) {
        int node1, node2, dist;
        cin >> node1 >> node2 >> dist;
        vector<int> edge;
        edge.push_back(node2);
        edge.push_back(dist);
        adj[node1].push_back(edge);
        edge.clear();
        edge.push_back(node1);
        edge.push_back(dist);
        adj[node2].push_back(edge);
    }
    // displayAdj(adj, nodes);  
    int source;
    cin >> source;
    vector<int> visited(nodes), d(nodes, INT_MAX); 
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;  
    d[source] = 0;
    pq.push(make_pair(0, source));
    while(!pq.empty()) {
        int top = pq.top().second; 
        pq.pop();
        for(int i = 0; i < adj[top].size(); ++i) {
            int wt = adj[top][i][1];
            int *d_v = &d[adj[top][i][0]]; 
            int d_u = d[top];

            if(*d_v > (d_u + wt)) {
                *d_v = d_u + wt; 
                pq.push(make_pair(*d_v, adj[top][i][0]));
            }
        }
    }

    for(int i = 0; i < nodes; ++i) {
        cout << d[i] << " "; 
    }
    return 0;
} 

/*
5 7
0 1 7
0 2 1
0 3 2
1 2 3
1 3 5 
1 4 1
3 4 7
ans - 0 4 1 2 5
4 5
0 1 5
0 2 8
1 2 9
1 3 2
2 3 6
0
ans - 0 5 8 7 
*/