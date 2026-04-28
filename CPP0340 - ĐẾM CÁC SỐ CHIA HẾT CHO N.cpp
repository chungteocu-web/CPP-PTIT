#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        string s;
        cin >> m >> n >> s;
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][(s[0] - '0') % n]++;
        for (int i = 1; i < m; i++)
        {
            dp[i][(s[i] - '0') % n]++;
            for (int j = 0; j < n; j++)
            {
                dp[i][j] += dp[i - 1][j];
                dp[i][(j * 10 + s[i] - '0') % n] += dp[i - 1][j];
            }
        }
        cout << dp[m - 1][0] << endl;
    }
}
