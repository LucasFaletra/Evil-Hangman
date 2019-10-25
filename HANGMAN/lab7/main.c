#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "generic.h"
#include "status.h"
#include "my_string.h"


void clear_keyboard(void);

Boolean check_word(MY_STRING word);

Boolean check_for_guess(MY_STRING str_guesses, char guess);

Node* evil_hangman(Node* max, Node* root, MY_STRING word_family, MY_STRING key, GENERIC_VECTOR words, char guess);

int main(int argc, char* argv[])
{
  int word_length = 0;
  int guesses = 0;
  char y_n;
  char c;
  char cont = 'y';
  MY_STRING word_family = NULL;
  MY_STRING key = my_string_init_default();
  MY_STRING str_guesses = NULL;
  GENERIC_VECTOR working_words = NULL;
  
  FILE* fp = fopen("dictionary.txt", "r");
  int i = 0;
  int j = 0;
  MY_STRING extract = my_string_init_default();
  GENERIC_VECTOR* vectors = (GENERIC_VECTOR*)malloc(sizeof(GENERIC_VECTOR) * 30);
  for(i = 0; i <=29; i++)
    {
      vectors[i] = generic_vector_init_default(my_string_assignment, my_string_destroy);
    }
 
      while(my_string_extraction(extract, fp) == SUCCESS)
         {
	   
	     generic_vector_push_back(vectors[my_string_get_size(extract) - 1], (Item)extract);
	   
	 }
        
	my_string_destroy((Item*)&extract);

	/*********************************************************************************************/
	//only input is in this block
	while(cont == 'y')
	  {
	    str_guesses = my_string_init_default();
	    j = 0;
	    my_string_destroy((Item*)&key);
	    printf("enter amount of guesses: ");
	    scanf("%d", &guesses);
	    clear_keyboard();
	    while(guesses <= 0)
	      {
		printf("that is an invalid guess, try again: ");
		scanf("%d", &guesses);
		clear_keyboard();
	      }
	
	    printf("enter length of word: ");
	    scanf("%d", &word_length);
	    clear_keyboard();
	    while(generic_vector_get_size(vectors[word_length - 1]) == 0)
	      {
		printf("no words with that many letters exist, guess again: ");
		scanf("%d", &word_length);
		clear_keyboard();
	      }
	   

	    printf("would you like to see a running total of words remaining?[y/n]: ");
	    scanf("%c", &y_n);
	    clear_keyboard();
	    while(y_n != 'n' && y_n != 'y')
	      {
		printf("invalid input\nwould you like to see a running total of words remaining?[y/n]: ");
		scanf("%c", &y_n);
		clear_keyboard();
	      }
	  


	/*****************************************************************************************/

	  working_words = vectors[word_length - 1];//select first group of working words
	  word_family = key_init_default(word_length);
	  //my_string_destroy((Item*)&key);
	  key = key_init_default(word_length);
	  Node* node = NULL;
          Node* info = NULL;
	  Node* root = NULL;
	  
	  while(guesses > 0 /*&& generic_vector_get_size(working_words) > 0*/)//loop for game
	    {
	     printf("guesses remaining: %d\n", guesses);
	     if(y_n == 'y')
	       {
		 printf("number of possible words: %d\n", generic_vector_get_size(working_words));
	       } 
	     printf("pick a letter to guess: ");
	     scanf("%c", &c);
	     clear_keyboard();
	     while(check_for_guess(str_guesses, c) == TRUE)
	       {
		 printf("you already guesses that letter, pick a new letter to guess: ");
                 scanf("%c", &c);
                 clear_keyboard();
	       }
	     my_string_push_back(str_guesses, c);
             my_string_push_back(str_guesses, ' ');

	     info = evil_hangman(node, root, word_family, key, working_words, c);
	        
	     if(check_word(info->key) == TRUE)
               break;
	     
	     
	     if(j > 0)
	       generic_vector_destroy(&working_words);
	     
	     working_words = info->words;
	     my_string_destroy((Item*)&word_family);
	     word_family = info->key;
	     printf("previous guesses: %s\n", my_string_c_str(str_guesses));
	     printf("word is: %s\n", my_string_c_str(info->key));
	     guesses--;
	     j++;
	     
	     destroy_tree(&root);
	    }
	     
	  if(/*generic_vector_get_size(working_words) == 1 &&*/ check_word(info->key) == TRUE)
	    printf("you guessed correctly! the word was: %s\n", my_string_c_str(generic_vector_at(working_words, 0)));
	  else if(generic_vector_get_size(working_words) > 0)
	    printf("you are out of guesses the word was: %s\n", my_string_c_str(generic_vector_at(working_words, 0)));
	  j = 0;
	  /*my_string_destroy((Item*)&str_guesses);
	    str_guesses = my_string_init_default();*/
	  generic_vector_destroy(&working_words);
	  my_string_destroy((Item*)&word_family);
	  my_string_destroy((Item*)&key);
	  my_string_destroy((Item*)&str_guesses);
	  
	  printf("would you like to play again?[y/n]");
	  scanf("%c", &cont);
	  clear_keyboard();
	  
	  while(cont != 'y' && cont != 'n')
	    {
	      printf("invalid input, would you like to continue?");
	      scanf("%c", &cont);
	      clear_keyboard();
	    }
	 

	  }
    	
    for(i = 0; i <= 29; i++)
    {
      
      generic_vector_destroy(&vectors[i]);

    }
   
  free(vectors);
  fclose(fp);
  return 0;
}

void clear_keyboard(void)
{
	char c;
	do
	{
		scanf("%c", &c);
	} while (c != '\n');
	return;
}

  
Node* evil_hangman(Node* max, Node* root, MY_STRING word_family, MY_STRING key, GENERIC_VECTOR words, char guess)
{
 
  int wc = generic_vector_get_size(words) - 1;
 
  Node* garbage = node_init(word_family, generic_vector_at(words, wc), guess);
  MY_STRING temp_key = my_string_init_default();
  
  Node* n =  node_init(word_family, generic_vector_at(words, wc), guess);
  Node* important = NULL;

  
  max = n;
  root = n;
  while(wc > 1 && n!= NULL)
    {
      
      get_word_key_value(word_family, temp_key, generic_vector_at(words, wc), guess); 
      my_string_c_str(temp_key);
      
      
      if(check_for_key(n, temp_key) == FALSE)
	{
	  key = temp_key;
	 
	  insert_node(n, temp_key, word_family, generic_vector_at(words, wc), guess);
	  
	}
      else
	{
	  key = temp_key;
	  generic_vector_push_back((find_key(n, temp_key))->words, generic_vector_at(words, wc));
        
	}
      max = find_max(n, max);
      wc--;     
    }
  print_tree(n);
  my_string_destroy((Item*)&temp_key);
  
  important = max;
  max = garbage;
  
  
 
  return important;
  
}

Boolean check_word(MY_STRING word)
{
  int size  = my_string_get_size(word);
  int i;
  for(i = 0; i < size; i++)
    {
      if(*(my_string_at(word, i)) == '-')
	return FALSE;
    }
  return TRUE;

}

Boolean check_for_guess(MY_STRING str_guesses, char guess)
{
  int i;
  for(i = 0; i < my_string_get_size(str_guesses); i++)
    {
      if( *(my_string_at(str_guesses, i)) == guess)
         {
	   return TRUE;
         }
    }
    return FALSE;  

}
  
