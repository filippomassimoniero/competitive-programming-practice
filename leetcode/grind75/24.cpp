#include "bits/stdc++.h"

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> alreadySeen;
    
    for(auto &x : nums) {
        if(alreadySeen.find(x) != alreadySeen.end()) {
            return true;
        }
        alreadySeen.insert(x);
    }
    return false;
}