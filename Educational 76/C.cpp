#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define sz(x) (int)((x).size())

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

vector<int> V;
vector<int> used(1000000,false);

int solve(){
    queue<int> Q;
    int mini = INT_MAX;
    //cout << "testing: " << V << endl;
    for(auto i:V){
        if(used[i]++){
            //cout << "found: " << i << endl;
            while(Q.front()!=i || used[i]>2)
                used[Q.front()]-=1,
                Q.pop();
            mini = min(mini,sz(Q)+1);
        }
        Q.push(i);
    }
    //cout << "mini: " << mini << endl;
    if(mini == INT_MAX)return -1;
    return mini;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while(Q--){
        int n;
        cin >> n;
        V.resize(n);
        fill(used.begin(),used.begin()+n+1,false);
        for(auto &i:V)cin >> i;
        cout << solve() << endl;
    }
}