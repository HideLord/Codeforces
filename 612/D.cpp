#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define mp make_pair

using namespace std;

typedef unsigned long long ull;
typedef pair<int, int> ii;

template <class U, class T>
ostream &operator<<(ostream &out, pair<U, T> &P)
{
    return out << "[" << P.first << ", " << P.second << "]";
}
template <class T>
ostream &operator<<(ostream &out, vector<T> &V)
{
    if (!V.empty())
        out << "[";
    for (int i = 0; i < sz(V); i++)
        out << V[i] << (i + 1 == sz(V) ? "]" : ", ");
    return out;
}
int n, root;

int c[2005], t[2005], h[2005], val[2005];
vector<int> g[2005];

void dep(int nod)
{
    h[nod] = h[t[nod]] + 1;
    for (auto &fiu : g[nod])
        dep(fiu);
}

void dfs(int nod, int ancient)
{
    if (c[nod] != -1)
        val[nod] = val[ancient];
    for (auto &fiu : g[nod])
        dfs(fiu, ancient);
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> c[i];
        if (!t[i])
            root = i;
        val[i] = 1;
        g[t[i]].push_back(i);
    }
    dep(root);
    int rem = n;
    while (rem)
    {
        int nod = -1, mn = n + 1;
        for (int i = 1; i <= n; i++)
        {
            if (c[i] == 0 && h[i] < mn)
            {
                mn = h[i];
                nod = i;
            }
        }
        if (nod == -1)
        {
            cout << "NO\n";
            return 0;
        }
        c[nod] = -1;
        dfs(nod, nod);
        rem--;
        while (nod != root)
        {
            nod = t[nod];
            if (c[nod] > 0)
                c[nod]--, val[nod]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (c[i] != -1)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << val[i] << " ";
    return 0;
}