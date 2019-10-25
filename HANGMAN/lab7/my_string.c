#include "my_string.h"
#include "status.h"
#include "generic.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*struct node {
  MY_STRING key;
  GENERIC_VECTOR words;
  struct node* left;
  struct node* right;
  struct node* parent;
  int height;
};
typedef struct node Node;*/





struct my_string{
  int size;
  int capacity;
  char*  data;
};
typedef struct my_string My_string;

typedef void* GENERIC_VECTOR;



struct generic_vector
{
  int size;
  int capacity;
  Item* data;
  Status(*Item_assignment)(Item* left, Item Right);
  void(*item_destroy)(Item* phItem);
  
  
};

typedef struct generic_vector Generic_vector;

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

void my_string_destroy(Item* pItem)
{
  
  My_string* pstring = (My_string*)*pItem;
  if(pstring != NULL)
    {
      
      free(pstring->data);
      free(pstring);
      *pItem = NULL;
    }
}

MY_STRING my_string_init_c_string(const char*c_string)
{
  My_string* string;
  int i, size;
  size = 0;
  for(i = 0; c_string[i] != '\0'; i++)
    size++;
  string  = (My_string*)malloc(sizeof(My_string));
  if (string != NULL)
    {
      string->size = size;
      string->capacity = (string->size)+1;
      string->data = (char*)malloc(sizeof(char) * (string->capacity));
      if(string->data == NULL)
	return NULL;
      for(i = 0; i < string->size; i++)
	{
	  string->data[i] = c_string[i];
	}
      //string->data[i] = '\0';
      return(MY_STRING)string;
      
    }
  return NULL; 
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
        {

          return stringL->data[i]- stringR->data[i];
        }


    }


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
  else if(string->data == NULL)
    {
      string = my_string_init_default();
    }
  else if(fp == NULL)
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

Status my_string_push_back(MY_STRING hMy_string, char item)
{
  My_string* string = (My_string*)hMy_string;
  char* temp;
  int i;
  if(string != NULL)
    {

  if(string->size >= string->capacity)
    {
      temp = (char*)malloc(sizeof(char) *  string->capacity * 2);
                           if(temp == NULL)
                             {
                               return FAILURE;
                             }
                           for(i = 0; i < string->size; i++)
                             {
                               temp[i] = string->data[i];
                             }
                           free(string->data);
                           string->data = NULL;
                           string->data = temp;
                           string->capacity *= 2;

    }

  string->data[string->size] = item;
  string->size++;
  return SUCCESS;
    }
  else
    return FAILURE;
}

Status my_string_pop_back(MY_STRING hMy_string)
{
  My_string* string = (My_string*)hMy_string;
  
  if(string->size <= 0)
    {
      return FAILURE;
    }
  else
    {
      
      //string->size--;
      if(string->size > 0)
	string->data[string->size] = '\0';
      string->size--;
      return SUCCESS;
    }
  
  
}

char* my_string_at(MY_STRING hMy_string, int index)
{
  My_string* string = (My_string*)hMy_string;
  if(index <= string->size)
  {
    return &(string->data[index]);
  }
  else
    {
      return NULL;
    }
}

char* my_string_c_str(MY_STRING hMy_string)
{
  My_string* string = (My_string*)hMy_string;
  my_string_push_back(hMy_string, '\0');
  string->size--;
  return string->data;   
}

Status my_string_concat(MY_STRING hResult, MY_STRING hAppend)
{
  My_string* original = (My_string*)hResult;
  My_string* append = (My_string*)hAppend;
  char* temp;
  int i;
  int j;

  if(original->data != NULL && append->data != NULL)
    {
      temp = (char*)malloc(sizeof(char) * ((original->size) + (append->size) +2));
      if(temp == NULL)
        {
          free(temp);
          temp = NULL;
          return FAILURE;
        }
      for(i = 0; i <= original->size; i++)
        {
          temp[i] = original->data[i];
        }
      j = i;
      for(i = 0; i <= append->size; i++, j++)
	{
	  temp[j] = append->data[i];
	}
    }
  else
    {
      free(original);
      original = NULL;
      free(append);
      append = NULL;
      return FAILURE;
    }
  free(original->data);
  original->data = NULL;
  original->data = temp;
  original->size += append->size;
  original->capacity += append->capacity - 1;
  return SUCCESS;
}

Boolean my_string_empty(MY_STRING hMy_string)
{
  My_string* string = (My_string*)hMy_string;
  if(string->size > 0)
    return FALSE;
  else
    return TRUE;

}

