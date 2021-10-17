// #include <iostream>
// #include <vector>
// #include <bitset>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

#define Positive  1
#define Negative  2
#define DC        3
#define Zero      0
#define Vec_2D    vector<vector<int>>



Vec_2D Cofactor(Vec_2D Pol_Comp_i, int most_binate, int Size, int No, int type){

  // cout<< "\n\t" << ++count << endl;
  //Positive Cofactor 
  if( type == 1){
    for(int i = 0; i < No; i++){

        if(Pol_Comp_i[i][most_binate] == Positive){
          Pol_Comp_i[i][most_binate] = DC;
        }
        else if(Pol_Comp_i[i][most_binate] == Negative){
          //Remove cubelist
          Pol_Comp_i.erase(Pol_Comp_i.begin() + i);
          i--;
          No--;
        }
                  
    }  
  }


  //Negative Cofactor
  else if( type == 0 ){

    // cout << endl << No << endl << Size << endl;
    for(int i = 0; i < No; i++){

        if(Pol_Comp_i[i][most_binate] == Negative){
          Pol_Comp_i[i][most_binate] = DC;
        }
        else if(Pol_Comp_i[i][most_binate] == Positive){
          //Remove cubelist
          Pol_Comp_i.erase(Pol_Comp_i.begin() + i);
          i--;
          No--;
        }
                  
    }     
  } 


//   for(int i = 0; i < Pol_Comp_i.size(); i++){
//     for (int j = 0; j < Pol_Comp_i[i].size(); j++){
//         cout << Pol_Comp_i[i][j] << " ";
//     }
//     cout << endl << endl;
        
//   } 
//   cout << endl << endl;  

  return Pol_Comp_i;
}
