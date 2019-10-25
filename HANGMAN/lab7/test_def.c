#include "unit_test.h"
#include "my_string.h"
#include "status.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
Status my_string_init_default_test_if_NULL(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_c_string("hello");

  if(hString == NULL)
    {
      
      strncpy(buffer, "test_init_default_returns_nonNULL\n" "my_string_init_default returns NULL", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
      return SUCCESS;
    }
}

Status size_on_init_default(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();

  

  if(my_string_get_size(hString) != 0)
    {
      strncpy(buffer, "size_on_init_default\n" "size is not initialized correctly on init default\n", length);
      my_string_destroy((Item*)&hString);
      return FAILURE;
    }
  else
    {
      
      strncpy(buffer, "\tsize_on_init_default\n", length);
      my_string_destroy((Item*)&hString);
      return SUCCESS;
    }
  
}

Status capacity_on_init_default(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();

  

  if(my_string_get_capacity(hString) != 7)
    {
      strncpy(buffer, "capacity_on_init_default\n" "capacity is not initialized correctly on init default\n", length);
      my_string_destroy((Item*)&hString);
      return FAILURE;
    }
  else
    {
      strncpy(buffer, "\tcapacity_on_init_default\n", length);
      my_string_destroy((Item*)&hString);
      return SUCCESS;
    }
}

Status  my_string_init_c_string_test_if_NULL(char* buffer, int length)
{
   MY_STRING hString = NULL;

   hString = my_string_init_c_string("hi");

   if(hString == NULL)
     {
       strncpy(buffer, "size_on_init_default\n" "my_string_init_c_string returns NULL\n", length);
       return FAILURE;
    }
  else
    {
      strncpy(buffer, "\tmy_string_init_c_string\n", length);
      my_string_destroy((Item*)&hString);
      return SUCCESS;
    }
  
}


Status  size_on_my_string_init_c_string_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

   hString = my_string_init_c_string("hi");

  

   if(my_string_get_size(hString) != 2)
     {
       strncpy(buffer, "size_on_my_string_init_c_string\n" "size is not initialized correctly on init_c_string\n", length);
       my_string_destroy((Item*)&hString);
       return FAILURE;
    }
  else
    {

      strncpy(buffer, "\tsize_on_my_string_init_c_string\n", length);
      my_string_destroy((Item*)&hString);
      return SUCCESS;
    }
}

Status  content_in_my_string_init_c_string_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

   hString = my_string_init_c_string("hi");

   

   char test[3] = "hi";
   
   if(test[0] == *(my_string_at(hString, 0)) && test[1] != *(my_string_at(hString, 1)))
     {
       strncpy(buffer, "content_in_my_string_init_c_string\n" "content is not initialized correctly on init_c_string\n", length);
       my_string_destroy((Item*)&hString);
       return FAILURE;
     }
  else
    {

      strncpy(buffer, "\tsize_on_my_string_init_c_string\n", length);
      my_string_destroy((Item*)&hString);
      return SUCCESS;
    }
}

Status my_string_destroy_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  my_string_destroy((Item*)&hString);
  if(hString != NULL)
    {
      strncpy(buffer, "my_string_destroy_test\n" "my_string_destroy returns nonNULL", length);
      
      return FAILURE;
    }
  else
    {
      
      strncpy(buffer, "\tmy_string_destroy_test\n", length);
      return SUCCESS;
    }
}

Status my_string_get_capacity_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();

  if(my_string_get_capacity(hString) != 7)
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "my_string_get_capacity_test\n" "my_string_get_capacity returns incorrect value", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "\tmy_string_destroy_test\n", length);
      return SUCCESS;
    }
}

Status my_string_get_size_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();

  if(my_string_get_size(hString) != 0)
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "my_string_destroy_test\n" "my_string_destroy returns incorrect values", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "\tmy_string_destroy_test\n", length);
      return SUCCESS;
    }
}

