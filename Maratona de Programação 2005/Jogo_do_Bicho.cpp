#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

  double V;
  int N, M, n, m;
  string sN, sM, auxn, auxm;
  
  while(cin >> V >> N >> M){
    if(!V && !N && !M) return 0;
    auxn = ""; auxm = "";
    sN = to_string(N);
    sM = to_string(M);
    
    reverse(sN.begin(), sN.end());
    reverse(sM.begin(), sM.end());

    while(sN.size() < 4) sN += "0";
    while(sM.size() < 4) sM += "0";
    
    int cnt = 0;
    //cout << sN << " " << sM << endl;
    for(int i = 0; i < 4; i++){
      if(sN[i] == sM[i]){
        cnt++;
      }
      else {
        break;
      }
    }
    if(cnt <= 1){
        auxn += sN[1];
        auxn += sN[0];
        auxm += sM[1];
        auxm += sM[0];
        n = stoi(auxn);
        m = stoi(auxm);
        n--; m--;
        //cout << "n: " << auxn << " m: " << auxm << endl; 
        if(n == -1) n = 99;
        if(m == -1) n = 99;
      n /= 4;
      m /= 4;

      //cout << "n: " << n << " m: " << m << endl;

      if(n == m){
        cnt = 1;
      } else cnt = 0;
      
    }

    switch(cnt){
      case 4:
        V *= 3000;
        break;
      case 3:
        V *= 500;
        break;
      case 2:
        V *= 50;
        break;
      case 1:
        V *= 16;
        break;
        default:
        V = 0;
        break;
    }

    printf("%.2lf\n", V);
  }
  
}
