class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        //이동할 때 현재까지의 높이가 최대인 블록에 사다리를 쓰지 않고 더 작은 곳에 썼다고 가정하자.
        //만약 가장 큰 곳에 썻다면 현재의 상태가 블록 수가 더 많다. 따라서 무조건 큰 곳에 써야한다.
        
        //어떻게 최대인 걸 바꿀까?
        //순서는 상관없으니 queue를 이용하자.
        
        // 언제까지의 최대인 걸 바꿀까?
        // 현재 벽돌이 모자란 순간에 그 때 까지의 최대를 사다리로 대체하고 남은 벽돌로 현재를 시도하자.
        
         
        priority_queue<int> queue;
        
        
        for(int i=0; i<heights.size()-1;i++){

            int d= heights[i+1]-heights[i];
            
            if(d<0) continue;
            
            bricks-=d;
            queue.push(d);
            
            
            //불가능한 지점 - 최대와 벽돌을 바꿔야 하는 순간
            if(bricks<0){
                int max = queue.top();
                queue.pop();
                cout << bricks <<' '<<max<<' ';
                bricks+=max;
                
                cout << bricks<<endl;
                ladders--;
                if(ladders<0) return i;
            }
        }
        
        
        return heights.size()-1;
    }
};