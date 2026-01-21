#include <bits/stdc++.h>
using namespace std;
void printArray(const vector<long long>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << " ";
    }
    cout << "\n";
}

void printArray(const vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << " ";
    }
    cout << "\n";
}

// Your optimized solution
vector<long long> yourSolution(int n, int m, long long h, 
                                vector<long long> original, 
                                vector<pair<int, long long>>& operations) {
    vector<long long> current(n);
    vector<int> lastUpdatedAtQuery(n, -1);
    int lastReset = -1;
    
    for(int j = 0; j < n; j++) {
        current[j] = original[j];
    }
    
    for(int j = 0; j < m; j++) {
        int b = operations[j].first - 1; // Convert to 0-indexed
        long long c = operations[j].second;
        
        if(lastReset > lastUpdatedAtQuery[b]) {
            current[b] = original[b];
        }
        if(current[b] + c > h || original[b] + c > h) {
            // Reset
            // cout << "==============+RESET++++++================"<<endl;
            // cout << "Reset at query " << j+1 << "because curr sum would be " << current[b] + c << "or original sum would be " << original[b] + c  << endl; 

            lastReset = j;
            current[b] = original[b];

            // cout << "Now lastReset is "<< j << endl;
            // cout << "lastUpdatedAtQuery ";printArray(lastUpdatedAtQuery);
            // cout << "current ";printArray(current);
        } else {
            // If this cell is still "dirty"
            if(lastReset > lastUpdatedAtQuery[b]) {
                // cout << "Using old value" << endl;
                current[b] = original[b] + c;
            } else {
                // No reset happened. Just increase 
                current[b] += c;
            }
        }
        lastUpdatedAtQuery[b] = j;
    }
    
    vector<long long> result(n);
    // cout << "Current" << endl;
    // printArray(current);
    for(int k = 0; k < n; k++) {
        if(lastReset > lastUpdatedAtQuery[k]) {
            result[k] = original[k];
        } else {
            result[k] = current[k];
        }
    }
    
    return result;
}

// Brute force solution
vector<long long> bruteForceSolution(int n, int m, long long h, 
                                      vector<long long> original, 
                                      vector<pair<int, long long>>& operations) {
    vector<long long> a = original;
    
    for (int i = 0; i < m; i++) {
        int b = operations[i].first - 1; // Convert to 0-indexed
        long long c = operations[i].second;
        
        // Perform the operation
        a[b] += c;
        
        // Check if any element exceeds h
        bool crash = false;
        for (int j = 0; j < n; j++) {
            if (a[j] > h) {
                crash = true;
                break;
            }
        }
        
        // If crash, reset the entire array to original values
        if (crash) {
            a = original;
        }
    }
    
    return a;
}

// Random test case generator
struct TestCase {
    int n, m;
    long long h;
    vector<long long> original;
    vector<pair<int, long long>> operations;
};

TestCase generateRandomTest(int maxN = 10, int maxM = 10, long long maxH = 100) {
    TestCase tc;
    tc.n = 1 + rand() % maxN;
    tc.m = 1 + rand() % maxM;
    tc.h = 1 + rand() % maxH;
    
    tc.original.resize(tc.n);
    for (int i = 0; i < tc.n; i++) {
        tc.original[i] = rand() % (tc.h + 1);
    }
    
    tc.operations.resize(tc.m);
    for (int i = 0; i < tc.m; i++) {
        tc.operations[i].first = 1 + rand() % tc.n;
        tc.operations[i].second = rand() % (tc.h + 1);
    }
    
    return tc;
}

void printTestCase(const TestCase& tc) {
    cout << "n=" << tc.n << ", m=" << tc.m << ", h=" << tc.h << "\n";
    cout << "original: ";
    for (auto x : tc.original) cout << x << " ";
    cout << "\noperations:\n";
    for (auto [b, c] : tc.operations) {
        cout << "  " << b << " " << c << "\n";
    }
}


int main() {
    srand(963);
    
    cout << "Testing your solution against brute force...\n\n";
    
    int numTests = 100000;
    int failedTests = 0;
    
    for (int test = 1; test <= numTests; test++) {
        TestCase tc = generateRandomTest(200, 200, 1e9);
        
        vector<long long> yourResult = yourSolution(tc.n, tc.m, tc.h, tc.original, tc.operations);
        vector<long long> bruteResult = bruteForceSolution(tc.n, tc.m, tc.h, tc.original, tc.operations);
        
        if (yourResult != bruteResult) {
            failedTests++;
            cout << "❌ COUNTEREXAMPLE FOUND (Test #" << test << "):\n";
            cout << "================================\n";
            printTestCase(tc);
            cout << "\nYour output:        ";
            printArray(yourResult);
            cout << "Brute force output: ";
            printArray(bruteResult);
            cout << "================================\n\n";
            
            if (failedTests >= 5) {
                cout << "Found " << failedTests << " counterexamples. Stopping.\n";
                break;
            }
        } else if (test % 1000 == 0) {
            cout << "✓ Passed " << test << " tests so far...\n";
        }
    }
    
    if (failedTests == 0) {
        cout << "\n✅ All " << numTests << " tests passed! No counterexamples found.\n";
    } else {
        cout << "\n⚠️  Found " << failedTests << " counterexample(s).\n";
    }
    
    return 0;
}