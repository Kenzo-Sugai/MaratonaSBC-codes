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

## Tri-du

```cpp
#include <iostream>

using namespace std;

int main(){
    
 int A, B;
 cin >> A >> B;
 if(A >= B) cout << A << endl;
 else cout << B << endl;
}
```

## Fatorial

```cpp
#include <iostream>
#include <vector>

using namespace std;

long long int N;

vector<long long int> Fatorial;

int main(){
    cin >> N;
    long long int total = 1;
    for(int i = 1; i <= 10; i++){
        total *= i;
        Fatorial.push_back(total);
    }
    int t = 0;
    while(N != 0){
        for(int i = 9; i >= 0; i--){
            if(N - Fatorial[i] >= 0){
                t++;
                N -= Fatorial[i];
                break;
            }
        }
    }
    cout << t << endl;

}


```

## Praça do Retângulo

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cord {
    int x, y;
};

bool comp(cord a, cord b){
    
    if(a.x == b.x)
        return a.y < b.y;

    return a.x < b.x;
}

int main(){

    int N, x, y, maxY = 0, minY = 0;

    cin >> N;

    vector<cord> points;

    while(N--){

        scanf("%d %d", &x, &y);
        points.push_back({x, y});
        maxY = max(maxY, y);
        minY = min(minY, y);

    }

    sort(points.begin(), points.end(), comp);

    int ret = 0;

    for(int i = 0; i < points.size(); i++){

        int maxi = maxY+1, mini = minY-1;

        for(int j = i+1; j < points.size(); j++){
            
            if(points[j].y > points[i].y && points[j].y < maxi){
                maxi = points[j].y;
                ret++;
           
            }
            if(points[j].y < points[i].y && points[j].y > mini){
                mini = points[j].y;
                ret++;
            
            }

        }

    }

    cout << ret << endl;


}c++
```
