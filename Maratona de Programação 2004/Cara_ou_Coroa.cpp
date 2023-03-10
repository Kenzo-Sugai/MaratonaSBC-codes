#include <iostream>

using namespace std;

int main(){

  int N, ri, M = 0, J = 0;

  while(cin >> N){
    if(N == 0){
      break;
    }

    M = 0, J =0;

    while(N--){
      cin >> ri;
      if(ri == 0)
        M++;
      else
        J++;
    }
    cout << "Mary won " << M << " times and John won " << J << " times" << endl;
  }
}
