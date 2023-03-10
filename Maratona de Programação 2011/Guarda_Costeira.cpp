#include <iostream>
#include <math.h>

using namespace std;
 
int main() {
    float D, VF, VG, t, tempF, tempG, hip;
    while(cin >> D >> VF >> VG){
        bool v = false;
        for(int i = 1; i <= 12; i++){
         tempF = i/VF;
         hip = sqrt((D*D) + (i*i));
         tempG = hip/VG;
         //cout << "G: " << tempG << endl;
         //cout << "F: " << tempF << endl;
         if(tempG <= tempF){
             v = true;
             cout << "S" << endl;
             break;
         }
        }
        if(v == false){
            cout << "N" << endl;
        }
    }
 
    return 0;
}
