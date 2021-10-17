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


Vec_2D Terminate_Complement(Vec_2D Pol_Term_i, int Size, int No){
  Vec_2D Pol_Term_Comp;
  int cube_Zero = 0;//For a cube that has a 00 in it
  int cube_One = 0;//Checks if there are all 11 or all don't care cubes

  //TERMINATION CONDITION - 1(If the whole Cubelist F doesn't exist)
  for(int i = 0; i < No; i++){
    for (int j = 0; j < Size; j++){
        if(Pol_Term_i[i][j] == Zero){
           j += Size;
           cube_Zero++;
        }
    }
        
  }
  
  if(cube_Zero == No){
      vector<int> Variables;
    for (int i = 0; i<Size; i++){
      Variables.push_back(DC);
    }
    Pol_Term_Comp.push_back(Variables);

    // for(int i = 0; i < 1; i++){
    //   for (int j = 0; j < Pol_Term_Comp[0].size(); j++){
    //       cout << Pol_Term_Comp[i][j] << " " << endl <<endl;

    //   }
          
    // }    
  }


  //TERMINATION CONDITION - 2(If F has a [11 11 11 11] or All Don't Care cube)
  for(int i = 0; i < No; i++){
    cube_One = 0;
    for (int j = 0; j < Size; j++){
        if(Pol_Term_i[i][j] == DC){
           cube_One++;
        }
    }
        
  }
  
  if(cube_One == Size){
      vector<int> Variables;
    for (int i = 0; i<Size; i++){
      Variables.push_back(Zero);
    }
    Pol_Term_Comp.push_back(Variables);

    // for(int i = 0; i < 1; i++){
    //   for (int j = 0; j < Pol_Term_Comp[0].size(); j++){
    //       cout << Pol_Term_Comp[i][j] << " " << endl <<endl;
    //   }
          
    // }    
  }

  //TERMINATION CONDITION - 3(If F has only one cube, can complement using De Morgan's Laws)
  
  if(No == 1){
    for(int i = 0; i < No; i++){
      cube_One = 0;

      for (int j = 0; j < Size; j++){
          if(Pol_Term_i[i][j] == Positive){
            vector<int> Variables;                            
            for (int k = 0; k<Size; k++){   
                 if(k == j)
                    {
                      Variables.push_back(Negative);
                    }
                 else
                    {
                      Variables.push_back(DC);
                    }
            }
          Pol_Term_Comp.push_back(Variables);
          }

          if(Pol_Term_i[i][j] == Negative){
            vector<int> Variables;                            
            for (int k = 0; k<Size; k++){
                 if(k == j)
                    {
                      Variables.push_back(Positive);
                    }
                 else
                    {
                      Variables.push_back(DC);
                    }
            }
          Pol_Term_Comp.push_back(Variables);
          }


      }
          
    }

  //   for(int i = 0; i < Pol_Term_Comp.size(); i++){
  //     for (int j = 0; j < Pol_Term_Comp[i].size(); j++){
  //         cout << Pol_Term_Comp[i][j] << " ";
  //     }
  //     cout << endl << endl;
          
  //   } 
  }
  return Pol_Term_Comp;
 
}