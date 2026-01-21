#include "bits/stdc++.h"

using namespace std;

int longestPalindrome(string s) {
    int characters[52];
    memset(characters, 0, sizeof(characters));

    for(char &c: s) {
        if(c > 'Z') { //lowercase
            characters[c-'a']++;
        } else {
            characters[26+ c-'A']++;
        }
    }

    bool hasOddNumbers = false;

    int sum = 0;
    for(int &x: characters) {
        if(x % 2 == 1) {
            sum += x-1;
            hasOddNumbers = true;
        } else {
            sum += x;
        }
    }
    if(hasOddNumbers) sum++;
    return sum;
}
