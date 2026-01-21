#include "bits/stdc++.h"

using namespace std;

class Solution {
    public:
        bool lemonadeChange(vector<int>& bills) {
            int cont5=0, cont10=0;
            for(auto x : bills) {
                // cout << x << endl;
                if (x == 5) {
                    cont5++;
                } else if (x == 10) {
                    // 10 dollars: we try to give back 5, otherwise we return false
                    if (cont5 > 0) {
                        cont5--;
                        cont10++;
                    }else {
                        return false;
                    }
                } else {
                    // 20 dollars: we try to give back 10 +5, otherwise we try to give back 3*5, otherwise return false
                    if (cont10 > 0 && cont5 > 0) {
                        cont5--;
                        cont10--;
                    } else if (cont5 >= 3){
                        cont5 -= 3;
                    } else {
                        return false;
                    }
                }
            }
            return true;
        }
};


int main (int argc, char *argv[]) {
    Solution s;
    vector<int> bills;
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        int x;
        cin >> x;
        bills.push_back(x);
    }
    cout << s.lemonadeChange(bills);
    return 0;
}
