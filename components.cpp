#include "components.h"
#include "stages.h"

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
#include <fstream>
#include <stdio.h>

using namespace std;

int ALU[3]      = {0,0,0};
int PC_REGS[10] = {2,4,6,0,0,0,0,0,31,33};
int MEM[10]     = {8,10,12,0,0,0,0,0,0,99};

void in_ALU(string operation, int pos) {
  bool zero = false;
  cout << "               EXECUTING...\n";
  if(operation =="add") {
    ALU[0] = ALU[1] + ALU[2];
    writeBack(PC_REGS, ALU[0], pos);
  } else if (operation == "sub") {
    ALU[0] = ALU[1] - ALU[2];
    writeBack(PC_REGS, ALU[0], pos);
  } else if (operation =="mul") {
    ALU[0] = ALU[1] * ALU[2];
    writeBack(PC_REGS, ALU[0], pos);
  } else if (operation =="and") {
    ALU[0] = (ALU[1] & ALU[2]);
    writeBack(PC_REGS, ALU[0], pos);
  } else if (operation =="or") {
    ALU[0] = (ALU[1] | ALU[2]);
    writeBack(PC_REGS, ALU[0], pos);
  } else if (operation =="sll") {
    ALU[0] = (ALU[1] << ALU[2]);
    writeBack(PC_REGS, ALU[0], pos);
  } else if (operation =="srl") {
    ALU[0] = (ALU[1] >> ALU[2]);
    writeBack(PC_REGS, ALU[0], pos);
  } else if (operation == "addi") {
    ALU[0] = (ALU[1] + ALU[2]);
    writeBack(PC_REGS, ALU[0], pos);
  } else if (operation == "lw") {
    cout <<"                  TO MEM...\n";
    in_Mem(MEM, pos, ALU[1], operation);
    return;
  } else if (operation == "sw") {
    in_Mem(MEM, ALU[0], ALU[1], operation);
    return;
  } else if (operation == "beq") {
    zero = (ALU[1]-ALU[0]);
    if (zero == 0){
    bool zero = true;
    in_ALU2(ALU[2]);
    } else {
      return;
    }
    return;
  } else if (operation == "j") {
    in_ALU2(ALU[0]);
  }
  return;
}
void in_ALU2(int target) {

  string mytarget = to_string(target);
  bool found = false;

  fstream file; file.open("output.txt", ios::in | ios::out);
  string line;
  string line2;
  int amt = 0; 

  fstream countlines;
  countlines.open("output.txt");
  while (getline(countlines, line2)){
    amt++; 
  }
  countlines.close(); 
  countlines.open("output.txt");
    while(!found && amt > 0){
      file >> line;
      if(line == mytarget) {
        file << " HERE:";
        found = true;
        return;
      } amt--; 
        getline(file, line2);
    }
    cout << "JUMP NOT FOUND...";
}
void inFetchALU(vector <string> instructions, int &amt_instructions) {
  string op1, op2, reg1, reg2, reg3;
  stringstream ss;

  if (amt_instructions == 0) {
      return;
  }
  ss << instructions.front();
  ss >> op1 >> reg1 >> reg2 >> reg3;
  decode(op1, reg1, reg2, reg3);
  instructions.erase(instructions.begin());
  amt_instructions--;
  ss.clear();
  fetch(instructions, amt_instructions);
  return;
}
void RF_read(string regs[], string operation, int &i, int &first) {
    if ((regs[i] == "" || i >= 3) && (operation == "add" || operation == "sub" ||               operation == "mul" || operation == "and" || operation == "or")) {
      return;
    } else if ((regs[i] == "" || i >= 2) && ((operation == "sll") || operation == "srl" ||             operation == "addi")) {
      ALU[i] = stoi(regs[i]);
      return;
    } else if ((regs[i] == "" || i >= 1) && operation == "lw") {
      ALU[i] = stoi(regs[i]);
      return;
    } else if ((regs[i] == "" || i >= 1) && operation == "sw") {
      ALU[i] = stoi(regs[i]);
      return;
    } else if ((regs[i] == "" || i >= 2) && operation == "beq") {
      ALU[i] = stoi(regs[i]);
      return;
    }
    else if ((regs[i] == "" || i >= 0) && operation == "j") {
      ALU[i] = stoi(regs[i]);
      return;
    }
  for (int j = 0; j < 10; j++) {
    if (regs[i] == "$r1," || regs[i] == "$r1") {
      ALU[i] = PC_REGS[0];
      if (i == 0) {
        first = 1;
      }
      break;
    } else  if (regs[i] == "$r2," || regs[i] == "$r2") {
      ALU[i] = PC_REGS[1];
      if (i == 0) {
        first = 2;
      }
      break;
    } else  if (regs[i] == "$r3," || regs[i] == "$r3") {
      ALU[i] = PC_REGS[2];
      if (i == 0) {
        first = 3;
      }
      break;
    } else  if (regs[i] == "$r4," || regs[i] == "$r4") {
      ALU[i] = PC_REGS[3];
      if (i == 0) {
        first = 4;
      }
      break;
    } else  if (regs[i] == "$r5," || regs[i] == "$r5") {
      ALU[i] = PC_REGS[4];
      if (i == 0) {
        first = 5;
      }
      break;
    } else  if (regs[i] == "$r6," || regs[i] == "$r6") {
      ALU[i] = PC_REGS[5];
      if (i == 0) {
        first = 6;
      }
      first++;
      break;
    } else  if (regs[i] == "$r7," || regs[i] == "$r7") {
      ALU[i] = PC_REGS[6];
      if (i == 0) {
        first = 7;
      }
      break;
    } else  if (regs[i] == "$r8," || regs[i] == "$r8") {
      ALU[i] = PC_REGS[7];
      if (i == 0) {
        first = 8;
      }
      break;
    } else  if (regs[i] == "$r9," || regs[i] == "$r9") {
      ALU[i] = PC_REGS[8];
      if (i == 0) {
        first = 9;
      }
      break;
    } else if (regs[i] == "$r10," || regs[i] == "$r10") {
      ALU[i] = PC_REGS[9];
      if (i == 0) {
        first = 10;
      }
      break;
    } else {
      cout << "ERR: please enter valid registers... \n"
           << "Terminating...";
           void abort( void );
           return;
    }
  }
  i++;
  RF_read(regs, operation, i, first);
  return;
}
void in_Mem(int MEM[], int reg_pos, int mem_pos, string op) {

  if (op != "sw" && mem_pos%4 == 0){
  int result = MEM[mem_pos/4];
  writeBack(PC_REGS, result, reg_pos);
  return;
  } else if (op == "sw" && mem_pos%4 == 0) {
    cout << "                      "
         << reg_pos << " result stored to $s" << (mem_pos/4)+1 <<"\n";
    MEM[mem_pos/4] = reg_pos;
  }
  else {
    cout << "ERR: incorrect memory address...";
  }
  return;
}
void writeBack(int PC_REGS[], int result, int pos) {
  cout << "                      "
       << result << " result stored in $r" << pos <<  "\n";
  PC_REGS[pos-1] = result;
  return;
}
void printArry() {
  cout << "\n\nPC:   ";
    for (int i = 0; i < (sizeof(PC_REGS)/4); i++){
      cout << PC_REGS[i] << " ";
  }
  cout <<"\n\nMEM:  ";
  for (int i = 0; i < (sizeof(MEM)/4); i++){
      cout << MEM[i] << " ";
  }
  return;
}
