#include "bits/stdc++.h"

using namespace std;


class Solution {
public:
    bool isBadVersion(int version) {
        return false;
    }
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;


        while(l <= r) {
            long mid = ((long)l + r) / 2;
            
            if(isBadVersion(mid)) {
                // repeat research in the left part
                r = mid - 1;
            } else {
                // repeat research in the right part
                l = mid + 1;

            }
        }

        return l;
    }
};