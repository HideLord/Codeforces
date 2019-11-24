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

int N;

vector<ii>  V;

void solve(){
    V.resize(N);
    for(auto &i:V){
        cin >> i.first >> i.second;
    }
    sort(all(V));
    ii ans = {V.back().first,V.back().first};
    for(auto i:V)
        if(ans.second>i.second) ans.second = i.second;
    

    cout << abs(ans.second-ans.first) << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while(Q--){
        cin >> N;
        solve();
    }
}