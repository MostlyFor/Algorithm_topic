#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    s = ' ' + s;
    
    for(int i=0; i<s.size(); i++){
        if(s[i]!=' ' && s[i-1]==' '){
            s[i] = toupper(s[i]);
            continue;
        }
        
        s[i] = tolower(s[i]);
        
    }
    
    
    return s.substr(1);
}