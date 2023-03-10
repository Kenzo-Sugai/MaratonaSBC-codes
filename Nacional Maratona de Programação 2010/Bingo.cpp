#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){

    int N, B, b;

    while(cin >> N >> B){
        if(!N && !B) return 0;

        vector<int> balls;
        set<int> all_balls;

        for(int i = 0; i < B; i++){
            cin >> b;
            balls.push_back(b);
        }

        for(int i = 0; i < balls.size(); i++){

            for(int j = i; j < balls.size(); j++){

                int sub = abs(balls[i] - balls[j]);
                if(sub <= N) all_balls.insert(sub);

            }
        }

        if(all_balls.size() == N+1) cout << "Y" << endl;
        else cout << "N" << endl;
    }

}
