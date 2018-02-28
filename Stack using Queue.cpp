/* basic functions
1. push
2. size
3. pop
4. top
*/

#include "bits/stdc++.h"
using namespace std;

queue < int > Q;

void stack_push (int x) {
    Q.push(x);
}

int stack_top () {
    return Q.back();
}

int stack_size() {
    return Q.size();
}

void stack_pop () {
    if (Q.size() > 0) {
        vector < int > V;
        while (not Q.empty()) {
            int x = Q.front();
            Q.pop();
            V.push_back(x);
        }
        int L = V.size() - 1;
        for (int i = 0; i < L; i++)
            Q.push(V[i]);
    } else {
        printf("No elements in Queue");
    }
}

int main () {
    for (int i = 1; i <= 5; i++)
        stack_push(i);
    cout << stack_size() << endl;
    cout << stack_top() << endl;
    stack_pop();
    cout << stack_top() << endl;
    return 0;
}
