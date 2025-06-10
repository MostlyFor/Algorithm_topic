#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool is_not_prime[1000001];
vector<long long> arr;
long long n;
long long suf = 0; // 누적된 소인수 개수


void f(vector<long long>& tmp, int idx, int cnt, long long total){
    if(tmp.size() == cnt){
        if(cnt % 2) suf += n / total;
        else suf -= n / total;
        return;
    }
    
    for(int i = idx; i<arr.size(); i++){
        tmp.push_back(i);
        f(tmp, i+1, cnt, total * arr[i]);
        tmp.pop_back();
    }
}

int main(){
    cin >> n;
    long long ori_n = n;
    
    if(n == 1){
        cout << 1 << '\n';
        return 0;
    }
    
    // 문제 : n 이하의 수에서 n과의 서로소의 개수
    // 풀이 : n 을 소인수분해 한 후 집합 연산을 통해 답 도출
    
    // 1. O(n^(1/2))  루트 n 까지 돌면서 소인수 구하기
    // n이 루트 n 보다 큰 소인수를 가지더라도 그 전에 검출됨
    
    for(long long i = 2; i * i <= n; i++){
        if(is_not_prime[i] == true) continue;
        // 만약 소수면 소인수인지 체크
        if(n % i == 0){
            arr.push_back(i);
            while(n % i == 0) n  = n / i;
        }
        
        for(long long j = i; i * j <= 1000001; j++){
            is_not_prime[i * j] = true;
        }
    }
    
    if(n!= 1) arr.push_back(n);

    
    n = ori_n;

    // 2. 전체 개수에서 소인수의 배수 개수 빼기
    // arr개 의개수만큼 중복 세기
    for(int i=1; i<=arr.size(); i++){
        vector<long long> tmp;
        f(tmp, 0, i, 1); 
    }
    
    if(suf == 0) suf++;
    // cout << ori_n << '\n';
    cout << n - suf;

    return 0;
}