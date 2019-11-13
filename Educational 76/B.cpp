#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair

#define rep(n) for(int i = 0; i < (n); i++)
#define repp(a,n) for(int i = (a); i < (n); i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

template<class T>
ostream& operator<<(ostream& out, vector<T> V){
    for(auto &i:V)out << i << " ";
    return out;
}

ll a,b;

bool solve(){
    cin >> a >> b;
    if(a>b || a==b)return true;
    if(a==2 && b==3)return true;
    if(a==1 || a==3 || a==2)return false;
    return true;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--){
        puts(solve()?"YES":"NO");
    }
}