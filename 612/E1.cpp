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

int n;

string a[5100], s;
map<string, int> f;
int ap[256], temp[256];
vector<string> res;

bool comp(string a, string b)
{
    return a.size() < b.size();
}

int main()
{
    cin >> n;
    if (n == 1)
    {
        cout << "? 1 1" << endl;
        cin >> s;
        cout << "! " << s << endl;
        return 0;
    }
    cout << "? 1 " << n << endl;
    for (int i = 1; i <= n * (n + 1) / 2; i++)
        cin >> a[i], sort(a[i].begin(), a[i].end());
    cout << "? 2 " << n << endl;
    for (int i = 1; i <= n * (n - 1) / 2; i++)
        cin >> s, sort(s.begin(), s.end()), f[s]++;
    for (int i = 1; i <= n * (n + 1) / 2; i++)
    {
        if (f[a[i]])
            f[a[i]]--;
        else
            res.push_back(a[i]);
    }
    sort(res.begin(), res.end(), comp);
    cout << "! " << res[0];
    ap[res[0][0]]++;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < res[i].size(); j++)
            temp[res[i][j]]++;
        for (int j = 'a'; j <= 'z'; j++)
        {
            if (ap[j] != temp[j])
            {
                ap[j]++;
                cout << char(j);
            }
            temp[j] = 0;
        }
    }
    cout << endl;
    return 0;
}
