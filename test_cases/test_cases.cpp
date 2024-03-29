﻿/* For all test case functions, each rule uses the following:
 * - the default file "temp.txt" located in the same directory as the program.
 *   Place any code you want to test into this text file.
 * - a vector that will store all the tokens from reading in the contents of the text file.
 * The boolean result will display whether all the tokens pass or fail whichever
 * appropriate procedure function is called.
 * Then the contents of the vector of tokens is displayed to analyze the results. */

// #include "lexer.hpp"

#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../procedure_functions.cpp"
#include "../lexer.cpp"

void writeTokensToFile(std::vector<token_323> tokens, std::string filename) {
    std::ofstream outputFile("outputfile.txt");
    
    if (outputFile.is_open()) {
        for (auto token : tokens) {
            outputFile << token.token() << "\t" << token.lexeme() << std::endl;
        }
        
        outputFile.close();
        std::cout << "Tokens written to file " << filename << std::endl;
    } else {
        std::cout << "Error: Unable to open file " << filename << std::endl;
    }
}

// bool identifier_helper(token_323 input_token);

// R28. <Primary> :: = <Identifier> | <Integer> | <Identifier>  (<IDs>) | (<Expression>) | <Real> | true | false
//---------------------------------------------------------------------------------------------------
// bool procedure_Primary(vector<token_323>& all_tokens, int& loc);

// R27. <Factor> :: = -<Primary> | <Primary>
//---------------------------------------------------------------------------------------------------
// bool procedure_Factor(vector<token_323>& all_tokens, int& loc);
/*void test_R27()
{
    std::ifstream input_file("temp.txt");
    bool test_results = false;
    std::vector<token_323> all_tokens;
    int loc = 0;
    int check_eof; // additional flag to properly detect the end of file.

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

    writeTokensToFile(all_tokens, "outputfile.txt");

    input_file.close();
    
    return;
} */

// R26.1 <Term'> :: = * <Factor> <Term>' | / <Factor> <Term>' | ϵ
//---------------------------------------------------------------------------------------------------
// bool procedure_Term_q(vector<token_323>& all_tokens, int& loc);
/*void test_R26_1() {
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
    int check_eof; // additional flag to properly detect the end of file.

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
    	writeTokensToFile(all_tokens, "outputfile.txt");
} */

// R26. <Term>    :: = <Factor> <Term>'
//---------------------------------------------------------------------------------------------------
// bool procedure_Term(vector<token_323>& all_tokens, int& loc);

// R25. <Expression>  :: = <Term> <Expression'>
//---------------------------------------------------------------------------------------------------
// bool procedure_Expression(vector<token_323>& all_tokens, int& loc);
/*void testR25() {
  std::vector<token_323> all_tokens;
  int loc = 0;
  token_323 sampleToken;
  sampleToken.TokenUpdate("Expression");
  sampleToken.LexemeUpdate("Another");
  all_tokens.push_back(sampleToken);
  
	if (procedure_Expression(all_tokens, loc)) {
    std::cout << "R25: Passed" << std::endl;
  } else {
    std::cout << "R25: Failed" << std::endl;
  }
	writeTokensToFile(all_tokens, "outputfile.txt");
} */

// R25.1 <Expression'>  :: = ϵ | +<Term> <Expression'>  | -<Term> <Expression'>
//---------------------------------------------------------------------------------------------------
// bool procedure_Expression_q(vector<token_323>& all_tokens, int& loc);

// R24. <Relop> :: = ==   |   !=    | > | <    |  <=   | = >
//---------------------------------------------------------------------------------------------------
// bool procedure_Relop(vector<token_323>& all_tokens, int& loc);
/*void testR24() {
  std::vector<token_323> all_tokens;
  int loc = 0;
  token_323 sampleToken;
  sampleToken.TokenUpdate("!=");
  sampleToken.LexemeUpdate("==");
  all_tokens.push_back(sampleToken);

	if (procedure_Relop(all_tokens, loc)) {
    std::cout << "R24: Passed" << std::endl;
  } else {
    std::cout << "R24: Failed" << std::endl;
  }
	writeTokensToFile(all_tokens, "outputfile.txt");
} */

// R23. <Condition> :: = <Expression>  <Relop>   <Expression>
//---------------------------------------------------------------------------------------------------
// bool procedure_Condition(vector<token_323>& all_tokens, int& loc);
/*void test_R23()
{
  std::ifstream input_file("temp.txt");
  bool test_results = false;
  std::vector<token_323> all_tokens;
  int loc = 0;
  int check_eof; // additional flag to properly detect the end of file.

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
  writeTokensToFile(all_tokens, "outputfile.txt");
  input_file.close();

  return;
} */

