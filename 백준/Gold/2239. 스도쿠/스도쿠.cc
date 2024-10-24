#include <iostream>
using namespace std;

int board[9][9];

bool solved = false;


bool ch1(int x, int y){
    bool is_pos = true;

    int arr[9] = {0,0,0,0,0,0,0,0,0};
    
    for(int i=0; i<9; i++){
        if(board[x][i]==0) continue;
        if(arr[board[x][i]-1] != 0) is_pos = false;
        else arr[board[x][i]-1] = 1;
    }
 

    return is_pos;
}

bool ch2(int x, int y){
    bool is_pos = true;

    int arr[9] = {0,0,0,0,0,0,0,0,0};
    
    for(int i=0; i<9; i++){
        if(board[i][y] == 0) continue;
        if(arr[board[i][y]-1] != 0) is_pos = false;
        else arr[board[i][y]-1] = 1;
    }

    return is_pos;
}

bool ch3(int x, int y){
    bool is_pos = true;

    int arr[9] = {0,0,0,0,0,0,0,0,0};
    
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[x/3 * 3+i][y/3 *3+j]==0) continue;
            if(arr[board[x/3 * 3+i][y/3 *3+j] -1] != 0) is_pos = false;
            else arr[board[x/3 * 3+i][y/3 * 3+j] -1]=1;
        }
    }

    return is_pos;
}

void check_board(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << board[i][j];
        }        
        cout << '\n';
    }
    cout << '\n';
}

void f(){
    int x = -1;
    int y = -1;
    
    for(int i=8; i>=0; i--){
        for(int j=8; j>=0; j--){
            if(board[i][j] == 0){
                x = i;
                y = j;
            }
        }
    }
    
    if(x==-1 && y==-1){
        solved = true;
    }
    
    if(solved == true) return;
    
    for(int i=1; i<=9; i++){
        board[x][y] = i;
        if(ch1(x,y) && ch2(x,y) && ch3(x,y)){
            f();
            if(solved) return;
        }
        board[x][y] = 0;
    }
    
}




int main(){
    for(int i=0; i<9; i++){
        string tmp; cin >>tmp;
        for(int j=0; j<9; j++){
            board[i][j] = tmp[j]-'0';
        }        
    }
    

    f();
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << board[i][j];
        }        
        cout << '\n';
    }
    
    return 0;
}