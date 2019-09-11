#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll a, N;

ll factor(ll gcd){
    ll br = 0;
    for(ll i = 1; i < sqrt(gcd); i++)br += (gcd%i==0?2:0);
    br += (ll(sqrt(gcd))*ll(sqrt(gcd)) == gcd);
    return br;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);
    cin >> N;
    ll gcd = -1;
    for(ll i = 0; i < N; i++)
        cin >> a, gcd = (gcd == -1?a:__gcd(gcd,a));
    cout << factor(gcd) << endl;
}
