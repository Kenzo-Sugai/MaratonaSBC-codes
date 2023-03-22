#include <bits/stdc++.h>
 
using namespace std;
 
struct cord {
    int i, j;
};
 
unordered_map<int, cord> pos; 
 
int main(int argc, char const *argv[])
{
    
    int R, C, n;
    cin >> R >> C;
    vector<vector<int>> G(R);
 
    for(int i = 0; i < R; i++){
 
        for(int j = 0; j < C; j++){
 
            cin >> n;
            pos[n] = {i, j};
            G[i].push_back(n);
 
        }
 
    }
 
    vector<int> comidas(R*C, 0);
 
    int maxvalue = 0;
 
    for(int i = 1; i <= R*C; i++){
 
        if(comidas[i - 1] == 0){
 
            queue<cord> Q;
            Q.push(pos[i]);
            int lvl = i;
            unordered_map<int, int> dist;
            dist[i] = 1;
            vector<bool> cor(R*C, false);
            vector<int> pode;
 
            while(!Q.empty()){
 
                cord u = Q.front(); Q.pop();
 
                int I = u.i;
                int J = u.j;
 
                //cout << G[I][J] << endl;
 
                if(I - 1 >= 0 && G[I - 1][J] > lvl && !cor[G[I - 1][J]]){
 
                    pode.push_back(G[I - 1][J]);
                    cor[G[I - 1][J]] = true;
 
                }
                if(I + 1 < R && G[I + 1][J] > lvl && !cor[G[I + 1][J]]){
 
                    pode.push_back(G[I + 1][J]);
                    cor[G[I + 1][J]] = true;
 
                }
                if(J - 1 >= 0 && G[I][J - 1] > lvl && !cor[G[I][J - 1]]){
 
                    pode.push_back(G[I][J - 1]);
                    cor[G[I][J - 1]] = true;
 
                }
                if(J + 1 < C && G[I][J + 1] > lvl && !cor[G[I][J + 1]]){
 
                    pode.push_back(G[I][J + 1]);
                    cor[G[I][J + 1]] = true;
 
                }
 
                if(pode.size() > 0)
                    sort(pode.begin(), pode.end());
 
                if(pode.size() > 0 && pode[0] > lvl){
                    dist[pode[0]] = dist[lvl] + 1;
                    lvl = pode[0];
                    Q.push(pos[lvl]);
                    pode.erase(pode.begin());
                }
            }
 
            for(auto x : dist){
                
                if(comidas[x.first - 1] < x.second){
                    maxvalue = max(maxvalue, x.second);
                    comidas[x.first - 1] = x.second;
                }
            }
        }
 
    }
 
 
    cout<< maxvalue << endl;
 
 
 
 
 
    return 0;
}
