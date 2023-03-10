#include <iostream>

using namespace std;

int main(){

  int aux, X, cntX, cntY, Y, resto {0}, i {2};

  cin >> X >> Y;
  if(X == Y){
    cout << 0 << endl;
    return 0;
  }

  if(X > Y){
    aux = X;
    X = Y;
    Y = aux;
  }
  cntX = X;
  cntY = Y;
  cntX += X;
  //cout << cntX << "  " << cntY << endl;
  while(cntX > cntY){
    i += 1;
    cntX += X;
    cntY += Y;
    //cout << cntX << "  " << cntY << endl;
  }
  cout << i << endl;
}
