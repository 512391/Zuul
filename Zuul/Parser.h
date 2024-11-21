#include<iostream>

/*
  Author: jay williamson
  Date: 11/21/2024
  this header defines the functions and variables of the parser
 */


namespace Zuul
{
  class Parser
  {
    private:
    //variables for the words inputed
      char firstWord[7];
      char secondWord[10];
    public:
    const char ACCEPTED_COMMAND_WORDS[6][7] = {"go", "quit", "pickup", "drop", "help", "print"};
    //gets the words and seperates them
      void inputWords(char* input);
    //gets the first input word
      void getFirstInput(char* output);
    //gets the second input word
      void getSecondInput(char* output);
    //checks if the command is valid
      bool isValidCommand();
  };
}
