#include <bits/stdc++.h>
using namespace std;

int n, u, v;
vector<vector<int>> gr;
vector<int> path;
int startNode, endNode;
int pathCount = 0;

void dfs(int v, vector<bool>& used) {
    path.push_back(v);

    if (v == endNode) {
        pathCount++;
        cout << "P" << pathCount << " = [";
        for (size_t i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i + 1 != path.size()) cout << ", ";
        }
        cout << "]\n";
        path.pop_back();
        return;
    }

    used[v] = true;
    for (int to : gr[v]) {
        if (!used[to]) {
            dfs(to, used);
        }
    }
    used[v] = false;
    path.pop_back();
}

int main() {
    cin >> n;
    cin >> startNode >> endNode;
    gr.assign(n, {});
    vector<bool> used(n, false);

    while(cin >> u >> v){
        gr[u].push_back(v);
    }
    dfs(startNode, used);

    return 0;
}
