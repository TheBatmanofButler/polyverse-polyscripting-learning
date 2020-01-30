#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXTOKENBUFLEN 100
#define MAXFILEBUFLEN 200000

int main(int argc, char *argv[])
{
  FILE *input_file_p = fopen(argv[1], "r");
  char output_file_buffer[MAXFILEBUFLEN];
  int output_file_buffer_p = 0;

  char token_buffer[MAXTOKENBUFLEN];
  int token_buffer_p = 0;
  char c;

  c = fgetc(input_file_p);
  while (c != EOF)
  {
    if (c == 'i') // | c == '\n' | c == '(' | c == ')' | c == ':')
    {

      for (int ii = 0; ii <= token_buffer_p;
           ii++)
      {
        output_file_buffer[output_file_buffer_p + ii] = token_buffer[ii];
      }
      // output_file_buffer_p += token_buffer_p + 1;
      output_file_buffer[output_file_buffer_p] = c;
      output_file_buffer_p++;

      memset(token_buffer, 0, sizeof token_buffer);
      token_buffer_p = 0;
    }
    else
    {
      token_buffer[token_buffer_p++] = c;
    }

    c = fgetc(input_file_p);
  }

  fclose(input_file_p);

  FILE *output_file_p = fopen("output.txt", "w");
  if (fputs(output_file_buffer, output_file_p) == EOF)
  {
    printf("Error");
  }
  fclose(output_file_p);

  return 0;
}