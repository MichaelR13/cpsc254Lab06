#ifndef LEXER_H // include guard per style guide
#define LEXER_H

#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
//#include "procedure_functions.h"
using namespace std;

//functions used to determine input type-----------------------------------
bool IsSeparator(char input);
bool IsOperator(char input);
bool isUnderline(char input);
bool isDot(char input);
bool IsKeyword(string input);
string operator_or_seperator(char input);
bool IsWhitespace(char input);
//2FSMs and helper functions
int ColumnDeterminer(char input);

int IdentifierFsm(int state, char input);
bool IsAcceptingIdentifier(int state);

int IntegerRealFsm(int state, char input);
bool IsAcceptingIntegerReal(int state);
//determine token type based on final state------------------------------------------
string end_integer_real(int state);
string end_identifier(int state);


struct instruction_table {
  string op;
  string oprnd;

  void NewInstruction(string ope, string opre) {
    op = ope;
    oprnd = opre;
  }

  void PrintInstruction(ofstream& outfile) {
    cout << op << "     " << oprnd << "\n";
    outfile << op << "     " << oprnd << "\n";
  }
};



class token_323 {
private:
  string token_323_;
  string lexeme_323_;
public:  
  vector<instruction_table> all_instructions;
  vector<string> rule_holder;

  //constructor destructor
  token_323() {
    token_323_ = "none";
    lexeme_323_ = "none";
  }

  //~token323();

  //accessor and modifier functions------------------------------------------
  string token() { return token_323_; }
  string lexeme() { return lexeme_323_; }
  void TokenUpdate(string token) { token_323_ = token; }
  void LexemeUpdate(string lexeme) { lexeme_323_ = lexeme; }
  //void rule_holder_update(string rule) { }

  //function that helps print out rules
  void RulePrintHelper() {  //ofstream& outfile
    //TokenPrintHelper();
    string tokenp;
    string lexemep;
    tokenp = token();
    lexemep = lexeme();
    cout << "Token: " << tokenp << "                   Lexeme: " << lexemep << "\n";
    //outfile << "Token: " << tokenp << "                   Lexeme: " << lexemep << "\n";    
    int k = rule_holder.size() - 1;
    for (int i = k; i >= 0; i--) {
      cout << "   " << rule_holder[i] ;
      //outfile << "   " << rule_holder[i];
    }
  }

  //functions used to help print------------------------------------------
  void StartPrintHelper() {
    cout << "Program begins\n";
    cout << left << setw(15) << "token" << "lexeme" << "\n";
    //cout << "token" << "lexeme" << "\n";
    cout << "-------------------\n";
  }

  void TokenPrintHelper() {
    //ofstream& outfile
    string tokenp;
    string lexemep;
    tokenp = token();
    lexemep = lexeme();
    cout <<"Token: " << tokenp << "                   Lexeme: " << lexemep << "\n";
    //outfile << left << setw(15) << tokenp << lexemep << "\n";
    //cout << lexemep << tokenp << "\n";
    //outfile << lexemep << tokenp << "\n";
  }
};

token_323 lexer_323(ifstream& input_file);

struct symbol_table_element {
  //Identifier   MemoryLocation       Type
  string Identifier;
  int MemoryLocation;
  string Type;
    
  int GetMemoryLocation(string id) {
    if (id == Identifier) {
      return MemoryLocation;
    }
    else {
      //cout << "error, identifier not defined\n";
      return -1;
    }
  }

  void PrintElement(ofstream& outfile) {        
    cout << Identifier << "           " << MemoryLocation << "           " << Type << "\n";
    outfile << Identifier << "           " << MemoryLocation << "           " << Type << "\n";
  }
};

#endif  //LEXER_H