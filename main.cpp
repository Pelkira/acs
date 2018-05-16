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
#include "make_graph.cpp"
#define INF 1e+9
using namespace std;
using namespace boost;
typedef adjacency_list<listS, vecS, undirectedS, no_property, property<edge_weight_t, int> > Graph;
typedef pair<int, int> Edge;
typedef graph_traits<Graph>::vertex_descriptor   Vertex;
int dist (Graph g, Vertex from, Vertex to){
    if (from == to)return 0;
    vector<Vertex> parents(num_vertices(g));
    dijkstra_shortest_paths(g, from, predecessor_map(&parents[0]));//幅でも良い
    if (parents[to] == to)return INF;

    int cnt = 0;
    for (Vertex v = to; v != from; v = parents[v]) cnt++;

    return cnt;
}
int dist (Graph g, Vertex vertex, vector<Vertex> query_vertices){
    int max_dist = 0;
    for (int i = 0;i < query_vertices.size();i++){
        max_dist = max(max_dist, dist(g, vertex, query_vertices[i]));
    }
    return max_dist;
}
int dist (Graph h, vector<Vertex> query_vertices){
    int max_dist = 0;
    auto vertex_range = vertices(h);
    for (auto first = vertex_range.first, last = vertex_range.second; first != last; ++first){
        Graph::vertex_descriptor vd = *first;
        Vertex v = get(vertex_index, h, vd);
        max_dist = max(max_dist, dist(h, v, query_vertices));
    }
    return max_dist;
}

int main (){
    Graph g = make_graph();
    vector<Vertex> Vq = {q1h,v4h};
    Vertex u = v7;
    Graph h = make_subgraph();

    print_graph(g, names.c_str());
    cout << dist(h, Vq) << endl;
}