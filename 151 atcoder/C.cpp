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

int A[200001];

int main(){
    ios_base::sync_with_stdio(false);
    int N, M, res = 0, acc = 0;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int p;
        string ans;
        cin >> p >> ans;
        if(A[p] == -1)continue;
        if(ans=="WA")A[p]++;
        else{
            if(A[p]!=-1){
                res+=A[p];
                A[p] = -1;
                acc+=1;
            }
        }
    }
    cout << acc << " " <<  res << endl;
}