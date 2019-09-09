#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

set<char> all{'a','b','c'};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    string s,t;
    cin >> n >> s >> t;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(k==j || k==i || i==j)continue;
                string A = "..",B = "..", C = "..", D = "..";
                A[0] = 'a'+i;
                A[1] = 'a'+j;
                B[0] = A[1];
                B[1] = 'a'+k;
                C[0] = A[1];
                C[1] = A[0];
                D[0] = D[1] = B[1];
                if(A == s || A == t || B == s || B == t || C == s || C == t || D == s || D == t)continue;
                cout << "YES" << endl;
                for(int i = 0; i < n; i++)cout << A;
                for(int i = 0; i < n; i++)cout << B[1];
                cout << endl;
                return 0;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(k==j || k==i || i==j)continue;
                string A = "..",B = "..", C = "..", D = "..";
                A[0] = 'a'+i;
                A[1] = 'a'+j;
                B[1] = A[0];
                B[0] = 'a'+k;
                C[0] = A[1];
                C[1] = A[0];
                D[0] = D[1] = B[1];
                if(A == s || A == t || B == s || B == t || C == s || C == t || D == s || D == t)continue;
                cout << "YES" << endl;
                for(int i = 0; i < n; i++)cout << B[0];
                for(int i = 0; i < n; i++)cout << A;
                cout << endl;
                return 0;
            }
        }
    }
}




