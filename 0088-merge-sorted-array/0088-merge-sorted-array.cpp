class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // nums1에 m+n개의 원소를 sorting 하기
        // greedy
        // 1. nums2 -> nums1 옮김 O(n)
        // 2. sorting O(N+M log(N+M))
        
        // conditions
        // 1. non-decreasing order
        
        // solution
        // 1. nums1 배열 복사 copy O(M)
        // 2. pointer로 하나씩 옮기기 O(M + N)
        
        // base case
        // nums가 0인 경우
        
        if(m == 0) {
            nums1 = nums2;
            return;
        }
        
        if(n == 0) return;
        
        vector<int> tmp;
        for(int i=0; i<m; i++) tmp.push_back(nums1[i]);
        tmp.push_back(2e9); nums2.push_back(2e9);
        int p1 = 0;
        int p2 = 0;
        int cnt = 0;
        
        // p1 과 p2중 더 작은 값 넣기
        while(p1 < m || p2 < n){
            if(tmp[p1] > nums2[p2])
                nums1[cnt] = nums2[p2++];
            else
                nums1[cnt] = tmp[p1++];
            cnt++;
        }
    }
};