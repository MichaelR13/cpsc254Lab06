// #include "lexer.hpp"

#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include "../procedure_functions.cpp"
#include "../lexer.cpp"

// bool identifier_helper(token_323 input_token);

// R28. <Primary> :: = <Identifier> | <Integer> | <Identifier>  (<IDs>) | (<Expression>) | <Real> | true | false
//---------------------------------------------------------------------------------------------------
// bool procedure_Primary(vector<token_323>& all_tokens, int& loc);

// R27. <Factor> :: = -<Primary> | <Primary>
//---------------------------------------------------------------------------------------------------
// bool procedure_Factor(vector<token_323>& all_tokens, int& loc);
void test_R27()
{
    std::ifstream input_file("temp.txt");
    bool test_results = false;
    std::vector<token_323> all_tokens;
    int loc = 0;
    int check_eof;

    while (!input_file.eof()) {
        all_tokens.push_back(lexer_323(input_file));
        check_eof = input_file.peek();
        if (check_eof == EOF) {
            break;
        }
    }

    test_results = procedure_Factor(all_tokens, loc);

    if (test_results == false) {
        std::cout << "Failed: Testing of R27 <Factor>" << std::endl;
    } else {
        std::cout << "Passed: Testing of R27 <Factor>" << std::endl;
    }

    std::cout << "\nHere are all the tokens in the vector:" << std::endl;
    for (auto token : all_tokens) {
        token.token_print_helper();
    }

    input_file.close();

    return;
}

// R26.1 <Term'> :: = * <Factor> <Term>' | / <Factor> <Term>' | ϵ
//---------------------------------------------------------------------------------------------------
// bool procedure_Term_q(vector<token_323>& all_tokens, int& loc);
void test_R26_1() {
    // Open the input file
    std::ifstream input_file("temp.txt");

    // Check if the file was opened successfully
    if (!input_file.is_open()) {
        std::cout << "Failed to open input file" << std::endl;
        return;
    }

    // Read the input from the file and store it in a vector of tokens
    std::vector<token_323> all_tokens;
    int loc = 0;
    int check_eof;

    while (!input_file.eof()) {
        all_tokens.push_back(lexer_323(input_file));
        check_eof = input_file.peek();
        if (check_eof == EOF) {
            break;
        }
    }

    // Call the procedure and check the results
    bool test_results = procedure_Term_q(all_tokens, loc);
    if (test_results == false) {
        std::cout << "Failed: Testing of R26.1 <Term'>" << std::endl;
    } else {
        std::cout << "Passed: Testing of R26.1 <Term'>" << std::endl;
    }

    // Print out all the tokens in the vector
    std::cout << "\nHere are all the tokens in the vector:" << std::endl;
    for (auto token : all_tokens) {
        token.token_print_helper();
    }
}

// R26. <Term>    :: = <Factor> <Term>'
//---------------------------------------------------------------------------------------------------
// bool procedure_Term(vector<token_323>& all_tokens, int& loc);

// R25. <Expression>  :: = <Term> <Expression'>
//---------------------------------------------------------------------------------------------------
// bool procedure_Expression(vector<token_323>& all_tokens, int& loc);

// R25.1 <Expression'>  :: = ϵ | +<Term> <Expression'>  | -<Term> <Expression'>
//---------------------------------------------------------------------------------------------------
// bool procedure_Expression_q(vector<token_323>& all_tokens, int& loc);

// R24. <Relop> :: = ==   |   !=    | > | <    |  <=   | = >
//---------------------------------------------------------------------------------------------------
// bool procedure_Relop(vector<token_323>& all_tokens, int& loc);

// R23. <Condition> :: = <Expression>  <Relop>   <Expression>
//---------------------------------------------------------------------------------------------------
// bool procedure_Condition(vector<token_323>& all_tokens, int& loc);
void test_R23()
{
  std::ifstream input_file("temp.txt");
  bool test_results = false;
  std::vector<token_323> all_tokens;
  int loc = 0;
  int check_eof;

  while (!input_file.eof()) {
    all_tokens.push_back(lexer_323(input_file));
    check_eof = input_file.peek();
    if (check_eof == EOF) {
      break;
    }
  }

  test_results = procedure_Condition(all_tokens, loc);

  if (test_results == false) {
    std::cout << "Failed: Testing of R23 <Condition>" << std::endl;
  } else {
    std::cout << "Passed: Testing of R23 <Condition>" << std::endl;
  }

  std::cout << "\nHere are all the tokens in the vector:" << std::endl;
  for (auto token : all_tokens) {
    token.token_print_helper();
  }

  input_file.close();

  return;
}

