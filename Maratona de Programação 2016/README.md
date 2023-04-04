# Fase Regional da Maratona de Programação 2016

* [x] Andando do Tempo
* [ ] Batata Quente
* [x] Cachorros-Quentes
* [ ] Contaires
* [ ] Divisores
* [ ] Estatística Hexa
* [ ] Estiquetas Coloridas
* [ ] Fundindo Árvores
* [ ] Go--
* [x] Huaauhahhuahau
* [x] Isósceles
* [ ] Jogos Olímpicos
* [ ] Kit de Encolhimento de Polígonos
* [x] Ladrilhos

## Andando no Tempo

```cpp
#include <iostream>

using namespace std;

int main(){

  int a, b, c;
  cin >> a >> b >> c;
  if(a == b || a == c || b == c){
    cout << "S" << endl;
  }
  else if(a + b == c || a + c == b || b + c == a){
    cout << "S" << endl;
  }
  else{
    cout << "N" << endl;
  }
}
```

## Cachorros-Quentes

```cpp
#include <iostream>
 
using namespace std;
 
int main() {
 
    double H, P;
    scanf("%lf %lf", &H, &P);
    double C = H/P;
    printf("%.2lf\n", C);
 
}
```

## Huaauhahhuahau

```cpp
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
 
    string S, temp, reversetemp;
    cin >> S;
    for(int i : S){
        if(i == 'a' or i == 'e' or i == 'i' or i == 'o' or i == 'u'){
            temp += i;
        }
    }
    reversetemp = temp;
    reverse(reversetemp.begin(), reversetemp.end());
    
    if(temp == reversetemp) cout << "S" << endl;
    else cout << "N" << endl;
 
    return 0;
}
```

## Isósceles

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;

    cin >> N;

    vector<int> esq(N), dir(N), h(N);

    for(int i = 0; i < N; i++){

        cin >> h[i];

    }

    esq[0] = dir[N - 1] = 1;

    for(int i = 1, j = N - 2; i < N; i++, j--){

        esq[i] = min(h[i], esq[i - 1] + 1);
        dir[j] = min(h[j], dir[j + 1] + 1);
    
    }

    int resp = 0;

    for(int i = 0; i < N; i++){

        resp = max(resp, min(dir[i], esq[i]));

    }

    cout << resp << endl;

}
```

## Ladrilhos

```cpp
#include <iostream>
#include <queue>

using namespace std;

struct pos {
    int i;
    int j;
    int az;
};

int main(){

    int N, M, cnt = 0, menor;

    cin >> N >> M;
    int G[N][M];
    bool cor[N][M];

    menor = N*M;
    
    for(int i = 0; i < N; i++){

        for(int j = 0; j < M; j++){
            cin >> G[i][j];
            cor[i][j] = false;
        }
    }

    queue<pos> Q;
    Q.push({0, 0, G[0][0]});

    for(int i = 0; i < N; i++){

        for(int j = 0; j < M; j++){
            if(!cor[i][j]){
                cor[i][j] = true;
                Q.push({i, j, G[i][j]});

            }
            cnt = 0;
            
            while(!Q.empty()){

                pos u = Q.front();
                Q.pop();

                cnt++;
                if(u.i-1 >= 0 && !cor[u.i-1][u.j] && G[u.i-1][u.j] == u.az){
                    cor[u.i-1][u.j] = true;
                    Q.push({u.i-1, u.j, u.az});
                }
                if(u.i+1 < N && !cor[u.i+1][u.j] && G[u.i+1][u.j] == u.az){
                    cor[u.i+1][u.j] = true;
                    Q.push({u.i+1, u.j, u.az});
                }
                if(u.j-1 >= 0 && !cor[u.i][u.j-1] && G[u.i][u.j-1] == u.az){
                    cor[u.i][u.j-1] = true;
                    Q.push({u.i, u.j-1, u.az});
                }
                if(u.j+1 < M && !cor[u.i][u.j+1] && G[u.i][u.j+1] == u.az){
                    cor[u.i][u.j+1] = true;
                    Q.push({u.i, u.j+1, u.az});
                }
            

            }

            if(cnt != 0 && cnt < menor){
                menor = cnt;
            }

        }
    }

    cout << menor << endl;

}
```
