#include "bits/stdc++.h"

using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.length() <= 1) return s.length();
    
    unordered_map<char,int> amounts;

    int max_size = 0;
    int curr_size = 0;
    for (int i = 0; i < s.size(); i++) {
        if(amounts[s[i]] == 0) {
            curr_size++;
            amounts[s[i]] = 1;
        } else {
            // remove characters while i don't find the same char
            while(s[i-curr_size] != s[i]) {
                amounts[s[i-curr_size]] = 0;
                curr_size--;
            }
        }

        max_size = max(max_size, curr_size);
    }
    

    return max_size;
    

}