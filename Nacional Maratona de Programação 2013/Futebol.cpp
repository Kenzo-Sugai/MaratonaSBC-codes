#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct jogos{
  int casa;
  int adv;
  int pontos;
  int dif;
};

bool compare(jogos A, jogos B){
  return A.dif < B.dif;
}

int main(){

  int partidas, gols, H, A, p, total, diferenca, index, dif;

  while(scanf("%d %d", &partidas, &gols) != EOF){

    vector<jogos> P;
    total = 0;
    for(int i = 0; i < partidas; i++){
      cin >> H >> A;
      if(H == A){
        if(gols > 0){
          H++;
          p = 3;
          gols--;
        } 
        else{
          p = 1;
          dif = abs(H-A);
          P.push_back({H, A, p, dif});
        }
      }
      else if(H > A){
        p = 3;
      }
      else{
        p = 0;
        dif = abs(H-A);
        P.push_back({H, A, p, dif});
      }
      total += p;
    }

    sort(P.begin(), P.end(), compare);

    for(int i = 0; i < P.size(); i++){
      if(gols == 0){
        break;
      }
      if(P[i].pontos == 1){
        gols--;
        total += 2;
      }
      if(P[i].pontos == 0){
        if(gols == P[i].dif){
          gols -= P[i].dif;
          total += 1;
        }
        else if(gols > P[i].dif){
          gols -= P[i].dif+1;
          total += 3;
        }
        else{
          gols = 0;
        }
      }
    }
    printf("%d\n", total);
  }
}
