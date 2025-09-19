#include <bits\stdc++.h>
using namespace std;


int n, u, v;
vector<vector<int>> gr;
vector<bool> used;

void dfs(int u){
    if(used[u] == false){
        used[u] = true;
        for(auto tmp: gr[u]){
            dfs(tmp);
        }
    }
}


int main(){
    cin >> n;
    gr.assign(n, {});
    used.assign(n, false);
    while(cin >> u >> v)
    {
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    dfs(0);
    for(auto tmp: used)
    {
        if(tmp == false){
            cout << "false\n";
            return 0;
        }
    }
    cout << "true\n";
    return 0;
}