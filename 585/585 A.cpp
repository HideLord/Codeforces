#include <iostream>

using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    int a1,a2,k1,k2,n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int temp = n;
    temp-=(a1*(k1-1)+a2*(k2-1));
    if(temp<0)temp=0;
    cout << temp << " ";
    int br = 0;
    if(k1 < k2){
        br+=min(n/k1,a1);
        n-=(br*k1);
        br+=n/k2;
    }else{
        br+=min(n/k2,a2);
        n-=(br*k2);
        br+=n/k1;
    }
    cout << br << endl;
}
