#include "bits/stdc++.h"
using namespace std;

const int LMT = 1e4;

int N, edges;
int start_Node;
bool visited[LMT];
vector < int > Node[LMT];

bool dfs_cycle (int x, int parent) {
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < Node[x].size(); i++)
        if (!visited[Node[x][i]]) {
            if (dfs_cycle(Node[x][i], x))
                return true;
        }
        else if (visited[Node[x][i]] && Node[x][i] != parent)
            return true;
    return false;
}

int main () {
    cin >> N >> edges;
    for (int i = 0; i < edges; i++) {
        int x, y;
        cin >> x >> y;
        Node[x].push_back(y);
        Node[y].push_back(x);
    }
    cin >> start_Node;
    if (dfs_cycle(start_Node, -1)) {
        cout << "\nCycle Found" << endl;
    } else {
        cout << "\nNo cycles" << endl;
    }
    return 0;
}
