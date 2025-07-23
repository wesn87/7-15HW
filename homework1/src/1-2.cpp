#include <iostream>
#include <stack>
using namespace std;

struct Call {
    int m, n;
    Call(int m_, int n_) : m(m_), n(n_) {}
};

int ackermannNonRecursive(int m, int n) {
    stack<Call> calls;
    calls.push(Call(m, n));
    int result = 0; // 用於儲存最終結果
    while (!calls.empty()) {
        Call current = calls.top();
        calls.pop();
        m = current.m;
        n = current.n;
        if (m == 0) {
            result = n + 1;
            continue;
        }
        if (n == 0) {
            calls.push(Call(m - 1, 1));
            continue;
        }
        calls.push(Call(m - 1, result)); // 儲存當前狀態
        calls.push(Call(m, n - 1));      // 遞歸下一步
    }
    return result;
}

int main() {
    // 測試一些小值
    cout << "A(0, 2) = " << ackermannNonRecursive(0, 2) << endl; // 應為 3
    cout << "A(1, 1) = " << ackermannNonRecursive(1, 1) << endl; // 應為 3
    cout << "A(2, 1) = " << ackermannNonRecursive(2, 1) << endl; // 應為 5
    return 0;
}
