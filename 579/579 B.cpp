    #include <iostream>
    #include <string.h>
    #include <map>
    #include <set>
    #include <vector>

    using namespace std;

    int main(){
        cin.tie(0);
        cout.tie(0);
        std::ios_base::sync_with_stdio(false);

        int q;
        cin >> q;
        while(q--){
            int n,a;
            cin >> n;
            int A[10001] = {0};
            map<int,int> M;
            set<int> s;
            vector<int> v;
            for(int i = 0; i < 4*n; i++){
                cin >> a;
                s.insert(a);
                A[a]++;
            }

            v.insert(v.begin(),s.begin(),s.end());
            for(int i = 0; i < 10001; i++)A[i]/=2;
            int i = 0, j = v.size()-1;

            for(; i <= j; i++){
                for(; j >= i; j--){
                    while(A[v[j]]){
                        if(i==j){
                            M[v[i]*v[i]] += A[v[i]]/2;
                            if(M[v[j]*v[i]] >= n){
                                cout << "YES" << endl;
                                goto ending;
                            }else{
                                cout << "NO" << endl;
                                goto ending;
                            }
                        }
                        //cout << v[i] << " " << v[j] << endl;
                        M[v[j]*v[i]] += min(A[v[i]],A[v[j]]);
                        if(M[v[j]*v[i]] >= n){
                            cout << "YES" << endl;
                            goto ending;
                        }
                        int k =min(A[v[i]],A[v[j]]);
                        A[v[j]]-=k;
                        A[v[i]]-=k;
                        if(A[v[i]]==0){
                            i++;
                            if(i==j)break;
                        }
                    }
                }
            }

            cout << "NO" << endl;
            ending:;
        }
    }
