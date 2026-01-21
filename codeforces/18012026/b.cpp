#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        vector<int> arr(n);
        for(int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        sort(arr.begin(), arr.end());
        auto it = unique(arr.begin(), arr.end());
        
        int currSeq = 1;
        int maxSeq = 1;
        for(int i = 0; i < arr.size()-1; i++) {
            // cout << arr[i] << " " << arr[i+1] << endl;
            if(arr[i] == arr[i+1] - 1) {
                currSeq++;
                // cout << currSeq << endl;
            } else {
                maxSeq = max(maxSeq, currSeq);
                currSeq = 1;
            }
        }
        maxSeq = max(maxSeq, currSeq);
        cout << maxSeq << endl;
    }
    return 0;
}