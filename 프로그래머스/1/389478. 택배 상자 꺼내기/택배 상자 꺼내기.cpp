#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[100][10];

int solution(int n, int w, int num) {
    
    int cnt = 1;
    
    for(int i=0; i<100; i++){
        if(cnt == n+1) break;
        
        if(i % 2==0){
            for(int j=0; j<w; j++){
                arr[i][j] = cnt++;
                if(cnt == n+1) break;
            }
        }
        else{
            for(int j=w-1; j>=0; j--){
                arr[i][j] = cnt++;
                if(cnt == n+1) break;
            }
        }
    }
    
    int x = 0;
    int y = 0;
    
    for(int i=0; i<100; i++){
        for(int j=0; j<10; j++){
            if(arr[i][j] == num){
                x = i;
                y = j;
            }
        }
    }
    
    int answer = 0;
    while(arr[x][y]){
        answer++;
        x++;
    }
    
    
    return answer;
}