class Solution {
    int r,c;
public:
    bool InRange(int x, int y){
        return 0 <= x && 0<= y && x <r && y<c;
    }
    
    // bc -> board[x][y] == word[cnt] 확인 
//     void bc(int x, int y, int cnt, vector<vector<bool>>& visit, string word, vector<vector<char>>& board){        
//         if(cnt == word.size()) {pos = true; return;}
        
//         for(int dir = 0; dir <4; dir++){
//             if(InRange(x+dx[dir], y+dy[dir]) && visit[x+dx[dir]][y+dy[dir]] == false && board[x+dx[dir]][y+dy[dir]] == word[cnt]){
//                 visit[x+dx[dir]][y+dy[dir]] = 1;
//                 bc(x+dx[dir], y+dy[dir], cnt+1, visit, word, board);
//                 visit[x+dx[dir]][y+dy[dir]] = 0;
//             }
//         }
        
//     }
    
    // board[x][y] == word[cnt]
    bool bc(vector<vector<char>>& board, string word, int x, int y, int cnt){
        if(cnt == word.size()) return true;
        
        // [x][y]가 밖에 있거나, board[x][y] == word[cnt]가 아니라면
        if(InRange(x, y) == false || board[x][y] != word[cnt]) return false;
    
        board[x][y] = '*';        
        
        bool pos = bc(board, word, x+1, y, cnt+1) ||
            bc(board, word, x-1, y, cnt+1) ||
            bc(board, word, x, y+1, cnt+1) ||
            bc(board, word, x, y-1, cnt+1);
        
        board[x][y] = word[cnt];
        
        return pos;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        r = board.size(); c = board[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j] == word[0]){
                    if(bc(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};