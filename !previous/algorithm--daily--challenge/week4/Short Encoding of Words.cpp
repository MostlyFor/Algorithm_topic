class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        // 자신의 앞 단어가 자기를 포함하는지 확인
        
        // time m me
        // time#m#
        
        //단어가 끝이랑 맞지 않으면 그냥 무용지물임.
        //단어를 뒤집어서 끝에서 비교하여 같은 그룹을 찾고
        //같은 그룹은 한 #안에 머물 수 있음.
        
        //그 그룹의 개수 + 각 그룹에서 가장 긴 단어들 길이
        
        //모든 단어들을 보면서 그룹을 짓는 방법이 뭘까?
        
        priority_queue<string,vector<string>,greater<string>> dict;
        
        for(auto word : words){
            reverse(word.begin(), word.end());
            dict.push(word);
        }
        
        int group_number=1;
        int ans =0;
        
        while(true){
            string group = dict.top();
            dict.pop();
            
            //만약 마지막 원소였다면 자기 크기 더하고 종료
            if(dict.empty()){
                ans +=group.size();
                break;
            }
            
            //다음 원소가 자신을 포함하는지 확인
            string group_member = dict.top();
            
            //포함됨 -> 같은 그룹
            if(group_member.find(group) == 0) continue;
            
            group_number++;
            ans+=group.size();
            
        }
        
        int last = words[words.size()-1].size();
        
       
      
        return group_number+ans;
        
    }
};