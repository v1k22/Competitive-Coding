#include "bits/stdc++.h"
using namespace std;

stack < int > S1;
stack < int > S2;

void queue_push (int x) {
    S1.push(x);
}

int queue_front () {
    int ret;
    if (S1.size() > 0) {
        vector < int > V;
        while (not S1.empty()) {
            int x = S1.top();
            S1.pop();
            V.push_back(x);
        }
        int L = V.size();
        for (int i = L-1; i >= 0; i--) {
            S1.push(V[i]);    
        }
        ret = V[L-1];
        V.clear();
    } else {
        ret = S2.top();
    }
    return ret;
}

void queue_pop() {
    while (not S1.empty()) {
        int x = S1.top();
        S1.pop();
        S2.push(x);
    }
    if (S2.size() > 0)
        S2.pop();
    else printf("there are no elements in Queue");
}

int queue_size() {
    return S1.size() + S2.size();
}

int main () {
    for (int i = 1; i <= 5; i++)
        queue_push(i);
    queue_pop();
    cout << queue_front() << endl;
    cout << queue_size() << endl;
    return 0;
}
