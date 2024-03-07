class Solution {
    int r,c;
    bool pos;
    vector<vector<char>> board;
    string word;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
public:
    bool InRange(int x, int y){
        return 0 <= x && 0<= y && x <r && y<c;
    }
    
    // board[x][y] == word[cnt] 인지 확인 (현재 시점 확인)
    void bc(int x, int y, int cnt, vector<vector<bool>>& visit){
        if(board[x][y] != word[cnt]) return;
        
        visit[x][y] = true;
        
        cnt++;
        
        if(cnt == word.size()) pos = true;
        
        
        for(int dir = 0; dir <4; dir++){
            if(InRange(x+dx[dir], y+dy[dir]) && visit[x+dx[dir]][y+dy[dir]] == false){
                bc(x+dx[dir], y+dy[dir], cnt, visit);
            }
        }
        visit[x][y] = false;
    }
    
    // bc2 - 미래 시점 확인
    // board[x][y] == word[cnt]
    void bc2(int x, int y, int cnt, vector<vector<bool>>& visit){        
        if(cnt == word.size()) pos = true;
        
        for(int dir = 0; dir <4; dir++){
            if(InRange(x+dx[dir], y+dy[dir]) && visit[x+dx[dir]][y+dy[dir]] == false && board[x+dx[dir]][y+dy[dir]] == word[cnt]){
                visit[x+dx[dir]][y+dy[dir]] = 1;     
                bc2(x+dx[dir], y+dy[dir], cnt+1, visit);
                visit[x+dx[dir]][y+dy[dir]] = 0;
            }
        }
        
    }
    
    bool exist(vector<vector<char>>& board2, string word2) {
        
        r = board2.size();
        c = board2[0].size();
        word = word2;
        
        board.resize(r,vector<char>(c,' '));
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++) board[i][j] = board2[i][j];
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                vector<vector<bool>> visit(r,  vector<bool>(c,0));
                if(board[i][j] == word[0]){
                    visit[i][j] = 1;
                    bc2(i, j, 1, visit);
                    visit[i][j] = 0;
                }
            }
        }
        
        
        return pos;
    }
};