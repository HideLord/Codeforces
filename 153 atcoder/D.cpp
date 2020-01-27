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
    unsigned long long L;
    cin >> L;
    if(L == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < 64; i++){
        ull res = (1ull << i);
        if(res > L){
            cout << res-1 << endl;
            break;
        }
    }
}