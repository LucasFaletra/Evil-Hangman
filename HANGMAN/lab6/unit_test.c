#include <stdio.h>
#include "unit_test.h"

int main(int argc, char* argv[])
{
  Status(*tests[])(char*, int) =
    {
      my_string_init_default_test_if_NULL,
      size_on_init_default,
      capacity_on_init_default,
      my_string_init_c_string_test_if_NULL,
      size_on_my_string_init_c_string_test,
      content_in_my_string_init_c_string_test,
      my_string_destroy_test,
      my_string_get_capacity_test,
      my_string_get_size_test,
      my_string_compare_test,
      my_string_compare_when_equal,
      my_string_extraction_test,
      my_string_extraction_test_with_empty_file,
      my_string_insertion_test,
      my_string_insertion_test_with_no_string,
      my_string_push_back_test,
      my_string_push_back_with_NULL_string,
      my_string_pop_back_test,
      my_string_pop_back_with_empty_string,
      my_string_at_test,
      my_string_c_str_test,
      my_string_concat_test,
      my_string_concat_with_one_empty_string,
      my_string_empty_test,
      my_string_not_empty_test
    };
  int number_of_functions = 25;
  int i;
  char buffer[500];
  int success_count = 0;
  int failure_count = 0;
  for(i = 0; i < number_of_functions; i++)
    {
      if(tests[i](buffer, 500) == FAILURE)
	{
	  printf("FAILED: Test %d failed miserably\n", i);
	  printf("\t%s\n", buffer);
          failure_count++;
        }
      else
      {
        printf("PASS: Test %d passed\n", i);
	printf("\t%s\n", buffer);
	success_count++;
      }

        
    }
    printf("Total number of tests: %d\n", number_of_functions);
    printf("%d/%d Pass, %d/%d Failure\n", success_count, number_of_functions, failure_count, number_of_functions);
    return 0;
}
