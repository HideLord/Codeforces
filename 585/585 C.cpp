#include <iostream>
#include <vector>

using namespace std;
vector<int> V1;
vector<int> V0;

int main(){
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;

    int br1 = 0;
    int br0 = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i]=='a' && t[i]=='b')V1.push_back(i),br1++;
        if(s[i]=='b' && t[i]=='a')V0.push_back(i),br0++;
    }
    if((br1+br0)%2){
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int,int>> op;

    for(int i = 0; ; i++){
        if(V1.size()<2)break;
        int a = V1.back()+1;
        V1.pop_back();
        int b = V1.back()+1;
        V1.pop_back();
        op.push_back({a,b});
    }
    if(!V1.empty()){
        op.push_back({V1[0]+1,V1[0]+1});
        V0.push_back(V1[0]);
    }
    for(int i = 0; ; i++){
        if(V0.size()<2)break;
        int a = V0.back()+1;
        V0.pop_back();
        int b = V0.back()+1;
        V0.pop_back();
        op.push_back({a,b});
    }
    cout << op.size() << endl;
    for(int i = 0; i < op.size(); i++){
        cout << op[i].first << " " << op[i].second << endl;
    }
}
