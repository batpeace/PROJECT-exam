#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"

int main()
{ 
  //(Cell_t).pLast = NULL;                            //Inizializza pLast.
 BookList_t Library;
 int choice;
 instructions();
 printf("\nChoice: "); 
 scanf("%d", &choice);
 while(choice!=5)
  {
  switch (choice) 
     {
      case 1: 
      printf("Enter a book:\n");
      insTail(&Library);
      break;
      
      case 2:
      printf("Enter the id:\n");
      Cell_t* p= searchId(&Library);
       if(p) //sottointeso != NULL
	printElem(&p->book);
       else
	printf("No id available.\n");
      break;
 
      /* case 3: */
      /* printf("Find the book from its id:\n"); */
      /* searchId(); */
      /* break; */
      
      case 4:
      printf("Remove the last book of the list.\n");
      rmvTail(&Library);
      break;
     }  
  printf("\nChoice: "); scanf("%d", &choice);
  } 
 return 0;
} 
