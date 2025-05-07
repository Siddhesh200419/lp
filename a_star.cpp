#include <iostream>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;

const int N = 5;
bool grid[N][N] = {
    {0, 1, 0, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0}
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

struct Node {
    int x, y;
    int g, h;
    Node* parent;
    int f() const { return g + h; }
};

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < N && y < N && grid[x][y] == 0;
}

int heuristic(int x, int y, int tx, int ty) {
    return abs(x - tx) + abs(y - ty);
}

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->f() > b->f();
    }
};

void reconstructPath(Node* end) {
    stack<pair<int, int>> path;
    while (end) {
        path.push({end->x, end->y});
        end = end->parent;
    }
    cout << "Path: ";
    while (!path.empty()) {
        cout << "(" << path.top().first << "," << path.top().second << ") ";
        path.pop();
    }
    cout << endl;
}

void aStar(int sx, int sy, int tx, int ty) {
    bool visited[N][N] = {false};
    priority_queue<Node*, vector<Node*>, Compare> pq;

    Node* start = new Node{sx, sy, 0, heuristic(sx, sy, tx, ty), nullptr};
    pq.push(start);

    while (!pq.empty()) {
        Node* current = pq.top();
        pq.pop();

        if (visited[current->x][current->y]) continue;
        visited[current->x][current->y] = true;

        if (current->x == tx && current->y == ty) {
            reconstructPath(current);
            return;
        }

        for (int d = 0; d < 4; d++) {
            int nx = current->x + dx[d];
            int ny = current->y + dy[d];

            if (isValid(nx, ny) && !visited[nx][ny]) {
                Node* neighbor = new Node{nx, ny, current->g + 1, heuristic(nx, ny, tx, ty), current};
                pq.push(neighbor);
            }
        }
    }

    cout << "No path found." << endl;
}

int main() {
    int startX = 0, startY = 0;
    int targetX = 4, targetY = 4;

    aStar(startX, startY, targetX, targetY);
    return 0;
}



// Imagine you're playing a maze game.

// The computer looks ahead smartly, considering how far you've come and how far the goal is.

// It avoids dead ends and finds the best path.

// Then it shows you how it got to the goal.