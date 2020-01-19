#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)((x).size())
#define mp make_pair

using namespace std;

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

vector<ll> V;
ll mod = 1e9+7;

ll mypow(ll a, ll p){
    ll res = 1;
    for(;p;p>>=1, (a*=a)%=mod)
        if(p&1)(res*=a)%=mod;
    return res;
}

ll inverse(ll a){
    return mypow(a,mod-2);
}

int primes[1000001];

vector<ll> p;
bool remember[1000001];

void init(){
    bool used[1000001] {};
    for(int i = 2; i < 1000001; i++){
        if(!used[i]) p.push_back(i), remember[i] = 1;
        for(int j = i*2; j < 1000001; j+=i)used[j] = 1;
    }
}

void factor(ll a){
    if(remember[a]){
        primes[a] = max(primes[a],1);
        remember[a] = 1;
        return;
    }
    int i = 0, br = 0;
    while(a>1) {
        if(a%p[i]==0){
            a/=p[i];
            br++;
        }
        else {
            primes[p[i]] = max(primes[p[i]], br);
            i++;
            br = 0;
            if(remember[a]){
                primes[a] = max(primes[a],1);
                return;
            }
        }
    }
    primes[p[i]] = max(primes[p[i]], br);
}

int main(){
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    init();
    V.resize(N);
    for(auto& i: V)cin >> i, factor(i);


    ll lcm = 1, res = 0;
    for(int i = 2; i < 1000001; i++){
        if(primes[i])
            lcm *= mypow(i, primes[i]), lcm%=mod;
    }
    for(int i = 0; i < N; i++){
        res += (lcm * inverse(V[i]))%mod;
        res%=mod;
    }
    cout << res << endl;
}