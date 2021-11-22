#include <stdio.h>
#include <stdlib.h>
#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"

int parser_PublisherFromText(FILE* pFile , LinkedList* pArrayListPublisher);
int parser_BooksFromText(FILE* pFile , LinkedList* pArrayListBooks);
int parser_SaveAsText(FILE* pFile , LinkedList* pArrayList);

#endif /* PARSER_H_ */
