#include <iostream>
#include <cmath>

using namespace std;

int n;

int p(int i) {
    return (i+n)%n;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    int q;
    cin >> q;
    while(q--) {
        int a[201], sind, eind;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 1)
                sind = i;
            if(a[i] == n)
                eind = i;
        }
        for(int i = 0; i < n; i++) {
            if(abs(a[i]-a[p(i-1)]) != 1){
                if(i!=sind || p(i-1)!=eind){
                    if(i!=eind || p(i-1)!=sind){
                        cout << "NO" << endl;
                        goto ending;
                    }
                }
            }
        }
        cout << "YES" << endl;
        ending:;
    }
}
