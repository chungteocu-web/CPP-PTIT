#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> matran(1005, vector<int>(1005));
struct toado
{
    int x, y, z;
};
int main()
{
    int m;
    cin >> m;
    while (m--)
    {
        vector<vector<bool>> visit(1005, vector<bool>(1005, false));
        int N, M, x, y, z, t, check = 1;
        cin >> N >> M >> x >> y >> z >> t;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> matran[i][j];
            }
        }
        int k = 0;
        if (matran[x][y] == 0)
        {
            cout << "-1" << endl;
            continue;
        }
        queue<toado> q;
        q.push({x, y, k});
        while (!q.empty())
        {
            toado temp = q.front();
            int i = temp.x, j = temp.y, k = temp.z;
            visit[i][j] = true;
            q.pop();
            if (i == z && j == t)
            {
                cout << k << endl;
                check = 0;
                break;
            }
            if (i + 1 < N && matran[i + 1][j] == 1 && visit[i + 1][j] == false)
            {
                q.push({i + 1, j, k + 1});
                visit[i + 1][j] = true;
            }
            if (i - 1 >= 0 && matran[i - 1][j] == 1 && visit[i - 1][j] == false)
            {
                q.push({i - 1, j, k + 1});
                visit[i - 1][j] = true;
            }
            if (j + 1 < M && matran[i][j + 1] == 1 && visit[i][j + 1] == false)
            {
                q.push({i, j + 1, k + 1});
                visit[i][j + 1] = true;
            }
            if (j - 1 >= 0 && matran[i][j - 1] == 1 && visit[i][j - 1] == false)
            {
                q.push({i, j - 1, k + 1});
                visit[i][j - 1] = true;
            }
        }
        if (check == 1)
            cout << -1 << endl;
    }
}
