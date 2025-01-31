
class NumMatrix {
    int sum[201][201]={0,};
public:
    //시간복잡도 O(RC)
    //sum[c+1][r+1] = (0,0) ~ (c,r)까지의 합
    NumMatrix(vector<vector<int>>& matrix) {
        int c = matrix.size();
        int r = matrix[0].size();
        
        for(int i =0 ; i<c; i++)
            for(int j =0; j<r; j++){
                sum[i+1][j+1] = sum[i][j+1]+sum[i+1][j]-sum[i][j]+matrix[i][j];
            }
    }
    
    
    //시간복잡도 O(1)
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] - sum[row1][col2+1]-sum[row2+1][col1] + sum[row1][col1];
    }
    
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */