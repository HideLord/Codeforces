#include <iostream>
#include <stack>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int q;
    cin >> q;
    while(q--){
        int n,br = 0;
        cin >> n;
        stack<int> s;
        while(n--){
            int p;
            cin >> p;
            while(!s.empty() && s.top() > p){
                br++;
                s.pop();
            }
            s.push(p);
        }
        cout << br << endl;
    }
}

