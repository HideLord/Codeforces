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

vector <int> V;

int dp[3000001][2];

int rec(int n, int ost){
    if(n>=V.size())return 0;
    if(n+1==V.size())return dp[n][ost] = V[n]/2 + (V[n]%2+ost)/2;
    if(dp[n][ost])   return dp[n][ost];
    dp[n][ost] = rec(n+2,0) + V[n+1] + (V[n]-V[n+1])/2 + ((V[n]-V[n+1])%2 + ost)/2;
    if(ost && V[n-1]%2==0)dp[n][ost] = max(dp[n][ost],rec(n+1,(V[n]%2+ost)%2) + V[n]/2 + ((V[n]%2+ost)/2&&V[n]==V[n-1]));
    else dp[n][ost] = max(dp[n][ost],rec(n+1,(V[n]%2+ost)%2) + V[n]/2 + (V[n]%2+ost)/2);
    return dp[n][ost];
}

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    V.resize(n);
    for(int i = 0; i < n; i++)cin >> V[i];
    cout << rec(0,0) << endl;
    for(int i = 0; i < n; i++)cout << dp[i][0] << " ";
    cout << endl;
    for(int i = 0; i < n; i++)cout << dp[i][1] << " ";
}