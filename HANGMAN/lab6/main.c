#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
  MY_STRING* handles = (MY_STRING*)malloc(sizeof(MY_STRING) * 100);
  int i = 0;
  
  for(i = 0; i < 100; i++)
    {
      handles[i] = NULL;
    }
  handles[0] = my_string_init_c_string("COPY ME!\n");
  handles[1] = my_string_init_default();
  handles[2] = my_string_init_c_string("000000000000000000");
  for(i = 1; i < 100; i++)
    {
      my_string_assignment((Item*)&handles[i], handles[0]);
    }
    for(i = 0; i< 100; i++)
    {
      printf("[%d]%s",i ,  my_string_c_str(handles[i]));
      
      my_string_destroy(&handles[i]);
      }
  free(handles);
  
}
