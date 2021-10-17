using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;

int Write_PCN(string filename, Vec_2D Pol_Comp_o){
  ofstream output_file(filename);
  int no_active = 0;
  int a = 1, b = 21;
  if(output_file.is_open()){
    output_file << Pol_Comp_o[0].size() << endl << Pol_Comp_o.size() <<endl;
    for(int i = 0; i < Pol_Comp_o.size(); i++){
      no_active = 0;
      for (int j = 0; j < Pol_Comp_o[i].size(); j++){
        if(Pol_Comp_o[i][j] != DC){
          no_active++;
        }
      }
      output_file << no_active << " ";//Show the number of non-don't care variables
      for (int j = 0; j < Pol_Comp_o[i].size(); j++){


        if(Pol_Comp_o[i][j] == Positive){
          if(j < (Pol_Comp_o[i].size() - 1)){//Adjustments to avoid spaces at the EOL
            output_file << j + 1 << " ";
          }
          else{
            output_file << j + 1;
          }
        }

        else if(Pol_Comp_o[i][j] == Negative){
          if(j < (Pol_Comp_o[i].size() - 1)){//Adjustments to avoid spaces at the EOL
             output_file << (j + 1)*(-1) << " ";
          }
          else{
             output_file << (j + 1)*(-1);
          }
        }


      }
      
      if(i < (Pol_Comp_o.size() - 1)){
        output_file << endl;
      }
    }
  }

  else{
    cout<<"\n Error in opening O/P File";
  }
  output_file.close();
   return 0;
}
