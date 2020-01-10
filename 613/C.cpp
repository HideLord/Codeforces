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

int main(){
    ios_base::sync_with_stdio(false);
    long long X;
    cin >> X;
    ll lim = ceil(sqrt(X));
    ll mini = X*2;
    pair<ll,ll> ans;
    for(ll a = 1; a <= lim; a++){
        if(X%a == 0){
            if(__gcd(a,X/a) == 1){
                ll curMin = max(a,X/a);
                if(curMin < mini){
                    mini = curMin;
                    ans = {a,(X/a)};
                }
            }
        }
    }
    cout << ans.first << " " << ans.second << endl;
}