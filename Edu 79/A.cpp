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
    int T;
    cin >> T;
    while(T--){
        vector<int> V(3);
        cin >> V[0] >> V[1] >> V[2];
        sort(all(V));
        if(V[0] + V[1] < V[2]-1)cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}