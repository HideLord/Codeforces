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

vector<vector<int>> V;

int modInverse(int a, int m) { 
    int m0 = m; 
    int y = 0, x = 1; 
    if (m == 1) 
      return 0; 
    while (a > 1)  { 
        int q = a / m; 
        int t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 

int main(){
    ios_base::sync_with_stdio(false);
    int N, k;
    cin >> N;
    V.resize(N);
    for(int i = 0; i < N; i++){
        cin >> k;
        V[i].resize(k);
        for(int j = 0; j < k; j++){
            cin >> V[i][j];
        }
    }
}