#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"

int main()
{ 
 BookList_t Library;
 int choice;
 instructions();
 printf("\nChoice: "); 
 scanf("%d", &choice);
 while(choice!=7)
  {
  switch (choice) 
     {
      case 1: 
      printf("Enter the book:\n");
      insTail(&Library);
      break;
      
      case 2:
      Cell_t *ptr = Control(&Library);
      printf("Enter the id:\n");
      Cell_t *p = searchId(&Library);
      if(p!=NULL)
      printElem(&p->book);
      else printf("No book with this id available.\n");
      break;
 
      case 3: //Come il Case 2 ma stampa TRUE o FALSE.
      printf("Enter the id to see if the book is in the list:\n");
      Cell_t *ren = searchId(&Library);
      if (ren != NULL)
       printf("TRUE\n"); 
      else printf("FALSE\n");
      break;
      
      case 4:
      printf("Remove the last book of the list.\n");
      rmvTail(&Library);
      break;
      
      case 5:
      printf("Enter the book:\n");
      insHead(&Library);
      break;
            
      case 6:
      printf("Remove the first book of the list.\n");
      rmvHead(&Library);
      break;
     } 
      
      printf("\nChoice: "); 
      scanf("%d", &choice);
  
  }    
 return 0;
}   
