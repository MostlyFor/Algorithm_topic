class Solution {
public:
    int maxProduct(vector<string>& words) {
        // Length는 배열 길이 words.length는 원소 최대 길이
        // 시간 복잡도는 O( Length(words.length + Length*word.length)
        // O(Length*word.length*Length) -> 여기선 10^9임.
        
        // 수도코드
        // 1. 모든 조합 확인
        // 2. i 번째 문자열 알파벳 정보 저장 
        // 3. j 번째 문자열 알파벳 정보 확인하면서 겹치면 끝냄 ( * 근데 여기서 j 번째 문자열 알파벳 정보를 확인했는데 나중에 i에서 또 확인하게 됨 )
        // 3-1. i * j 해서 최대를 만들 수 없다면 넘어감
        
        
        int ans =0;
        
        // 모든 원소 확인
        // length 만큼 소요
        for(int i =0; i<words.size(); i++){
            
            int len1 =words[i].size();
            int abcd[26] = {0,};
            int cnt = 0;
            
            //최대 words.length만큼 소요
            for(auto letter : words[i]){
                //하나씩 다 찼으면 끝냄
                if(cnt==26) break;
                
                //없으면 추가
                if(abcd[letter-'a']==0){
                    abcd[letter-'a']=1;
                    cnt++;
                }
            }
            
            
            //length만큼 소요
            for(int j = i+1; j<words.size(); j++){
                
                bool pass = false;
                
                int len2 = words[j].size();
                
                if(len1 * len2 < ans) continue;
                
                // words.length만큼 소요
                for(auto letter : words[j])
                    //이미 있다면 탐색 종료 후 넘어감
                    if(abcd[letter-'a']!=0){
                        pass= true;
                        break;
                    }
                
                if(pass) continue;
                
                ans = max(ans, len1*len2);
                
                
            }
        }
                
        
        return ans;
    }
};


// 
class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        // 수도코드
        // 1. 비트 정보 저장하는 배열 만듦.
        // 2. 비트 정보에 모든 정보 저장 O(Length * words.length)
        // 3. 비트 정보를 기반으로 모두 확인  O(Length * Length)
        // O (Length * (words.length + Length))
        
        int ans =0;
        int n = words.size();

        vector<int> bit(n,0);


        for(int i = 0; i<n; i++){
            for(auto letter : words[i])
                bit[i] |= 1 << (letter - 'a'); 
        }
        
        for(int i = 0; i<n; i++){
            for(int j =i; j<n; j++){
                if( (bit[i] & bit[j]) == 0){
                    int tmp = words[i].size() * words[j].size();
                    ans = max(ans,tmp);
                }
            }
        }
                
        
        return ans;
    }
};
