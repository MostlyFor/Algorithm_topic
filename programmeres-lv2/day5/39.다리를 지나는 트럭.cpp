#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    int wi = 0;
    int wi_car = 0;
    //현재 다리에 있는 차
    int car_in = 0;
    
    vector<int> v(truck_weights.size(), bridge_length);
    
    vector<int> waiting_time(truck_weights.size());
    
    while(wi_car <truck_weights.size()){
        time ++;
        //시간이 다 된 차는 out
        if(v[car_in] == 0) {
            wi -= truck_weights[car_in++];
        }
        

        if(weight >= wi + truck_weights[wi_car]){
            wi += truck_weights[wi_car++];
        }
        
        
        
        for(int i=car_in; i<wi_car; i++)
            v[i]--;
        
    }
    
    return time + bridge_length;
}