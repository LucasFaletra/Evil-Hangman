#include "status.h"
#include "my_string.h"
Status my_string_init_default_test_if_NULL(char* buffer, int length);

Status size_on_init_default(char* buffer, int length);

Status capacity_on_init_default(char* buffer, int length);

Status  my_string_init_c_string_test_if_NULL(char* buffer, int length);

Status  size_on_my_string_init_c_string_test(char* buffer, int length);

Status  content_in_my_string_init_c_string_test(char* buffer, int length);

Status my_string_destroy_test(char* buffer, int length);

Status my_string_get_capacity_test(char* buffer, int length);

Status my_string_get_size_test(char* buffer, int length);

Status my_string_compare_test(char* buffer, int length);

Status my_string_compare_when_equal(char* buffer, int length);

Status my_string_extraction_test(char* buffer, int length);

Status my_string_extraction_test_with_empty_file(char* buffer, int length);

Status my_string_insertion_test(char* buffer, int length);

Status my_string_insertion_test_with_no_string(char* buffer, int length);

Status my_string_push_back_test(char* buffer, int length);

Status my_string_push_back_with_NULL_string(char* buffer, int length);

Status my_string_pop_back_test(char* buffer, int length);

Status my_string_pop_back_with_empty_string(char* buffer, int length);

Status my_string_at_test(char* buffer, int length);

Status my_string_c_str_test(char* buffer, int length);

Status my_string_concat_test(char* buffer, int length);

Status my_string_concat_with_one_empty_string(char* buffer, int length);

Status my_string_empty_test(char* buffer, int length);

Status my_string_not_empty_test(char* buffer, int length);
