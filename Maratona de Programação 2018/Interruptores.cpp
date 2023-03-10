#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void printVector(const vector<bool> &V){
  for(int i = 0; i < V.size(); i++){
    cout << V[i] << " ";
  }
  cout << endl;
}

struct cash {
  int it;
  vector<bool> lamp;
};

int main(){

  int N, M, qnt, l;

  cin >> N >> M;

  vector<bool> lampadas(M, false);
  vector<bool> apagado(M, false);
  vector<cash> save;
  vector<vector<int>> interruptor;
  interruptor.resize(N);
  cin >> qnt;

  for(int i = 0; i < qnt; i++){
    cin >> l;
    lampadas[l-1] = true;
  }

  for(int i = 0; i < N; i++){
    cin >> qnt;
    for(int j = 0; j < qnt; j++){
      cin >> l;
      interruptor[i].push_back(l-1);
    }
  }
  int cnt {0};
  while(true){
    for(int i = 0; i < N; i++){
      cnt++;
      //cout << i << ": " << endl;
      //printVector(lampadas);
      for(int j = 0; j < interruptor[i].size(); j++){
        if(lampadas[interruptor[i][j]] == true){
          lampadas[interruptor[i][j]] = false;
        } 
        else if(lampadas[interruptor[i][j]] == false){
          lampadas[interruptor[i][j]] = true;
        }
      }
      //printVector(lampadas);
      if(apagado == lampadas){
        cout << cnt << endl;
        return 0;
      }
      for(const auto &x: save){
        if(x.lamp == lampadas && x.it == i){
          cout << "-1" << endl;
          return 0;
        }
      }
      save.push_back({i, lampadas});
    }
  }
}
