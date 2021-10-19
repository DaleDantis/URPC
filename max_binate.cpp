using std::cout;
using std::cin;
using std::endl;
using std::vector;

#define Positive  1
#define Negative  2
#define DC        3
#define Zero      0
#define Vec_2D    vector<vector<int>>

int max_binate(Vec_2D Pol_binate_i, int Size, int No){
  int binate_variable;//Is the most binate variable
  int count_p[Size] = {0};//Counting the positive occurences of each variable
  int count_n[Size] = {0};//Counting the negative occurences of each variable
  int count_t[Size] = {0};//Counting the total occurences of each variable
  int is_unate = 1;//Assume the function is unate

  for(int j = 0; j < Size; j++){
     for (int i = 0; i < No; i++){
         if(Pol_binate_i[i][j] != 3){
           if(Pol_binate_i[i][j] == 1){
             count_p[j]++;
           }
           else if(Pol_binate_i[i][j] == 2){
             count_n[j]++;
           }
        }        
      }
    }

  for(int i = 0; i < Size; i++){
    count_t[i] = count_n[i] + count_p[i];
  }

  for(int i = 0; i < Size; i++){
     if(!(( (count_p[i] != 0) && (count_n[i] ==0) ) || ( (count_n[i] != 0) && (count_p[i] == 0) )) ){
       is_unate = 0;
       break;
     }
  }
  if(is_unate == 0){
    int bin_max = 0;//Number of occurences of the most binate variable
    binate_variable = 0;

    for(int i = 0; i < Size; i++){
      if( count_t[i] > bin_max ){//If the variable @ i is more binate than the currently assigned binate_variable
          binate_variable = i;
          bin_max = count_t[i];
      }
      else if(bin_max == count_t[i]){//If the variable @ i is equal binate to currently assigned binate_variable
          if( abs(count_p[i] - count_n[i]) > abs(count_p[binate_variable] - count_n[binate_variable]) ){//Subract their positive and negative occurences
              binate_variable = i;
              bin_max = count_t[i];
            }

          else if( abs(count_p[i] - count_n[i]) == abs(count_p[binate_variable] - count_n[binate_variable]) ){//Else choose the variable at the lower index
              binate_variable = (binate_variable < i) ? binate_variable : i;
              bin_max = count_t[binate_variable];
            }
        }
      }
    }
  

  else{
      int bin_max = 0;
      binate_variable = 0;
      for(int i = 0; i < Size; i++){
        if(count_t[i] > bin_max){
          bin_max = count_t[i];
          binate_variable = i;
        }
        else if(count_t[i] == bin_max){
          binate_variable = (binate_variable < i) ? binate_variable : i;
          bin_max = count_t[binate_variable];          
        }
      }
  }



  return binate_variable;

}

