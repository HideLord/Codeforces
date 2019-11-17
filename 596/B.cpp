#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

template<class T>
ostream& operator<<(ostream& out, vector<T> V){
    for(auto &i:V)out << i << " ";
    return out;
}

vector <int> V;
int n,k,d;

int solve(){
    vector<int> used(d+1,0);
    int br = 0, i=0, mini = 213123;
    for(; i < k; i++)
        br+=(used[V[i]]++==0);
    mini = br;
    for(; i < n; i++){
        br-=(--used[V[i-k]]==0);
        br+=(used[V[i]]++==0);
        mini = min(mini,br);
    }
    return mini;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--){
        cin >> n >> d >> k;
        V.resize(n);
        for(auto &i:V)cin >> i;
        cout << solve() << endl;
    }
}