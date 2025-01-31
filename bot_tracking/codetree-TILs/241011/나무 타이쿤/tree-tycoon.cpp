#include <iostream>
#include <vector>
using namespace std;

int n, m;
int board[15][15];
int superboard[15][15];
int turn;
int used[15][15];
int d, p; // 이동 방향과 칸 수

int dx[8] = {0,-1,-1,-1, 0, 1,1,1};
int dy[8] = {1, 1, 0,-1,-1,-1,0,1};

void input(){
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> board[i][j];
        }
    }

    superboard[n-1][0] = 1;
    superboard[n-2][0] = 1;
    superboard[n-1][1] = 1;
    superboard[n-2][1] = 1;
}

void super_move(){
    int next_superboard[15][15];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            next_superboard[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(superboard[i][j]){
                int nx = i + p * dx[d];
                int ny = j + p * dy[d];

                nx = (nx + n) % n;
                ny = (ny + n) % n;

                next_superboard[nx][ny] = 1;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            superboard[i][j] = next_superboard[i][j];
        }
    }

}

void test_superboard(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << superboard[i][j] << ' ';
        }
        cout << '\n';
    } cout << '\n';
}

void test_board(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    } cout << '\n';
}

void inject(){

    int next_board[15][15];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            next_board[i][j] = board[i][j];
        }
    }
    // test_superboard();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(superboard[i][j]==1) board[i][j]++;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 해당 땅에 투입

            if(superboard[i][j] ==1){
                used[i][j] = 1;
                superboard[i][j] = 0;
                next_board[i][j]++;

                for(int dir=0; dir<8; dir++){
                    if(dx[dir] * dy[dir] == 0) continue;
                    
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(0 > nx || 0 > ny || n<= nx || n <= ny) continue;
                    if(board[nx][ny] >=1) next_board[i][j]++;
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            board[i][j] = next_board[i][j];
        }
    }
}

void test_used(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << used[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    input();

    while(turn < m){
        turn++;
        cin >> d >> p;
        d--;

        // cout << turn << "번째 관찰" << '\n';
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) used[i][j] = 0;
        }

        // 1, 특수 영양제 이동
        super_move();

        // test_board();

        // test_superboard();

        // 2. 해당 땅에 특수 영양제 투입
        inject();

        // test_board();
        // test_used();

        // 3. 새로운 특수 영양제 투입
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] >= 2 && used[i][j] == 0){
                    board[i][j] -= 2;
                    superboard[i][j] = 1;
                }
            }
        }

        // test_board();
        // test_superboard();
        // test_superboard();
    }


    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            answer += board[i][j];
        }
    }
    cout << answer;

    return 0;
}