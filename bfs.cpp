#include "bits/stdc++.h"
using namespace std;

const int LMT = 1e5;

int edges;
int start_Node;
bool visited[LMT];
vector < int > Node[LMT];
queue < int > Q;

void bfs (int x) {
    Q.push(x);
    visited[x] = true;
    while (!Q.empty()) {
        int x = Q.front();
        cout << x << " ";
        Q.pop();
        for (int i = 0; i < Node[x].size(); i++) {
            if (!visited[Node[x][i]]) {
                visited[Node[x][i]] = 1;
                Q.push(Node[x][i]);
            }
        }
    }
}

int main () {
    cin >> edges;
    for (int i = 0; i < edges; i++) {
        int x, y;
        cin >> x >> y;
        Node[x].push_back(y);
        Node[y].push_back(x);
    }
    cin >> start_Node;
    bfs(start_Node);
    return 0;
}
