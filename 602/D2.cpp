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

int N, M;
vector<int> V;
vector<ii> S;
vector<pair<ii,int>> qs;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> U;

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    V.resize(N);
    S.resize(N);
    for(int i = 0; i < N; i++)cin >> V[i];
    for(int i = 0; i < N; i++)S[i] = {V[i],i};
    sort(all(S),[](ii a, ii b){if(a.first == b.first)return a.second>b.second;return a.first<b.first;}); // order by element asc, index desc
    cin >> M;
    for(int i = 0; i < M; i++){ // read queries
        int p, k, rem;
        cin >> k >> p;
        qs.push_back({{k,p},i});
    }
    sort(all(qs),[](pair<ii,int> &a,pair<ii,int> &b){return a.first.first>b.first.first;}); // order by length
    int prev = 0; // the previous removed
    vector<int> ans(M); // the answers;
    for(int i = 0; i < N; i++)U.insert(i); // insert every index;
    for(int i = 0; i < qs.size(); i++){
        int ind = qs[i].second;
        int p = qs[i].first.second, k = qs[i].first.first, rem;
        rem = N-k;
        for(;prev < rem; prev++){
            U.erase(S[prev].second);
        }
        ans[ind]=V[*U.find_by_order(p-1)];
    }
    for(auto i:ans)cout << i << endl;
}