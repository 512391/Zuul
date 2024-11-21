#include<iostream>
#include<cstring>
#include"./Parser.h"

using namespace Zuul;
using namespace std;

/*
  Author: jay williamson
  Date: 11/21/2024
  this class controls the logic of the parser
 */

void Parser::inputWords(char* input)
{
  //empties the word arrays
  memset(Parser::firstWord, 0, sizeof Parser::firstWord);
  memset(Parser::secondWord, 0, sizeof Parser::secondWord);

  //checks if they are on the first or second word
  bool atSpace = false;
  int j = 0;
  //iterates through the input
  for(int i = 0; i < strlen(input); i++)
    {

      //checks if the word is done
      if(input[i] == ' ' && atSpace)
	{
	  return;
	}//checks if starting the second word
      else if(input[i] == ' ')
	{
	  atSpace = true;
	}//checks if at the first word
      else if(!atSpace)
	{
	  //adds letters to first word
	  Parser::firstWord[i] = input[i];
	}
      else
	{
	  //adds letters to second word
	  Parser::secondWord[j] = input[i];
	  j++;
	}
    }
}


//gets the first word
void Parser::getFirstInput(char* output)
{
  //assigns it to the output pointer
  strcpy(output, Parser::firstWord);
}

//gets the second word
void Parser::getSecondInput(char* output)
{
  //assigns it to the output pointer
  strcpy(output, Parser::secondWord);
}

//checks if the command is valid
bool Parser::isValidCommand()
{
  //iterates through valid commands
  for(const char* c : Parser::ACCEPTED_COMMAND_WORDS)
    {
      //checks if the valid is in the input
      if(strcmp(c, Parser::firstWord) == 0)
	{
	  return true;
	}
    }
  return false;
}