// R22. <While> :: = while (<Condition>) < Statement >
//---------------------------------------------------------------------------------------------------
// bool procedure_While(vector<token_323>& all_tokens, int& loc);
/*void test_R22()
{
  //Create vector of tokens and default location of 0
  std::vector<token_323> all_tokens;
  int loc = 0;

  //Create sample input tokens for test case
  token_323 token1;
  token1.token_update("keyword");
  token1.lexeme_update("while");

  token_323 token2;
  token2.token_update("symbol");
  token2.lexeme_update("(");

  token_323 token3;
  token3.token_update("statement");
  token3.lexeme_update("Condition");

  token_323 token4;
  token4.token_update("symbol");
  token4.lexeme_update(")");

  //Push tokens into vector
  all_tokens.push_back(token1, token2, token3, token4);

  //Call function and set to results bool
  bool results = procedure_While(all_tokens, loc);

  //Print correct statement for results
  if (results == true) {
   std::cout << "Test passed: R22 <While>" << std::endl;
 } else {
   std::cout << "Test failed: R22 <While>" << std::endl;
 }
 writeTokensToFile(all_tokens, "outputfile.txt");
} */

// R21. <Scan> :: = get(<IDs>);
//---------------------------------------------------------------------------------------------------
// bool procedure_Scan(vector<token_323>& all_tokens, int& loc);

// R20. <Print> :: = put(<Expression>);
//---------------------------------------------------------------------------------------------------
// bool procedure_Print(vector<token_323>& all_tokens, int& loc);

// R19. <Return> :: = return; | return <Expression>;
//---------------------------------------------------------------------------------------------------
// bool procedure_Return(vector<token_323>& all_tokens, int& loc);

/*void test_R19() {
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
  writeTokensToFile(all_tokens, "outputfile.txt");

} */

// R18. <If> :: = if (<Condition>) < Statement > fi | if (<Condition>) < Statement > else  <Statement>  fi
//---------------------------------------------------------------------------------------------------
// bool procedure_If(vector<token_323>& all_tokens, int& loc);
/*void test_R18()
{
  std::ifstream input_file("temp.txt");
  bool test_results = false;
  std::vector<token_323> all_tokens;
  int loc = 0;
  int check_eof; // additional flag to properly detect the end of file.

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
  writeTokensToFile(all_tokens, "outputfile.txt");
} */

// R17. <Assign> :: = <Identifier> = <Expression>;
//---------------------------------------------------------------------------------------------------
// bool procedure_Assign(vector<token_323>& all_tokens, int& loc);
/*void test_R17()
{
  //Create vector of tokens
  std::vector<token_323> all_tokens;
  int loc = 0;

  //Create sample input tokens to test and push into vector
  token_323 token1;
  token1.token_update("identifier");
  token1.lexeme_update("a");
  all_tokens.push_back(token1);

  token_323 token2;
  token2.token_update("operator");
  token1.lexeme_update("=");
  all_tokens.push_back(token2);

  token_323 token3;
  token3.token_update("num");
  token3.lexeme_update("1");
  all_tokens.push_back(token3);

  token_323 token4;
  token4.token_update("symbol");
  token4.lexeme_update(";");
  all_tokens.push_back(token4);

  //Call function and set to results bool
  bool results = procedure_Assign(all_tokens, loc);

  //Print out appropriate statements for results
  if (results == true) {
    std::cout << "Test passed: R17 <Assign>" << std::endl;
  } else {
    std::cout << "Test failed: R17 <Assign>" << std::endl;
  }
  writeTokensToFile(all_tokens, "outputfile.txt");

} */

// R16. <Compound> :: = { <Statement List> }
//---------------------------------------------------------------------------------------------------
// bool procedure_Compound(vector<token_323>& all_tokens, int& loc);

// R15. <Statement> :: = <Compound> | <Assign> | <If> | <Return> | <Print> | <Scan> | <While>
//---------------------------------------------------------------------------------------------------
// bool procedure_Statement(vector<token_323>& all_tokens, int& loc);
/*void testR15() {
  std::vector<token_323> all_tokens;
  int loc = 0;
  token_323 sampleToken;
  sampleToken.TokenUpdate("return");
  sampleToken.LexemeUpdate("scan");
  all_tokens.push_back(sampleToken);
  
  if (procedure_Statement(all_tokens, loc)) {
    std::cout << "R15: Passed" << std::endl;
  } else {
    std::cout << "R15: Failed" << std::endl;
  }
	writeTokensToFile(all_tokens, "outputfile.txt");
} */

// R14. <Statement List> :: = <Statement> | <Statement> <Statement List>
//---------------------------------------------------------------------------------------------------
// bool procedure_Statement_List(vector<token_323>& all_tokens, int& loc);

// R13. <IDs> :: = <Identifier> | <Identifier>, <IDs>
//---------------------------------------------------------------------------------------------------
// bool procedure_IDs(vector<token_323>& all_tokens, int& loc);

/*void test_R13() {

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
  writeTokensToFile(all_tokens, "outputfile.txt");
} */

// R12. <Declaration> :: = <Qualifier > <IDs>
//---------------------------------------------------------------------------------------------------
// bool procedure_Declaration(vector<token_323>& all_tokens, int& loc);
/*void test_R12()
{
  bool test_results = false;
  std::vector<token_323> all_tokens;
  int loc = 0;
  std::ifstream input_file("temp.txt");
  int check_eof; // additional flag to properly detect the end of file.

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
  writeTokensToFile(all_tokens, "outputfile.txt");
} */

