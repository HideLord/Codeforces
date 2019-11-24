#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)((x).size())
#define mp make_pair

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> ii;

template<class U,class T>ostream& operator<<(ostream& out, pair<U,T> & P){
    return out << "[" << P.first << ", " << P.second << "]";
}
template<class T>ostream& operator<<(ostream& out, vector<T> & V){
    if(!V.empty())out << "[";
    for(int i = 0; i < sz(V); i++)out << V[i] << (i+1==sz(V)?"]":", ");
    return out;
}
int N, M;

void dfs(int v, vector<vector<int>> &edges, vector<bool> &visited, int &maxi) {
    visited[v] = true;
    maxi = max(maxi, v);
    for (auto it : edges[v]) {
        if (!visited[it]) {
            dfs(it, edges, visited, maxi);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> N >> M;
    vector<vector<int>> edges(N, vector<int>());
    vector<bool> visited(N, false);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edges[u-1].push_back(v-1);
        edges[v-1].push_back(u-1);
    }
    int ans = 0, maxi = -1;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            if (i < maxi) {
                ans++;
            }
            dfs(i, edges, visited, maxi);
        }
    }
    cout << ans << endl;
}