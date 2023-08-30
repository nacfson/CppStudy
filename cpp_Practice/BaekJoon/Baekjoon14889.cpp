#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
vector<vector<int>> stats;
int min_diff = 999999;

int calculate_ability(const vector<int>& team) {
    int ability = 0;
    for (int i = 0; i < team.size(); ++i) {
        for (int j = 0; j < team.size(); ++j) {
            ability += stats[team[i]][team[j]];
        }
    }
    return ability;
}

void backtrack(int idx, vector<int>& team_start, vector<int>& team_link) {
    if (idx == n) {
        int diff = abs(calculate_ability(team_start) - calculate_ability(team_link));
        min_diff = min(min_diff, diff);
        return;
    }

    if (team_start.size() < n / 2) {
        team_start.push_back(idx);
        backtrack(idx + 1, team_start, team_link);
        team_start.pop_back();
    }

    if (team_link.size() < n / 2) {
        team_link.push_back(idx);
        backtrack(idx + 1, team_start, team_link);
        team_link.pop_back();
    }
}

int main() {
    cin >> n;
    stats.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> stats[i][j];
        }
    }

    vector<int> team_start, team_link;
    backtrack(0, team_start, team_link);
    cout << min_diff << endl;

    return 0;
}
