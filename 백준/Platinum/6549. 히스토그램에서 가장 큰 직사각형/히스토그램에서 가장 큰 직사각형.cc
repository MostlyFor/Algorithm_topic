#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n = 1;


void solve(){
    
    vector<int> arr(n, 0); // 직사각형 높이
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<int> left(n, 0);
    vector<int> right(n ,0);
    
    // 문제 아이디어
    // 정답이 될 직사각형은 어떤 직사각형의 높이를 가지고 있음
    // 그러면 모든 직사각형의 길이만 구해서 최댓값 찾으면 됨
    // O(N)에 풀기 위해서 한 번씩 돌면서 오른쪽, 왼쪽 경계값 찾기
    
    stack<pair<int,int>> st; //  높이, 시작 위치
    for(int i=0; i<n; i++){
        // 높이가 낮아지는 경우
        while(st.size() && arr[i] < st.top().first){
            right[st.top().second] = i;
            st.pop();
        }
        st.push({arr[i], i});
    }
    
    while(st.size()){
        right[st.top().second] = n;
        st.pop();
    }
    
    for(int i=n-1; i>=0; i--){
        // 높이가 낮아지는 경우
        while(st.size() && arr[i] < st.top().first){
            left[st.top().second] = i;
            st.pop();
        }
        st.push({arr[i], i});
    }
    
    while(st.size()){
        left[st.top().second] = -1;
        st.pop();
    }
    
    
    long long ans = 0;
    
    for(int i=0; i<n; i++){
        long long tmp = 1;
        ans = max(ans, tmp * (right[i] - left[i]-1) * arr[i]);
    }
    
    
    cout << ans << '\n';
}


int main(){
    
    while(n){
        cin >> n;
        if(n==0) break;
        solve();
    }
    return 0;
}