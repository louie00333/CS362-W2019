#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar(int state)
{
	 // 50:50 chance between correct and incorrect next char
	 char randChar = ' ';
	 switch(state)
	 {
	 case 0: case 8:
		 randChar = rand() % 3 + ((int)'[');	
	   break;
	 case 1: case 7:
		 randChar = rand() % 3 + ((int)'(');
	   break;
	 case 2: case 6:
		 randChar = rand() % 3 + ((int)'{');
	   break;
	 case 3:
		 randChar = rand() % 3 + ((int)' ');
	   break;
	 case 4:
		 randChar = rand() % 3 + ((int)'a');
	   break;
	 case 5:
		 randChar = rand() % 3 + ((int)'x');
	   break;
	 default:
		 randChar = ' ';
	 }
	 return randChar;
}

char *inputString()
{
	int i = 0;
	char string[6];
	char *options = "reset\0"; 
  for(i; i < 6 ; i++)
	{ 
		string[i] = options[rand() % 6];
	}
	char *finalStr;
	finalStr = string;
	return finalStr;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar(state);
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' ' && state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error \n");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
