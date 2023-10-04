#include<iostream>
#include<vector>

using namespace std;
int main() {
    int nodes, number_of_edges;
    cin >> nodes >> number_of_edges; 
    vector< vector<int> > adj_matrix(nodes + 1); 
    int node1, node2;
    for(int i = 0; i < number_of_edges; ++i) {
        cin >> node1 >> node2;
        adj_matrix[node1].push_back(node2);
        adj_matrix[node2].push_back(node1);
    }
    for(int i = 1; i <= nodes; ++i) {
        cout << i << ": i";
        for(int j = 0; j <  adj_matrix[i].size(); ++j) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}