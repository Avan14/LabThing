#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int sum(const vector<int>& freq, int i, int j) {
    int total = 0;
    for (int k = i; k <= j; ++k) total += freq[k];
    return total;
}

int optimalBST(const vector<int>& freq) {
    int n = freq.size();
    vector<vector<int>> cost(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) cost[i][i] = freq[i];

    for (int L = 2; L <= n; ++L) {
        for (int i = 0; i <= n - L; ++i) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; ++r) {
                int c = (r > i ? cost[i][r - 1] : 0) +
                        (r < j ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                cost[i][j] = min(cost[i][j], c);
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    vector<int> freq = {34, 8, 50};
    cout << "Minimum cost of Optimal BST: " << optimalBST(freq) << endl;
    return 0;
}
