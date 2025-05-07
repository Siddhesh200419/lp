#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 100; // maximum number of vertices
vector<int> adj[MAX]; // adjacency list
bool visited[MAX];    // visited array

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // because undirected
}

// Recursive DFS
void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

// Iterative BFS
void bfs(int start) {
    
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    // Create a simple graph
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 5);
    addEdge(2, 6);

    cout << "DFS starting from node 0: ";
    fill(visited, visited + MAX, false); // reset before DFS
    dfs(0);
    
    fill(visited, visited + MAX, false); // reset visited array
    cout << "\nBFS starting from node 0: ";
    bfs(0);

    return 0;
}
