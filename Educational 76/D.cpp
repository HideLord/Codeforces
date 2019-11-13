#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair

#define rep(n) for(int i = 0; i < (n); i++)
#define repp(a,n) for(int i = (a); i < (n); i++)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> ii;
typedef vector<ii> vii;

template<class T>
ostream& operator<<(ostream& out, vector<T> V){
    for(auto &i:V)out << i << " ";
    return out;
}

vector<ii> heroes;
vector<int> A;

int n, m;

void build(){
    for(int i = n-1; i > 0; i--)A[i]=max(A[i<<1],A[i<<1|1]);
}
int query(int l, int r){
    int res = 0;
    if(r-l==1)return A[l+n];
    for(l+=n,r+=n; l<r; r>>=1,l>>=1){
        if(l&1)res = max(res,A[l++]);
        if(r&1)res = max(res,A[--r]);
    }
    return res;
}

int solve(){
    int day = 0, curr = 0;
    sort(all(heroes),[](ii a, ii b){
        if(a.first==b.first)return a.second > b.second;
        return a.first>b.first;});
    int maxi = 0;
    vector<int> best;
    for(auto h:heroes){
        maxi=max(h.second,maxi);
        best.push_back(maxi);
    }
    auto isPossible = [&best](int l, int r){
        int f = query(l,r);
        int a=0,b=m;
        while(a<=b&&a!=m){
            int mid = (a+b)>>1;
            if(heroes[mid].first>=f)a=mid+1;
            else b=mid-1;
        }
        if(a--==0)return false;
        if(best[a]<r-l)return false;
        return true;
    };
    while(curr<n){
        int l=0,r=n;
        while(l<=r&&r){
            int mid = (l+r)>>1;
            if(isPossible(curr,min(curr+mid,n)))l=mid+1;
            else r=mid-1;
        }
        if(l<=1)return -1;
        curr+=l-1;
        day++;
    }
    return day;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--)
    {
        cin >> n;
        A.resize(2*n);
        for(int i = 0; i < n; i++)cin >> A[i+n];
        build();
        cin >> m;
        heroes.resize(m);
        for(auto &i:heroes)cin >> i.first >> i.second;
        cout << solve() << endl;
    }
}