#include <iostream>
 
using namespace std;
 
int main(){
 
    int N, b, yMax= 0;
 
    cin >> N;
 
    int Ballons[N];
 
    for(int i = 0; i < N; i++){
 
        cin >> b;
        Ballons[i] = b;
        yMax = max(yMax, b);
    }
 
    int *Arrows = (int*)calloc(yMax+1, sizeof(int));
    int arr = 0;
 
    for(int i = 0; i < N; i++){
 
        if(Arrows[Ballons[i]] == 0){
            arr++;
            Arrows[Ballons[i] - 1]++;
        }
        else{
            Arrows[Ballons[i]]--;
            if(Ballons[i] - 1 >= 0){
                Arrows[Ballons[i] - 1]++;
            }
        }
    
    }
 
    cout << arr << endl;
 
    free(Arrows);
 
}
