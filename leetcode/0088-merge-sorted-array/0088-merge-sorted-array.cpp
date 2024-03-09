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
        // 처음부터 옮기면 값이 지워지므로 이를 해결하기 위해 빈공간인 뒤에서부터 채우기! O(m+n)
        
        int p1 = m-1;
        int p2 = n-1;
        int cnt = m+n-1;
        while(p1 >= 0 && p2 >= 0){
            if(nums1[p1] > nums2[p2]){
                nums1[cnt--] = nums1[p1--];
            }
            else{
                nums1[cnt--] = nums2[p2--];
            }
        }

        while(p2 != -1){
            nums1[cnt--] = nums2[p2--];
        }
    }
};