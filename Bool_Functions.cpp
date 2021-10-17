

using std::cout;
using std::cin;
using std::endl;
using std::vector;

#define Positive  1
#define Negative  2
#define DC        3
#define Zero      0
#define Vec_2D    vector<vector<int>>


Vec_2D And_Function(Vec_2D Pol_Comp_i, int cofactor, int Size, int No, int type){
  
  if( type == 1){
    for(int i = 0; i < Pol_Comp_i.size(); i++){

        if(Pol_Comp_i[i][cofactor] == DC){
          Pol_Comp_i[i][cofactor] = Positive;
        }

    }  
  }


  //Negative Cofactor
  else if( type == 0 ){

    // cout << endl << No << endl << Size << endl;
    for(int i = 0; i < Pol_Comp_i.size(); i++){

        if(Pol_Comp_i[i][cofactor] == DC){
          Pol_Comp_i[i][cofactor] = Negative;
        }

                  
    }     
  } 


  // for(int i = 0; i < Pol_Comp_i.size(); i++){
  //   for (int j = 0; j < Pol_Comp_i[i].size(); j++){
  //       cout << Pol_Comp_i[i][j] << " ";
  //   }
  //   cout << endl << endl;
        
  // } 
  // cout << endl << endl;  
  return Pol_Comp_i;
}


Vec_2D Or_Function(Vec_2D Pos_Cofactor, Vec_2D Neg_Cofactor){

  for(int i = 0; i < Neg_Cofactor.size(); i++){
    Pos_Cofactor.push_back(Neg_Cofactor[i]);
  }

  // for(int i = 0; i < Pos_Cofactor.size(); i++){
  //   for (int j = 0; j < Pos_Cofactor[i].size(); j++){
  //       cout << Pos_Cofactor[i][j] << " ";
  //   }
  //   cout << endl << endl;
        
  // } 
  // cout << endl << endl;  
  return Pos_Cofactor;
}