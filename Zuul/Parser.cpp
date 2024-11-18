#include<iostream>
#include<cstring>
#include"./Parser.h"

using namespace Zuul;
using namespace std;

void Parser::inputWords(char* input)
{
  memset(Parser::firstWord, 0, sizeof Parser::firstWord);
  memset(Parser::secondWord, 0, sizeof Parser::secondWord);
  
  bool atSpace = false;
  for(int i = 0; i < strlen(input); i++)
    {
      if(input[i] == ' ')
	{
	  atSpace = true;
	}
      else if(!atSpace)
	{
	  Parser::firstWord[i] = input[i];
	}
      else
	{
	  Parser::secondWord[i] = input[i];
	}
    }
}

void Parser::getFirstInput(char* output)
{
  strcpy(output, Parser::firstWord);
}

void Parser::getSecondInput(char* output)
{
  strcpy(output, Parser::secondWord);
}

bool Parser::isValidCommand()
{
  for(const char* c : Parser::ACCEPTED_COMMAND_WORDS)
    {
      if(strcmp(c, Parser::firstWord) == 0)
	{
	  return true;
	}
    }
  return false;
}
