#include <iostream>
 
using namespace std;
 
int main() {
    int N, L, D;
    cin >> N >> L >> D;
    
    int min = N * D;
    int litros = L*1000;
    while(litros < min) litros += L*1000;
    cout << litros/1000 << endl;
    
 
    return 0;
}
