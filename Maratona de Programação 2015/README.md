# Fase Regional da Maratona de Programação 2015

* [x] A - Mania de Par
* [ ] B - Bolsa de valores
* [x] C - Tri-du
* [ ] D - Quebra-cabeça
* [ ] E - Espiral
* [x] F - Fatorial
* [ ] G - Guardiões Curiosos
* [x] H - Praça do Retângulo
* [ ] I - Ominobox
* [ ] J - Jogo da Estratégia
* [ ] K - Palíndromo
* [ ] L - Loteria

## Mania de Par

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
vector<vector<Vertice> > g2;
 
vector<int> d; 
vector<bool> cor;
vector<int> p;
 
 
bool comp(const int A, const int B)
{
    return d[A] > d[B];
}
 
void dijkstra(int s)
{
    vector<int> Q;
     
    p.resize(g2.size(), -1);
    cor.resize(g2.size(), false);
    d.resize(g2.size(), INT_MAX);
    Q.push_back(s);
    d[s] = 0;
    cor[s] = true;
     
    while(!Q.empty()){
        
        int u = Q[0];
        pop_heap(Q.begin(),Q.end(), comp);
        Q.pop_back();
         
        for(int i = 0; i < g2[u].size(); i++) {
			
            if(d[u] + g2[u][i].w < d[g2[u][i].ind]){
              
                d[g2[u][i].ind] = d[u] + g2[u][i].w;
                p[g2[u][i].ind] = u;
            }
            
            if(cor[g2[u][i].ind] == false){
                cor[g2[u][i].ind] = true;
                Q.push_back(g2[u][i].ind); 
            }
        }
 
        make_heap(Q.begin(), Q.end(), comp);
    }
}
int main(){
	int X,Y, M, N, peso, peso2;
    scanf("%d %d", &N, &M);
    g.resize(N+1);
    g2.resize(N+1);
	double w;
	for(int i=0;i<M;i++){
		scanf("%d %d %lf", &X, &Y, &w);
		g[X].push_back(Vertice(Y,w));
        g[Y].push_back(Vertice(X,w));
    }
    for(int i = 1; i < N; i++){

        for(int j = 0; j < g[i].size(); j++){
 
            peso = g[i][j].w;
         
            int u = g[i][j].ind;
          
            for(int k = 0; k < g[u].size(); k++){
                if(g[u][k].ind != g[i][j].ind || g[u][k].ind != i){
              
                    peso2 = g[u][k].w + peso;
               
                    g2[i].push_back(Vertice(g[u][k].ind, peso2));
                }
            }
        }
    }
    dijkstra(1);
    if(d[N] == INT_MAX){
        printf("-1\n");
    }
    else{
       printf("%d\n", d[N]); 
    }
	return 0;
}
```
