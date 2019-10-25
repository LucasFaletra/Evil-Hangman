#ifndef GENERIC_H
#define GENERIC_H
#include "status.h"

typedef void* Item;

typedef void* GENERIC_VECTOR;

GENERIC_VECTOR generic_vector_init_default(Status (*assignment)(Item* phleft, Item Right), void(*destroy)(Item* phItem));

Status generic_vector_push_back(GENERIC_VECTOR hVector, Item item);

int generic_vector_get_size(GENERIC_VECTOR hVector);
int generic_vector_get_capacity(GENERIC_VECTOR hVector);
Status generic_vector_pop_back(GENERIC_VECTOR hVector);

Boolean generic_vector_empty(GENERIC_VECTOR hVector, int index);

Item generic_vector_at(GENERIC_VECTOR hVector, int index);

void generic_vector_destroy(GENERIC_VECTOR* hVector);



#endif

