//
// Student names: Esther Xin, Sydney LeBlanc
//
// SYDE 121 assignment: 5
// file name: a5_book.hpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//***************************************************

#ifndef a5_book_hpp
#define a5_book_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//PURPOSE: Class that models a Book instance with corresponding attributes
class Book {
    string title, author, date;
    
public:
    //PURPOSE: Default constructor with no attributes specified
    Book();
    
    //PURPOSE: Parametric constructor with all attributes specified
    Book(string new_title, string new_author, string new_date);
    
    //PURPOSE: Parametric constructor with only title and author attributes specified
    Book(string new_title, string new_author);
    
    //PURPOSE: Parametric constructor with only title attributes specified
    Book(string new_title);
    
    // PURPOSE: Simple accessor methods for member attributes
    string get_title();
    string get_author();
    string get_date();
    
    // PURPOSE: Service function that outputs all attribute values
    void print();
};
#endif /* a5_book_hpp */

