class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 0이 세 개인 경우 -> 그냥 0의 개수를 알면 조합 쓰면 됨
        // 0이 한 개인 경우 -> 양수쪽 한번씩 돋면서 같은거 있나 찾으면 됨 n lg n
        // 0이 0개인 경우 -> 음수 2개를 찾아서 양수에 있는지 확인하면 됨 n^2 lg n
        vector<int> pos;
        vector<int> neg;
        map<int,int> neg_dict;
        map<int,int> pos_dict;
        int zero_cnt = 0;

        for(auto num : nums){
            if(num > 0){
                pos.push_back(num);
                pos_dict[num]++;
            }
            else if(num < 0){
                neg.push_back(num);
                neg_dict[num]++;
            }
            else
                zero_cnt++;
        }
        
        vector<vector<int>> ans;
        // 0이 세 개인 경우
        if(zero_cnt >= 3) ans.push_back(vector<int>(3,0));

        // 0이 한 개인 경우 (N^2)
        if(zero_cnt >= 1){
            // pos랑 neg랑 같은 값이 있는지 확인
            for(int i=0; i<pos.size(); i++){
                for(int j=0; j<neg.size(); j++){
                    if(pos[i] + neg[j] == 0){
                        vector<int> tmp;
                        tmp.push_back(neg[j]);
                        tmp.push_back(0);
                        tmp.push_back(pos[i]);
                        ans.push_back(tmp);
                    }
                }
            }
        }
        
        
        // 0 이 하나도 없는 경우
        for(int i=0; i<pos.size(); i++){
            for(int j=i+1; j<pos.size(); j++){
                if(neg_dict[-1 * (pos[i] + pos[j])]!=0){
                    vector<int> tmp;
                    tmp.push_back(pos[i]);
                    tmp.push_back(pos[j]);
                    tmp.push_back(-1 * (pos[i] + pos[j]));
                    sort(tmp.begin(), tmp.end());
                    ans.push_back(tmp);
                }
            }
        }
        
        for(int i=0; i<neg.size(); i++){
            for(int j=i+1; j<neg.size(); j++){
                if(pos_dict[-1 * (neg[i] + neg[j])]!=0){
                    vector<int> tmp;
                    tmp.push_back(neg[i]);
                    tmp.push_back(neg[j]);
                    tmp.push_back(-1 * (neg[i] + neg[j]));
                    sort(tmp.begin(), tmp.end());
                    ans.push_back(tmp);
                }
            }
        }
        
        set<vector<int>> s;
        for(auto v : ans){
            s.insert(v);
        }
        
        vector<vector<int>> rans;
        for(auto v : s){
            rans.push_back(v);
        }
        
        return rans;
    }
};