// R22. <While> :: = while (<Condition>) < Statement >
//---------------------------------------------------------------------------------------------------
// bool procedure_While(vector<token_323>& all_tokens, int& loc);

// R21. <Scan> :: = get(<IDs>);
//---------------------------------------------------------------------------------------------------
// bool procedure_Scan(vector<token_323>& all_tokens, int& loc);

// R20. <Print> :: = put(<Expression>);
//---------------------------------------------------------------------------------------------------
// bool procedure_Print(vector<token_323>& all_tokens, int& loc);

// R19. <Return> :: = return; | return <Expression>;
//---------------------------------------------------------------------------------------------------
// bool procedure_Return(vector<token_323>& all_tokens, int& loc);

void test_R19() {
  std::vector<token_323> all_tokens;
  int loc = 0;

    // Create tokens for test case
  token_323 return_token;
  return_token.token_update("Keyword");
  return_token.lexeme_update("return");

  token_323 semicolon_token;
  semicolon_token.token_update("Operator");
  semicolon_token.lexeme_update(";");

  all_tokens.push_back(return_token);
  all_tokens.push_back(semicolon_token);

    // Call function being tested
  bool results = procedure_Return(all_tokens, loc);

    // Check results
  if (results) {
        std::cout << "\nTest passed: <Return> -> return;" << std::endl;
  } else {
        std::cout << "\nTest failed: <Return> -> return;" << std::endl;
  }

  std::cout << "\nHere are all the tokens in the vector:" << std::endl;
  for (auto token : all_tokens) {
    token.token_print_helper();
  }

}


// R18. <If> :: = if (<Condition>) < Statement > fi | if (<Condition>) < Statement > else  <Statement>  fi
//---------------------------------------------------------------------------------------------------
// bool procedure_If(vector<token_323>& all_tokens, int& loc);
void test_R18()
{
  std::ifstream input_file("temp.txt");
  bool test_results = false;
  std::vector<token_323> all_tokens;
  int loc = 0;
  int check_eof;

  while (!input_file.eof()) {
    all_tokens.push_back(lexer_323(input_file));
    check_eof = input_file.peek();
    if (check_eof == EOF) {
      break;
    }
  }

  test_results = procedure_If(all_tokens, loc);

  if (test_results == false) {
    std::cout << "Failed: Testing of R18 <If>" << std::endl;
  } else {
    std::cout << "Passed: Testing of R5 <If>" << std::endl;
  }

  std::cout << "\nHere are all the tokens in the vector:" << std::endl;
  for (auto token : all_tokens) {
    token.token_print_helper();
  }
}

// R17. <Assign> :: = <Identifier> = <Expression>;
//---------------------------------------------------------------------------------------------------
// bool procedure_Assign(vector<token_323>& all_tokens, int& loc);

// R16. <Compound> :: = { <Statement List> }
//---------------------------------------------------------------------------------------------------
// bool procedure_Compound(vector<token_323>& all_tokens, int& loc);

// R15. <Statement> :: = <Compound> | <Assign> | <If> | <Return> | <Print> | <Scan> | <While>
//---------------------------------------------------------------------------------------------------
// bool procedure_Statement(vector<token_323>& all_tokens, int& loc);

// R14. <Statement List> :: = <Statement> | <Statement> <Statement List>
//---------------------------------------------------------------------------------------------------
// bool procedure_Statement_List(vector<token_323>& all_tokens, int& loc);

// R13. <IDs> :: = <Identifier> | <Identifier>, <IDs>
//---------------------------------------------------------------------------------------------------
// bool procedure_IDs(vector<token_323>& all_tokens, int& loc);

