#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int a, int b) {
    return uniform_int_distribution<int> (a, b) (rng);
}

int main(void) {
    ofstream out("cdiv.inp");
    int n = randInt(100, 1000);
    out << n << "\n";
    for(int i = 1; i <= n; ++i) {
        out << randInt(10000, 100000) << " ";
    }
}
