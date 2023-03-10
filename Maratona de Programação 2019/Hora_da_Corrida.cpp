#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int V, P, total, g;
    long double p;
    
    cin >> V >> P;

    total = V*P;

    for(int i = 1; i <= 9; i++){
        p = ceil((total * 10.0*i) /100.0);
        g = p;
        if(i != 9)
            printf("%d ", g);
    }
    printf("%d\n", g);
}
