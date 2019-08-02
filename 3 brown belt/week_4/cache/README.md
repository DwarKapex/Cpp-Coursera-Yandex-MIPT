In this task, we will work with shared_ptr in a multi-threaded environment.

It will be necessary to implement the backend cache of the electronic library. There are many books on the disk — archived text files. The user requests a book with the given name. It must be considered, unpacked and returned. Most often, users request the same books, so I want to cache them. In this case, requests come in several threads.

To access the books, the ICache interface declared in the Common.h file is used. It has only one GetBook () method, which returns shared_ptr to the book (uses the synonym BookPtr). The implementation of this method should ensure proper caching.

The book is presented by the IBook interface. Its two methods GetName () and GetContent () allow you to get the title and text of the book, respectively.

Finally, reading and unpacking the book is done using the IBooksUnpacker interface. Its UnpackBook () method returns the unpacked book as an IBook object by the passed book title.

To create an ICache object, use the MakeCache () function, which you need to implement. It accepts an IBooksUnpacker object, as well as an ICache :: Settings object — cache settings. In our task, the settings contain only one max_memory parameter - the maximum total size of all books in the cache in bytes - but in reality there may be more. That is why we designed the settings in the form of a structure. The size of the book is the size of its text in bytes.

Caching is done by displacing long unused elements (Least Recently Used, LRU). Each cache element has a rank. When the GetBook () method is called, if the book with the same name is already in the cache, its rank rises to the maximum (strictly more than all the others). If such a book is not in the cache, then it is added to the cache, and its rank, again, is set to the maximum. In this case, if the total size of the books exceeds the max_memory limit, the books with the lowest rank are deleted from the cache, as long as necessary. Perhaps until it is completely empty. If the size of the requested book already exceeds max_memory, then after calling the method the cache remains empty, that is, the book is not added to it.

The GetBook () method can be called from several threads at the same time, so it is necessary to ensure its safety in such conditions.

Implementations of LRU caches used in practice allow you to search for items by key and delete long-unused items in constant time. This task is not required. You can search for long unused elements by sorting through all available ones.

In addition to Common.h, you are given two files: main.cpp and Solution.cpp. The first contains an incomplete set of tests for the MakeCache function, the second contains a solution preparation. Implement the MakeCache function in the Solution.cpp file and pass this file to the testing system.
