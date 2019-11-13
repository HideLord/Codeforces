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

int read() {
    int n = 0, f = 1;
    char c;
    while ((c = getchar()) < '0' || c > '9') 
        if (c == '-') f = -1;
    do  n = n * 10 + c - '0';
    while ((c = getchar()) >= '0' && c <= '9');
    return n * f;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--){
        int n,x,a,b;
        cin >> n >> x >> a >> b;
        if(a>b)swap(a,b);
        int maxi = a-1 + n-b;
        cout << b-a+min(maxi,x) << endl;
    }
}