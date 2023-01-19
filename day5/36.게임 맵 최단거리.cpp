#include <vector>
#include <queue>
using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    queue<int> q;
    
    bool visit[100][100] = {false,};
    
    q.push(0);
    
    int dist = 1;
    while(!q.empty()){
        int n = q.size();
        dist++;
        for(int k=0; k<n; k++){
            int here = q.front(); q.pop();
            int x = here/1000; int y = here%1000;
            
            for(int i=0; i<4; i++){
                int new_x = x+dx[i];
                int new_y = y+dy[i];
                
                if(new_x<0 || new_x>=maps.size() || new_y <0 ||new_y >= maps[0].size()) continue;
                if(maps[new_x][new_y]==0) continue;
                if(visit[new_x][new_y]) continue;
                
                visit[new_x][new_y] = true;
                q.push(new_x * 1000 + new_y);
                
                if(visit[maps.size()-1][maps[0].size()-1]) return dist;
            }
        }
    }
    
    return -1;
}