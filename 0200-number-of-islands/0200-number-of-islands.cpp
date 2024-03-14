class Solution {
    int n, m;
    int ans=0;
public:
    bool InRange(int x, int y){
        return 0 <= x && x <n && 0<=y && y<m;
    }
    
    void bfs(vector<vector<char>>& grid, int x, int y){
        ans++;
        queue<pair<int,int>> q;
        q.push({x,y});
        grid[x][y] = '0';
        int dx[4] = {0,0,1,-1};
        int dy[4] = {-1,1,0,0};
        
        while(q.size()){
            auto h = q.front(); q.pop();
            
            for(int dir=0; dir<4; dir++){
                int nx = h.first + dx[dir];
                int ny = h.second + dy[dir];
                
                if(!InRange(nx,ny)) continue;
                if(grid[nx][ny] != '1') continue;
                
                q.push({nx,ny});
                grid[nx][ny] = '0';
            }
        }
        
        return;
    }
    
    
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] =='1') bfs(grid, i, j);
            }
        }
        
        return ans;
    }
};