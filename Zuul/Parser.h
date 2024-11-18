#include<iostream>

namespace Zuul
{
  class Parser
  {
    private:
      char firstWord[7];
      char secondWord[10];
    public:
      const char ACCEPTED_COMMAND_WORDS[4][7] = {"go", "quit", "pickup", "drop"};
      void inputWords(char* input);
      void getFirstInput(char* output);
      void getSecondInput(char* output);
      bool isValidCommand();
  };
}
