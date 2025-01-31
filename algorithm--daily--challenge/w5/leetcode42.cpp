class Solution {
public:
    int trap(vector<int>& height) {
        int last = height.size()-1;
        int left = 0, right =1;

        int right_max = 0;
        int right_index = 0;
        
        int ans =0;
        
        
        //left가 last가 되거나 크면 끝냄
        while(left < last){
            //누적 블록 넓이
            int bls = 0;
            
            
            int right_max = -1;
            int right_index = 0;
            
            
            
            //자기보다 큰 벽 발견할때까지 전진
            //그 사이에서 넓이 구함
            while(right <= last && height[left] > height[right]){
                bls+=height[right];
                
                //최댓값 갱신
                if(right_max < height[right]){
                    right_max = height[right];
                    right_index = right;
                }
                
                
                right ++;
                
            }
            
            //마지막까지 갔는데 나보다 큰게 없음? 그러면 그나마 그 중에서 가장 큰 값 선택해서 그 위치로 left 값 바꿈
            if(right==last+1){
                height[left] = height[right_index];
                right= left+1;
                continue;
            }
            
            //cout << left << ' ' << right ;
                ans += (right-left-1) * height[left] - bls;
                left = right;
                right++;
            
            
                      
        }
        
        
        
        return ans;
    }
};