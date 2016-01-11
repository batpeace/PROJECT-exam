#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"

int main()
{ 
 BookList_t Library;
 BookList_t *List;
 int choice;
 instructions();
 printf("\nChoice: "); 
 scanf("%d", &choice);
 while(choice!=11)
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
      printf("Book removed successfully.\n");
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
      break;
      
      case 8:
      printf("Enter the book's id you want to delete:\n");
      Cell_t* Ptr = searchId(&Library);
      Cell_t *Temp = List->pFirst;
      if (Ptr != NULL)
      while(Temp != Ptr)
      {
       Temp = Temp->pNext;
       Temp->pNext = NULL;
       free(Ptr);
       Ptr = Temp;
      }        
      break;
      
      case 9: //Funzione che restituisce un libro. (copyIn)
      printf("Insert the id of the book you are returning:\n");
      Cell_t* Pointer = searchId(&Library);
      if(Pointer != NULL)
       if (Pointer->book.outLibrary == 0)
        { 
         printf ("No book with this id is out of the library.\n"); 
        }
      else if (Pointer->book.outLibrary > 0)
      {
       Pointer->book.inLibrary++;
       Pointer->book.outLibrary--;
       printf("Now we have %hd %s in library and %hd out library.\n", 
               Pointer->book.inLibrary,
               Pointer->book.title,
               Pointer->book.outLibrary);
      }
      break;
      
      case 10: //Funzione che prende un libro in prestito. (copyOut).
      printf("Insert the id of the book you are borrowing:\n");
      Cell_t* Puntatore = searchId(&Library);
      if(Puntatore != NULL)
        if (Puntatore->book.inLibrary == 0)
        {
         printf("All the books with this id are out of the library.\n");
        } 
         else if (Puntatore->book.inLibrary > 0)
         {
          Puntatore->book.inLibrary--;
          Puntatore->book.outLibrary++;
          printf("Now we have %hd %s in library and %hd out library.\n", 
                  Puntatore->book.inLibrary,
                  Puntatore->book.title,
                  Puntatore->book.outLibrary); }            
      break;
     } 
      printf("\nChoice: "); 
      scanf("%d", &choice);
  }    
 printf("\nThanks for using our e-Library and have a good day!\n\n");
 return 0; 
}
     
