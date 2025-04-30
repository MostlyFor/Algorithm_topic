#include <string>
#include <vector>
#include <iostream>
using namespace std;

int n, m;

// 시계방향 90도 회전
void rotate(vector<vector<int>>& key){
    vector<vector<int>> tmp(m, vector<int>(m, 0));
    
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            tmp[j][m - 1 - i] = key[i][j];
        }
    }
    
    key.swap(tmp);
    
}

bool in_range(int x, int y){
    return 0<=x && 0<=y && x <n && y < n;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    m = key.size();
    n = lock.size();
    
    for(int dir=0; dir<4; dir++){
        
        // key 시작 좌표
        for(int i=-n; i<n; i++){
            for(int j=-n; j<n; j++){
                vector<vector<int>> lock_tmp = lock;
                
                bool is_pos = true; // 가능한지 여부
                
                // key 옮기기
                for(int x=0; x<m; x++){
                    for(int y=0; y<m; y++){
                        if(!in_range(i+x, j+y)) continue; // 범위 나간 경우
                        // 어차피 안되는 경우
                        if(lock_tmp[i+x][j+y] == 1 && key[x][y] == 1) { is_pos = false; break;} 
                        if(lock_tmp[i+x][j+y] == 0 && key[x][y] == 0) { is_pos = false; break;}
                        lock_tmp[i+x][j+y] = 1;
                    }
                }
                
                if(is_pos == false) continue; // 해당 경우 불가능
                
                for(int x=0; x<n; x++){
                    for(int y=0; y<n; y++){
                        if(lock_tmp[x][y] == 0) is_pos = false;
                    }
                }
                
                if(is_pos == false) continue;
                return true;
            }
        }
        
        rotate(key);

    }

    
    return false;
}