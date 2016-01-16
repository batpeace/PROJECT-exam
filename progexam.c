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
 while(choice!=11)
  {
   switch (choice) 
     {
      case 1: 
      printf("\nEnter the book:\n");
      insHead(&Library);
      printf("Book added correctly\n");
      printList(&Library);
      printf("\nList printed correctly.\n");
      break;
      
      case 2:
      printf("\nEnter the book:\n");
      insTail(&Library);
      printf("Book added correctly\n");
      printList(&Library);
      printf("\nList printed correctly.\n");
      break;
      
      case 3: 
      printf("\nRemoving the first book of the list...\n");
      rmvHead(&Library);
      printf("Function worked correctly.\n");
      printList(&Library);
      printf("\nList printed correctly.\n");
      break;
      
      case 4:
      printf("\nRemoving the last book of the list...\n");
      rmvTail(&Library);
      printf("Function worked correctly.\n");
      printList(&Library);
      printf("\nList printed correctly.\n");
      break;
      
      case 5: 
      rmvId(&Library);
      printf("Function worked correctly.\n");
      printList(&Library);
      printf("\nList printed correctly.\n");
      break;
            
      case 6:
      printf("\nEnter the id to see if the book is in the list:\n");
      Cell_t* Ptr = searchIdTrueFalse(&Library);
      if(Ptr != NULL)
      printf("Function worked correctly.\n");
      break;
      
      case 7: 
      copyOut(&Library);
      printf("Function worked correctly.\n");
      break;
      
      case 8:
      copyIn(&Library);
      printf("Function worked correctly.\n");
      break;

      case 9: 
      printf("\nEnter the id:\n");
      Cell_t *p = searchId(&Library);
      if(p != NULL)
      {
       printf("Book found correctly.\n");
       printElem(&p->book);
      } 
      else printf("No book with this id available.\n"); 
      printf("\nFunction worked correctly.\n");
      break;
      
      case 10:
      printf("\nSearching for the list..\n");
      printList(&Library);
      printf("List printed correctly.\n");
      break;
     
     } 
      
      printf("\nChoice: "); 
      scanf("%d", &choice);
  }    
 printf("\nThanks for using our e-Library and have a good day!\n\n");
 return 0; 
}
     
