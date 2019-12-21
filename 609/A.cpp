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
bool isPrime(int n){
    if(n<=2)return true;
    int lim = ceil(sqrt(n));
    for(int i = 2; i <= lim; i++)if(n%i==0)return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    for(int i = 6; ; i++){
        if(!isPrime(n+i) && !isPrime(i)){
            cout << n+i << " " << i << endl;
            return 0;
        }
    }
    cout << n << " " << 0 << endl;
}