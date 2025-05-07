#include <iostream>
#include <climits>
using namespace std;

const int V = 5;

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], minIndex = v;
    return minIndex;
}

void primMST(int graph[V][V]) {
    int parent[V], key[V];
    bool mstSet[V] = {0};

    for (int i = 0; i < V; i++) key[i] = INT_MAX;
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    primMST(graph);
}
// This C++ code implements **Prim's Algorithm** to find the **Minimum Spanning Tree (MST)** of a graph, which is a subset of edges that connects all vertices with the **minimum total weight** and **no cycles**.

// Here's how it works:

// * It starts from the first vertex and **greedily picks the smallest edge** that connects a new vertex not yet in the MST.
// * The `key[]` array keeps track of the **minimum weight edge** to add a vertex.
// * The `parent[]` array stores the final MST structure.
// * The graph is represented using a **2D array (adjacency matrix)**.
// * After building the MST, it prints the edges included and their weights.

// This algorithm ensures all vertices are connected with the **least possible total cost**.
