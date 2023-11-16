/*
All pairs shortest path
*/  
#include<iostream> 
#include<vector> 
using namespace std;
void display(int nodes, vector<vector<int> > adj_matrix) {
     for(int i = 0; i < nodes; ++i) {
        for(int j = 0; j < nodes; ++j) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int> > adj_matrix(nodes, vector<int>(nodes, 1e8)); 
    for(int i = 0; i < edges; ++i) {
        int node1, node2, cost;
        cin >> node1 >> node2 >> cost; 
        adj_matrix[node1][node2] = cost;
    }
    // display(nodes, adj_matrix); 
    for(int i = 0; i < nodes; ++i) {
        for(int j = 0; j < nodes; ++j) {
            if(i == j) continue;
            for(int k = 0; k < nodes; ++k) {
                if(i == k) continue; 
                if(j == k) {
                    adj_matrix[j][k] = 0; 
                    continue;
                } 
                adj_matrix[j][k] = min(adj_matrix[j][k], adj_matrix[j][i] + adj_matrix[i][k]);
            }
        }
    }
    display(nodes, adj_matrix);
    return 0;
}