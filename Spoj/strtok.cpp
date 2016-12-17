#include <stdio.h>
#include <string.h>

int main ()
{
  char str[100];
  int ar[100];
  int i=0;
  gets(str);
  char * test;
  test = strtok (str," ");
  while (test != NULL)
  {
      sscanf(test,"%d",&ar[i++]);
    printf ("%d\n",ar[i]);
    test= strtok (NULL, " ");
  }
  return 0;
}
