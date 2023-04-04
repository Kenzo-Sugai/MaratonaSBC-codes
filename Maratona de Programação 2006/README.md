# Fase Regional da Maratona de Programação 2006

* [ ] WA - Fechem as Portas!
* [x] WA - Esquerda, Volver!
* [x] A - Circuito Bioquímico Digital
* [ ] B - O Problema da Parada
* [x] C - Países em Guerra
* [ ] D - Energia X Tempo
* [ ] E - MegaDamas
* [ ] F - Copa do Mundo
* [ ] G - Rota Crítica
* [ ] H - Amigos ou Inimigos?

## Esquerda, Volver!

```cpp
#include <iostream>

using namespace std;

int main(){

    int N;
    char position[] = {'N', 'L', 'S', 'O'};
    string comandos;
    while(cin >> N){
    
        if(!N) return 0;
        
        cin >> comandos;
        
        int pos = 0;
        
        for(int i = 0; i < comandos.size(); i++){
            if(comandos[i] == 'D') pos++;
            else pos--;

            if(pos > 3) pos = 0;
            else if(pos < 0) pos = 3;
        }

        cout << position[pos] << endl;
    }
    
}
```

## Países em Guerra

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<climits>
 
using namespace std;
 
class Vertice{
    public:
        double w;
        int ind;
         
        Vertice(){};
         
        Vertice(int ind, double w){
            this->w = w;
            this->ind = ind;
        }
};
 
 
vector< vector<Vertice> > g;
 
vector<int> d; 
vector<bool> cor;
vector<int> p;
 
bool comp(const int A, const int B)
{
    return d[A] > d[B];
}
 
 

void dijkstra(int s, int t)
{
    vector<int> Q;
     
    cor.clear();
    p.clear();
    d.clear();
    p.resize(g.size(), -1);
    cor.resize(g.size(), false);
    d.resize(g.size(), INT_MAX);
    Q.push_back(s);
    d[s] = 0;
    cor[s] = true;
    bool search = false;
   
    while(!Q.empty()){
        
        int u = Q[0];
        pop_heap(Q.begin(),Q.end(), comp);
        Q.pop_back();
         
        for(int i = 0; i < g[u].size(); i++) {
          if(g[u][i].ind == t){
          
          }
          if(d[u] + g[u][i].w < d[g[u][i].ind]){
            d[g[u][i].ind] = d[u] + g[u][i].w;
            p[g[u][i].ind] = u;
          }  
          if(cor[g[u][i].ind] == false){
            cor[g[u][i].ind] = true;
            Q.push_back(g[u][i].ind); 
          }
        }
 
        make_heap(Q.begin(), Q.end(), comp);
    }
}
int main(){
	int X, Y, M, N, K, cnt = 0;
  while(true){
    cin >> N >> M;
    if(N == 0 && M == 0){
      break;
    }
    cnt++;
    g.resize(N+1);
	  double w;
    bool v = false;
    int j;
    for(int i = 0; i < M; i++){
      cin >> X >> Y >> w;
      for(j = 0; j < g[Y].size(); j++){
        if(g[Y][j].ind == X){
          v = true;
          break;
        }
      }
      if(v== false){
         g[X].push_back(Vertice(Y,w));
      }
      else{
        g[X].push_back(Vertice(Y,0));
        g[Y][j].w = 0;
        v = false;
      }
    }
   
    cin >> K;
	  for(int i=0;i<K;i++){
      cin >> X >> Y;
      dijkstra(X, Y);
      if(d[Y] == INT_MAX){
        cout << "Nao e possivel entregar a carta" << endl;
      }
      else{
        cout << d[Y] << endl;
      }
    }
    g.clear();
    cout << endl;
  }
	return 0;
}
```

## Circuito Bioquímico Digital

```cpp
#include <iostream>

using namespace std;

int main(){
    
    int N, M, C;

    while(cin >> N >> M >> C){
        if(!N && !M && !C){
            return 0;
        }
        int result {0};
        int exp[M][N];

        for(int i = 0; i < M; i++){

            for(int j = 0; j < N; j++){
                cin >> exp[i][j];
            }
        }

        for(int i = 0; i < N; i++){
            int cnt {0};
            for(int j = 0; j < M; j++){
          
                if(exp[j][i] == 1){
                    cnt++;
                }
                else{
                    if(cnt >= C){
                        result++;
                    }
                    cnt = 0;
                }
            }
            if(cnt >= C){
                result++;
            }
        }
        cout << result << endl;
    }
}
```
