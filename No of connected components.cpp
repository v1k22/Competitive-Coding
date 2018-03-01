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
    int connected_components = 0;
    // 13 Nodes
    for (int i = 1; i <= 13; i++) {
        if (visited[i] == false) {
            dfs(i);
            connected_components += 1;
        }
    }
    cout << "connected_components = ";
    cout << connected_components << endl;
    return 0;
}