void test_R13() {
    
    std::vector<token_323> all_tokens;
    int loc = 0;

    // Create tokens for test case
    token_323 ids_token;
    ids_token.token_update("IDs");
    ids_token.lexeme_update("a,b,c");

    all_tokens.push_back(ids_token);

    // Call function being tested
    bool results = procedure_IDs(all_tokens, loc);

    // Check results
    if (results) {
        std::cout << "\nTest passed: <IDs> -> <Identifier>, <IDs>" << std::endl;
    } else {
        std::cout << "\nTest failed: <IDs> -> <Identifier>, <IDs>" << std::endl;
    }
  std::cout << "\nHere are all the tokens in the vector:" << std::endl;
  for (auto token : all_tokens) {
    token.token_print_helper();
  }
}

// R12. <Declaration> :: = <Qualifier > <IDs>
//---------------------------------------------------------------------------------------------------
// bool procedure_Declaration(vector<token_323>& all_tokens, int& loc);
void test_R12()
{
  bool test_results = false;
  std::vector<token_323> all_tokens;
  int loc = 0;
  std::ifstream input_file("temp.txt");
  int check_eof;

  while (!input_file.eof()) {
    all_tokens.push_back(lexer_323(input_file));
    check_eof = input_file.peek();
    if (check_eof == EOF) {
      break;
    }
  }

  test_results = procedure_Declaration(all_tokens, loc);

  if (test_results == false) {
    std::cout << "Failed: Testing of R12 <Declaration>" << std::endl;
  } else {
    std::cout << "Passed: Testing of R12 <Declaration>" << std::endl;
  }

  std::cout << "Here are all the tokens in the vector:" << std::endl;
  for (auto token : all_tokens) {
    token.token_print_helper();
  }
}

// R11. <Declaration List>  : = <Declaration>; | <Declaration>; <Declaration List>
//---------------------------------------------------------------------------------------------------
// bool procedure_Declaration_List(vector<token_323>& all_tokens, int& loc);

// R10. <Opt Declaration List> :: = <Declaration List> | <Empty>
//---------------------------------------------------------------------------------------------------
// bool procedure_Opt_Declaration_List(vector<token_323>& all_tokens, int& loc);

// R9. <Body>  :: = { < Statement List> }
//---------------------------------------------------------------------------------------------------
// bool procedure_Body(vector<token_323>& all_tokens, int& loc);

// R8. <Qualifier> :: = int | boolean | real
//---------------------------------------------------------------------------------------------------
// bool procedure_Qualifier(vector<token_323>& all_tokens, int& loc);
void test_R8()
{
  std::ifstream input_file("temp.txt");
  bool test_results = false;
  std::vector<token_323> all_tokens;
  int loc = 0;
  int check_eof;

  while (!input_file.eof()) {
    all_tokens.push_back(lexer_323(input_file));
    check_eof = input_file.peek();
    if (check_eof == EOF) {
      break;
    }
  }

  test_results = procedure_Qualifier(all_tokens, loc);

  if (test_results == false) {
    std::cout << "Failed: Testing of R8 <Qualifier>" << std::endl;
  } else {
    std::cout << "Passed: Testing of R8 <Qualifier>" << std::endl;
  }

  std::cout << "Here are all the tokens in the vector:" << std::endl;
  for (auto token : all_tokens) {
    token.token_print_helper();
  }

  input_file.close();

  return;
}

// R7. <Parameter> :: = <IDs >  <Qualifier>
//---------------------------------------------------------------------------------------------------
// bool procedure_Parameter(vector<token_323>& all_tokens, int& loc);
void test_R7() 
{

    std::vector<token_323> all_tokens;
    int loc = 0;

    // Create tokens for test case
    token_323 ids_token;
    ids_token.token_update("IDs");
    ids_token.lexeme_update("a,b,c");

    token_323 qualifier_token;
    qualifier_token.token_update("Qualifier");
    qualifier_token.lexeme_update("const");

    all_tokens.push_back(ids_token);
    all_tokens.push_back(qualifier_token);

    // Call function being tested
    bool results = procedure_Parameter(all_tokens, loc);

    // Check results
    if (results) {
        std::cout << "\nTest passed: <Parameter> -> <IDs> <Qualifier>" << std::endl;
    } else {
        std::cout << "\nTest failed: <Parameter> -> <IDs> <Qualifier>" << std::endl;
    }
  std::cout << "\nHere are all the tokens in the vector:" << std::endl;
  for (auto token : all_tokens) {
    token.token_print_helper();
  }
}


