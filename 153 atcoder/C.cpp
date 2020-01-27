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

int main(){
    ios_base::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    V.resize(N);
    for(int i = 0; i < N; i++){
        cin >> V[i];
    }
    sort(all(V), greater<int>());

    long long res = 0;

    for(int i = K; i < V.size(); i++){
        res+=V[i];
    }
    cout << res << endl;
}