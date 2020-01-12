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

typedef long long ll;
vector<ll>V;
ll N, K;
ll mod = 1e9+7;

int64_t pow(int64_t a, int64_t power, int64_t mod){
    int64_t i(power), ans(1);
    for(; i; i>>=1, ((a%=mod)*=a)%=mod)if(i&1)(ans*=a)%=mod;
    return ans;
}

int64_t fact[1000000]={1};

int64_t binomial(int64_t n, int64_t m) {
    int64_t numerator(fact[n]),denominator(1);
    (denominator*=fact[m])%=mod;
    (denominator*=fact[n-m])%=mod;
    denominator = pow(denominator,mod-2,mod);
    return (numerator*denominator)%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    V.resize(N);
    for(int i = 0; i < N;i++){
        cin >> V[i];
    }

    for(int i = 1; i <= N; i++) fact[i] = (fact[i-1]*i)%mod;

    sort(all(V));
    ll ans = 0;
    for(int i = N-1; i >= 0; i--){
        if(N-i>=K){ // can be min
            ll res = binomial(N-1-i,K-1);
            ans -= (res*V[i])%mod;
            ans+=mod;
            ans%=mod;
        }
        if(i+1>=K){
            ll res = binomial(i,K-1);
            ans += (res*V[i])%mod;
            ans+=mod;
            ans%=mod;
        }
    }
    cout << ans << endl;
}