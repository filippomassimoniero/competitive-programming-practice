#include "bits/stdc++.h"

using namespace std;

class Solution {
	public:
	bool isPalindrome(string s) {
        const vector<char> charvect(s.begin(), s.end()); 

        vector<char> clean;
        for (int i = 0; i < charvect.size(); i++) {
            char c = charvect[i];
            if(isalnum(c)) {
                clean.push_back(tolower(c));
            }
            
        }
        
        for (int i = 0; i < clean.size()/2; i++) {
            if(clean[i] != clean[clean.size() - 1 - i]) return false;            
        }
        
        return true;

    }
};