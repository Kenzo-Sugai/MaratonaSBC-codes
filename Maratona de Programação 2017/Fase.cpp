#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
  return a > b;
}

int main(){

  int N, min;
  int n;

  cin >> N;
  cin >> min;
  vector<int> notas;
  for(int i = 0; i < N; i++){
    cin >> n;
    notas.push_back(n);
  }

  sort(notas.begin(), notas.end(), compare);
  int cnt {min};

  for(int i = min; i < notas.size(); i++){
    if(notas[i] == notas[i - 1]){
      cnt++;
    }
    else{
      break;
    }
  }
  cout << cnt << endl;

}
