#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> gr;
vector<vector<int>> gr_rev;
vector<bool> used;
bool flag = true;
int n, u, v;


void dfs(int p, vector<vector<int>> &graph)
{
    if(used[p] == false)
    {
        used[p] = true;
        for(auto tmp: graph[p])
        {
            dfs(tmp, graph);
        }
    }
}

bool check()
{
    dfs(0, gr);
    for(auto tmp: used)
    {
        if(tmp == false){
            return false;
        }
    }
    used.assign(n, false);
    dfs(0, gr_rev);
    for(auto tmp: used)
    {
        if(tmp == false){
            return false;
        }
    }
    return true;
}


int main()
{
    cin >> n;
    gr.assign(n, {});
    gr_rev.assign(n, {});
    used.assign(n, false);
    while(cin >> u >> v)
    {
        gr[u].push_back(v);
        gr_rev[v].push_back(u);
    }
    if(check() == true)
    {
        cout << "true";
    }
    else{
        cout << "false";
    }
}