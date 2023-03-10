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
