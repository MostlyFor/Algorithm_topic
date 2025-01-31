class Solution {
    vector<vector<string>> ans;
public:
    // 대략 O(3N* N^N)
    void NQ(int n,vector<string> candidate,int available[][9]){
        if(candidate.size()==n){
            ans.push_back(candidate);
            return;
        }
        for(int i=0; i<n; i++){
            int r = candidate.size();

            if(!available[r][i]){
                string tmp(n,'.');
                tmp[i] = 'Q';
                int arr[9][9]={1,};
                
                copy(&available[0][0],&available[0][0]+81,&arr[0][0]);
                
                int k =0;
                //오른쪽 대각선
                while(i+k<n && r+k <n){
                    arr[r+k][i+k] = 1;
                    k++;
                }
                
                k = 0;
                //왼쪽 대각선
                while(i-k>=0 && r+k <n){
                    arr[r+k][i-k] = 1;
                    k++;
                }
                
                k=0;
                //내 아래
                while(r+k <n){
                    arr[r+k][i] = 1;
                    k++;
                }
                
                
                candidate.push_back(tmp);
                
                NQ(n,candidate,arr);
                candidate.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<string>> solveNQueens(int n){
        
        int available[9][9]={0,};
        
        vector<string> candidate;
        
        NQ(n,candidate,available);
        
        return ans;
    }
};