Status my_string_compare_test(char* buffer, int length)
{
  MY_STRING hString = NULL;
  MY_STRING hString2 = NULL;
  
  hString = my_string_init_c_string("string");
  hString2 = my_string_init_c_string("yes");
  if(my_string_compare(hString, hString2) != 's' - 'y')
    {
      my_string_destroy((Item*)&hString);
      my_string_destroy((Item*)&hString2);
      strncpy(buffer, "my_string_compare_test\n" "my_string_compare returns incorrect values", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString);
      my_string_destroy((Item*)&hString2);
      strncpy(buffer, "\tmy_string_compare_test\n", length);
      return SUCCESS;
    }
}

Status my_string_compare_when_equal(char* buffer, int length)
{
  MY_STRING hString = NULL;
  MY_STRING hString2 = NULL;

  hString = my_string_init_c_string("no");
  my_string_c_str(hString);
  hString2 = my_string_init_c_string("no");
  my_string_c_str(hString2);
  if(my_string_compare(hString, hString2) != 0)
    {
      my_string_destroy((Item*)&hString);
      my_string_destroy((Item*)&hString2);
      strncpy(buffer, "my_string_compare_when_equal_test\n" "my_string_compare returns incorrect values for same strings", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString);
      my_string_destroy((Item*)&hString2);
      strncpy(buffer, "\tmy_string_compare_when_equal_test\n", length);
      return SUCCESS;
    }
}

Status my_string_extraction_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  FILE* fp = fopen("dictionary.txt", "r");
  if(my_string_extraction(hString, fp) != SUCCESS)
    {
      fclose(fp);
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "my_string_extraction_test\n" "my_string_extraction does not work properly", length);
      return FAILURE;
    }
  else
    {
      fclose(fp);
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "\tmy_string_destroy_test\n", length);
      return SUCCESS;
    }
}

Status my_string_extraction_test_with_empty_file(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_default();
  FILE* fp = fopen("empty.txt", "r");
  if(my_string_extraction(hString, fp) == SUCCESS)
    {
      fclose(fp);
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "my_string_extraction_test_with_empty_file\n" "my_string_extraction works when the file is empty", length);
      return FAILURE;
    }
  else
    {
      fclose(fp);
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "\tmy_string_extraction_test\n", length);
      return SUCCESS;
    }
}

Status my_string_insertion_test(char* buffer, int length)
{
  MY_STRING hString = NULL;
  
  hString = my_string_init_c_string("hi there");
  
  if(my_string_extraction(hString, stdout) == SUCCESS)
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "my_string_insertion_test\n" "my_string_insertion does not return correct values with two words", length);
      return FAILURE;
    }
  else
    {
      if(my_string_extraction(hString, stdout) == SUCCESS)
	{
	  my_string_destroy((Item*)&hString);
	  strncpy(buffer, "my_string_insertion_test\n" "my_string_insertion does not work with two words", length);
          return FAILURE;
	}
      else
	{
	  my_string_destroy((Item*)&hString);
	  strncpy(buffer, "\tmy_string_insertion_test\n", length);
	 return SUCCESS;
	}  
    }

  
}

Status my_string_insertion_test_with_no_string(char* buffer, int length)
{
  MY_STRING hString = NULL;

  

  if(my_string_extraction(hString, stdout) == SUCCESS)
    {
      
      strncpy(buffer, "my_string_insertion_test_with_no_string\n" "my_string_insertion does not return correct values without a string", length);
      return FAILURE;
    }
  else
    {
      
      strncpy(buffer, "\tmy_string_insertion_test_with_no_string\n", length);
      return SUCCESS;
    }
}

Status my_string_push_back_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_c_string("pushstuff");
  int before_push = my_string_get_size(hString);
  my_string_push_back(hString, 'n');

  if(my_string_get_size(hString) != before_push + 1)
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "my_string_push_back_test\n" "my_string_push_back does not increase the size. Might not push correctly", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "\tmy_string_push_back_test\n", length);
      return SUCCESS;
    }
}

