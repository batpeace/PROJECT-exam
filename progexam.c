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
 while(choice!=8)
  {
   switch (choice) 
     {
      case 1: 
      printf("Enter the book:\n");
      insTail(&Library);
      printList(&Library);
      break;
      
      case 2:
      printf("Enter the id:\n");
      Cell_t *p = searchId(&Library);
      if(p != NULL)
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
      rmvTail(&Library);
      printf("Removed the last book of the list.\n");
      break;
      
      case 5:
      printf("Enter the book:\n");
      insHead(&Library);
      break;
            
      case 6:
      printf("Removed the first book of the list.\n");
      rmvHead(&Library);
      break;
      
      case 7:
      printList(&Library);
     } 
      
      printf("\nChoice: "); 
      scanf("%d", &choice);
  
  }    
 return 0;
}   
