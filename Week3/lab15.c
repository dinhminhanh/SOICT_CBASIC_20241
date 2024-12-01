#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char vn[50];
  char eng[50];
} Dict;

void convertTextToBinary(const char *textFile, const char *binaryFile)
{
  FILE *file_text = fopen(textFile, "r");
  FILE *file_bin = fopen(binaryFile, "wb");

  if (file_text == NULL || file_bin == NULL)
  {
    perror("fopen");
    return;
  }

  char line[256];
  Dict word;

  while (fgets(line, sizeof(line), file_text))
  {
    char *token = strtok(line, ":");
    if (token != NULL)
    {
      strcpy(word.vn, token);
      token = strtok(NULL, ":");

      if (token != NULL)
      {
        token[strcspn(token, "\n")] = '\0';
        while (*token == ' ')
          token++;

        strcpy(word.eng, token);
      }
    }

    fwrite(&word, sizeof(Dict), 1, file_bin);
  }

  fclose(file_text);
  fclose(file_bin);
}

void readFromBinary(const char *binaryFile, int from, int to)
{
  FILE *file_bin = fopen(binaryFile, "rb");
  if (file_bin == NULL)
  {
    perror("file bin");
    return;
  }

  Dict word;

  fseek(file_bin, (from - 1) * sizeof(Dict), SEEK_SET);

  for (int i = from; i <= to; i++)
  {
    fread(&word, sizeof(Dict), 1, file_bin);
    printf("vn: %s - eng: %s\n", word.vn, word.eng);
  }

  fclose(file_bin);
}

int main()
{
  char textFile[] = "vnedict.txt";
  char binaryFile[] = "vnedict.dat";

  convertTextToBinary(textFile, binaryFile);

  int from, to;
  printf("Read file <from> <to>: ");
  scanf("%d %d", &from, &to);

  readFromBinary(binaryFile, from, to);

  return 0;
}
