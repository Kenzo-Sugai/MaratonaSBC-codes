#include <iostream>
#include <cmath>
 
int main() {
     
    int loopQuantity;
    std::cin >> loopQuantity;

    while (loopQuantity--) {
        long long int cardsQuantity;
        std::cin >> cardsQuantity;

        double cardsLevel = abs((2 * sqrt(6 * cardsQuantity + 1) - 1) / 6) + pow(10, -9);
        std::cout << ((long long int)cardsLevel) << std::endl;
    }
 
    return 0;
}
