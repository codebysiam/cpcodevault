#include <bits/stdc++.h>
using namespace std;

/* ----------------------- Adjacency List ----------------------- */
/*
    An adjacency list represents a graph by storing, for each
    vertex, a list of all vertices directly connected to it.

            0
           / \
          1---2
         / \
        3   4

    For this graph, the adjacency list is:

        0 -> {1, 2}
        1 -> {0, 2, 3, 4}
        2 -> {0, 1}
        3 -> {1}
        4 -> {1}

    Since this is an undirected graph, each edge is stored in
    both directions. For example, the edge (0, 1) appears in
    both adj[0] and adj[1].

    Space complexity: O(V + E), where V is the number of vertices
    and E is the number of edges.

    An adjacency list is generally more space-efficient than an
    adjacency matrix for sparse graphs.
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n = 5;
    vector<vector<int>> adj(n);
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);

    adj[2].push_back(0);
    adj[2].push_back(1);

    adj[3].push_back(1);

    adj[4].push_back(1);

    for(int i = 0; i<n; i++){
        cout << i << " : ";
        for(int &x: adj[i]){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}