#include <iostream>
#include <algorithm>
#include <stdbool.h>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <cstring>
#include <utility>
using namespace std;
struct dothi
{
    int giatri, vitri;
};
bool sosanh(dothi a, dothi b)
{
    if (a.giatri == b.giatri)
        return a.vitri < b.vitri;
    return a.giatri < b.giatri;
}
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        int a, tong = 0;
        cin >> a;
        vector<dothi> mang(a);
        vector<int> danhdau(a, 0);
        for (int i = 0; i < a; i++)
        {
            cin >> mang[i].giatri;
            mang[i].vitri = i;
        }
        sort(mang.begin(), mang.end(), sosanh);
        for (int i = 0; i < a; i++)
        {
            if (danhdau[i] == 1 || mang[i].vitri == i)
                continue;
            int j = i, canhdothi = 0;
            while (danhdau[j] == 0)
            {
                danhdau[j] = 1;
                j = mang[j].vitri;
                canhdothi++;
            }
            if (canhdothi > 0)
            {
                tong += canhdothi - 1;
            }
        }
        cout << tong << endl;
    }
}
