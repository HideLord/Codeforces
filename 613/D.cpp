#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)((x).size())
#define mp make_pair

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> ii;

template<class U,class T>ostream& operator<<(ostream& out, const pair<U,T> & P){
    return out << "[" << P.first << ", " << P.second << "]";
}
template<class T>ostream& operator<<(ostream& out, const vector<T> & V){
    if(!V.empty())out << "[";
    for(int i = 0; i < sz(V); i++)out << V[i] << (i+1==sz(V)?"]":", ");
    return out;
}

vector<uint32_t> V;
uint32_t rec(int pos, int l, int r){
    if(pos == -1)return 0u;
    for(int i = l; i < r; i++)V[i] &= ((1u<<pos+1)-1);//,cout << bitset<3>(V[i]) << endl;
    int m = distance(V.begin(), lower_bound(V.begin()+l,V.begin()+r,(1u<<pos)));
    if(m == r || m == l)
        return (0u) | rec(pos-1,l,r);
    return min((1u<<pos) | rec(pos-1, l, m), (1u<<pos) | rec(pos-1, m, r));
}

int main(){
    ios_base::sync_with_stdio(false);
    int N;
    cin >> N;
    V.resize(N);
    for(int i = 0; i < N; i++)cin >> V[i];
    sort(all(V));
    cout << rec(30,0,V.size()) << endl;
}