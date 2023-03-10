#include <iostream>
#include <vector>

using namespace std;

vector<int> fib(100, 0);

int main(){
    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i < 100; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    int n;
    while(scanf("%d", &n) != EOF){
        if(!n) return 0;
        printf("%d\n", fib[n+1]);
    }
}
