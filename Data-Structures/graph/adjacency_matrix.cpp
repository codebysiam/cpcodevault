#include <bits/stdc++.h>
using namespace std;

/* ------------------- Adjacency Matrix ------------------- */
/*
    To work with graphs in programming, we need to represent the
    vertices and the connections between them in a data structure.

    One popular way to represent a graph is an Adjacency Matrix.

    If we have n vertices, we create a 2D array with n rows and
    n columns. The rows and columns represent the vertices, from
    0 to n - 1.

    We construct the adjacency matrix so that:

        adj[u][v] = 1

    means that vertex u and vertex v are connected by an edge.

        adj[u][v] = 0

    means that there is no edge connecting u and v.


    For example, consider this undirected graph:

            0
           / \
          1 - 2
         / \
        3   4


    Its adjacency matrix is:

        | 0 1 2 3 4
    ----------------
      0 | 0 1 1 0 0
      1 | 1 0 1 1 1
      2 | 1 1 0 0 0
      3 | 0 1 0 0 0
      4 | 0 1 0 0 0


    We can see that vertex 1 and vertex 2 are connected.
    Therefore:

        adj[1][2] = 1

    Because this is an undirected graph, vertex 2 is also connected
    to vertex 1. Therefore:

        adj[2][1] = 1

    In general, for an undirected graph:

        adj[u][v] = adj[v][u]

    Therefore, the adjacency matrix of an undirected graph is
    symmetric across its main diagonal.


    For a directed graph, the situation is different.

    Suppose there is a directed edge:

        1 -> 2

    This means there is an edge from vertex 1 to vertex 2, so:

        adj[1][2] = 1

    But there is not necessarily an edge from vertex 2 to vertex 1,
    so:

        adj[2][1] = 0

    Therefore, an adjacency matrix for a directed graph does not
    necessarily have to be symmetric.


    For a graph with n vertices, an adjacency matrix contains n^2
    cells. Therefore, the space complexity is:

        O(V^2)

    where V is the number of vertices.

    An adjacency matrix is particularly useful for dense graphs,
    where many pairs of vertices are connected.

    However, for a sparse graph, where there are relatively few
    edges, an adjacency matrix can waste memory because we still
    have to allocate V^2 cells even when most of them contain 0.

    One advantage of an adjacency matrix is that we can check
    whether an edge exists in O(1) time:

        adj[u][v]

    directly tells us whether vertex u is connected to vertex v.
*/

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);
    // Adjacency matrix of the undirected graph shown above.
    vector<vector<int>> adj = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 0, 0, 0},
    };
    int n = adj.size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(adj[i][j] == 1){
                cout << i << " --- " << j << '\n';
            }
        }
    }
    return 0;
}