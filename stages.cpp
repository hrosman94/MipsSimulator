#include "components.h"
#include "stages.h"

#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include <sstream>
#include <sstream>

using namespace std;

string opcode;

void fetch (vector <string> instructions, int &amt_instructions) {
  cout << "FETCHING... " << "\n";
  inFetchALU(instructions, amt_instructions);
}
void decode (string operation, string reg1, string reg2, string reg3) {
  cout <<"   DECODING...\n";
  string regs[3] = {reg1, reg2, reg3};

  if ((operation == "add" && operation[3] == '\0') ||
      (operation == "sub" && operation[3] == '\0') ||
      (operation == "mul" && operation[3] == '\0') ||
      (operation == "and" && operation[3] == '\0') ||
      (operation == "sll" && operation[3] == '\0') ||
      (operation == "srl" && operation[3] == '\0')) {
    opcode = "000000";
  } else if (operation == "or" && operation[2] == '\0') {
    opcode = "000000";
  } else if (operation == "addi") {
    opcode = "001000";
  } else if (operation == "lw"){
    opcode = "100011";
  } else if (operation == "beq") {
    opcode = "000100";
  } else if (operation == "j") {
    opcode = "000010";
  } else if (operation == "nop") {
    return;
  } else if (operation =="sw"){
    opcode = "101011";
  } else {
    cout << "ERR: please enter a valid command...\n";
    return;
  }
  int i = 0;
  int first = 1;
  RF_read (regs, operation, i, first);
  execute(operation, first);
  return;
}

void execute(string operation, int pos) {
  cout <<"        IN CONTROL UNIT. THE REMAINING DATAPATH\n"
       <<"        WILL BE DETERMINED BY WHAT OPERATIONS\n"
       <<"        CU PASSES FROM THIS POINT FORWARD...\n";
  if (opcode == "000000") {
    cout <<"            TO ALU...\n";
    in_ALU(operation, pos);
  } else if (opcode == "001000" && operation == "addi"){
    cout <<"            TO ALU...\n";
    in_ALU(operation, pos);
  } else if (opcode == "100011" && operation == "lw"){
    cout <<"            TO ALU...\n";
    in_ALU(operation, pos);
  } else if (opcode == "101011" && operation == "sw") {
    cout <<"            TO ALU...\n";
    in_ALU(operation, pos);
  } else if (opcode == "000100" && operation == "beq"){
    cout <<"            TO ALU...\n";
    in_ALU(operation, pos);
  }
  else if (opcode == "000010" && operation == "j"){
    cout <<"            TO ALU...\n";
    in_ALU(operation, pos);
  }
  return;
}
