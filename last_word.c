#include <stdio.h>
#include <string.h>

char* last_word(char* param_1)
{
    char *space = strrchr(param_1, ' ');
    char *comma = strrchr(param_1, ',');
    
    if (param_1 == "")
    {
      return 0;
    }
  
    char *final = (char*) malloc(sizeof(char)*30);
  
    if (comma != 0)
    {
      final = comma + 1;
      final[strlen(final)-2] = '\0';
      return final;
    }
    if (space && *(space + 1))
    {   
    final = space + 1;
    return final;
    }
}

int main()
{
// "FOR PONIES"
// "this        ...       is sparta"
// "  lorem,ipsum  "
// ""

    char input = "FOR PONIES";
    last_word(char* input);

    return 0;
}

