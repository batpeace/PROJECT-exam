#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"


Cell_t *allocBook()
{
 short id;
 Cell_t *Ptr = malloc(sizeof(Cell_t));
 Book_t *p = &Ptr->book;
 if(p==NULL)
 {
  printf("Memory allocation failed!\n");
 } 
 printf("__________________________________________________\n");
 printf("|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_\n");
 printf("|\n");
 printf("|  Title:  ");
 scanf(" %[^\n]", p->title);                     //Per poter utilizzare gli spazi con scanf..
 printf("|  Writer:  ");
 scanf(" %[^\n]", p->writer);                    //..altrimenti avrei utilizzato normalmente "%s".
 while (1)
 {
  printf("|  Genre: 0.Thriller;\n"
         "|         1.Fantasy;\n" 
         "|         2.Novel;\n"
         "|         3.Noir;\n" 
         "|         4.Adventure;\n"
         "|         5.Action;\n"
         "|         6.Horror.\n"
         "|  You have chosen the genre number: "); 
 scanf("%u", &p->genre);
 if(p->genre <= 6)
 break;
 printf("|\n"
        "|  Genre not available.\n"
        "|\n");
 }
 while(1)                                        //Loop infinito.
 {
  printf("|  Published in(dd/mm/yyyy):  ");
  scanf("%hd%hd%hd", 
  &p->published.day,
  &p->published.month,
  &p->published.year);
  if(p->published.day<32)
    if(p->published.month<13)
      if(p->published.year<2016)
     break;                                       //Esce dal loop solo se i valori sono corretti.
  printf("|  Invalid input!\n");
 }
 printf("|  In library:  ");
 scanf("%hd", &p->inLibrary);
 printf("|  Out library:  ");
 scanf("%hd", &p->outLibrary);
 printf("|  The id for this book is:  ");
 scanf("%hd", &p->id);
 printf("__________________________________________________\n");
 printf("|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_\n");
 printf("\n");
 return Ptr;
 }


void insTail(BookList_t* List)
{  
 Cell_t *ren = allocBook();                      //In onore di Kylo Ren.
 if(List->pLast == NULL)                         //Se la lista è vuota..          
   List->pLast = List->pFirst = ren;             //collego il primo e l'ultimo elemento.
 else 
     List->pLast->pNext = ren;                   
     List->pLast = ren;
} 

void printElem(Book_t *book)
{
 printf("The book you are searching for is:\n%s. ", book->title);
  if(book->genre==0)
 	 printf("The genre is 'thriller'");
  else if(book->genre==1)
 	 printf("The genre is 'fantasy'");
  else if(book->genre==2)
 	 printf("The genre is 'novel'");
  else if(book->genre==3)
 	 printf("The genre is 'noir'");
  else if(book->genre==4)
 	 printf("The genre is 'adventure'");
  else if(book->genre==5)
 	 printf("The genre is 'action'");
  else if (book->genre==6)
 	 printf("The genre is 'horror'");
  else printf(". Unfortunatelly the genre is not available");  
    printf(" and it's written by %s in %hd/%hd/%hd.\n"
           "We have %hd books in library and %hd out library. Also the id for this book is %hd.\n",
          book->writer,
          book->published.day, book->published.month, book->published.year,
          book->inLibrary, book->outLibrary, book->id);          
} 


void instructions()
        {
         printf("\nWelcome to our e-Library!\n" 
                "\nPlease first insert a book in the list.\n"
                "\nEnter your choice:\n\n"
                "[1] to insert a book at the beginning of the list.\n" 
                "[2] to insert a book at the end of the list.\n"
                "[3] to remove the first book's list.\n"
                "[4] to remove the last list's book.\n"
                "[5] to remove a book with a specific id.\n"
                "[6] to see if a book is in the list using its id.\n"
                "[7] to loan a book with a specific id.\n"
                "[8] to return a book with a specific id.\n"
                "[9] to see the book specifications using its id.\n"
                "[10] to see the books in the list.\n"
                "[11] to end.\n");        
        }        


