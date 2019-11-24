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

vector<int> V;

int N;

void solve(){
    V.resize(N);
    for(auto &i:V)cin >> i;
    vector<int> ans{V[0]};
    vector<int> used(N+1,0);
    used[V[0]]=1;
    int l = 1;
    auto next_min = [&used, &l](int n){
        for(; l < n; l++){
            if(!used[l]){
                used[l]=1;
                return l;
            }
        }
        return -1;
    };
    for(int i = 1; i < N;i++){
        if(V[i]>V[i-1])ans.push_back(V[i]), used[V[i]]=1;
        else ans.push_back(next_min(V[i]));
        if(ans.back()==-1){
            cout << -1 << endl;
            return;
        }
    }
    for(auto i:ans)cout << i << " ";
    cout << endl;
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