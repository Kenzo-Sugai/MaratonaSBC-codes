#include <iostream>
#include <string>

using namespace std;

long long int fatorial(long long int n){
    if(n <= 1) return 1;
    return n * fatorial(n - 1);
}

int main(){

    string N;
    string aux = "";
    while(cin >> N){
        if(N == "0") return 0;
        int sum = 0;
        int size = N.size();
        for(int i = 1; i <= size; i++){
            aux += N.back();
            //cout << fatorial(i) << endl;
            sum += stoi(aux)*fatorial(i);
            aux = "";
            N.pop_back();
            
        }

        cout << sum << endl;
    }

}
