#include <iostream>
#include <queue>

using namespace std;

int main() {
    int heap, node;
    cin >> heap >> node;
    
    if (node == 0) {
        cout << 0;
        return 0;
    }

    queue<int> q,result;
    q.push(0);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        result.push(cur);

        int lChild = (cur * 2) + 1;
        int rChild = (cur * 2) + 2;

        if (lChild < heap && lChild != node) q.push(lChild);
        if (rChild < heap && rChild != node) q.push(rChild);
    }

    cout << result.size() << endl;
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
}