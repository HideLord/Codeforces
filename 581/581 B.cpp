#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    long long n,l,r, currD = 1, currP = 1, sumS = 1, sumB = 1;
    cin >> n >> l >> r;
    for(int i = 1; i < n; i++){
        if(currD < r)++currD, currP*=2;
        sumB+=currP;
    }
    currD = l+1, currP = pow(2,l);
    for(int i = 1; i < n; i++){
        if(currD > 1)--currD, currP/=2;
        sumS+=currP;
    }
    cout << sumS << " " << sumB << endl;
}

