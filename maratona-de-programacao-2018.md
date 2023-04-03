# Fase Regional da Maratona de Programação 2018

* [ ] Aventurando-se no Slackline (Médio)
* [ ] Bolinhas de Gude (Difícil)
* [ ] Cortador de Pizza (Difícil)
* [x] Desvendando Monty Hall (Fácil)
* [x] Enigma (Fácil)
* [ ] Festival (Difícil)
* [ ] Gasolina (Difícil)
* [ ] Hipótese Policial (Difícil)
* [x] Interruptores (Médio)
* [ ] Juntando Capitais (Difícil)
* [ ] Kepler (Difícil)
* [ ] Linhas de Metrô (Difícil)
* [ ] Modificando SAT (Médio)

## Desvendando Monty Hall

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
