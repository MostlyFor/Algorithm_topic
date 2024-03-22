#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n;
double m;
int main() {
    cin >> n >> m;
    // 무게 가격 당 가치 계산
    // 가치 높은 순서대로 남은 무게 채워 넣을 수 있으면 더하기
    vector<tuple<double,double,double>> arr;
    for(int i=0; i<n; i++){
        double w,v; cin >> w >> v;
        double k = v / w;
        arr.push_back(make_tuple(-k,w,v));
    }

    sort(arr.begin(), arr.end());
    double ans = 0;
    int idx = 0;
    while(m>0 && idx < arr.size()){
        double value = get<2>(arr[idx]);
        double weight = get<1>(arr[idx]);
        double vpw = get<0>(arr[idx]);
        if(m > weight){
            ans+= value;
            m-= weight;
        }
        else{
            ans+= -vpw * m;
            m =0;
        }
        idx++;
    }
    cout<<fixed;
    cout.precision(3);  
    cout << ans;


    return 0;
}