// Cohen Nichols
// OS code 2
// banker.cpp

#include <fstream>
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::ifstream;

int main(){
  /*  // set command line argument
    if(argc < 2){
    cout << "this is the bankers algorithim for deadlock avoidance" << endl;
    cout << "please input the 2 .txt files to use" << endl;
    exit(1);
  }

  // setup string for files in command line
  int fileName1 = argv[1];
  int fileName2 = argv[2];
  */
  // input/open files
  ifstream file1("allocate.txt");
  ifstream file2("max.txt");

  if(!file1.is_open()){
    cout << "unable to open allocate.txt" << endl;
  }

   if(!file2.is_open()){
    cout << "unable to open max.txt" << endl;
  }

  // p0, p1, p2, p3, p4 are the names of processes

  int a, b, c, d, e;

  a = 5; // 5 processes // ie rows
  b = 3; // 3 resouces  // ie columns

  // allocation matrix from file
  int allocate[a][b];
    // cout << "before allocate rows loop" << endl; // debug
    for(int r = 0; r < a; r++){       // loop for rows
      //cout << "before allocate column loop" << endl;  // debug
      for(int c = 0; c < b; c++){     // loop for columns
        file1 >> allocate[r][c];      // take input from files and put into allocate[a][b]


      }
    }
   cout << "allocate.txt input" << endl;
    // print matrix to check status of input file
    for(int r = 0; r < a; r++){          // loop for rows
      for(int c = 0; c < b; c++){        // loop for columns
        cout << allocate[r][c] << "\t";  // print allocate[a][b]
      }
      cout << endl;
    }


  // max matrix from file
  int max[a][b];
  for(int r = 0; r < a; r++){       // loop for rows
    for(int c = 0; c < b; c++){     // loop for columns
      file2 >> max[r][c];           // take input from files and put into max[a][b]
    }
  }
  cout << "max.txt input" << endl;
  // print matrix to check status of input file
  for(int r = 0; r < a; r++){          // loop for rows
    for(int c = 0; c < b; c++){        // loop for columns
      cout << max[r][c] << "\t";       // print max[a][b]
    }
    cout << endl;
  }

  /*
  // allocation matrix hard coded
  int allocate[5][3] = {{0, 1 , 0}, // p0
                        {2, 0, 0},  // p1
                        {3, 0, 2},  // p2
                        {2, 1, 1},  // p3
                        {0, 0, 2}}; // p4
  // max matrix hard coded
  int max[5][3] =  {{7, 5 , 3}, // p0
                    {3, 2, 2},  // p1
                    {9, 0, 2},  // p2
                    {2, 2, 2},  // p3
                    {4, 3, 3}}; // p4
  */

  // available resources
  int available[3] = {3, 3, 2};

  int track[a], answer[a], index = 0;
  for(e = 0; e < a; ++ e){
    track[e] = 0;
  }

  int get[a][b];
  for(c = 0; c < a; ++c){
    for(d = 0; d < b; ++d){
      get[c][d] = max[c][d] - allocate[c][d];
    }
  }

 int z = 0;
  for(e = 0; e < 5; ++e){
    for(c = 0; c < a; ++c){
      if(track[c] == 0){
        int flag = 0;
        for(d = 0; d < b; ++d){
          if(get[c][d] > available[d]){
            flag = 1;
            break;
          }
        }
        if(flag == 0){
          answer[index++] = c;
          for(z = 0; z < b; ++z){
            available[z] += allocate[a][z];
            track[a] = 1;
          }
        }
      }
    }
  }

  int flag = 1;

  // check if safe or not
  for(int i = 0; i < a; ++i){
    if(track[i] == 0){
      flag = 0;
      cout << " not safe ! " << endl;
      break;
    }
  }
  if(flag == 1){
    cout << " this is a safe sequence" << endl;
    for(int i = 0; i < a - 1; ++i){
      cout << "P" << answer[i] << ", " <<
        "P" << answer[a - 1] << endl;
    }
  }

} // end of main

