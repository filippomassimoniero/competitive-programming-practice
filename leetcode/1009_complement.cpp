#include <bits/stdc++.h>

using namespace std;

int bitwiseComplement(int n) {
    if(n==0) 
        return 1;
    int num_bits = 32 - __builtin_clz(n); // count leading zero
    int mask = (1 << (num_bits)) - 1;
    return (n ^ mask);
}

int main() {
    cout << bitwiseComplement(10) << endl;
    cout << bitwiseComplement(5) << endl;
    cout << bitwiseComplement(7) << endl;
    return 0;
}