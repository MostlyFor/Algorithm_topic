#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    
    int r = board.size();
    int c = board[0].size();
    
    vector<vector<int>> board2(r+1, vector<int>(c+1, 0));
    
    for(int i=0; i<skill.size(); i++){
        int type = skill[i][0];
        int degree = skill[i][5];
        if(type == 1) degree *= -1;
        
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        
        board2[r1][c1] += degree;
        board2[r2+1][c1] += -degree;
        board2[r1][c2+1] += -degree;
        board2[r2+1][c2+1] += degree;
    }
    
    
    
    // 가로줄
    for(int i=0; i<r; i++){
        for(int j=1; j<c; j++){
            board2[i][j] += board2[i][j-1];
        }
    }

    
    // 세로줄
    for(int j=0; j<c; j++){
        for(int i=1; i<r; i++){
            board2[i][j] += board2[i-1][j];
        }
    }
    
    int ans = 0;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j] + board2[i][j] > 0) ans++;
        }
    }
    
    
    return ans;
}