class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //상수형의 공간복잡도 사용인데 오름차순이 추가됨.
        //오름차순이면 내가 탐색을 안해도 되는 부분이 생김.
        
        
        //two pointer : O(N)
        vector<int> ans;
        
        auto left = numbers.begin();
        auto right = numbers.end()-1;
        
        while(*left + *right!=target){
            if(*left + *right>target) right--;
            else if(*left + *right < target) left++; 
        }
        
        
        ans.push_back(left - numbers.begin()+1);
        ans.push_back(right - numbers.begin() +1);
        
        
        return ans;
    
    }
};