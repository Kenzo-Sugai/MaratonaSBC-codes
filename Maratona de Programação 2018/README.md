# Fase Regional da Maratona de Programação 2018

* [ ] Aventurando-se no Slackline
* [ ] Bolinhas de Gude
* [ ] Cortador de Pizza
* [x] Desvendando Monty Hall
* [x] Enigma
* [ ] Festival
* [ ] Gasolina
* [ ] Hipótese Policial
* [x] Interruptores
* [ ] Juntando Capitais
* [ ] Kepler
* [ ] Linhas de Metrô
* [ ] Modificando SAT

## Desvendando Monty Halll

```cpp
#include <iostream>
 
using namespace std;
 
int main() {
 
    int N, n;
    
    cin >> N;
    int cnt = 0;
    while(N--){
        
        cin >> n;
        if(n != 1) cnt++;
    }
    
    cout << cnt << endl;
 
    return 0;
}
```
