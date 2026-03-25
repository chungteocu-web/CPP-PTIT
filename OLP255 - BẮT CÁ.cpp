#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const double eps = 1e-9;
struct ttconca
{
    double w, x, v;
};
struct event
{
    double t;
    int i;
    double w;
};
bool sosanh(event &a, event &b)
{
    if (abs(a.t - b.t) > eps)
    {
        return a.t < b.t;
    }
    else
    {
        return a.i > b.i;
    }
}
int main()
{
    int n, a;
    cin >> n >> a;
    vector<ttconca> ds(n);
    for (int i = 0; i < n; i++)
    {
        cin >> ds[i].w >> ds[i].x >> ds[i].v;
    }
    double maxx = 0;
    for (int i = 0; i < n; i++)
    {
        vector<event> timeline;
        for (int j = 0; j < n; j++)
        {
            double dx = ds[j].x - ds[i].x, dv = ds[j].v - ds[i].v, tbd, tkt;
            if (dv == 0)
            {
                if (dx >= 0 && dx <= a)
                {
                    tbd = 0;
                    tkt = 99999999999999;
                }
                else
                {
                    continue;
                }
            }
            else if (dv > 0)
            {
                tbd = (-dx / dv);
                tkt = ((a - dx) / dv);
            }
            else
            {
                tkt = (-dx / dv);
                tbd = ((a - dx) / dv);
            }
            tbd = max(0.0, tbd);
            if (tbd <= tkt)
            {
                timeline.push_back({tbd, 1, ds[j].w});
                timeline.push_back({tkt, -1, ds[j].w});
            }
        }
        sort(timeline.begin(), timeline.end(), sosanh);
        double maxht = 0, tmp = 0;
        for (int j = 0; j < timeline.size(); j++)
        {
            if (timeline[j].i == 1)
            {
                tmp += timeline[j].w;
            }
            if (timeline[j].i == -1)
            {
                tmp -= timeline[j].w;
            }
            maxht = max(maxht, tmp);
        }
        maxx = max(maxht, maxx);
    }
    cout << maxx << endl;
}
