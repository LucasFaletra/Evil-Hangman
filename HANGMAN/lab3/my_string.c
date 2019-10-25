#include "my_string.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct my_string{
  int size;
  int capacity;
  char*  data;
};
typedef struct my_string My_string;




MY_STRING my_string_init_default(void)
{
  My_string* pstring;
  
  pstring  =(My_string*) malloc(sizeof(My_string));
  if (pstring != NULL)
    {
      pstring->size = 0;
      pstring->capacity = 7;
      pstring->data = (char*)malloc(sizeof(char) * pstring->capacity + 1);
      if (pstring == NULL)
	{
	  free(pstring);
	  return NULL;
	 }
    }
  
  return(MY_STRING)pstring;
}

void my_string_destroy(MY_STRING* phMy_string)
{

  My_string* pstring = (My_string*)*phMy_string;
  
  free(pstring->data);
  free(pstring);
 *phMy_string = NULL;
}

MY_STRING my_string_init_c_string(const char*c_string)
{
  My_string* string;
  int i, size;
  size = 0;
  for(i = 0; c_string[i] != '\0'; i++)
    size++;
  string  =(My_string*) malloc(sizeof(My_string));
  if (string != NULL)
    {
      string->size = size;
      string->capacity = (string->size)+1;
      string->data = (char*)malloc(sizeof(char) * (string->capacity));
      for(i = 0; c_string[i]!= '\0'; i++)
	string->data[i] = c_string[i];
      string->data[i] = '\0';
      if (string == NULL)
        {
          free(string);
          return NULL;
        }
      
    }
  return(MY_STRING)string; 
}

int my_string_get_capacity(MY_STRING hMy_string)
{
  My_string* string = (My_string*)hMy_string;
  return string->capacity;
}

int my_string_get_size(MY_STRING hMy_string)
{
  My_string* string = (My_string*)hMy_string;
  return string->size;
}
int my_string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
  int i;
  My_string* stringL = (My_string*)hLeft_string;
  My_string* stringR = (My_string*)hRight_string;
  for(i= 0;stringL->data[i] != '\0' && stringR->data[i]!= '\0'; i++)
    {
      if(stringL->data[i] - stringR->data[i] != 0)
	return stringL->data[i]- stringR->data[i];
      
	
    }
  if(stringL->data[i] == '\0'){
    return -1;}
  if(stringR->data[i] == '\0'){
    return 1;}
  else
    return 0;

}

Status my_string_extraction(MY_STRING hMy_string, FILE* fp)
{
 
  My_string* string = (My_string*)hMy_string;
  
  int i, j = 0;
  
  char* temp;
  char c;
  int noc;
  int size = 0;
  noc = fscanf(fp, " %c", &c);
  if(noc != 1)
    return FAILURE;
  if(string->data == NULL)
    {
      free(string->data);
      return FAILURE;
    }
  if(fp == NULL)
    {
      fclose(fp);
      return FAILURE;
    }
  for(i = 0; i < string->capacity-1; i++)
    {
      string->data[i] = '\0';
      
    }
  
  string->size = 0;
  
  while(noc == 1 && !isspace(c))
    {
      
      for(j = size; j < string->capacity && noc != -1 && !isspace(c) ;j++)
	{
	  string->data[j] = c;
	  noc = fscanf(fp, "%c", &c);
	  string->size++;
	  size++; 
	}
      if(j >= string->capacity)
	{
	  
	  temp = (char*)malloc(sizeof(char) * (string->capacity * 2)+1);
	      if(temp == NULL)
		{
		  
		  free(temp);
		  temp = NULL;
		  return FAILURE;
		}
	    
	      else
		{
		  for(i = 0; i <= string->size-1; i++)
		    {
		      temp[i] = string->data[i];
		    }
		  
		  
		  free(string->data);
		  string->data = NULL;
		  string->data = temp;
		  string->capacity*=2;
		  
		}
          }
	
    }
  
  if(isspace(c))
    { ungetc(c, fp);
      return SUCCESS;
      }
  return SUCCESS;
}

Status my_string_insertion(MY_STRING hMy_string, FILE* fp)
{
  My_string* string = (My_string*)hMy_string;
  int i;
  for(i=0; i<=string->size; i++)
    {
      if(string->data[i] == ' ')
	{
	  
	  return FAILURE;

	}
      else
      fprintf(fp, "%c",  string->data[i]);
      
    }
  return SUCCESS;
}
