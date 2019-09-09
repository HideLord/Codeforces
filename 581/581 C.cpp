#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> V[101];
vector<int> shortest[101][101];

vector<int> bfs(int a, int b){
    queue<int> Q;
    vector<int> res;
    Q.push(a);
    int used[101] = {0};
    used[a]=-1;
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        if(curr == b){
            while(1){
                res.push_back(curr);
                curr = used[curr];
                if(curr==-1)break;
            }
            reverse(res.begin(),res.end());
            return res;
        }
        for(int i = 0; i < V[curr].size(); i++){
            if(used[V[curr][i]])continue;
            used[V[curr][i]] = curr;
            Q.push(V[curr][i]);
        }
    }
    return vector<int>();
}

void print(vector<int> arr){
    for(int i = 0; i < arr.size(); i++)cout << arr[i] << " ";
    cout << endl;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        string s;
        cin >> s;
        for(int j = 1; j <= s.size(); j++)
            if(s[j-1]=='1')V[i].push_back(j);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i==j)continue;
            shortest[i][j] = bfs(i,j);
        }
    }

    vector<int> curr;
    vector<int> res;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int u;
        cin >> u;
        curr.push_back(u);
        if(curr.size()>=3){
            if(curr.size()!=shortest[curr[0]][curr.back()].size()){
                res.push_back(curr[0]);
                curr = vector<int> {curr[curr.size()-2],curr.back()};
            }
        }
    }
    res.push_back(curr[0]);
    res.push_back(curr.back());
    cout << res.size() << endl;
    print(res);
}


