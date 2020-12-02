//
// Student names: Esther Xin, Sydney LeBlanc
//
// SYDE 121 assignment: 5
// file name: a5_library.cpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//***************************************************

#include "a5_library.hpp"
#include <vector>

using namespace std;

Library::Library(){}

Library::Library(vector<Book> new_books) :
        books(new_books){}

bool Library::insert(Book new_book){
    Book current_book;
    
    // Step1. iternates through vector of Books in library, comparing each to the new book
    for (int i = 0; i < books.size(); i++) {
        current_book = books[i];
        
        // Step1.1. Compares each attribute of the books in the Library and the new book
        // If all attributes are the same, returns false
        if (current_book.get_title() == new_book.get_title() &&
            current_book.get_author() == new_book.get_author() &&
            current_book.get_date() == new_book.get_date()) {
            return false;
        }
    }
    // Step2. if none of the Books are the same, insert new_book into the Library
    // and return true
    books.push_back(new_book);
    return true;
}

bool Library::insert(string new_title, string new_author, string new_date){
    Book current_book;
     // Step1. iternates through vector of Books in library, comparing each to the new attributes
    for (int i = 0; i < books.size(); i++) {
        current_book = books[i];
        
        // Step1.1. Compares each attribute of the books in the Library and the new string values
        // If all attributes are the same, returns false
        if (current_book.get_title() == new_title &&
            current_book.get_author() == new_author &&
            current_book.get_date() == new_date) {
            return false;
        }
    }
    // Step2. if none of the Books are the same, create a Book instance with the values and insert
    // into the Library and return true
    Book new_book(new_title, new_author, new_date);
    books.push_back(new_book);
    return true;
}

bool Library::remove(Book remove_book){
    Book current_book;
    
    // Step1. iternates through vector of Books in library, comparing each to the  remove book
    for (int i = 0; i < books.size(); i++) {
           current_book = books[i];
      
        // Step1.1. Compares each attribute of the books in the Library and the uwanted book
        if (current_book.get_title() == remove_book.get_title() &&
            current_book.get_author() == remove_book.get_author() &&
            current_book.get_date() == remove_book.get_date()) {
            
        // Step1.2 If all attributes are the same, returns true and remove book from vector
            books.erase(books.begin() + i );
            return true;
       }
   }
    //Step2.  If there is no matching book, return false
    return false;
}

bool Library::remove(string remove_title, string remove_author, string remove_date){
    Book current_book;
    
    // Step1. iternates through vector of Books in library, comparing each to the new attributes
     for (int i = 0; i < books.size(); i++) {
         current_book = books[i];
         
         // Step1.1. Compares each attribute of the books in the Library and the provided string values
         if (current_book.get_title() == remove_title &&
             current_book.get_author() == remove_author &&
             current_book.get_date() == remove_date) {
             
             // Step1.2 If all attributes are the same, returns true and remove book from vector
             books.erase(books.begin() + i );
             return true;
         }
     }
     //Step2.  If there is no matching book, return false
    return false;
}

void Library::print(){
    Book current_book;
    cout << endl;

    //Step1. Internate through the vector and output each book stored
    for (int i = 0; i < books.size(); i++) {
        current_book = books[i];
        cout << "\nBook #" << (i + 1);
        current_book.print();
    }
}

