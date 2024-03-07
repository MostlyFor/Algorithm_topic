class Solution {
    int r,c;
    bool pos;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    
public:
    bool InRange(int x, int y){
        return 0 <= x && 0<= y && x <r && y<c;
    }
    
    // bc2 - 미래 시점 확인
    // board[x][y] == word[cnt]
    void bc(int x, int y, int cnt, vector<vector<bool>>& visit, string word, vector<vector<char>>& board){        
        if(cnt == word.size()) {pos = true; return;}
        
        for(int dir = 0; dir <4; dir++){
            if(InRange(x+dx[dir], y+dy[dir]) && visit[x+dx[dir]][y+dy[dir]] == false && board[x+dx[dir]][y+dy[dir]] == word[cnt]){
                visit[x+dx[dir]][y+dy[dir]] = 1;
                bc(x+dx[dir], y+dy[dir], cnt+1, visit, word, board);
                visit[x+dx[dir]][y+dy[dir]] = 0;
            }
        }
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        r = board.size();
        c = board[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                vector<vector<bool>> visit(r,  vector<bool>(c,0));
                if(board[i][j] == word[0]){
                    visit[i][j] = 1;
                    bc(i, j, 1, visit, word, board);
                    visit[i][j] = 0;
                }
            }
        }
        
        
        return pos;
    }
};