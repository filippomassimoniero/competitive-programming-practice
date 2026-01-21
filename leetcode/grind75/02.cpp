#include "bits/stdc++.h"

using namespace std;

class Solution {
	public:
	bool isValid(string s) {
		stack<char> myStack;
		myStack.push(s[0]);
		for (int i = 1; i < s.length(); i++) {
            char c = s[i];
			cout << c << endl;

			if (c == '(' || c == '[' || c == '{') {
				myStack.push(c);
			} else {
                if(myStack.size() == 0) return false;
    			char prev = myStack.top();
    			cout << "PREV" << prev << endl;
                // closing bracket. If it is the wrong type we need to return false
                if(abs(c - prev) > 2 || abs(c - prev) == 0) {
                    return false;
                }
                myStack.pop();
			}
		}

		return myStack.size() == 0;
	}
};