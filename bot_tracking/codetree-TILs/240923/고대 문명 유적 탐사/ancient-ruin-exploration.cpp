#include <iostream>
#include <queue>
#include <tuple>
using namespace std;


int K = 0; // K - 탐사 반복 횟수
int M = 0; // M - 벽면 유물 조각 개수
int board[5][5] = {};
int board_change[5][5] = {};
queue<int> queue_list;
int value = 0; // 해당 턴에서 얻은 점수

void input(){
    cin >> K >> M;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<M; i++){
        int tmp = 0;
        cin >> tmp;
        queue_list.push(tmp);
    }
}

// 회전하면서 얻을 수 있는 점수 계산
void rotate(int i, int j, int k){

    if(!(i == 1 && j ==1 && k ==1)) return;
    // for(int i=0; i<5; i++){
    //     for(int j=0; j<5; j++){
    //         cout << board_change[i][j] << ' ';
    //     }
    //     cout <<'\n';
    // }
    

    // 행렬 복사
    int copy[3][3] = {};

    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            copy[x][y] = board_change[i+x][j+y];
        }
    }

    // for(int i=0; i<3; i++){
    //     for(int j=0; j<3; j++){
    //         cout << copy[i][j] << ' ';
    //     }
    //     cout <<'\n';
    // }
    


    //행렬 회전
    int copy_rotate[3][3] = {};

    for(int cnt =0; cnt <k; cnt++){
        // x,y -> y,2-x
        for(int x=0; x<3; x++){
            for(int y=0; y<3; y++){
                copy_rotate[y][2-x] = copy[x][y];
            }
        }

        for(int x=0; x<3; x++){
            for(int y=0; y<3; y++){
                copy[x][y] = copy_rotate[x][y];
            }
        }
    }

    // for(int i=0; i<3; i++){
    //     for(int j=0; j<3; j++){
    //         cout << copy[i][j] << ' ';
    //     }
    //     cout <<'\n';
    // }


    // 2차원 배열 만들기
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            board_change[i+x][j+y] = copy_rotate[x][y];
        }
    }

    // for(int i=0; i<5; i++){
    //     for(int j=0; j<5; j++){
    //         cout << board_change[i][j] << ' ';
    //     }
    //     cout <<'\n';
    // }
}

// 회전한 행렬 기반 점수 계산
int get_money(){
    
    int money = 0;

    // 인접한 곳 찾기
    int visited[5][5] = {};
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            
            if(visited[i][j]) continue;

            vector<pair<int,int>> group; // 해당 퍼즐과 같은 그룹

            int target = board_change[i][j];
            if(target == 0) continue;

            queue<pair<int,int>> q;
            q.push({i,j});
            visited[i][j] = 1;
            group.push_back({i,j});

            while(q.size()){
                auto h = q.front();
                q.pop();

                for(int dir=0; dir<4; dir++){
                    int nx = h.first + dx[dir];
                    int ny = h.second + dy[dir];

                    //범위를 나간 경우
                    if(0>nx || 0>ny || nx>5 || ny >5) continue;
                    if(visited[nx][ny]) continue;
                    if(board_change[nx][ny] != target) continue;
                    visited[nx][ny] = visited[h.first][h.second]+1;
                    q.push({nx,ny});
                    group.push_back({nx,ny});
                }
            }

            if(group.size()>=3){ 
                money += group.size();

                for(auto g : group){
                    board_change[g.first][g.second] = 0;
                }
            }
        }
    }

    return money;

}




// 1. 탐사 진행 (9 x 3)
tuple<int,int,int,int> explore(){
    // 1-1. 총 27가지 탐사와 얻을 수 있는 점수 계산
    int score[3][3][3] = {}; // 위치 i, j, 각도 k

    priority_queue<tuple<int,int,int,int>> pq;


    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=1; k<=3; k++){

                // 모든 경우의 수 마다 board_change를 바꾸면서 계산
                for(int i=0; i<5; i++){
                    for(int j=0; j<5; j++){
                        board_change[i][j] = board[i][j];
                    }
                }


                //board_change 변경
                rotate(i, j, k);

                // 바뀐 board_change에서 유물을 얼마나 얻는지
                int first_money = get_money();
                
                pq.push(make_tuple(first_money, k,-j,-i));
            }
        }
    }

    // pq에 27가지가 있음   
    auto result = pq.top();
    return result;
}

void keep_explore(int x, int y, int k){

    rotate(x,y,k); // 해당 최대 회전 수행

    int inc = 0;
    inc = get_money();


    while(inc != 0){
        value += inc;

        int cnt = 0;

        //board_change에 0인 부분 채우기
        priority_queue<pair<int,int>> pq_q_list;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(board_change[i][j] == 0){
                    pq_q_list.push({-j,i});
                }
            }
        }

        while(pq_q_list.size()){
            auto qqq = pq_q_list.top();
            pq_q_list.pop();
            board_change[qqq.second][-qqq.first] = queue_list.front();
            queue_list.pop();
        }

        inc = get_money();

    }
    
}

int main() {
    input(); // 입력 받기

    value = 0; // 해당 턴에서 받을 수 있는 이득

    auto res = explore(); // 해당 턴에서 최대 이득을 만들어내는 회전

    // 이제부터 연쇄 탐사
    keep_explore(-get<3>(res), -get<2>(res), get<1>(res));

    cout << value;
    return 0;
}