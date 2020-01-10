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
int N;

vector<ll> V;
void solve(){
    ll sum = 0;
    for(int i = 0; i < V.size(); i++)sum+=V[i];
    
    ll maxi = -2e9, curr = 0;
    for(int i = 0; i+1 < V.size(); i++){
        curr += V[i];
        maxi = max(maxi,curr);
        if(curr < 0)curr = 0;
    }
    curr = 0;
    for(int i = 1; i < V.size(); i++){
        curr += V[i];
        maxi = max(maxi,curr);
        if(curr < 0)curr = 0;
    }
    cout << (sum > maxi? "YES":"NO") << endl;
}
        
int main(){
    ios_base::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while(Q--){
        cin >> N;
        V.resize(N);
        for(auto& i : V)cin >> i;
        solve();
    }
}
