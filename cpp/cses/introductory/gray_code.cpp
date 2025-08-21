#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string bits = "";

void increment(int place) {
    bits[place - 1] = (bits[place - 1] == '1') ? '0' : '1';
    cout << bits << "\n";
}

void generate(int n) {
    if (n <= 1) {
        increment(1);
        return;
    }
    
    generate(n - 1);
    increment(n);
    generate(n - 1);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        bits += '0';
    }
    cout << bits << "\n";
    generate(n);
}
