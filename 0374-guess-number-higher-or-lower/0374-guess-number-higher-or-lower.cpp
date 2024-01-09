/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long st = 0;
        long long ed = n;
        
        while(st+1 != ed){
            long long mid = (st+ed)/2 + 1;
            if(guess(mid) == 0) break;
            if(guess(mid) == 1){ // 숫자를 키워야 함
                st = mid;
            }
            else if(guess(mid) == -1){ // 숫자를 줄여야 함
                ed = mid-1;
            }
        }
        
        return (st+ed)/2 +1;
        
    }
};