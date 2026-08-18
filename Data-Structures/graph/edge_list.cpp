#include <bits/stdc++.h>
using namespace std;

/* --------------------- Edge List --------------------- */
/*
    An edge list is a way of representing a graph where we
    keep a list of all the edges of the graph.

    If the graph is unweighted, we keep the edge data in
    (vertex1, vertex2) format.

    If the graph is weighted, we keep the edge data in
    (vertex1, vertex2, weight) format.

    Unweighted graph:
            0
           / \
          1 - 2
         / \
        3   4

    Weighted graph:
               2
        0 ---------- 1
        |            |
      3 |            | 4
        |            |
        3 ---------- 2
               5

    The space complexity of an edge list is O(E), where E
    is the number of edges.
*/

struct Edge
{
    int x, y, w;
};


int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    // {vertex1, vertex2}
    cout << "Unweighted Graph: " << '\n';
    vector<pair<int, int>> uw_edge = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {1, 4}
    };

    for(int i = 0; i<uw_edge.size(); i++){
        cout << uw_edge[i].first << " --- " << uw_edge[i].second << '\n';
    }

    cout << "Weighted Graph: " << '\n';
    // {vertex1, vertex2, weight}
    vector<Edge> w_edge = {
        {0, 1, 2},
        {1, 2, 4},
        {2, 3, 5},
        {0, 3, 3}
    };

    for(int i = 0; i<w_edge.size(); i++){
        cout << w_edge[i].x << " -- [" << w_edge[i].w << "] -- " << w_edge[i].y << '\n';
    }

    return 0;
}