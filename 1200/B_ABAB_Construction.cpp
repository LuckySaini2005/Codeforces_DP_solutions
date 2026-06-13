#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        string x;
        cin >> n >> x;

        bool dp[2] = {true, false};

        for (int i = 1; i <= n; i++) {
            bool ndp[2] = {false, false};

            for (int p = 0; p < 2; p++) {
                if (!dp[p]) continue;

                // Take from left
                char left = (p == 0 ? 'a' : 'b');
                if (x[i - 1] == '?' || x[i - 1] == left) {
                    ndp[p ^ 1] = true;
                }

                // Take from right
                char right = ((n - i + 1 + p) & 1) ? 'a' : 'b';
                if (x[i - 1] == '?' || x[i - 1] == right) {
                    ndp[p] = true;
                }
            }

            dp[0] = ndp[0];
            dp[1] = ndp[1];
        }

        cout << ((dp[0] || dp[1]) ? "YES" : "NO") << '\n';
    }

    return 0;
}