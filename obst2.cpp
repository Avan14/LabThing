#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int sum(const vector<int>& freq, int i, int j) {
    int total = 0;
    for (int k = i; k <= j; ++k) total += freq[k];
    return total;
}

int optimalBST(const vector<int>& keys, const vector<int>& freq, int n) {
    vector<vector<int>> cost(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) cost[i][i] = freq[i];

    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; ++r) {
                int leftCost = (r > i) ? cost[i][r - 1] : 0;
                int rightCost = (r < j) ? cost[r + 1][j] : 0;
                int totalFreq = sum(freq, i, j);

                int currCost = leftCost + rightCost + totalFreq;
                cost[i][j] = min(cost[i][j], currCost);
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int n;
    cin >> n;

    vector<int> keys(n);
    vector<int> freq(n);

    for (int i = 0; i < n; ++i) cin >> keys[i];
    for (int i = 0; i < n; ++i) cin >> freq[i];

    cout << optimalBST(keys, freq, n) << endl;
    return 0;
}
