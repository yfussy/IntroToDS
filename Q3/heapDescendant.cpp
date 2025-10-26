#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, descendant;
    cin >> n >> descendant;

    queue<int> q, result;
    q.push(descendant);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        result.push(cur);

        int lChild = (cur * 2) + 1;
        int rChild = (cur * 2) + 2;

        if (lChild < n) q.push(lChild);
        if (rChild < n) q.push(rChild);
    }

    cout << result.size() << endl;
    while (!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
}