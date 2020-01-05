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

int N,A=0,B=0;
vector<int> V;

int dp[101][101][101][3];

int solve(int pos, int a, int b, int prev){
    if(a < 0)return 10000000;
    if(b < 0)return 10000000;
    if(pos >= N)return 0;
    int& res = dp[pos][a][b][prev];
    if(dp[pos][a][b][prev])return dp[pos][a][b][prev];
    if(V[pos]){
        dp[pos][a][b][prev] = solve(pos+1,a,b,V[pos]) + (prev!=V[pos]); 
    }
    else if(pos == 0){
        dp[pos][a][b][prev] = min(solve(pos+1,a-1,b,1), solve(pos+1,a,b-1,2));
        //cout << "pos: " << pos << " even: " << dp[pos+1][a-1][b][1] << endl;
        //cout << "pos: " << pos << "  odd: " << dp[pos+1][a][b-1][2] << endl;
    }else{
        dp[pos][a][b][prev] = min(solve(pos+1,a-1,b,1) + (prev!=1), solve(pos+1,a,b-1,2) + (prev!=2));
        //cout << "pos: " << pos << " even: " << dp[pos+1][a-1][b][1] << endl;
        //cout << "pos: " << pos << "  odd: " << dp[pos+1][a][b-1][2] << endl;
    }
    //cout << "pos: " << pos << " | res: " << dp[pos][a][b][prev] << endl; 
    return dp[pos][a][b][prev];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    V.resize(N);
    for(auto&i:V)cin >> i;
    set<int>S;
    for(int i = 1; i <= N; i++)S.insert(i);
    for(auto&i:V)S.erase(i);
    for(int i = 0; i < N; i++){
        if(V[i] == 0)
            continue;
        V[i] = V[i]%2 + 1;
    }
    for(auto i: S){
        if(i%2 == 0)A++; // even
        else        B++; // odd
    }
    //cout << V << endl;
    //memset(dp,-1,sizeof dp);
    cout << solve(0, A, B, V[0]) << endl;
}