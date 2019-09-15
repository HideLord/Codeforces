#include <iostream>
#include <vector>

using namespace std;

long long n;
long long A[200001];

int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i], A[i] = (A[i]>0?0:1);

    long long p = 0;
    vector<int> V;
    for(int i = 0; i < n; i++) {
        p++;
        if(A[i]){
            V.push_back(p);
            p=0;
        }
    }
    V.push_back(p+1);

    long long a = 0,b = 0,ans = 0;
    for(int i = 0; i < V.size()-1; i++) {
        //cout << V[i] << "\n";
        if(i%2==0) {
            a+=V[i]-1;
            ans+=(a+1)*(V[i+1]);
            //cout << "p1: "  << a << " p2: " << V[i+1]-1 << endl;
            a+=1;
        }else{
            b+=V[i]-1;
            ans+=(b+1)*(V[i+1]);
            //cout << "p1: "  << b << " p2: " << V[i+1]-1 << endl;
            b+=1;
        }

    }
    cout << ans << " " << ((n*(n+1))/2ll - ans) << endl;
}