// R6. <Parameter List>  :: = <Parameter> | <Parameter>, <Parameter List>
//---------------------------------------------------------------------------------------------------
// bool procedure_Parameter_List(vector<token_323>& all_tokens, int& loc);

// R5. <Opt Parameter List> :: = <Parameter List> | <Empty>
//---------------------------------------------------------------------------------------------------
// bool procedure_Opt_Parameter_List(vector<token_323>& all_tokens, int& loc);
void test_R5()
{
  // write input to be tested in file before running test.
  std::ifstream input_file("temp.txt");
  bool test_results = false;
  std::vector<token_323> all_tokens;
  int loc = 0;
 
  // uncomment for manual testing of tokens.
  /* token_323 token1;
  token1.token_update("Keyword");
  token1.lexeme_update("int");
  
  token_323 token2;
  token2.token_update("Identifier");
  token2.lexeme_update("num1");

  all_tokens.push_back(token1);
  all_tokens.push_back(token2); */

  int check_eof;
  while (!input_file.eof()) {
    all_tokens.push_back(lexer_323(input_file));
    check_eof = input_file.peek();
    if (check_eof == EOF) {
      break;
    }
  }

  test_results = procedure_Opt_Parameter_List(all_tokens, loc);

  if (test_results == false) {
    std::cout << "Failed: Testing of R5 <Opt Parameter List>" << std::endl;
  } else {
    std::cout << "Passed: Testing of R5 <Opt Parameter List>" << std::endl;
  }

  std::cout << "\nHere are all the tokens in the vector:" << std::endl;
  for (auto token : all_tokens) {
    token.token_print_helper();
    //token.rule_print_helper();
  }
}

// R4. <Function> :: = function  <Identifier>  (  <Opt Parameter List>  )   < Opt Declaration List >   <Body>
// bool procedure_Function(vector<token_323>& all_tokens, int& loc);

// R3. <Function Definitions>  :: = <Function> | <Function> <Function Definitions>
//---------------------------------------------------------------------------------------------------
// bool procedure_Function_Definitions(vector<token_323>& all_tokens, int& loc);

// R2. <Opt Function Definitions> :: = <Function Definitions> | <Empty>
//---------------------------------------------------------------------------------------------------
// bool procedure_Opt_Function_Definitions(vector<token_323> & all_tokens, int& loc);

// R1. <Rat20F>  :: = <Opt Function Definitions>   $$  <Opt Declaration List>  <Statement List>  $$
//---------------------------------------------------------------------------------------------------
// bool procedure_Rat20F(vector<token_323> & all_tokens, int& loc);

int main(int argc, char *argv[])
{
  //Uncomment whatever function you would like to test
  // R28 <Primary>
  //
  // R27 <Factor>
  //Failed
  //test_R27();
  // R26.1 <Term'>
  //
  // R26 <Term>
  //
  // R25 <Expression>
  //
  // R25.1 <Expression'>
  //
  // R24 <Relop>
  //
  // R23 <Condition>
  //Failed
  //test_R23();
  // R22 <While>
  //
  // R21 <Scan>
  //
  // R20 <Print>
  //
  // R19 <Return>
  //test_R19();
  // R18 <If>
  //test_R18();
  // R17 <Assign>
  //
  // R16 <Compound>
  //
  // R15 <Statement>
  //
  // R14 <Statement List>
  //
  // R13 <IDs>
  //test_R13();
  // R12 <Declaration>
  //test_R12();
  // R11 <Declaration List>
  //
  // R10 <Opt Declaration List>
  //
  // R9 <Body>
  //
  // R8 <Qualifier>
  //Failed
  //test_R8();
  // R7 <Parameter>
  //test_R7();
  // R6 <Parameter List>
  //
  // R5 <Opt Parameter List>
  //test_R5();
  // R4 <Function>
  //
  // R3 <Function Definitions>
  //
  // R2 <Opt Function Definitions>
  //
  // R1 <Rat20F>
  //

  return 0;
}
