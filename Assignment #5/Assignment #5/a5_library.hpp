//
// Student names: Esther Xin, Sydney LeBlanc
//
// SYDE 121 assignment: 5
// file name: a5_library.hpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//***************************************************

#ifndef a5_library_hpp
#define a5_library_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "a5_book.hpp"
using namespace std;

class Book;

// PURPOSE: Models a library instance with corresponding attributes
class Library {
    vector<Book> books;
public:
    // Default constructor
    Library();
    
    // PURPOSE: Parametric constructor that takes as input a vector of Book objects
    Library(vector<Book> new_books);
    
    // PURPOSE: Inserts a new book into the library based on specified values
    // returns true if the insertion/removal is a success, false is not
    bool insert(Book new_book);
    bool insert(string new_title, string new_author, string new_date);

    // PURPOSE: Removes a book from the library based on specified values
    // returns true if the insertion/removal is a success, false is not
    bool remove(Book remove_book);
    bool remove(string remove_title, string remove_author, string remove_date);

    // PURPOSE: Service function that outputs all the book in the Book collection
    void print();
};
#endif /* a5_library_hpp */
