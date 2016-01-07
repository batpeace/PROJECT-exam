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
 scanf("%s", p->title);
 printf("|  Writer:  ");
 scanf("%s", p->writer);
 printf("|  Genre: 0.Thriller;\n"
        "|         1.Fantasy;\n" 
        "|         2.Novel;\n"
        "|         3.Noir;\n" 
        "|         4.Adventure;\n"
        "|         5.Action;\n"
        "|         6.Horror.\n"
        "|  You have chosen the genre number: "); 
 scanf("%u", &p->genre);
 while(1) //loop infinito
 {
  printf("|  Published in(dd/mm/yyyy):  ");
  scanf("%hd%hd%hd", 
  &p->published.day,
  &p->published.month,
  &p->published.year);
 if(p->published.day<32)
   if(p->published.month<13)
     if(p->published.year<2016)
    break; //esce dal loop
 printf("|  Immissione non valida\n");
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
         printf("\nEnter your choice:\n"
                "1 to insert an element at the end of the list.\n" 
                "2 to see the book's specifications.\n"
                "3 to see if the book is in the list from its id.\n"
                "4 to remove the last list's book.\n"
                "5 to insert an element at the beginning of the list.\n"
                "6 to remove the first book's list.\n"
                "7 to end.\n");        
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
  if(tempPtr == List->pLast)
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


void insHead(BookList_t* List)                   //Non va bene :D.
{  
 Cell_t *p= allocBook();                       
 if (List->pFirst == NULL)
 List->pFirst = p;
}  
 
 
void rmvHead(BookList_t* List)                   //Nemmeno :D.
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

Cell_t* Control(BookList_t* List)
{
 Cell_t *Temp = List->pFirst;
 while(Temp)
 {
  if (&Temp->book == NULL)
  printf("Sorry but the list is still empty. Please select another function.\n");
  break;
  Temp = Temp->pNext;
 }
 return Temp;
}
 

 
 
