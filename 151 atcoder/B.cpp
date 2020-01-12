#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)((x).size())
#define mp make_pair

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;

template<class U,class T>ostream& operator<<(ostream& out, pair<U,T> & P){
    return out << "[" << P.first << ", " << P.second << "]";
}
template<class T>ostream& operator<<(ostream& out, vector<T> & V){
    if(!V.empty())out << "[";
    for(int i = 0; i < sz(V); i++)out << V[i] << (i+1==sz(V)?"]":", ");
    return out;
}

int A[123012];

int main(){
    ios_base::sync_with_stdio(false);
    ll N, K, M, sum = 0;
    cin >> N >> K >> M;
    for(int i = 0; i+1 < N; i++){
        cin >> A[i];
        sum+=A[i];
    }
    M*=N;
    auto ans = M-sum;
    ans = max(0ll,ans);
    if(ans > K)cout << -1 << endl;
    else cout << ans << endl;
}