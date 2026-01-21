#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<int> roots(25);
    for (int i = 0; i < 25; i++) {
        roots[i] = (i + 1);
    }

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        for(int j = 0; j < n; j++) {
            cout << roots[j];
            if(j < n-1) cout << " "; 
        }
        cout << endl;
        

    }
    return 0;
}