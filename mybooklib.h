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
                      short id;                 //id = codice di riconoscimento.
                      } Book_t;                 //Book_t sinonimo di tutta la "struct Book"

typedef struct Cell { Book_t book;                     
                      struct Cell* pNext; 
                    } Cell_t;                   //Ogni elemento della BookList è sinonimo distruct Cell.
 
typedef struct BookList { Cell_t *pFirst; Cell_t *pLast; } BookList_t; 

                     
Cell_t* allocBook();                            //Allocare memoria per una struct Cell.
void insHead();                                 //Inserire libro in cima alla lista
void insTail();                                 //Inserire libro in fondo alla lista.
void printElem(Book_t*);                        //Stampare elementi di un libro puntato da Book.
void rmvHead(BookList_t*);                      //Eliminazione libro in cima alla lista. 
void rmvTail(BookList_t*);                      //Eliminazione libro in fondo alla lista. 
void instructions();                            //Scegliere la funzione da svolgere.
Cell_t* searchId(BookList_t*);                  //Ricerca elemento attraverso il suo id.
Cell_t* searchIdTrueFalse(BookList_t*);         //Come searchId ma stampa TRUE o FALSE.
void printList(BookList_t*);                    //Stampa tutti i libri da cui la lista è composta.
void rmvId(BookList_t*);                        //Elimina un libro dato uno specifico id.
void copyOut(BookList_t*);                      //Prestito di un libro con uno specifico id.
void copyIn(BookList_t*);                       //Rientro di un libro con uno specifico id.
