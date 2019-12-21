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

int N, mod,x = 1000000009,
A[2001],B[2001];

int solve(){
    int dif = (B[0]-A[0] + mod)%mod;
    for(int i = 1; i < N; i++){
        int curr = (B[i]-A[i] + mod)%mod;
        if(curr!=dif)return x;
    }
    return dif;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> N >> mod;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < N; i++){
        cin >> B[i];
    }
    sort(B,B+N);
    sort(A,A+N);
    for(int i = 0; i < N; i++){
        rotate(A,A+1,A+N);
        x = min(x,solve());
    }
    cout << x << endl;
}