#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)((x).size())
#define mp make_pair

using namespace std;

typedef unsigned long long ull;
typedef pair<int,int> ii;

template<class U,class T>ostream& operator<<(ostream& out, pair<U,T> & P){
    return out << "[" << P.first << ", " << P.second << "]";
}
template<class T>ostream& operator<<(ostream& out, vector<T> & V){
    if(!V.empty())out << "[";
    for(int i = 0; i < sz(V); i++)out << V[i] << (i+1==sz(V)?"]":", ");
    return out;
}

char arr[200][200];
bool used[200][200];

vector<vector<int>> dir{{1,0},{0,1},{-1,0},{0,-1}};

int N, M,maxi = 0;

int solve(int i, int j, int targetI, int targetJ){
    queue<tuple<int,int,int>> Q;
    Q.push(tuple<int,int,int>(i,j,0));
    used[i][j] = true;
    while(!Q.empty()){
        i = get<0>(Q.front());
        j = get<1>(Q.front());
        int de = get<2>(Q.front());
        Q.pop();
        if(arr[i][j] == '#')continue;
        if(i==targetI && j==targetJ)return de;
        for(int d = 0; d < 4; d++){
            if(i+dir[d][0] < 0 || j+dir[d][1] < 0 || i+dir[d][0] >= N || j+dir[d][1] >= M) continue;
            if(used[i+dir[d][0]][j+dir[d][1]])continue;
            used[i+dir[d][0]][j+dir[d][1]] = 1;
            if(arr[i+dir[d][0]][j+dir[d][1]] == '#')continue;
            Q.push(tuple<int,int,int>(i+dir[d][0],j+dir[d][1],de+1));
        }
    }
    return 100000000;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int ti = 0; ti < N; ti++){
                for(int tj = 0; tj < M; tj++){
                    if(arr[i][j] == '.' && arr[ti][tj] == '.'){
                        memset(used,false,sizeof used);
                        int ans = solve(i,j, ti,tj);
                        if(ans < 1000000)
                            maxi = max(maxi, ans);
                    }
                }
            }
        }
    }
    cout << maxi << endl;
}