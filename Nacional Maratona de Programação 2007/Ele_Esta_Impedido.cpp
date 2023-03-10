#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int A, D;
    while(cin >> A >> D){
        if(!A && !D) return 0;


        int atk[A]; int def[D];
        for(int i = 0; i < A; i++){
            cin >> atk[i];
        }
        for(int i = 0; i < D; i++){
            cin >> def[i];
        }

        sort(atk, atk + A);
        sort(def, def + D);

        if(atk[0] >= def[1] || (atk[0] == def[0] && atk[0] == def[1])){
            cout << "N" << endl;
        }
        else{
            cout << "Y" << endl;
        }

        



    }

}
