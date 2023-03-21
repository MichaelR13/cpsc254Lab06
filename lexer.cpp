#pragma once

#include <iostream>

#include <iomanip>

#include <string>

#include <cctype>

#include <algorithm>

#include <vector>

#include <fstream>

#include <sstream>

#include "lexer.hpp"

using namespace std;

// functions used to determine input type-----------------------------------
// return 1 if input is equal to a char in string
// functions are in PascalCase, per the style guide
// NOTE: isUnderline() and isDot() are not in PascalCase, because they 
// would better match the styling of isalpha() and isdigit() 
bool IsSeparator(char input) {
  string separator_st = "'\"(){}[],:;";
  if (separator_st.find(input) != string::npos) {
    return 1;
  } else {
    return 0;
  }
}
//return 1 if input is equal to a char in string
bool IsOperator(char input) {
  string operator_st = "*+-/><%=";
  if (operator_st.find(input) != string::npos) {
    return 1;
  } else {
    return 0;
  }
}
//return 1 if input is equal to _
bool isUnderline(char input) {
  char underline_st = '_';
  if (input == underline_st) {
    return 1;
  } else {
    return 0;
  }
}
//return 1 if input is equal to .
bool isDot(char input) {
  char dot_st = '.';
  if (input == dot_st) {
    return 1;
  } else {
    return 0;
  }
}

//return 1 if input is equal to a keyword in vector
bool IsKeyword(string input) {
  vector < string > keywords_st {
    "and",
    "asm",
    "auto",
    "bool",
    "break",
    "case",
    "catch",
    "char",
    "class",
    "const",
    "continue",
    "return",
    "do",
    "double",
    "else",
    "enum",
    "explicit",
    "extern",
    "false",
    "float",
    "for",
    "friend",
    "goto",
    "if",
    "int",
    "long",
    "namespace",
    "new",
    "not",
    "nullptr",
    "operator",
    "or",
    "private",
    "protected",
    "public",
    "return",
    "short",
    "signed",
    "sizeof",
    "static",
    "struct",
    "main",
    "get",
    "put",
    "switch",
    "template",
    "this",
    "throw",
    "true",
    "try",
    "typedef",
    "typeid",
    "typename",
    "unsigned",
    "using",
    "virtual",
    "void",
    "while",
    "real",
    "function",
    "boolean",
    "real"
  };

  if (find(keywords_st.begin(), keywords_st.end(), input) != keywords_st.end()) {
    return 1;
  }
  return 0;
} // isdigit() and isalpha() are used to determine d and l

//check which type of "other" input it is---------------------------------------
string operator_or_seperator(char input) {
  if (IsOperator(input) != 0) {
    return "Operator";
  } else if (IsSeparator(input) != 0) {
    return "Separator";
  } else {
    return "Other Separators";
  }
}

//returns 1 if input is a white space
bool IsWhitespace(char input) {
  string whitespace_st = "\n \t";
  if (whitespace_st.find(input) != string::npos) {
    return 1;
  } else {
    return 0;
  }
}

//determine on which column an input is for state charts
int ColumnDeterminer(char input) {
  int col;
  if (isalpha(input)) {
    col = 0;
  } else if (isdigit(input)) {
    col = 1;
  } else if (isUnderline(input)) {
    col = 2;
  } else if (isDot(input)) {
    col = 3;
  } else {
    col = 4;
  }
  return col;
}
// IdentifierFsm 
int IdentifierFsm(int state, char input) {
  int state_chart_id[5][5] = {
    {
      2,
      2,
      2,
      3,
      4
    },
    {
      2,
      2,
      2,
      3,
      4
    },
    {
      4,
      4,
      4,
      4,
      5
    },
    {
      5,
      5,
      5,
      5,
      5
    },
    {
      5,
      5,
      5,
      5,
      5
    }
  };
  int state_chart_row = state - 1;
  int state_chart_column = ColumnDeterminer(input);
  return state_chart_id[state_chart_row][state_chart_column];
}
// check if in accepting state for identifier FSM
bool IsAcceptingIdentifier(int state) {
  if (state == 1 || state == 2 || state == 3) {
    return 1;
  } else {
    return 0;
  }
}
// IntegerRealFsm
int IntegerRealFsm(int state, char input) {
  int state_chart_intreal[7][5] = {
    {
      4,
      2,
      4,
      3,
      5
    },
    {
      4,
      2,
      4,
      3,
      5
    },
    {
      4,
      3,
      4,
      4,
      6
    },
    {
      4,
      4,
      4,
      4,
      7
    },
    {
      7,
      7,
      7,
      7,
      7
    },
    {
      7,
      7,
      7,
      7,
      7
    },
    {
      7,
      7,
      7,
      7,
      7
    }
  };

  int state_chart_row = state - 1;
  int state_chart_column = ColumnDeterminer(input);
  return state_chart_intreal[state_chart_row][state_chart_column];
}

