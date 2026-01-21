#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<pair<int, bool>> firstRed(n);
        vector<pair<int, bool>> firstBlue(n);
        bool color = false;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            firstRed[i] = {temp, color};
            firstBlue[i] = {temp, !color};

            color = !color;
        }

        sort(firstRed.begin(), firstRed.end());
        sort(firstBlue.begin(), firstBlue.end());

        // Check firstRed
        bool isFirstValid = true;
        for(int i = 0; i < n -1;i++) {
            if(firstRed.at(i).second == firstRed.at(i+1).second) isFirstValid = false;
        }

        bool isSecondValid = true;
        for(int i = 0; i < n -1;i++) {
            if(firstBlue.at(i).second == firstBlue.at(i+1).second) isSecondValid = false;
        }


        cout << ((isFirstValid || isSecondValid) ? "YES" : "NO") << endl;

    }
    return 0;
}