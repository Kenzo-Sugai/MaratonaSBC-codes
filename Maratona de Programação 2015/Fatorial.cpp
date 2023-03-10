#include <iostream>
#include <vector>

using namespace std;

long long int N;

vector<long long int> Fatorial;

int main(){
    cin >> N;
    long long int total = 1;
    for(int i = 1; i <= 10; i++){
        total *= i;
        //cout << total << endl;
        Fatorial.push_back(total);
    }
    int t = 0;
    while(N != 0){
        for(int i = 9; i >= 0; i--){
            if(N - Fatorial[i] >= 0){
                t++;
                N -= Fatorial[i];
                //cout << Fatorial[i] << endl;
                break;
            }
        }
    }
    cout << t << endl;

}