//check if in accepting state for int/real FSM
bool IsAcceptingIntegerReal(int state) {
  if (state == 1 || state == 2 || state == 3 || state == 4) {
    return 1;
  } else {
    return 0;
  }
}

// return token type as string based on final state for int/real machine
string end_integer_real(int state) {
  if (state == 5) {
    return "Integer";
  } else if (state == 6) {
    return "Real";
  } else if (state == 7) {
    return "Invalid Token";
  } else {
    return "An error occured. Still in accepting state";
  }
}

// return token type as string based on final state for identifier machine
string end_identifier(int state) {
  if (state == 4) {
    return "Identifier";
  } else if (state == 5) {
    return "Invalid Token";
  } else {
    return "An error occured. Still in accepting state";
  }
}

// lexer machine
token_323 lexer_323(ifstream & input_file) {
  token_323 return_token;
  int state = 1;
  char input_char;
  input_file.get(input_char);
  string token_string = "";
  token_string.push_back(input_char);

  //firstly check the first char and determine which machine to go to
  if (isdigit(input_char)) { //case for int/real
    while (input_file.eof() != true && IsAcceptingIntegerReal(state)) { //keep reading char until terminates a token
      input_file.get(input_char);
      token_string.push_back(input_char);
      state = IntegerRealFsm(state, input_char);
    }
    if (input_file.eof() != true) { //if not end of file, return 1 char
      input_file.unget();
      token_string.pop_back();
    }
    string return_token_st = end_integer_real(state);
    string return_lexeme_st = token_string;
    return_token.TokenUpdate(return_token_st);
    return_token.LexemeUpdate(return_lexeme_st);
    return return_token;
  } else if (isalpha(input_char)) { //case for id
    while (input_file.eof() != true && IsAcceptingIdentifier(state)) { //keep reading char until terminates a token
      input_file.get(input_char);
      token_string.push_back(input_char);
      state = IdentifierFsm(state, input_char);
    }
    if (input_file.eof() != true) { //if not end of file, return 1 char
      input_file.unget();
      token_string.pop_back();
    }
    string return_token_st = end_identifier(state);
    string return_lexeme_st = token_string;
    return_token.LexemeUpdate(return_lexeme_st);
    if (IsKeyword(return_lexeme_st)) {
      return_token_st = "Keyword";
    }
    return_token.TokenUpdate(return_token_st);
    return return_token;
  } else if (IsWhitespace(input_char)) { //case for whitespace
    string return_token_st = "Other Separators";
    string return_lexime_st = token_string;
    //update token class with info we get and return
    return_token.TokenUpdate(return_token_st);
    return_token.LexemeUpdate(return_lexime_st);
    return return_token;
  } else if (input_char == '\0' || input_file.eof()) {
    cout << "error";
    return return_token;
  } else { //case for other seperator/operators
    //determine what typen of token input char is
    string return_token_st = operator_or_seperator(input_char);
    string return_lexime_st = token_string;
    char char_holder_2;
    if (return_lexime_st == "$") {
      input_file.get(char_holder_2);
      if (char_holder_2 == '$') {
        return_lexime_st += char_holder_2;
      } else {
        input_file.unget();
      }
    } else if (return_lexime_st == "!") {
      input_file.get(char_holder_2);
      if (char_holder_2 == '=') {
        return_lexime_st += char_holder_2;
      } else {
        input_file.unget();
      }
    } else if (return_lexime_st == "=") {
      input_file.get(char_holder_2);
      if (char_holder_2 == '=' || char_holder_2 == '>') {
        return_lexime_st += char_holder_2;
      } else {
        input_file.unget();
      }
    } else if (return_lexime_st == "<") {
      input_file.get(char_holder_2);
      if (char_holder_2 == '=') {
        return_lexime_st += char_holder_2;
      } else {
        input_file.unget();
      }
    } else if (return_lexime_st == "/") {
      input_file.get(char_holder_2);
      if (char_holder_2 == '*') {
        bool loopc = true;
        while (loopc == true) {
          input_file.get(char_holder_2);
          if (char_holder_2 == '*') {
            input_file.get(char_holder_2);
            if (char_holder_2 == '/') {
              loopc = false;
              return_lexime_st == "Ignored";
              return_token_st = "Comments";
            } else {
              input_file.unget();
            }
          }
        }
      } else {
        input_file.unget();
      }
    }
    //update token class with info we get and return
    return_token.TokenUpdate(return_token_st);
    return_token.LexemeUpdate(return_lexime_st);
    return return_token;
  }
}