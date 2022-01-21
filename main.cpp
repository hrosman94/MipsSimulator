#include "main.h"
#include "components.h"
#include "stages.h"

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main() {
  ofstream file;
  file.open ("output.txt");
  bool more_ops = true;
  int num_lines = 0;
  int i = 0;
      cout << "PC registers:     $r1-$r10 \n"
           << "Memory slots available: 10 \n"
           << "input operations into PC...\n";
  while (instruction != "stop") {
      cout <<"    ";
      getline (cin, instruction);
      if(instruction == "stop"){
          break;
      }
      num_lines++;
      PC.push_back(instruction);
      file << num_lines << "         " << instruction <<"\n";
      amt_instructions++;
      if (instruction == "stop") {
            break;
        }
    }
  file.close();
  fetch(PC, amt_instructions);
  cout << "NO INSTRUCTIONS LEFT, DISPLAYING MEMORY \n";
  printArry();
  cout << "\n\nDONE!";
  return 0;
}

