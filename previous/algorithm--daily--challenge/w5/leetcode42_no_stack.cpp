Runtime: 15 ms, faster than 93.86% of C++ online submissions for Trapping Rain Water.
Memory Usage: 20.7 MB, less than 10.62% of C++ online submissions for Trapping Rain Water.


class Solution {
public:
    int trap(vector<int>& height) {
        
        stack<int> front;
        stack<int> back;
        
        int ans= 0;
        int fp = 0;
        int bp = height.size()-1;
        
        front.push(height[fp++]);
        
        
        int cnt =0;
        int blocks = 0;
        int last_fp = 0;
        //앞에 오르막 처리
        while(fp<=bp){
            int bl = front.top();
            
            //나보다 크거나 같은 애
            if(bl <= height[fp]) {
                front.push(height[fp]);
                last_fp = fp;
                ans += cnt * bl - blocks;
                fp++;
                cnt =0;
                blocks = 0;
                continue;
            }
            blocks += height[fp++];
            cnt ++;
        }
        
        
        //뒤에 내리막 처리
        
        
        back.push(height[bp--]);
        cnt = 0;
        blocks =0;
        while(bp >=last_fp){
            int bl = back.top();
            
            //나보다 크거나 같은 애
            if(bl <= height[bp]){
                back.push(height[bp]);
                ans+=cnt*bl - blocks;
                bp --;
                cnt =0;
                blocks =0;
                continue;
            }
            blocks +=height[bp--];
            cnt ++;
        }
        
        
        return ans;
        
    }
};