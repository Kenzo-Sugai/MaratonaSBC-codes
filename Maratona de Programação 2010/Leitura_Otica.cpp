#include <iostream>

using namespace std;

int main(){

    int N, n;
    char notas[5] = {'A', 'B', 'C', 'D', 'E'};

    while(cin >> N && N){
        
        for(int i= 0; i< N; i++){

            int R, c = 0;

            for(int j = 0; j < 5; j++){

                cin >> n;
                if(n <= 127){
                    R = j;
                    c++;
                }

            }

            if(c == 1) cout << notas[R] << endl;
            else cout << '*' << endl;

        }

    }

}
