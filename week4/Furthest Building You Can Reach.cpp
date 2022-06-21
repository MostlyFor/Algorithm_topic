class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        // 사다리를 가장 높은 블록에 쓴다고 가정하자.
        // 그 블록을 넘은 후 상태 (블록개수, 사다리 개수)
        // 1. 사다리 이용 x (n-k, m) 
        // 2. 사다리 이용 o (n, m-1) 
        // 사다리를 이용하지 않은 1번 경우가 언젠가는 처음 사다리를 쓰게 될 것
        // 그 때 (n-k-a1-a2-... , m-1) 이 됨.
        // 이때 2번 경우가 1번과 같은 타이밍에 사다리를 쓴다고 하자.
        // (n-X-a1-a2...,m-1) 상태가 됨. X<=k이므로 사다리를 이용한 쪽이 좀 더 나은 선택을 한것
        // -> 사다리를 사용하자.
        
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