Status my_string_assignment(Item* pLeft, Item Right)
{
  if(*pLeft == NULL)
    {
      *pLeft = my_string_init_c_string(my_string_c_str(Right));
      return SUCCESS;
    }
  else
    {
      my_string_destroy(pLeft);
      *pLeft = my_string_init_c_string(my_string_c_str(Right));
      return SUCCESS;
    }
  return FAILURE;
  

  
}



GENERIC_VECTOR generic_vector_init_default(
	   Status (*assignment)(Item* phleft, Item Right), void(*destroy)(Item* phItem)
)
{
  Generic_vector* pVector;
  pVector = (Generic_vector*)malloc(sizeof(Generic_vector));
  int i;
  if(pVector != NULL)
    {
      pVector->size = 0;
      pVector->capacity = 1;
      pVector->data = (Item*)malloc(sizeof(Item) * pVector->capacity);
      if(pVector->data == NULL)
	{
	  free(pVector);
	  return NULL;
	}
      
      pVector->Item_assignment = assignment;
      pVector->item_destroy = destroy;
      for(i = 0; i < pVector->capacity; i++)
	{
	  pVector->data[i] = NULL;
	}
    }
  return (GENERIC_VECTOR)pVector;
}

Status generic_vector_push_back(GENERIC_VECTOR hVector, Item item)
{
  Generic_vector* pVector = (Generic_vector*)hVector;
  Item* temp;
  int i;

  if(pVector->size >= pVector->capacity)
    {
      temp = (Item*)malloc(sizeof(Item) * 2 * pVector->capacity);
      if(temp == NULL)
	{
	  return FAILURE;
	}
      for(i = 0; i < pVector->size; i++)
	{
	  temp[i] = pVector->data[i];
	}
      pVector->capacity *=2;
      for(;i<pVector->capacity; i++)
	{
	  temp[i] = NULL;
	}
      free(pVector->data);
      pVector->data = temp;
    }
  if (pVector->Item_assignment(&(pVector->data[pVector->size]), item) == SUCCESS)
    {
      pVector->size++;
      return SUCCESS;
    }
  return FAILURE;
}

int generic_vector_get_size(GENERIC_VECTOR hVector)
{
  Generic_vector* pVector = (Generic_vector*)hVector;
  return pVector->size;


}
int generic_vector_get_capacity(GENERIC_VECTOR hVector)
{
  Generic_vector* pVector = (Generic_vector*)hVector;
  return pVector->capacity;


}
Status generic_vector_pop_back(GENERIC_VECTOR hVector)
{
  Generic_vector* pVector = (Generic_vector*)hVector;

  if (pVector->size <= 0)
    {
      return FAILURE;
    }
    else
      {
      
	pVector->item_destroy(&pVector->data[pVector->size-1]);
	pVector->size--;
	return SUCCESS;
      }

}

Boolean generic_vector_empty(GENERIC_VECTOR hVector, int index)
{
  Generic_vector* pVector = (Generic_vector*)hVector;
  return (Boolean)(pVector->size == 0);


}

Item generic_vector_at(GENERIC_VECTOR hVector, int index)
{
  Generic_vector* pVector = (Generic_vector*)hVector;
  if (index < 0 || index >= pVector->size)
    {
      return NULL;
    }
  return pVector->data[index];

}

void generic_vector_destroy(GENERIC_VECTOR* hVector)
 {
  Generic_vector* pVector = (Generic_vector*)*hVector;
  if(pVector->data != NULL && pVector != NULL)
    {
      int i;
      for(i = 0; i < pVector->size; i++)
	pVector->item_destroy(&pVector->data[i]);
      free(pVector->data);
  
      free(pVector);
      *hVector = NULL;
      
    }
  return;
  

}

Status get_word_key_value(MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess)
{
  
  int i = 0;
  
  
  //Status ret;
  if(new_key == NULL)
    new_key = my_string_init_default();
  else
    {
      while(my_string_empty(new_key) == FALSE)
	{
	  my_string_pop_back(new_key);
	}
    }
  
  if(isupper(guess))
    guess = tolower(guess);
  
  
 
  
  for(i = 0; i < my_string_get_size(word); i++)
    {
      if(*(my_string_at(word, i)) == guess)
	{
	  if(my_string_push_back(new_key, guess) == FAILURE)
	    {
	      
	      return FAILURE;
	    }
	}
      else
	{
	  if(my_string_push_back(new_key, *(my_string_at(current_word_family, i))) == FAILURE)
	    {
	      
	      return FAILURE;
	    }
	}
      
     }
  return SUCCESS;
  

}

MY_STRING key_init_default(int word_length)
{
  MY_STRING def = my_string_init_default();
  int i  = 0;
  for(i = 0; i < word_length; i++)
	{
	  my_string_push_back(def, '-');
	  
	}
   
  
    return def;
}

