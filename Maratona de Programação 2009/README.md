# Fase Regional da Maratona de Programação 2009

* [ ] Fulminante
* [x] Alarme Despertador
* [x] Troca de Cartas
* [ ] Sub-prime
* [ ] Dragster
* [x] Escultura à Laser
* [ ] Torres de Telefonia Celular
* [ ] Registrador de Deslocamento

## Alarme Despertador

```cpp
#include <iostream>
#include <math.h>

using namespace std;
 
int main() {
 
    int H1, M1, H2, M2, H, M;
    
    while(cin >> H1 >> M1 >> H2 >> M2){
        if(H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0){
            return 0;
        }
    
        if(M2 > M1){
            M = M2-M1;
        }
        if(M1 > M2){
            M = M1-M2;
            M = std::abs(M-60);
            H1++;
        }
        if(M1 == M2){
            M = 0;
        }
        if(H2 > H1){
            H = H2-H1;
        }
        if(H1 > H2){
            H = H1-H2;
            H = std::abs(H-24);
        }
        if(H1 == H2){
            if(M1 == M2){
            H = 24;
            }
            else{
            H = 0;
            }
        }

        cout << (H*60)+M << endl;
    }
}
```

## Escultura à Laser

```cpp
#include <iostream>

using namespace std;

int main(){

    int A, C, n;

    while(cin >> A >> C){
        if(!A & !C) return 0;
        int alturas[C];

        int cnt = 0, alturaAnt = 0, altura;

        for(int i = 0; i < C; i++){

            cin >> alturas[i];
            altura = A - alturas[i];
            if(altura > alturaAnt){
                cnt += altura - alturaAnt;
            }
            alturaAnt = altura;

        }

        cout << cnt << endl;

    }

}
```

## Troca de Cartas

```cpp
#include <iostream>
#include <set>

using namespace std;

int main(){

    int A, B, n;

    while(cin >> A >> B){

        if(!A && !B) return 0;

        set<int> A_Cards;
        set<int> B_Cards;
        set<int> conj;

        for(int i = 0; i < A; i++){
            cin >> n;
            A_Cards.insert(n);
            conj.insert(n);
        }

        for(int i = 0; i < B; i++){
            cin >> n;
            B_Cards.insert(n);
            conj.insert(n);
        }

        cout << min(conj.size() - A_Cards.size(), conj.size() - B_Cards.size()) << endl;

    }

}
```
