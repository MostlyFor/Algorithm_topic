class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //문자열이 주어졌을 때 k개의 0과 1의 조합 2^k개를 모두 포함하고 있는지 확인하는 문제
        
        //1. 인덱스 0 부터 가능한 범위까지 k개를 확인한다. (이때 윈도우를 이용)
            //1-1. k개를 set을 이용해서 추가한다.
        //2. set의 개수가 2^k개면 모든 조합이 있다.
        
        // 시간 복잡도 O(Nlog N) 
        
        set<string> combination;
        
        string window = "";
        
        //처음
        window = s.substr(0,k);
        combination.insert(window);
        
        for(int right=k; right < s.size(); right++){
            window.erase(0, 1);
            
            window+=s[right];
            
            combination.insert(window);
            
            if(combination.size() == 1 << k) return true;
        }
            
        
        
        return false;
    }
};


class Solution {
public:
    bool hasAllCodes(string s, int k) {
        //문자열이 주어졌을 때 k개의 0과 1의 조합 2^k개를 모두 포함하고 있는지 확인하는 문제
        
        //1. 인덱스 0 부터 가능한 범위까지 k개를 확인한다. (이때 윈도우를 이용)
            //1-1. k개를 set을 이용해서 추가한다.
        //2. set의 개수가 2^k개면 모든 조합이 있다.
       
        // 굳이 정렬하는데 시간을 쓸 필요가 없으므로 O(N)
        
        unordered_set<string> combination;
        
        string window = "";
        
        //처음
        window = s.substr(0,k);
        combination.insert(window);
        
        for(int right=k; right < s.size(); right++){
            window.erase(0, 1);
            
            window+=s[right];
            
            combination.insert(window);
            
            if(combination.size() == 1 << k) return true;
        }
            
        
        
        return false;
    }
};

