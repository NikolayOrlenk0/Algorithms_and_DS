#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid{
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 0},
    {0, 1, 1, 0, 1},
    {0, 1, 0, 1, 0}
};

vector<vector<bool>> used;
queue<pair<int, int>> q;
int cnt = 0;


void bfs(int x, int y)
{
    q.push({x, y});
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        if(grid[p.first][p.second] == 1 && used[p.first][p.second] == false){
            used[p.first][p.second] = true;
            if(p.first > 0){
                q.push({p.first-1, p.second});
            }
            if(p.first < grid.size() - 1){
                q.push({p.first+1, p.second});
            }
            if(p.second > 0){
                q.push({p.first, p.second-1});
            }
            if(p.second < grid[p.first].size()-1){
                q.push({p.first, p.second+1});
            }
        }
    }
    cnt++;
}


int main()
{
    used.assign(grid.size(), vector<bool>(grid[0].size(), false));

    for(size_t i = 0; i < grid.size(); i++)
        for(size_t j = 0; j < grid[i].size(); j++)
            if(grid[i][j] == 1 && !used[i][j]){
                bfs(i, j);
            }
    cout << cnt;
}