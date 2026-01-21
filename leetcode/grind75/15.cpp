#include "bits/stdc++.h"

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int letters[26];

    memset(letters, 0, sizeof(letters));

    for (char& c : magazine) {
        letters[c - 'a']++;
    }
    for (char& c : ransomNote) {
        letters[c - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (letters[i] < 0) return false;
    }
    return true;
}

int main(int argc, char const* argv[]) {
	canConstruct("aa", "aab");
	return 0;
}
