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

vector<pair<ll,ll>> V;
ll A[200000];
ll B[200000];

int main(){
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        ll N, M;
        cin >> N >> M;
        V.resize(N);
        for(ll i = 0; i < N; i++){
            cin >> V[i].second;
            V[i].first = 1000000000;
            A[V[i].second] = i;
        }
        for(ll j = 0; j < M; j++){
            cin >> B[j];
            V[A[B[j]]].first = j;
        }
        long long ans = 0, j = 0;
        set<ll> S;
        for(ll i = 0; i < M; i++){
            if(S.count(B[i]))continue;
            ans += 2ll*(A[B[i]] - i) + 1;
            for(; j < A[B[i]]; j++){
                if(V[j].first < 1000000000ll){
                    ans += 1ll;
                    S.insert(V[j].second);
                }
            }
            j++;
        }
        cout << ans << endl;
    }
}
/*
2
10 5
1 2 3 4 5 6 7 8 9 10
6 7 8 9 10
*/