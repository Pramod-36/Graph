#include<iostream>
#include<vector>

using namespace std;
int main() {
    int nodes, number_of_edges;
    cin >> nodes >> number_of_edges; 
    vector< vector<int> > adj_matrix(nodes, vector<int>(nodes, 0)); // default 0 (nodes)
    
    int node1, node2;
    for(int i = 0; i < number_of_edges; ++i) {
        cin >> node1 >> node2;
        adj_matrix[node1][node2] = 1;
        adj_matrix[node2][node1] = 1; // For Undirected Graph if its directed we omit this line 
    }
    
    for(int i = 0; i < nodes; ++i) {
        for(int j = 0; j < nodes; ++j) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
input - 1
5 5
1 2
2 3
3 4
4 5
5 1
*/