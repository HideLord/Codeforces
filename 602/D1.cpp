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
 
int main(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    V.resize(N);
    S.resize(N);
    for(int i = 0; i < N; i++)cin >> V[i];
    for(int i = 0; i < N; i++)S[i] = {V[i],i};
    sort(all(S),[](ii a, ii b){if(a.first == b.first)return a.second>b.second;return a.first<b.first;});
    cin >> M;
    while(M--){
        int p, k, rem;
        cin >> k >> p;
        rem = N-k;
        for(int i = 0; i < rem; i++)
            V[S[i].second] = -V[S[i].second];
        for(int i = 0; i < N; i++){
            if(V[i]>0){
                p--;
                if(p==0){
                    cout << V[i] << endl;
                    break;
                }
            }
        }
        for(int i = 0; i < rem; i++)
            V[S[i].second] = -V[S[i].second];
    }
}