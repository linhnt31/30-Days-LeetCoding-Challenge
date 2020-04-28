#include <bits/stdc++.h>

using namespace std;

//Example 1:
//Let us consider string S. You are required to count the frequency of all the characters in this string.
int freq[26];
int hashFunc(char c){
    return (c - 'a');
}
void countFreq(string s){
    for(int i = 0 ; i < s.size(); i++){
        int index = hashFunc(s[i]);
        freq[index]++;
    }
    for(int i = 0 ; i < 26; ++i){
        cout << (char)(i + 'a') << "\t" << freq[i] << endl;
    }
}
int main()
{
    countFreq("abcsdz");
    return 0;
}
