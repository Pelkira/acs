#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <deque>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#define INF 1e+9
using namespace std;
using namespace boost;
typedef int Node;
typedef pair<int, int> Edge;
typedef adjacency_list<listS, vecS, directedS> Graph;
int dist (Graph g, Node from, Node to){
    if (from == to)return 0;
    std::vector<Vertex> parents(num_vertices(g));
    dijkstra_shortest_paths(g, from, predecessor_map(&parents[0]));//幅でも良い
    if (parents[to] == to)return INF;

    int cnt = 0;
    for (Node v = to; v != from; v = parents[v]) cnt++;

    return cnt;
}
int dist (Graph g, vector<Node> query_nodes, Node node){
    int max_dist = 0;
    for (int i = 0;i < query_nodes.size();i++){
        max_dist = max(max_dist, dist(node, query_nodes[i]));
    }
    return max_dist;
}
int main(){
    vector<Edge> edges;
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(2, 3));
    Graph g(edges.begin(), edges.end(), 4);

    print_graph(g);
}