Cell_t* searchId(BookList_t* List)               //Puntatore alla Cell del libro che cerco.
{
 Cell_t* TempPtr = List->pFirst;
 short id;
 scanf("%hd", &id);
 while(TempPtr)                                  //Scorre tutta la lista.
  {
   if (TempPtr->book.id == id)                   //Esce dal ciclo quando trova il libro.
   break;
   TempPtr = TempPtr->pNext;
  }
 return TempPtr;
} 


void rmvTail(BookList_t* List)
{                                                
  Cell_t* tempPtr = List->pFirst;                 //Puntatore temporaneo.               
  if (tempPtr == NULL)
  printf("The list is empty.\n");
  else if(tempPtr == List->pLast)
   {
    free(tempPtr);
    List->pFirst = List->pLast = NULL;
   } 
    else
     {
      while(tempPtr->pNext != List->pLast)       //Arriva al penultimo elemento.
       tempPtr= tempPtr->pNext;
       tempPtr->pNext = NULL;
       free (List->pLast);
       List->pLast = tempPtr;
     }
}


void insHead(BookList_t* List)                   
{  
 Cell_t *ptr = allocBook();                    
 Cell_t *temp;
 if(List->pLast == NULL)                                   
   List->pLast = List->pFirst = ptr;             //Lista vuota collego primo e ultimo elemento.          
 else 
    temp = List->pFirst;                         //Prendo il libro con un puntatore temporaneo.
    List->pFirst = ptr;                          //Dove c'era quel libro ci metto il nuovo libro.
    List->pFirst->pNext = temp;                  //Il successivo del nuovo libro inserito è il libro che si trovava alla "prima posizione".
} 
  

void rmvHead(BookList_t* List)                   
{                                                
  Cell_t* tempPtr = List->pFirst;                 //Puntatore temporaneo.               
  if (tempPtr == NULL)
  printf("The list is empty.\n");
  else if(tempPtr == List->pLast)
   {
    free(tempPtr);
    List->pFirst = List->pLast = NULL;
   } 
    else
     {
      tempPtr = List->pFirst->pNext;
      free(List->pFirst);
      List->pFirst = tempPtr;      
     }
}


void printList(BookList_t* List)
{
 Cell_t* Temp = List->pFirst;
 if (Temp == NULL)
 {
  printf("\nThe list is still empty.\n");
 }
 else 
  { 
   printf("\nThe list is:\n\n");
   while(Temp != NULL) 
    {
     printf("%s --> ", Temp->book.title);
     Temp = Temp->pNext;
    }
   printf("NULL\n\n");
  }
}  
 

void rmvId(BookList_t* List)
{
 printf("\nEnter the book's id you want to delete:\n");
      Cell_t* Ptr = searchId(List);
      Cell_t* Temp = List->pFirst;
      Cell_t* Hold;
      if (Ptr != NULL)
       {
        while(Temp) 
        {
         if(Temp->pNext == Ptr)
         break;
        } 
         Hold = Ptr->pNext;
         free(Ptr);
         Temp->pNext = Hold;
       }  
      else printf("No book with this id available.\n"); 
} 
 
 
Cell_t* searchIdTrueFalse(BookList_t* List)
{
 Cell_t *P = searchId(List);
 if (P != NULL)
 printf("TRUE\n"); 
 else printf("FALSE\n");
}  
 
 
void copyOut(BookList_t* List)
{
 printf("Insert the id of the book you are loaning:\n");
      Cell_t* Puntatore = searchId(List);
      if(Puntatore != NULL)
        {
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
                   Puntatore->book.outLibrary); 
          }
        }                     
      else printf("No book with this id available.\n"); 
}       


void copyIn(BookList_t* List)
{
 printf("\nInsert the id of the book you are returning:\n");
 Cell_t* Pointer = searchId(List);
 if(Pointer != NULL)
  {
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
     printf("Function worked correctly.\n");
    }        
   }       
   else printf("No book with this id available.\n"); 
}   


