#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int K, M; // K : 탐사 반복 횟수, M : 벽면 유물 조각 개수
int board[5][5];
int board_cp[5][5];
queue<int> arr; // 벽면 유물 조각
int total;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool InRange(int x, int y){
    return 0<= x && 0<= y && x <5 && y<5;
}

void input(){
    cin >> K >> M;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<M; i++){
        int tmp; cin >> tmp;
        arr.push(tmp);
    }
}

void board_cp_check(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << board_cp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void board_check(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

// 회전 + 유물 
int rotate(int x,int y,int k){
    int money = 0;

    int board_sub[3][3] = {};

    // 해당 회전 계산에 쓰일 board_cp 초기화
    for(int i=0; i<5; i++) for(int j=0; j<5; j++) board_cp[i][j] = board[i][j];
    

    // 행렬 회전
    while(k--){

        // 회전 이전 행렬 copy
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                board_sub[i][j] = board_cp[x+i][y+j];
            }
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                board_cp[x + i][y + j] = board_sub[3-1-j][i];
            }
        }
        
    }


    // 회전 test
    // if(x==1 && y==1)
    //     board_cp_check();
    


    // 회전 후 중복 계산 - bfs로 같이 묶여있는 애들 3개 이상인 경우 해당 블록들 좌표 저장
    vector<pair<int,int>> removed; // 해당 턴에서 같이 묶여있는 애들
    int visited[5][5] = {0,};

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(visited[i][j]) continue;
            
            queue<pair<int,int>> q; // bfs 큐
            vector<pair<int,int>> cache; // 현재 숫자랑 겹치는 애들의 좌표
            int target = board_cp[i][j]; // 같은 숫자여야 함

            q.push({i,j});
            visited[i][j] = 1; // 방문 1번
            cache.push_back({i,j});
            

            while(q.size()){
                auto h = q.front(); q.pop();
                int hx = h.first;
                int hy = h.second;

                for(int dir =0; dir<4; dir++){
                    int nx = hx+dx[dir];
                    int ny = hy+dy[dir];

                    if(!InRange(nx,ny)) continue;
                    if(visited[nx][ny]) continue;
                    if(target != board_cp[nx][ny]) continue;
                    visited[nx][ny] = 1;
                    q.push({nx,ny});
                    cache.push_back({nx,ny});
                }
            }


            // 만약 현재 숫자랑 겹치는 애들이 3개 이상이라면 제거 대상
            if(cache.size() >=3){
                money += cache.size(); // 유물 채워주고

                for(auto c : cache)
                removed.push_back(c); 
            }

        }
    }

    return money;
}




// 유물 탐사 함수
tuple<int,int,int,int> get_money(){

    priority_queue<tuple<int,int,int,int>> pq; // 가장 좋은 조합

    // 회전이 가능한 경우의 수는 총 27개, 이 중 가장 얻을 수 있는 조합을 찾는 것
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=1; k<=3; k++){
                int money = rotate(i, j, k);
                pq.push(make_tuple(money, -k, -j, -i));
            }
        }
    }

    return pq.top();
}

int keep(tuple<int,int,int,int> discovery){
    int x = -get<3>(discovery);
    int y = -get<2>(discovery);
    int k = -get<1>(discovery);

    // 행렬 회전
    while(k--){

        int board_sub[3][3] = {};

        // 회전 이전 행렬 copy
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                board_sub[i][j] = board[x+i][y+j];
            }
        }

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                board[x + i][y + j] = board_sub[3-1-j][i];
            }
        }
    }

    int total_money =0;
    int money =0;

    do{
        money = 0;

        vector<pair<int,int>> removed; // 해당 턴에서 같이 묶여있는 애들
        int visited[5][5] = {0,};

        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(visited[i][j]) continue;
                
                queue<pair<int,int>> q; // bfs 큐
                vector<pair<int,int>> cache; // 현재 숫자랑 겹치는 애들의 좌표
                int target = board[i][j]; // 같은 숫자여야 함

                q.push({i,j});
                visited[i][j] = 1; // 방문 1번
                cache.push_back({i,j});
                

                while(q.size()){
                    auto h = q.front(); q.pop();
                    int hx = h.first;
                    int hy = h.second;

                    for(int dir =0; dir<4; dir++){
                        int nx = hx+dx[dir];
                        int ny = hy+dy[dir];

                        if(!InRange(nx,ny)) continue;
                        if(visited[nx][ny]) continue;
                        if(target != board[nx][ny]) continue;
                        visited[nx][ny] = 1;
                        q.push({nx,ny});
                        cache.push_back({nx,ny});
                        board[nx][ny] = 0;
                    }
                }


                // 만약 현재 숫자랑 겹치는 애들이 3개 이상이라면 제거 대상
                if(cache.size() >=3){
                    total_money += cache.size();
                    money += cache.size();
                    board[cache[0].first][cache[0].second] = 0;
                }

            }
        }

        for(int j=0; j<5; j++){
            for(int i=4; i>=0; i--){
                if(board[i][j]==0){
                    board[i][j] = arr.front(); arr.pop();
                }
            }
        }
        // board_check();
        
    }while(money);

    return total_money;

}


int main(){
   
    input();

    // 각 턴마다 획득한 유물의 가치의 총합을 공백을 두고 출력
    while(K--){
        int total = 0; // 해당 턴에서 얻을 수 있는 유물의 가치의 합

        auto discovery = get_money(); // 유물 탐사

        total += get<0>(discovery);

        // + 탈출 조건 : 만약 해당 턴에서 획득한 유물이 없다면 그냥 종료
        if(total==0) break;

        // 유물 연쇄 탐사
        total =0;
        total += keep(discovery);

        cout << total << ' ';
    }

    return 0;
}