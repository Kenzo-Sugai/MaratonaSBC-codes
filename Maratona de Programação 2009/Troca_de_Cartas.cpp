#include <iostream>
#include <set>

using namespace std;

int main(){

    int A, B, n;

    while(cin >> A >> B){

        if(!A && !B) return 0;

        set<int> A_Cards;
        set<int> B_Cards;
        set<int> conj;

        for(int i = 0; i < A; i++){
            cin >> n;
            A_Cards.insert(n);
            conj.insert(n);
        }

        for(int i = 0; i < B; i++){
            cin >> n;
            B_Cards.insert(n);
            conj.insert(n);
        }

        cout << min(conj.size() - A_Cards.size(), conj.size() - B_Cards.size()) << endl;

    }

}
