#include <iostream>
#include <math.h>

#define PI 3.14159265358979323846

using namespace std;

int main(){

    int L, C, R1, R2, D, D1, D2;

    while(cin >> L >> C >> R1 >> R2){
        if(L == 0 && C == 0 && R1 == 0 && R2 == 0){
            return 0;
        }
        D1 = R1*2;
        D2 = R2*2;
        D = R1+R2;
        

        if(D1 <= L && D1 <= C && D2 <= L && D2 <= C && D <= sqrt(pow(R1-(L-R2),2) + pow(R1-(C-R2),2))){
            cout << "S" << endl;
        }
        else{
            cout << "N" << endl;
        }
    }
}
