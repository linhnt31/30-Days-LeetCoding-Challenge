// Time complexity: O(n)... Space complexity: O(n)
class Solution {
public:
    string remove(string s){ // pass by value
        string tmp;
        for(char c : s){
            if(c == '#'){
                if(!tmp.empty()){
                    tmp.pop_back();
                }
            }else{
                tmp += c;
            }
        }
        return tmp;
    }
    bool backspaceCompare(string S, string T) {
        return remove(S) == remove(T);  // require O(n) space 
    }
};

/*
if we want to reduce space complexity to O(1) ---> modify in-place of string S and T. 
*/

//Time complexity: O(n) .... Space complexity: O(1)
class Solution {
public:
    int backspace(string &s){
        int i, j; // j is index of characters that will be modified and it is also length of string after modifying 
        for( i = j = 0 ; i < (int) s.size(); ++i){
            if(s[i] == '#'){
                if(j > 0){
                    j -= 1;
                }
            }else{
                s[j++] = s[i];
            }
        }
        return j;
    }
    bool backspaceCompare(string S, string T) {
        int sLen = backspace(S);
        int tLen = backspace(T);
        
        if(sLen != tLen) return false;
        for(int i = 0; i < sLen; i++){
            if(S[i] != T[i]) return false;
        }
        return true;
    }
};