// R11. <Declaration List>  : = <Declaration>; | <Declaration>; <Declaration List>
//---------------------------------------------------------------------------------------------------
// bool procedure_Declaration_List(vector<token_323>& all_tokens, int& loc);

// R10. <Opt Declaration List> :: = <Declaration List> | <Empty>
//---------------------------------------------------------------------------------------------------
// bool procedure_Opt_Declaration_List(vector<token_323>& all_tokens, int& loc);
/*void test_R10()
{
  // Create sample vector of tokens
  std::vector<token_323> all_tokens;
  int loc = 0;

  // Create sample tokens and push to the vector all_tokens
  token_323 token1;
  token1.token_update("keyword");
  token1.lexeme_update("int");
  all_tokens.push_back(token1);

  token_323 token2;
  token2.token_update("identifier");
  token2.lexeme_update("a");
  all_tokens.push_back(token2);

  token_323 token3;
  token3.token_update("symbol");
  token3.lexeme_update(";");
  all_tokens.push_back(token3);

  //Call Opt_Declaration_List function and set to result bool
  bool result = procedure_Opt_Declaration_List(all_tokens, loc);

  // Print out appropriate statment for result
  if (result == true)
  {
    std::cout << "Test passed: R10 <Opt_Declaration_List>" << std::endl;
  } else {
    std::cout << "Test failed: R10 <Opt_Declaration_List>" << std::endl;
  }
  writeTokensToFile(all_tokens, "outputfile.txt");
} */

// R9. <Body>  :: = { < Statement List> }
//---------------------------------------------------------------------------------------------------
// bool procedure_Body(vector<token_323>& all_tokens, int& loc);

// R8. <Qualifier> :: = int | boolean | real
//---------------------------------------------------------------------------------------------------
// bool procedure_Qualifier(vector<token_323>& all_tokens, int& loc);
/*void test_R8()
{
  std::ifstream input_file("temp.txt");
  bool test_results = false;
  std::vector<token_323> all_tokens;
  int loc = 0;
  int check_eof; // additional flag to properly detect the end of file.

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
  writeTokensToFile(all_tokens, "outputfile.txt");

  input_file.close();

  return;
} */

// R7. <Parameter> :: = <IDs >  <Qualifier>
//---------------------------------------------------------------------------------------------------
// bool procedure_Parameter(vector<token_323>& all_tokens, int& loc);
/*void test_R7()
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
  writeTokensToFile(all_tokens, "outputfile.txt");
} */


// R6. <Parameter List>  :: = <Parameter> | <Parameter>, <Parameter List>
//---------------------------------------------------------------------------------------------------
// bool procedure_Parameter_List(vector<token_323>& all_tokens, int& loc);

// R5. <Opt Parameter List> :: = <Parameter List> | <Empty>
//---------------------------------------------------------------------------------------------------
// bool procedure_Opt_Parameter_List(vector<token_323>& all_tokens, int& loc);
void test_R5(std::vector<token_323>& all_tokens)
{
  int loc = 0;
  bool test_results = false;

  test_results = procedure_Opt_Parameter_List(all_tokens, loc);

  if (test_results == false) {
    std::cout << "Failed: Testing of R5 <Opt Parameter List>" << std::endl;
  } else {
    std::cout << "Passed: Testing of R5 <Opt Parameter List>" << std::endl;
  }

  std::cout << "\nHere are all the tokens in the vector:" << std::endl;
  for (auto token : all_tokens) {
    token.TokenPrintHelper();
  }
  writeTokensToFile(all_tokens, "outputfile.txt");
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


int main(int argc, char * argv[]) {
  string file_name = "temp.txt";

  // Check if filename is provided
  if (argc > 1) {
    file_name = argv[1];
  }

  // Open file for input
  ifstream input_file(file_name);

  // Check if file is open
  if (!input_file.is_open()) {
    cout << "Error opening file\n";
    return 1;
  }

  // Check if file has data
  if (input_file.peek() == ifstream::traits_type::eof()) {
    cout << "File is empty\n";
    return 1;
  }

  vector<token_323> tokens;

  // Generate tokens from file
  while (input_file.good()) {
    tokens.push_back(lexer_323(input_file));
  }

  // Print tokens
//for (const auto& token : tokens) {
//    token.TokenPrintHelper();
//  }




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
  // testR25();
  // R25.1 <Expression'>
  //
  // R24 <Relop>
  // testR24();
  // R23 <Condition>
  //Failed
  //test_R23();
  // R22 <While>
  //test_R22();
  // R21 <Scan>
  //
  // R20 <Print>
  //
  // R19 <Return>
  //test_R19();
  // R18 <If>
  //test_R18();
  // R17 <Assign>
  //test_R17();
  // R16 <Compound>
  //
  // R15 <Statement>
  // testR15();
  // R14 <Statement List>
  //
  // R13 <IDs>
  //test_R13();
  // R12 <Declaration>
  //test_R12();
  // R11 <Declaration List>
  //
  // R10 <Opt Declaration List>
  //test_R10();
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
  //test_R5(tokens);
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
