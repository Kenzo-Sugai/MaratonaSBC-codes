#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, I, X, Y, n, t, g, px, py;
vector<vector<int>> G;
vector<int> K;
void BFS(int idx){
  bool v = false;
  int menor = 100000, cnt = 0; 
  queue<int> Q;
  vector<bool> color(N+1, false);
  vector<int> d(N+1, -1);
  Q.push(idx);
  while(!Q.empty()){
    int u = Q.front();
    cnt++;
    //cout << "u: " << u << endl;
    Q.pop();
    for(int i = 0; i < G[u].size(); i++){
      if(!color[G[u][i]]){
        if(K[G[u][i]-1] < menor){
          menor = K[G[u][i]-1];
        }
        color[G[u][i]] = true;
        d[G[u][i]] = d[u] +1;
        Q.push(G[u][i]); 
      }
    }
    if(cnt == 1 && G[u].size() == 0){
      v = true;

    }
  }
  if(v == true){
    cout << "*" << endl;
  }
  else{
    cout << menor << endl;
  }
}
int main(){
  string Q;
  while(cin >> N >> M >> I){
    G.resize(N+1);
    vector<int> index;
    for(int i = 0; i < N; i++){
      cin >> n;
      K.push_back(n);
      index.push_back(i+1);
    }
    for(int i = 0; i < M; i++){
      cin >> X >> Y;
      G[Y].push_back(X);
    }
    for(int i = 0; i < I; i++){
      cin >> Q;
      if(Q == "P"){
        cin >> n;
        for(int j = 0; j < N; j++){
          if(index[j] == n){
            g = j+1;   
          }
        }
        //cout << "Pergunta para: " << n << endl;
        BFS(g);
      }
      if(Q == "T"){
        cin >> X >> Y;
        //cout << "Troca de " << X << " para o " << Y << endl;
        for(int j = 0; j < index.size(); j++){
          if(index[j] == X){
            px = j;
          }
          if(index[j] == Y){
            py = j;
          }
        }
        //cout << "px: " << px << " py: " << py << endl;
        t = K[px];
        K[px] = K[py];
        K[py] = t;

        g = index[px];
        index[px] = index[py];
        index[py] = g;
        /*
        for(int j = 0; j < N; j++){
          cout << K[j] << " ";
        }
        cout << endl;
        */
      }
    }
    G.clear();
    K.clear();
  }
}
