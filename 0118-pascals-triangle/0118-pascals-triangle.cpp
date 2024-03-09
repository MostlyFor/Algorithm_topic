class Solution {
public:
    
    
    vector<vector<int>> generate(int numRows) {
        int r = numRows;
        vector<vector<int>> ans;
        vector<int> board(r, 0);
        board[0] = 1;
        
        for(int i=0; i<r; i++){
            vector<int> tmp;
            for(int j=0; j<=i; j++) tmp.push_back(board[j]);
            
            //tmp를 채우기
            for(int j=1; j<=i; j++){
                tmp[j] = board[j] + board[j-1];
            }
            
            for(int j=0; j<=i; j++) board[j] = tmp[j];
            
            // 개수
            ans.push_back(tmp);
        }
        
        
        return ans;
    }
};