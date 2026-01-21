#include "bits/stdc++.h"

using namespace std;
class Solution {
	public:
	bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<char> vector_s(s.begin(), s.end());
        vector<char> vector_t(t.begin(), t.end());

        sort(vector_s.begin(), vector_s.end());
        sort(vector_t.begin(), vector_t.end());

        for (int i = 0; i < vector_s.size(); i++) {
            if(vector_s[i] != vector_t[i]) return false;
        }
        return true;
    }
};