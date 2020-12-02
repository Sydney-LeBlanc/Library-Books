//
// Student names: Esther Xin, Sydney LeBlanc
//
// SYDE 121 assignment: 5
// file name: a5_book.cpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//***************************************************

#include "a5_book.hpp"

using namespace std;
    
Book::Book(string new_title, string new_author, string new_date) :
    title(new_title),
    author(new_author),
    date(new_date){}

Book::Book(string new_title, string new_author) :
    title(new_title),
    author(new_author),
    date("n/a"){}

Book::Book(string new_title) :
    title(new_title),
    author("n/a"),
    date("n/a"){}


Book::Book() :
    title("n/a"),
    author("n/a"),
    date("n/a"){}


string Book::get_title(){
    return title;
}
string Book::get_author(){
    return author;
}
string Book::get_date(){
    return date;
}

void Book::print(){
    // Output current values stored inside book object
    cout << ":\nTitle: " << title
        << "\nAuthor: " << author
        << "\nPublication Date: " << date << endl;
}
    

