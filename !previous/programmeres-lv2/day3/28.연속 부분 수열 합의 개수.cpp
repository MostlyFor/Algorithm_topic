#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int size = elements.size();
    set<int> s;
    
    for(int i=0; i<size; i++) elements.push_back(elements[i]);
    
    for(int i=0; i<size; i++){
        int sum = 0;
        for(int j=i; j<i+size; j++){
            sum +=elements[j];
            s.insert(sum);
        }
    } 
    
    
    return s.size();
}