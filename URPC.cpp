//  cubelist Complement( cubeList F ) { 
//          check if F is simple enough to complement it directly and quit// 
//               if ( F is simple and we can complement it directly ) 
//                      return( directly computed complement of F )
//
//               else { // do recursion let x = most binate variable for splitting
//                          cubeList P = Complement( positiveCofactor( F, x ) ) 
//                          cubeList N = Complement( negativeCofactor( F, x ) )     
//                          P = AND( x  , P ) 
//                          N = AND( x’ , N )
//                          return( OR( P, N ) ) 
//                        } // end recursion
//                    } // end function


#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Read_PCN.cpp"
#include "Terminate_Complement.cpp"
#include "max_binate.cpp"
#include "Cofactor.cpp"
#include "Bool_Functions.cpp"
#include "Write_PCN.cpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

#define Positive  1
#define Negative  2
#define DC        3
#define Zero      0
#define Vec_2D    vector<vector<int>>





Vec_2D Complement(Vec_2D, int, int);



int main(){
  Vec_2D Polarities;
  string Input_filename = "../ProgrammingAssignment1Files/UnateRecursiveComplement/part5.pcn";
  string Output_filename = "../Output/part5.pcn";
  Vec_2D input_values = Read_PCN(Input_filename);

  Vec_2D Pol_Comp_o = Complement(input_values, cubeSize, cubeNo);
    // To remove the Zeros in the PCN function
  for(int i = 0; i < Pol_Comp_o.size(); i++){
    for (int j = 0; j < Pol_Comp_o[i].size(); j++){
      if(Pol_Comp_o[i][j] == Zero){
        Pol_Comp_o.erase(Pol_Comp_o.begin() + i);
        i--;
      }
    }
  }
  Write_PCN(Output_filename, Pol_Comp_o);

  return 0;

}

Vec_2D Complement(Vec_2D Pol_Comp_i, int Size, int No){

  Vec_2D Pol_Comp; 

  int most_binate;
  Pol_Comp = Terminate_Complement(Pol_Comp_i, Size, No );
  // Pol_Comp = Terminate_Complement(Pol_Comp_i, Size, Pol_Comp_i.size() );
  
  if(Pol_Comp.size() == 0){
    most_binate = max_binate(Pol_Comp_i, Pol_Comp_i[0].size(), Pol_Comp_i.size() );

    Vec_2D P = Cofactor(Pol_Comp_i, most_binate, Pol_Comp_i[0].size(), Pol_Comp_i.size(), 1);// Cofactor(Input vector(F), most_binate(x), Size, Number, Positive Cofactor)
    Vec_2D N = Cofactor(Pol_Comp_i, most_binate, Pol_Comp_i[0].size(), Pol_Comp_i.size(), 0);// Cofactor(Input vector(F), most_binate(x), Size, Number, Negative Cofactor)
    P = Complement( P, P[0].size(), P.size() );//Recursive function, Complement the Cofactored functions
    N = Complement( N, N[0].size(), N.size() );
    P = And_Function(P, most_binate, P[0].size(), P.size(), 1);
    N = And_Function(N, most_binate, N[0].size(), N.size(), 0);

    Pol_Comp = Or_Function(P, N);



  }


  return Pol_Comp;
}









