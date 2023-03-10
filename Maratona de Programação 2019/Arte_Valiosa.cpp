#include <bits/stdc++.h>

using namespace std;

double distancia(int x1, int y1, int x2, int y2){

  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  
}

struct sensor {

  int x, y, s, n;

};

void DFS(int u, vector<vector<int>> &G, vector<bool> &cor){

  cor[u] = true;
  
  for(int i = 0; i < G[u].size(); i++){
    if(!cor[G[u][i]])
      DFS(G[u][i], G, cor);
      
    
  }
  
}

int main() {

  int N, M, K, X, Y, R;

  vector<sensor> sensores; 
  
  cin >> M >> N >> K;

  vector<vector<int>> G(4+K);

  int noCount = 4;
  
  for(int i = 0; i < K; i++){

    cin >> X >> Y >> R;

    if(X - R <= 0){
      G[0].push_back(noCount);
      G[noCount].push_back(0);
    }
    if(Y + R >= N){
      G[1].push_back(noCount);
      G[noCount].push_back(1);
    }
    if(X + R >= M){
      G[2].push_back(noCount);
      G[noCount].push_back(2);
    }
    if(Y - R <= 0){
      G[3].push_back(noCount);
      G[noCount].push_back(3);
    }

    for(int j = 0; j < sensores.size(); j++){

      if(distancia(
        sensores[j].x, sensores[j].y, X, Y
        ) <= sensores[j].s + R){
        G[noCount].push_back(sensores[j].n);
        G[sensores[j].n].push_back(noCount);
        }
    }

    sensores.push_back({X, Y, R, noCount});
    noCount++;
    
  }
  /*
  for(int i = 0; i < G.size(); i++){

    cout << i << ": ";
    
    for(int j = 0; j < G[i].size(); j++){

      cout << G[i][j] << " ";
      
    }
    cout << endl;
    
  }*/

  vector<bool> coresq(G.size(), false);
  DFS(0, G, coresq);
  
  vector<bool> corbaixo(G.size(), false);
  DFS(3, G, corbaixo);

  vector<bool> corcima(G.size(), false);
  DFS(1, G, corcima);

  if((coresq[3]) || (coresq[1] && corbaixo[1]) || (corbaixo[1]) || coresq[2] || corcima[2]) cout << "N" << endl;
  else cout << "S" << endl;
  

  
  
  
  
}
