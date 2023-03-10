#include <iostream>

using namespace std;

void seq(int n){
    int maior {n};
    while(n != 1){
        if(n % 2 == 0){
            n *= (1.0/2.0);
        } else {
            n = (n * 3) + 1;
        }
        if(n > maior) maior = n;
    }
    cout << maior << endl;
}

int main(){

    int N;
    while(cin >> N){
        if(!N) break;
        seq(N);
    }

}
