#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int N, n;

    while(cin >> N){
        if(!N) return 0;

        vector<int> V;

        for(int i = 0; i < N; i++){
            cin >> n;
            V.push_back(n);
        }

        int sum = 0;
        while(!V.empty()){
            sum += V[0];
            for(int i = 1; i < V.size(); i++){
                if(V[i] == V[0]){
                    V[i] = 1;
                } else
                    V[i]++;
            }
            
            V.erase(V.begin());
        }

        cout << sum << endl;
    }

}
