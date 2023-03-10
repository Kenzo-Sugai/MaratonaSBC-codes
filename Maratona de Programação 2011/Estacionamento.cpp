#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){

  int size, evt, size_car, size_total, total {0};
  string placa;
  char type;

  while(cin >> size >> evt){
    map<string, pair<int, int>> car;
    vector<bool> interval_size(size, false);
    size_total = 0;
    total = 0;
    for(int i = 0; i < evt; i++){
        cin >> type;
        if(type == 'C'){
            cin >> placa >> size_car;
            int cnt = 0, idx_start, idx_end;
            for(int j = 0; j < interval_size.size(); j++){
                if(interval_size[j] == true) cnt = 0;
                else{ 
                    cnt++;
                    if(cnt == 1){
                        idx_start = j;
                    }
                }

                if(cnt == size_car){
                    total += 10;
                    idx_end = j;
                    car[placa] = {idx_start, idx_end};
                    for(int k = idx_start; k <= idx_end; k++) interval_size[k] = true;
                    break;
                }
            }
            //for(auto x: interval_size) cout << x << " ";
            //cout << endl;
        }
        if(type == 'S'){
            cin >> placa;
            for(int j = car[placa].first; j <= car[placa].second; j++){
                interval_size[j] = false;
            }
        }
    }
    cout << total << endl;
  }
}
