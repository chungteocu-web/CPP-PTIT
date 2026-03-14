#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
int matran[205][205], n, m, sum = 0, kq = 0;
void tri(int i, int j, int sum)
{
    sum += matran[i][j];
    if (sum > m)
        return;
    if (i == n - 1 && j == n - 1 && sum == m)
    {
        ++kq;
        return;
    }
    if (i + 1 < n)
    {
        tri(i + 1, j, sum);
    }
    if (j + 1 < n)
    {
        tri(i, j + 1, sum);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        sum = 0, kq = 0;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matran[i][j];
            }
        }
        tri(0, 0, 0);
        cout << kq << endl;
    }
}
