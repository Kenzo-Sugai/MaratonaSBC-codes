#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  bool v = false;
  string word;
  vector<char> letter;
  vector<string> words;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    cin >> word;
    words.push_back(word);
    letter.push_back(word[0]);
  }
  for(int i = 0; i < N; i++){
    int cont = 0;

    for(int j = 0; j < words[i].size(); j++){

      bool in = false;
      for(int k = 0; k < letter.size(); k++){
        if(char(words[i][j]) == letter[k]){
          //cout << letter[k] << " true" << endl;
          cont++;
          in = true;
          break;
        }

      }

      if(in == false){
        //cout << words[i][j] << " false" << endl;
        break;

      }

    }
    if(cont == words[i].size()){
      v = true;
      break;
    }
  }
  if(v == true){
    printf("Y\n");
  }
  else{
    printf("N\n");
  }
}
