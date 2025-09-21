#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> gr{
    {'B', 'C'},
    {'D'},
    {'E'},
    {'F'},
    {},
    {}
};
vector<bool> used;
queue<char> q;
char st, en;

bool bfs(char p)
{
    q.push(p);
    used[p - 'A'] = true;

    while(!q.empty()){
        char t = q.front();
        q.pop();

        if(t == en) return true;

        for(auto tmp: gr[t - 'A']){
            if(!used[tmp - 'A']){
                used[tmp - 'A'] = true;
                q.push(tmp);
            }
        }
    }
    return false;
}

int main()
{
    st = 'A';
    en = 'F';
    used.assign(gr.size(), false);
    if(bfs(st)){
        cout << "True";
    }
    else{
        cout << "False";
    }
    return 0;
}
