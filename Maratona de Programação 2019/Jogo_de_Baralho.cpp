#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<char, int> cartas;

int N, C;
bool joker = false;

class jogador{
  public:
    int n;
    int deck[14] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    jogador(int a, int b, int c, int d){
      deck[a]++;
      deck[b]++;
      deck[c]++;
      deck[d]++;
    }
};

vector<jogador> jogadores;

int jogada(int i){
  int menor = 5, indice = 0;
  if(jogadores[i].deck[13] == 1 && joker == true){
    joker = false;
    return 13;
  }
  else{
    for(int j = 0; j < 13; j++){
      int c = jogadores[i].deck[j];
      if(c < menor && c != 0){
        menor = c;
        indice = j;
      }
    }
    if(jogadores[i].deck[13])
      joker = true;
    return indice;
  }
}

bool verificar(int i){
  for(int j = 0; j < 14; j++){
    if(jogadores[i].deck[j] == 4){
      return true;
    }
  }
  return false;
}

int main(){
  int vez;
  cartas['A'] = 0;
  cartas['2'] = 1;
  cartas['3'] = 2;
  cartas['4'] = 3;
  cartas['5'] = 4;
  cartas['6'] = 5;
  cartas['7'] = 6;
  cartas['8'] = 7;
  cartas['9'] = 8;
  cartas['D'] = 9;
  cartas['Q'] = 10;
  cartas['J'] = 11;
  cartas['K'] = 12;
  cartas['C'] = 13;
  string D;
  cin >> N >> C;
  C--;
  for(int i = 0; i < N; i++){
    cin >> D;
    jogadores.push_back(jogador(cartas[D[0]], cartas[D[1]], cartas[D[2]], cartas[D[3]]));
    jogadores[i].n = i+1;
    if(i == C){
      vez = i;
      jogadores[i].deck[13] += 1;

    }
  }
  int contador = 0;
  for(int i = 0; i < jogadores.size(); i++){
    if(verificar(i) && jogadores[i].deck[13] == 0){
      cout << i+1 << endl;
      return 0;
    }
  }
  while(true){
    /*
    cout << "-- RODADA " << contador << " --" << endl;
    contador++;
    for(int i = 0; i < jogadores.size(); i++){
      cout << "i: " << i << endl;
      for(int j = 0; j < 14; j++){
        cout << jogadores[i].deck[j] << " ";
      }
      cout << endl;
    }
    */
    int p = jogada(vez);
    jogadores[vez].deck[p]--;
    if(verificar(vez)){
      cout << vez+1 << endl;
      break;
    }
    vez++;
    if(vez == N){
      vez = 0;
    }
    jogadores[vez].deck[p]++;
  }
  return 0;
}
