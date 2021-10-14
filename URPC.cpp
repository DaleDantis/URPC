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
#include <bitset>
#include "Terminate_Complement.cpp"
#include "max_binate.cpp"
#include "Cofactor.cpp"
#include "Bool_Functions.cpp"

using std::cout;
using std::cin;
using std::endl;
using std::vector;

#define Positive  1
#define Negative  2
#define DC        3
#define Zero      0
#define Vec_2D    vector<vector<int>>


int cubeSize, cubeNo, count=0;
void Size_Number_IP(){                      //TEMPORARY
  cout << endl << "Enter the Size and the Number of Cubes: ";
  
  cout << endl << "Cube Size: = ";
  cin >> cubeSize;

  cout<< endl << "Number of Cubes: = ";
  cin >> cubeNo;
}

Vec_2D Complement(Vec_2D, int, int);
// Vec_2D Terminate_Complement(Vec_2D, int, int);
// int max_binate(Vec_2D, int, int);
// Vec_2D Cofactor(Vec_2D Pol_Comp_i, int most_binate, int Size, int No, int type);
// Vec_2D And_Function(Vec_2D Pol_Comp_i, int cofactor, int Size, int No, int type);
// Vec_2D Or_Function(Vec_2D Pos_Cofactor, Vec_2D Neg_Cofactor);


int main(){
    Size_Number_IP();
    int temp;
    Vec_2D Polarities;

    for(int i = 0; i < cubeNo; i++){
      vector<int> Variables;


      //TEMPORARY
      for (int j = 0; j < cubeSize; j++)
      {     bool_ip_repeat:
              cin >> temp;
              
            if(temp > 3){
              cout << endl << "Retry with values <= 3" << endl;
              goto bool_ip_repeat;
            }

            Variables.push_back(temp);

      }
      Polarities.push_back(Variables); 
      cout << endl << "Next cube" << endl << endl << endl;
    }

    Vec_2D Pol_Comp_o = Complement(Polarities, cubeSize, cubeNo);

    for(int i = 0; i < Pol_Comp_o.size(); i++){
      for (int j = 0; j < Pol_Comp_o[i].size(); j++){
          cout << Pol_Comp_o[i][j] << " ";
      }
      cout << endl << endl;
          
    } 

    return 0;

}

Vec_2D Complement(Vec_2D Pol_Comp_i, int Size, int No){

  Vec_2D Pol_Comp; 
  int most_binate;
  Pol_Comp = Terminate_Complement(Pol_Comp_i, Size, No );
  
  if(Pol_Comp.size() == 0){
    most_binate = max_binate(Pol_Comp_i, Size, No );
    // cout << "\n\n" << most_binate + 1 <<"\n\n";

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









