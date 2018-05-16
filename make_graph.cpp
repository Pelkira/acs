#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <boost/graph/subgraph.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/copy.hpp>
#define INF 1e+9
using namespace std;
using namespace boost;
typedef adjacency_list<listS, vecS, undirectedS, no_property, property<edge_weight_t, int> > Graph;
typedef pair<int, int> Edge;
typedef graph_traits<Graph>::vertex_descriptor   Vertex;

enum VERTEX_NAME{q1, q2, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10};
const string names = "AB1234567890";

Graph make_graph()
{
    const vector<Edge> edges = {
        {q1, v1},
        {q1, v2},
        {q1, v3}, 
        {q1, v4}, 
        {q1, v5}, 
        {q1, v6}, 
        {q1, v7}, 
        {q1, v8}, 
        {q1, v9}, 
        {q1, v10}, 
        
        {q2, v1}, 
        {q2, v2}, 
        {q2, v3}, 
        {q2, v4}, 
        {q2, v5}, 
        {q2, v6}, 

        {v1, v2}, 
        {v1, v3}, 

        {v2, v3}, 

        {v4, v5}, 
        {v4, v6}, 
        
        {v5, v6}, 
        {v5, v7},

        {v6, v7}, 

        {v8, v9}, 

        {v9, v10}
    };

    // 辺の重みは1
    const std::vector<int> weights(edges.size(), 1);

    return Graph(edges.begin(), edges.end(), weights.begin(), 12);
}
enum {q1h, q2h, v4h, v5h, v6h};
Graph make_subgraph()
{
    const vector<Edge> edges = {
        {q1h, v4h}, 
        {q1h, v5h}, 
        {q1h, v6h}, 

        {q2h, v4h}, 
        {q2h, v5h}, 
        {q2h, v6h}, 

        {v4h, v5h}, 
        {v4h, v6h}, 
        
        {v5h, v6h}, 
    };

    // 辺の重みは1
    const std::vector<int> weights(edges.size(), 1);

    return Graph(edges.begin(), edges.end(), weights.begin(), 4);
}