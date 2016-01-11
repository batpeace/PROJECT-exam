#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"


Cell_t *allocBook()
{
 Cell_t *Ptr = malloc(sizeof(Cell_t));
 Book_t *p = &Ptr->book;
 if(p==NULL)
 {
  printf("Memory allocation failed!\n");
 } 
 printf("--------------------------------------------------\n");
 printf("|  Title:  ");
 scanf(" %[^\n]", p->title);
 printf("|  Writer:  ");
 scanf(" %[^\n]", p->writer);
 printf("|  Genre: 0.Thriller;\n"
        "|         1.Fantasy;\n" 
        "|         2.Novel;\n"
        "|         3.Noir;\n" 
        "|         4.Adventure;\n"
        "|         5.Action;\n"
        "|         6.Horror.\n"
        "|  You have chosen the genre number: "); 
 scanf("%u", &p->genre);
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
 printf("--------------------------------------------------\n");
 return Ptr;
 }


void insTail(BookList_t* List)
{  
 Cell_t *ren = allocBook();                      //In onore di Kylo Ren.
 if(List->pLast == NULL)                         //Se la lista è vuota..          
   List->pLast=List->pFirst = ren;               //collego il primo e l'ultimo elemento.
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
                "[1] to insert an element at the end of the list.\n" 
                "[2] to see the book's specifications.\n"
                "[3] to see if the book is in the list from its id.\n"
                "[4] to remove the last list's book.\n"
                "[5] to insert an element at the beginning of the list.\n"
                "[6] to remove the first book's list.\n"
                "[7] to see the books in the list.\n"
                "[8] to delete a book from its id.\n"
                "[9] to return a book with a specific id.\n"
                "[10] to borrow a book with a specific id.\n"
                "[11] to end.\n");        
        }        


Cell_t* searchId(BookList_t* List)               //Puntatore alla Cell del libro che cerco.
{
 Cell_t* Temp = List->pFirst;
 short id;
 scanf("%hd", &id);
 while(Temp)                                     //Scorre tutta la lista.
  {
   if (Temp->book.id == id)                      //Esce dal ciclo quando trova il libro.
   break;
   Temp = Temp->pNext;
  }
 return Temp;
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
       List->pLast= tempPtr;
     }
}


void insHead(BookList_t* List)                   
{  
 Cell_t *p= allocBook();                       
 if (List->pFirst == NULL)
 List->pFirst = p;
}  
 
 
void rmvHead(BookList_t* List)                   
{                                                
  Cell_t* tempPtr= List->pFirst;                 //Puntatore temporaneo.               
  if(tempPtr == List->pFirst)
   {
    free(tempPtr);
    List->pFirst = List ->pLast = NULL;
   } 
    else
     {
      while(tempPtr->pNext != List->pLast)       //Arriva al penultimo elemento.
       tempPtr= tempPtr->pNext;
       tempPtr->pNext = NULL;
       free (List->pFirst);
       List->pFirst= tempPtr;
     }
} 

void printList(BookList_t* List)
{
 Cell_t* Temp = List->pFirst;
 if (Temp == NULL)
 {
  printf("The list is still empty.\n");
 }
 else 
  { 
   printf("\nThe list is:\n");
   while(Temp != NULL) 
    {
     printf("%s --> ", Temp->book.title);
     Temp = Temp->pNext;
    }
   printf("END\n\n");
  }
}  
 
