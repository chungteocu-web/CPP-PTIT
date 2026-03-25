#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
vector<long long> so(1000), uocso;
int cnt = 0;
long long ucln(long long a, long long b)
{
    while (b != 0)
    {
        long long tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}
void tonguoc(long long a)
{
    for (int i = 2; i <= 1000000; i++)
    {
        int tmp = 0;
        if (a % i == 0)
        {
            while (a % i == 0)
            {
                a /= i;
                tmp++;
            }
            so[cnt++] = tmp;
        }
    }
    if (a > 1)
    {
        long long tmp = sqrt(a);
        if (tmp * tmp == a)
            so[cnt++] = 2;
        else
            so[cnt++] = 1;
    }
}
long long uclnn()
{
    long long tong = so[0];
    for (int i = 1; i < cnt; i++)
    {
        tong = ucln(tong, so[i]);
    }
    return tong;
}

int main()
{
    long long c;
    cin >> c;
    if (c == 1)
    {
        cout << 1;
        return 0;
    }
    tonguoc(c);
    long long uchung = uclnn();
    for (int i = 1; i * i <= uchung; i++)
    {
        if (uchung % i == 0)
        {
            uocso.push_back(i);
            if (i != (uchung / i))
            {
                uocso.push_back(uchung / i);
            }
        }
    }
    sort(uocso.begin(), uocso.end(), greater<long long>());
    for (int i = 0; i < uocso.size(); i++)
    {
        long long tmp = uocso[i], tong = 1;
        for (int j = 0; j < cnt; j++)
        {
            tong *= (so[j] / tmp + 1);
        }
        if (tong == tmp)
        {
            long long res = round(pow(c, (1.0 / tmp)));
            cout << res;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
