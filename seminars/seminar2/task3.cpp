#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> gr{
    {1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1}
};
vector<vector<int>> dist;
queue<pair<int,int>> q;
pair st {1, 1};
pair en {4, 4};

void bfs(pair<int, int> s)
{
    q.push({s.first, s.second});
    while(!q.empty()){
        cout << "kekw\n";
        auto v = q.front();
        q.pop();
        for(int dx = -1; dx <= 1; dx++)
            for(int dy = -1; dy <= 1; dy++)
            {
                cout << dx << " " << dy << "\n";
                if(abs(dx) != abs(dy) && gr[v.first+dx][v.second+dy] == 0 && dist[v.first+dx][v.second+dy] > dist[v.first][v.second] + 1)
                {
                    dist[v.first+dx][v.second+dy] = dist[v.first][v.second] + 1;
                    cout << v.first << " " << v.second << dist[v.first][v.second] << "\n";
                    q.push({v.first+dx, v.second+dy});
                }
            }
    }
}

int main()
{
    dist.assign(gr.size(), vector<int>(gr[0].size(), 9999));
    dist[st.first][st.second] = 0;
    bfs(st);
    if(dist[en.first][en.second] == 9999){
        cout << "-1";
    }
    else{
        cout << dist[en.first][en.second];
    }
    return 0;
}