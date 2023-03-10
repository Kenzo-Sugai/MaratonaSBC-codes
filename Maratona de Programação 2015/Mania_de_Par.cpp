#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdio>
#include<climits>
 
using namespace std;
 
// Estrutura usada para implementar a lista de adjac?ncia
class Vertice{
    public:
        double w; // peso da aresta
        int ind; // identifica??o do vertice destino da aresta
         
        // Construtores
        Vertice(){};
         
        Vertice(int ind, double w){
            this->w = w;
            this->ind = ind;
        }
};
 
 
vector< vector<Vertice> > g; // Lista de Adjac?ncia.
vector<vector<Vertice> > g2;
 
 
// Vetores utilizados no algoritmo de Dijkstra
 
//para os 3 vetores a seguir, cada posi??o do vetor representa um vertice do grafo.
vector<int> d; // Vetor que armazena o peso da aresta usada para alcan?ar o v?rtice.
vector<bool> cor; // Define se cada vertice ja foi encontrado ou n?o.
vector<int> p; // Vetor que armazena o pai de cada vertice.
 
 
// Fun??o de compara??o para utilizar a estrutura heap de minimo.
// Pois a biblioteca <algorithm> tem por padr?o a implementa??o do heap de m?ximo.
bool comp(const int A, const int B)
{
    return d[A] > d[B];
}
 
 
// Algoritmo calcula a menor distancia para alcan?ar todos os vertices do grafo partindo de um vertice inicial.
// S? funciona para arestas ponderadas.
void dijkstra(int s)
{
    vector<int> Q; // Vetor utilizado no heap de minimo bin?rio
     
    // Inicializa??o
    p.resize(g2.size(), -1);
    cor.resize(g2.size(), false);
    d.resize(g2.size(), INT_MAX);
    Q.push_back(s);
    d[s] = 0;
    cor[s] = true;
     
    // Enquanto o heap n?o estiver vazio
    while(!Q.empty()){
        // Procedimento para retirar a raiz da estrutura de heap
        int u = Q[0];
        pop_heap(Q.begin(),Q.end(), comp);
        Q.pop_back();
         
        // Para todo vertice adjacente ? "u"
        for(int i = 0; i < g2[u].size(); i++) {
            // Se o vertice adjacente ? "u" for diferente do vertice pai de "u"
            // E se a aresta para alcan?ar o vertice adjacente for mais leve do que a j? utilizada.
			
            if(d[u] + g2[u][i].w < d[g2[u][i].ind]){
                // Processo de relaxamento
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

        //cout << "Vertice " << i  << ":" << endl;
        for(int j = 0; j < g[i].size(); j++){
            //cout << j << ":" << endl;
            peso = g[i][j].w;
            // cout << "peso: " << peso << endl;
            int u = g[i][j].ind;
            //cout << u << ":" << endl;
            for(int k = 0; k < g[u].size(); k++){
                if(g[u][k].ind != g[i][j].ind || g[u][k].ind != i){
                    //cout << g[u][k].ind << ":" << endl;
                    peso2 = g[u][k].w + peso;
                    //cout << "peso2: " << peso2 << endl;
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
