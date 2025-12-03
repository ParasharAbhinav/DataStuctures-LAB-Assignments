// Kruskal's Algorithm
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
 int u, v, w;
 bool operator<(Edge const& other) {
 return w < other.w;
 }
};
int find(int v, vector<int>& parent) {
 if (v == parent[v]) return v;
 return parent[v] = find(parent[v], parent);
}
void unite(int a, int b, vector<int>& parent, vector<int>& rank) {
 a = find(a, parent);
 b = find(b, parent);
 if (a != b) {
 if (rank[a] < rank[b]) swap(a, b);
 parent[b] = a;
 if (rank[a] == rank[b]) rank[a]++;
 }
}
int main() {
 int V = 4;
 vector<Edge> edges = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
 sort(edges.begin(), edges.end());
 vector<int> parent(V), rank(V, 0);
 for (int i = 0; i < V; i++) parent[i] = i;
 int cost = 0;
 cout << "Edges in MST (Kruskal):\n";
 for (auto &e : edges) {
 if (find(e.u, parent) != find(e.v, parent)) {
 cost += e.w;
 cout << e.u << " - " << e.v << " : " << e.w << "\n";
 unite(e.u, e.v, parent, rank);
 }
 }
 cout << "Total cost: " << cost << endl;
 return 0;
}