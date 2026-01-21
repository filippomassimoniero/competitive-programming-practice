#include <bits/stdc++.h>

using namespace std;

int calculateMexc(vector<int> arr, int from, int to) {   
    // cerr << "Called with" << from << to << endl;
    sort(arr.begin() + from, arr.begin() + to + 1);

    int res = 0;

    for (int i = from; i <= to; i++) {
        if (arr[i] == res) {
            res++;
        } else if (arr[i] > res) {
            return res;
        }
    }
    
    return res;
}

int is_valid(vector<int> v) {
    sort(v.begin(), v.end());
    do {

        bool valid = true;
        for (int i = 0; i < v.size()-1 && valid; i++) {
            int left = calculateMexc(v,0,i);
            int right = calculateMexc(v,i+1,v.size()-1);

            if(left == right) valid = false;
        }

        if(valid) {
            for (auto i: v) cout << i << " ";
        }
        cout << ((valid)?"Y":"N") << endl;
        if(valid) return 1;
        
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cerr << "TESTCASE #" << i << endl;
        int n;
        cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            arr[i] = temp;
        }

        is_valid(arr);
    }
    return 0;
}