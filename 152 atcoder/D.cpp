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
    long long A[10][10] {}, N, res = 0;
    memset(A,0,sizeof A);
    cin >> N;
    for(int i = 1; i <= N; i++){
        int l = i%10, f = i;
        while(f>=10)f/=10;
        A[f][l] += 1;
    }
    for(int i = 1; i <= N; i++){
        int l = i%10, f = i;
        while(f>=10)f/=10;
        res+=A[l][f];
    }
    cout << res << endl;
}