// #include <iostream>
// #include <vector>
// #include <bitset>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::fstream;
using std::ifstream;

#define Positive  1
#define Negative  2
#define DC        3
#define Zero      0
#define Vec_2D    vector<vector<int>>

int cubeSize, cubeNo, count=0;

// Vec_2D Read_PCN(string filename);

Vec_2D Read_PCN(string filename){
  //initialize the array size
  vector<int> input_integers;//Holds the integers from the input file
  int temp;//Used to create the 2D-Variables
  Vec_2D Polarities;//Array to work on
  int no_active = -1;//Number of active variables, negative to correct index error
  int var_counted = 0;//To count the number of values read from the input_integers array WITHIN THAT LINE
  int no_val_read = 1;//To count the number of values read from the input_integers array
  ifstream input_file(filename);
  int cnt= 0;
  int x;
  if(input_file.is_open()){
    while ( input_file >> x){
        // cout << x << "\t";
        input_integers.push_back(x);// and read integer from file, DEBUG: Use a 2D Vector
        cnt++;
    }
    // cout<<"The integers are:"<<"\n";      // print the integers stored in the array
    // for (int i = 0; i < cnt; i++) {
    //     cout << input_integers[i] <<' ';
    // }


  //close the file
    input_file.close();
  }

  else{
    cout<<"\n Error in opening I/P File";
  }

  cubeSize = input_integers[0];
    cubeNo = input_integers[1];

  for(int i = 0; i < cubeNo; i++){
    vector<int> Variables;
    no_active = input_integers[ ++no_val_read];
    // no_val_read++;
    var_counted = 0;
    for(int j = 0; j < cubeSize; j++){
      if((j == abs(input_integers[no_val_read + 1] ) - 1) && (var_counted != no_active)){
        temp = input_integers[++no_val_read] > 0 ? Positive : Negative;
        Variables.push_back(temp);
        var_counted++;
      }

      else{
        temp = DC;
        Variables.push_back(temp);
      }
    }
    Polarities.push_back(Variables);
    
  }

    // for(int i = 0; i < Polarities.size(); i++){
    //   for (int j = 0; j < Polarities[i].size(); j++){
    //       cout << Polarities[i][j] << " ";
    //   }
    //   cout << endl << endl;
          
    // } 

   return Polarities;
}