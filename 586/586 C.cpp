#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string s;

int mem[256];
int A[500001];

string winner(int k){
    bool curr = 1;

    while(1){
        if(A[k] >= k || s[A[k]] == s[k])return (!curr?"Ann":"Mike");
        k = A[k];
        curr = !curr;
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    cin >> s;

    for(int i = 0; i < 256; i++)mem[i] = s.size()-1;

    for(int i = s.size()-1; i >= 0; i--){
        for(int j = s[i]+1; j <= ('z'); j++)mem[j] = i;
    }
    for(int i = 0; i < s.size(); i++)A[i]=i;
    for(int i = 0; i < s.size(); i++)A[i]=mem[s[i]];
    for(int i = 0; i < s.size(); i++)cout << winner(i) << endl;
}
