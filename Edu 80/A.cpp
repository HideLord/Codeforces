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

int main(){
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        double n, d;
        cin >> n >> d;
        int l = 0, r = n, done = 0;
        while(l<r){
            double m = (l+r)/2;
            if(ceil(d/(1.0+m)) <= n-m){
                cout << "YES" << endl;
                done = 1;
                break;
            }
            else l = m+1;
        }
        if(!done)cout << "NO" << endl;
    }
}