Node* find_max(Node* tree, Node* max)
{
  if(tree != NULL)
    {
      find_max(tree->left, max);
      if(generic_vector_get_size(tree->words) > generic_vector_get_size(max->words))
	{
	  max = tree;
	}
      find_max(tree->right, max);
    }
  return max;
}

Boolean check_for_key(Node* tree, MY_STRING key)
{
 
  if(tree != NULL && key != NULL)                                                                                                                         
    {
      my_string_c_str(tree->key);
      if(my_string_compare(tree->key, key) == 0)                                                                                                                   
        {                                                                                                                                                          
          return TRUE;                                                                                                                                             
        }
      check_for_key(tree->left, key);                                                                                                                            
      check_for_key(tree->right, key);
    }                                                                                                                                                              
    return FALSE;
}

Node* find_key(Node* tree, MY_STRING key)
{
  if(tree != NULL && tree->key != NULL && key != NULL)
    {
      
      if(my_string_compare(tree->key, key) == 0)
        {
          return tree;
        }
      find_key(tree->left, key);
      find_key(tree->right, key);
    }
  return NULL;
}

void node_destroy(Node** n)
{
  
  my_string_destroy((Item*)&((*n)->key));
  generic_vector_destroy(&((*n)->words));
  free(*n);
  *n = NULL;
  return;
}

void destroy_tree(Node** tree)
{
  
  if(*tree != NULL)
    {
      destroy_tree(&(*tree)->left);
      destroy_tree(&(*tree)->right);
      node_destroy(tree);
      *tree = NULL;
    }
  return;
}


int is_balanced(Node* n)
{
  if (n == NULL)
        return 0;
  else
    return (get_h(n->left) - get_h(n->right));
}

int get_h(Node* n)
{
  if(n == NULL)
    return 0;
  else
    return n->height;
}

Node* rotate_left(Node* n)
{
    Node *y = n->right;
    Node *T2 = y->left;
    y->left = n;
    n->right = T2;
    n->height = height_compare(get_h(n->left), get_h(n->right))+1;
    y->height = height_compare(get_h(y->left), get_h(y->right))+1;
    return y;
}

int height_compare(int x, int y)
{
  if(x > y)
    return x;
  else
    return y;
}
Node* rotate_right(Node* n)
{
    Node *x = n->left;
    Node *T2 = x->right;
 
    x->right = n;
    n->left = T2;
    n->height = height_compare(get_h(n->left), get_h(n->right))+1;
    x->height = height_compare(get_h(x->left), get_h(x->right))+1;  
    return x;
  
}

Node* node_init(MY_STRING current_word_family, MY_STRING word, char guess)
{
  Node* new_node = (Node*)malloc(sizeof(Node));
  if(new_node == NULL)
    return NULL;
  new_node->left = NULL;
  new_node->right = NULL;  
  new_node->key = my_string_init_default();
  new_node->words = generic_vector_init_default(my_string_assignment, my_string_destroy);
  get_word_key_value(current_word_family, new_node->key, word, guess);
  new_node->height = 0;
  return new_node;
}

Node* insert_node(Node* n, MY_STRING key, MY_STRING current_word_family, MY_STRING word, char guess)
{
    int bf;//balance factor
   
    if (n == NULL)
      {
	n = node_init(current_word_family, word, guess);
	
	return n;
	
      }
    if(n != NULL && key != NULL)
      {
    if (my_string_compare(n->key, key)  < 0)
      n->left  = insert_node(n->left, key, current_word_family, word, guess);
    else if (my_string_compare(n->key, key) > 0)
      n->right = insert_node(n->right, key, current_word_family, word, guess);
    else 
      return n;
      }
    
    n->height = 1 + height_compare(get_h(n->left), get_h(n->right));
 
    bf = is_balanced(n);
 
    if (bf > 1 && my_string_compare(n->key, key)  < 0)
        return rotate_right(n);
 
    
    if (bf < -1 && my_string_compare(n->key, key) > 0)
        return rotate_left(n);
 
    
    if (bf > 1 && my_string_compare(n->key, key) > 0)
    {
        n->left =  rotate_left(n->left);
        return rotate_right(n);
    }
 
    
    if (bf < -1 && my_string_compare(n->key, key)  < 0)
    {
        n->right = rotate_right(n->right);
        return rotate_left(n);
    }
 
    
    return n;
}

void print_tree(Node* tree)
{
  if(tree != NULL)
    {
      print_tree(tree->left);
      printf("%s \n", my_string_c_str(tree->key));
      print_tree(tree->right);

    }

}
