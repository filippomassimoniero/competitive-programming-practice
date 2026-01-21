#include "bits/stdc++.h"

using namespace std;

class Solution {
	public:

    inline int get(string s, int pos) {
        if(pos >= s.length()) return 0;
        return (s[s.length() - 1 - pos] == '0') ? 0 : 1;
    }

	string addBinary(string a, string b) {
        int max_size = max(a.length(), b.length());

        int remainder = 0;
        string res = "";
        res.reserve(max_size);
		for (int i = 0; i < max_size; i++) {
			int a_digit = get(a, i);
			int b_digit = get(b, i);

            int tot = remainder + a_digit + b_digit;

            remainder = (tot >1) ? 1 : 0;
            char c = (tot % 2) + '0';
            res.insert(0, 1, c);
		}
        if(remainder) {
            res = "1" + res;
        }
        return res;
	}
};