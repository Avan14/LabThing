#include <bits/stdc++.h>
using namespace std;

bool comp(pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b) {
    return a.first.second < b.first.second;
}

vector<pair<pair<int, int>, int>> ActivitySelection(vector<pair<pair<int, int>, int>> &nums, int n) {
    sort(nums.begin(), nums.end(), comp);
    vector<pair<pair<int, int>, int>> result;

    pair<pair<int, int>, int> last_selected = nums[0];
    result.push_back(last_selected);
    for (int i = 1; i < n; ++i) {
        if (nums[i].first.first >= last_selected.first.second){

            result.push_back(nums[i]);
            last_selected = nums[i];
        }
        else if (nums[i].first.first < last_selected.first.second){

            
            if (last_selected.second < nums[i].second) {
                result.pop_back();
                result.push_back(nums[i]);
                last_selected = nums[i];
            }
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> nums(n);

    for (int i = 0; i < n; i++) 
        cin >> nums[i].first.first >> nums[i].first.second >> nums[i].second;

    vector<pair<pair<int, int>, int>> ans = ActivitySelection(nums, nums.size());

    for (auto pair : ans) 
        cout << pair.first.first << " " << pair.first.second << " " << pair.second << endl;

    return 0;
}
