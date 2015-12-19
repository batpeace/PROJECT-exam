#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mybooklib.h"
#include <stdbool.h>
Book_t *insHead(BookList_t* List)
{
 Book_t *p= malloc(sizeof(Book_t));
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
        "|         6.Horror. ");
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
 /*if(List->pLast==NULL)
   List->pLast=List->pFirst = p;
 else {
       List->pLast->pNext = p;
       List->pLast = p;
      }*/
return p;
} 

void deallocBook(Book_t *book)
{
  free (book);
}

void printElem(Book_t *book)
{
 scanf("%hd", &book->id);
 if (&book->id == NULL)
   printf("No id available.\n");
 else if(&book->id != NULL)
   printf("The book you are searching for is:\n %s", book->title);
 if(book->genre==0)
 	printf("the genre is 'thriller'");
 else if(book->genre==1)
 	printf("the genre is 'fantasy'");
 else if(book->genre==2)
 	printf("the genre is 'novel'");
 else if(book->genre==3)
 	printf("the genre 'noir'");
 else if(book->genre==4)
 	printf("the genre is 'adventure'");
 else if(book->genre==5)
 	printf("the genre is 'action'");
 else if (book->genre==6)
 	printf("the genre is 'horror'");
 else printf(". Unfortunatelly the genre is not available");  
   printf(" and it's written by %s in %hd/%hd/%hd.\n",
          book->writer,
          book->published.day, book->published.month, book->published.year);          
} 

void instructions()
        {
         printf("Enter your choice:\n"
                "1 to insert an element into the list.\n" 
                "2 to see a book from its id.\n"
                "3 to see if the book is in the list from its id.\n"
                "4 to end.\n");
        }        

void searchId(int id, Book_t A[], int elementsnumber)
{
 int i;
 for(i=0; i<elementsnumber; i++)
 {
  if(A[i].id==id)
   printf("TRUE\n");
    else printf ("FALSE\n");
 }
} 
