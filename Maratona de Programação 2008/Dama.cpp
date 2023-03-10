#include <iostream>
#include <math.h>

using namespace std;

int X1, X2, Y1, Y2;

int main(){

    while(scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2)){
        if(!(X1) && !(Y1) && !(X2) && !(Y2)){
            return 0;
        }

        if(X1 == X2 && Y1 == Y2){
            printf("0\n");
        }
        else{
            if((X1 != X2 && Y1 == Y2) || (X1 == X2 && Y1 != Y2) || (std::abs(X1-X2) == std::abs(Y1-Y2))){
                printf("1\n");
            }
            else{
                printf("2\n");
            }
        }
    }
}
