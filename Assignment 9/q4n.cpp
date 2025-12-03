#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src) {
 vector<int> dist(V, 1e9);
 dist[src] = 0;
 priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
 pq.push({0, src});
 while (!pq.empty()) {
 int d = pq.top().first;
 int node = pq.top().second;
 pq.pop();
 for (auto it : adj[node]) {
 int next = it.first;
 int weight = it.second;
 if (d + weight < dist[next]) {
 dist[next] = d + weight;
 pq.push({dist[next], next});
 }
 }
 }
 cout << "Vertex\tDistance from Source\n";
 for (int i = 0; i < V; i++)
 cout << i << "\t" << dist[i] << "\n";
}
int main() {
 int V = 5;
 vector<vector<pair<int,int>>> adj(V);
 adj[0] = {{1,2},{2,4}};
 adj[1] = {{2,1},{3,7}};
 adj[2] = {{4,3}};
 adj[3] = {{4,2}};
 dijkstra(V, adj, 0);
 return 0;
}