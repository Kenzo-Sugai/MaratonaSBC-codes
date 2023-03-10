#include <iostream>

using namespace std;

int main(){

    int N;
    char position[] = {'N', 'L', 'S', 'O'};
    string comandos;
    while(cin >> N){
        if(!N) return 0;
        cin >> comandos;
        int pos = 0;
        for(int i = 0; i < comandos.size(); i++){
            if(comandos[i] == 'D') pos++;
            else pos--;

            if(pos > 3) pos = 0;
            else if(pos < 0) pos = 3;
        }

        cout << position[pos] << endl;
    }
    

}
