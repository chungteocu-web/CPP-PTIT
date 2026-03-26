#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int to = 1e9;
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> dp(n, to);
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] != to)
            {
                for (int j = i + 1; j <= i + a[i] && j < n; j++)
                {
                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }
        cout << dp[n - 1] << endl;
    }
}
