#include <iostream>
using namespace std;

int ackermann(int m, int n) {
    if (m == 0) return n + 1;
    if (n == 0) return ackermann(m - 1, 1);
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
    // 測試一些小值
    cout << "A(0, 2) = " << ackermann(0, 2) << endl; // 應為 3
    cout << "A(1, 1) = " << ackermann(1, 1) << endl; // 應為 3
    cout << "A(2, 1) = " << ackermann(2, 1) << endl; // 應為 5
    return 0;
}
