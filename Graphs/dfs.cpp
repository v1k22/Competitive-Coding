#include "bits/stdc++.h"
using namespace std;

const int LMT = 1e5;

int edges;
int start_Node;
bool visited[LMT];
vector < int > Node[LMT];

void dfs (int x) {
    if (!visited[x]) {
        visited[x] = true;
        cout << x << " ";
        for (int i = 0; i < Node[x].size(); i++)
            if (!visited[Node[x][i]])
                dfs(Node[x][i]);
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
    dfs(start_Node);
    return 0;
}
