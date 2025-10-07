#include <string>
#include <vector>
#include <iostream>
using namespace std;

int n, m;
vector<string> board;
bool is_erased = false;
int answer = 0; // 지워진 블록 개수 

void erase_2by2(vector<string>& board){
    
    vector<string> board_tmp;
    for(auto s : board) board_tmp.push_back(s);
    
    for(int i=0; i<m-1; i++){
        for(int j=0; j<n-1; j++){
            char ch = board[i][j];
            if(ch == '*') continue;
            if(board[i][j+1]==ch && board[i+1][j] == ch && board[i+1][j+1] == ch){
                board_tmp[i][j] = '*';
                board_tmp[i][j+1] = '*';
                board_tmp[i+1][j+1] = '*';
                board_tmp[i+1][j] = '*';
                is_erased = true;
            }
        }
    }
    
    
    // cout << "######" << '\n';
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout << board_tmp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
    // 중력
    for(int j=0; j<n; j++){
        vector<char> tmp;
        for(int i=m-1; i>=0; i--) 
            if(board_tmp[i][j] != '*') 
                tmp.push_back(board_tmp[i][j]);
        
        
        int k = 0;
        for(int i=m-1; i>=0; i--){
            if(k == tmp.size()) board[i][j] = '*';
            else board[i][j] = tmp[k++];
        }
    }
    
    // cout << "######" << '\n';
    // for(int i=0; i<m; i++){
    //     for(int j=0; j<n; j++){
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    
}



int solution(int M, int N, vector<string> board) {
    m = M;
    n = N;
    // 1,2 반복하기
    while(1){
        // 0. 초기화
        is_erased = false;
        // 1. 쭉 돌면서 2x2 찾기 -> 지워지는 부분 표시
        erase_2by2(board);
        if(is_erased == false) break;
        
    }
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == '*') answer++;
        }
    }
    
    return answer;
}