#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> powerset(vector<char>& S) {
    vector<vector<char>> result;
    if (S.empty()) {
        result.push_back({});
        return result;
    }
    char x = S[0];
    vector<char> rest(S.begin() + 1, S.end());
    vector<vector<char>> subPowerset = powerset(rest);
    result = subPowerset; // 不包含 x 的子集
    for (const auto& subset : subPowerset) {
        vector<char> newSubset = subset;
        newSubset.push_back(x);
        result.push_back(newSubset); // 包含 x 的子集
    }
    return result;
}

int main() {
    vector<char> S = {'a', 'b', 'c'};
    vector<vector<char>> result = powerset(S);
    for (const auto& subset : result) {
        cout << "{ ";
        for (char c : subset) cout << c << " ";
        cout << "}" << endl;
    }
    return 0;
}