Status my_string_push_back_with_NULL_string(char* buffer, int length)
{
  MY_STRING hString = NULL;

  if(my_string_push_back(hString, 'n') != FAILURE)
    {
      
      strncpy(buffer, "my_string_push_back_test_with_NULL_string\n" "my_string_push_back works with a NULL string", length);
      return FAILURE;
    }
  else
    {
      
      strncpy(buffer, "\tmy_string_push_back_test_with_NULL_string\n", length);
      return SUCCESS;
    }
}

Status my_string_pop_back_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_c_string("ooooof");
  int before_pop = my_string_get_size(hString);
  my_string_pop_back(hString);
  if(my_string_get_size(hString) != before_pop - 1)
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "my_string_push_back_test\n" "my_string_push_back does not increase the size. Might not push correctly", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "\tmy_string_pop_back_test", length);
      return SUCCESS;
    }
}

Status my_string_pop_back_with_empty_string(char* buffer, int length)
{
  MY_STRING hString = NULL;
  hString = my_string_init_default();
  if(my_string_pop_back(hString) != FAILURE)
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "my_string_pop_back_test_with_NULL_string\n" "my_string_pop_back works with a NULL string", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "\tmy_string_pop_back_test_with_NULL_string\n", length);
      return SUCCESS;
    }
}

Status my_string_at_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_c_string("Lucas");

  if(*(my_string_at(hString, 1)) != 'u')
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "my_string_at_test\n" "my_string_at is not returning a pointer to the proper index", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "\tmy_string_at_test", length);
      return SUCCESS;
    }
}

Status my_string_c_str_test(char* buffer, int length)
{
  MY_STRING hString = NULL;

  hString = my_string_init_c_string("Lucas Faletra");

  if(my_string_c_str == NULL)
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "my_string_c_str_test\n" "my_string_c_str is returning NULL when passed a valid string", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "\tmy_string_c_str", length);
      return SUCCESS;
    }
}

Status my_string_concat_test(char* buffer, int length)
{
  MY_STRING hString1 = NULL;
  MY_STRING hString2 = NULL;

  hString1 = my_string_init_c_string("Lucas");
  hString2 = my_string_init_c_string(" Faletra");
  my_string_concat(hString1, hString2);
  if(my_string_get_size(hString1) != 13)
    {
      my_string_destroy((Item*)&hString1);
      my_string_destroy((Item*)&hString2);
      strncpy(buffer, "my_string_concat_test\n" "my_string_concat is not updating the information in the concatenated string", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString1);
      my_string_destroy((Item*)&hString2);
      strncpy(buffer, "\tmy_string_concat", length);
      return SUCCESS;
    }
}

Status my_string_concat_with_one_empty_string(char* buffer, int length)
{
  MY_STRING hString1 = NULL;
  MY_STRING hString2 = NULL;
  hString1 = my_string_init_default();
  hString2 = my_string_init_c_string("nonNULL");
  if(my_string_concat(hString1, hString2) != SUCCESS)
    {
      my_string_destroy((Item*)&hString1);
      my_string_destroy((Item*)&hString2);
      strncpy(buffer, "my_string_concat_test_with_one_NULL_string\n" "my_string_concat works if passed a NULL string", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString1);
      my_string_destroy((Item*)&hString2);
      strncpy(buffer, "\tmy_string_concat", length);
      return SUCCESS;
    }
}

Status my_string_empty_test(char* buffer, int length)
{
  MY_STRING hString = NULL;
  hString = my_string_init_default();
  if(my_string_empty(hString) != TRUE)
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "my_string_empty_test\n" "my_string_empty is not returning correct values", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "\tmy_string_empty", length);
      return SUCCESS;
    }
}

Status my_string_not_empty_test(char* buffer, int length)
{
   MY_STRING hString = NULL;
   hString = my_string_init_c_string("not empty");
   if(my_string_empty(hString) != FALSE)
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "my_string_not_empty_test\n" "my_string_empty is not returning correct values", length);
      return FAILURE;
    }
  else
    {
      my_string_destroy((Item*)&hString);
      strncpy(buffer, "\tmy_string_empty", length);
      return SUCCESS;
    }
}
