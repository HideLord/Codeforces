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

int n,k;
string A;
int num[200001];
void solve(){
    bool only9 = true;
    bool hasDif = false;
    for(int i = 0; i < n; i++){
        if(A[i]!='9')only9 = false;
        if(i>=k && A[i%k]>A[i]){
            hasDif = true;
            break;
        }
        if(i>=k && A[i%k]<A[i]){
            break;
        }
        if(i==n-1)hasDif=true;
    }
    cout << n << endl;
    for(int i = 0; i < k; i++)num[i]=A[i]-'0';
    if(!hasDif){
        int p = k-1;
        while(p>=0 && (num[p] += 1)==10){
            num[p]%=10;
            p--;
        }
    }
    for(int i = 0; i < n; i++){
        cout << num[i%k];
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cin >> A;
    solve();
}