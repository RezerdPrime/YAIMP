#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    cout << (((2<<n) | (2<<m)) >> 1) << endl;
}
