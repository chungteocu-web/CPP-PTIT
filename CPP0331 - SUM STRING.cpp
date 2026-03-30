#include <iostream>
#include <algorithm>
#include <stdbool.h>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <utility>
using namespace std;
string sum(string a, string b)
{
    while (a.size() < b.size())
        a = "0" + a;
    while (a.size() > b.size())
        b = "0" + b;
    string res;
    int len, nho = 0;
    len = a.size();
    for (int i = len - 1; i >= 0; i--)
    {
        int tmp = a[i] - '0' + b[i] - '0' + nho;
        res.push_back((tmp % 10) + '0');
        nho = tmp / 10;
    }
    if (nho > 0)
    {
        char s = nho + '0';
        res.push_back(s);
    }
    reverse(res.begin(), res.end());
    return res;
}
bool check(string a, string b, string c)
{
    string tong = sum(a, b);
    if (tong.size() > c.size())
        return false;
    if (c.substr(0, tong.size()) == tong)
    {
        if (c.substr(0, tong.size()).size() == tong.size())
            return true;
        else
            return check(b, tong, c.substr(tong.size()));
    }
    return false;
}
void solve()
{
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 1; j + i < s.size(); j++)
        {
            string s1 = s.substr(0, i), s2 = s.substr(i, j), s3 = s.substr(j + i);
            if (check(s1, s2, s3))
            {
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" << endl;
}
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        solve();
    }
}
