#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
 
template<class T>
ostream& operator<<(ostream& out, vector<T> V){
    for(auto &i:V)out << i << " ";
    return out;
}
 
int dp[81][100001],m,N;
vector<int> X;
vector<int> S;
 
int solve(int n, int l){
    if(l>=m)return 0;
    if(n>=sz(X))return max(0,m-l);
    //cout << n << " " << X[n] << " " << S[n] << " " << l << endl;
    if(dp[n][l]!=-1)return dp[n][l];
    int cost = max(0,X[n]-S[n]-l-1);
    dp[n][l] = min(solve(n+1,l),solve(n+1,X[n]+S[n]+cost)+cost);
    return dp[n][l];
}
 
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> m;
    vector<ii> V;
    X.resize(N);
    S.resize(N);
    V.resize(N);
    memset(dp,-1,sizeof dp);
    for(int i = 0; i < N; i++)
        cin >> V[i].first >> V[i].second;
    sort(all(V));
    for(int i = 0; i < N; i++)
        X[i]=V[i].first, S[i]=V[i].second;
    cout << solve(0,0) << endl;
}