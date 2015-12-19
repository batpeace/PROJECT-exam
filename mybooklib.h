enum book { Thriller=0, Fantasy, Novel, Noir, Adventure, Action, Horror };
struct Date { short day;
              short month;
              short year; 
            };
typedef struct Book { char title [64];
                      char writer [32];
                      enum book genre;
                      struct Date published;
                      short inLibrary;
                      short outLibrary;
                      short id; 
                      } Book_t;                 //Book_t sinonimo di tutta la "struct Book"

typedef struct Cell { Book_t book;                     
                      struct Cell* pNext; 
                    } Cell_t;                   //Ogni elemento della BookList.Sinonimo distruct Cell.
 
typedef struct BookList { Cell_t* pFirst; Cell_t *pLast; } BookList_t; 

                     
Book_t* insHead();                                 //Inserire libro in cima alla lista
Book_t *insTail();                                 //Inserire libro in fondo alla lista.
void deallocBook(Book_t*);                         //Libera spazio in memoria.
void printElem(Book_t*);
void rmvHead(Cell_t*);                             //Eliminazione libro in cima alla lista. 
void rmvTail(Cell_t*);                             //Eliminazione libro in fondo alla lista.
void printList(BookList_t a);                      //Stampo tutti i campi di tutta la lista. 
void instructions();                               //Scegliere la funzione da svolgere.
void searchId();                                   //Ricerca elemento attraverso il suo codice.
