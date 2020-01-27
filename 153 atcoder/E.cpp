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

long long dp[10001][1001];
long long A[10000];
long long B[10000];

long long H, N;

long long rec(int h, int m){
    if (h <= 0)return 0ll;
    if (dp[h][m] != -1)return dp[h][m];
    if (m+1 < N) return dp[h][m] = min(rec(h-A[m], m) + B[m], rec(h,m+1));
    else return dp[h][m] = rec(h-A[m], m) + B[m];
    return dp[h][m];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> H >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i] >> B[i];
    }
    memset(dp,-1,sizeof dp);
    cout << rec(H,0) << endl;
}