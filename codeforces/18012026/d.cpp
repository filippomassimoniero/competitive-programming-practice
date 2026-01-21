#include <bits/stdc++.h>

using namespace std;


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, h;
        cin >> n >> m >> h;
        
        vector<int> original(n);
        vector<int> lastUpdatedAtQuery(n, -1);
        vector<int> current(n);

        int lastReset = -1;
        for(int j = 0; j < n; j++) {
            cin >> original[j];
            current[j] = original[j];
        }

        for(int j = 0; j < m; j++) {
            int b,c;

            cin >> b >> c;
            b = b-1;
            if(lastReset > lastUpdatedAtQuery[b]) {
                current[b] = original[b];
            }
            if(current[b] + c > h || original[b] + c > h) {
                //reset
                lastReset = j;
                current[b] = original[b];
            } else {
                // if this cell is still "dirty"
                if(lastReset > lastUpdatedAtQuery[b]) {
                    current[b] = original[b] + c;
                } else {
                    // no reset happened. Just increase 
                    current[b] += c;
                }
            }
                lastUpdatedAtQuery[b] = j;


            
            }

        for(int k = 0; k < n; k++) {
            if(lastReset > lastUpdatedAtQuery[k]) {
                cout << original[k] ;
            } else {
                cout << current[k];
            }
            if(k < n-1) cout << " "; 
        }
        cout << endl;

    }
    return 0;
}