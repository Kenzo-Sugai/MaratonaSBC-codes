# Fase Regional da Maratona de Programação 2007

* [ ] Onde Estão as Bolhas? (Difícil)
* [ ] Mário (Difícil)
* [x] Zak Galou (Difícil)
* [ ] Desempilhando Caixas (Difícil)
* [x] Histórico de Comandos (Médio)
* [ ] Olimpíadas (Médio)
* [ ] Série de Tubos (Médio)
* [ ] Jogo de Varetas (Fácil)
* [ ] Vôlei Marciano (Médio)
* [ ] Rouba Monte (Médio)

## Histórico de Comandos

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int N, n;

    while(cin >> N){
        if(!N) return 0;

        vector<int> V;

        for(int i = 0; i < N; i++){
            cin >> n;
            V.push_back(n);
        }

        int sum = 0;
        while(!V.empty()){
            sum += V[0];
            for(int i = 1; i < V.size(); i++){
                if(V[i] == V[0]){
                    V[i] = 1;
                } else
                    V[i]++;
            }
            
            V.erase(V.begin());
        }

        cout << sum << endl;
    }

}
```

## Zak Galou

```cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<climits>
#include <map>

using namespace std;

struct item{
    int mana;
    int dmg;
};

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
 
void dijkstra(int s)
{
    vector<int> Q;
     
    p.resize(g.size(), -1);
    cor.resize(g.size(), false);
    d.resize(g.size(), INT_MAX);
    Q.push_back(s);
    d[s] = 0;
    cor[s] = true;
     
    while(!Q.empty()){

        int u = Q[0];
        pop_heap(Q.begin(),Q.end(), comp);

        Q.pop_back();
     
        for(int i = 0; i < g[u].size(); i++) {
            
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

int knapsack_repeat(int true_W, int W, vector<item>& itens, int n){
    vector<int> S(W+1, INT_MAX);
    S[0] = 0;

    for (int i = 1; i <= W; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (itens[j].dmg <= i) {
                int tempDmg = S[i-itens[j].dmg];
                if (tempDmg != INT_MAX && tempDmg+itens[j].mana < S[i]) {
                    S[i] = tempDmg + itens[j].mana;
                }
            }
            else if (itens[j].dmg >= i && itens[j].mana < S[i])
            {
                S[i] = itens[j].mana;
            }
            
        }
    
    }
 
    for (int i = true_W; i <= W; i++)
    {
        if (S[i] != INT_MAX)
        {
            return S[i];
        }
        
    }

    return S[true_W];
}

int main() {

    int X, Y, M, N, spell, mons, S, H, v,w, total = 0;

    while (scanf("%d %d %d %d", &spell, &N, &M, &mons) != EOF)
    {
       
        if (!spell && !N && !M && !mons){
            break;
        }
    
        int max_dmg = 0;
        vector<item> itens;

        for(int i = 0; i < spell; i++){
            scanf("%d %d", &v, &w);
            itens.push_back({v, w});
            if (w > max_dmg) {
                max_dmg = w;
            }
        }

        g.resize(N+1);
        for(int i = 0; i < M; i++){
            scanf("%d %d", &X, &Y);
            g[X].push_back(Vertice(Y, 0));
            g[Y].push_back(Vertice(X, 0));
        }
        total = 0;
        map<int, vector<int>> monstros;
        for(int i = 0; i < mons; i++){
            scanf("%d %d", &S, &H);
            if(S == 1 or S == N){
                monstros[S].push_back(H);
                total += H;
            }
            else{
                monstros[S].push_back(H);
                for(int j = 0; j < g[S].size(); j++){
                    int k = 0;
            
                    for(; g[g[S][j].ind][k].ind != S; k++){}
                    g[g[S][j].ind][k].w += H;
                    
                }
            }
              
        }

        dijkstra(1);

        if (d[N] == INT_MAX){
            printf("-1\n");
        }
        else{
            d[N] += total;
            if (d[N] == 0) {
                printf("0\n");
            }
            else{
                int resp = 0;
                int papai = N, res;
                map<int, int> save;
                while(papai != -1){
                    for(int idx = 0; idx < monstros[papai].size(); idx++){
                        
                        if(save[monstros[papai][idx]] != 0){
                            resp += save[monstros[papai][idx]];
                        }
                        else{
                            int true_W = monstros[papai][idx];
                            int W = monstros[papai][idx] + max_dmg;
                            int n = itens.size();
                            
                            res = knapsack_repeat(true_W, W, itens, n);
                            save[monstros[papai][idx]] = res;
                            resp += res;
                        }
        
                    }
                    papai = p[papai];
                }
              
                if (resp != INT_MAX){
                    printf("%d\n", resp);
                }
                else{
                    printf("-1\n");
                }
            }
        }

        p.clear();
        cor.clear();
        d.clear();
        g.clear();

    } 
}
```
