#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    
    // 인접한 풍선 터트리기
    // 기본적으로 더 큰 풍선만 터트리기, <1회> 작은 풍선 터트리기
    
    // 1회 안쓰면 항상 제일 작은 애만 살아남음
    // 문제는 1회로 뭘 터트릴건지 -> 제일 작은 애 
    
    // 안쓰면 항상 구간 별 최솟값
    
    // 마지막엔 두 구간 최솟값끼리의 비교
    
    int n = a.size();
    vector<int> left(n,1e9);
    vector<int> right(n, 1e9);
    
    left[0] = a[0];
    right[n-1] = a[n-1];
    for(int i=1; i<n; i++){
        left[i] = min(left[i-1], a[i]);
    }
    
    for(int i=n-2; i>=0; i--){
        right[i] = min(right[i+1], a[i]);
    }
    
    unordered_map<int,int> hmap;
    
    for(int i=0; i<n; i++){
        hmap[left[i]] = 1;
        hmap[right[i]] = 1;
    }
    
    answer = hmap.size();
    
    
    
    // 최후까지 남을 수 있는 풍선의 수
    return answer;
}