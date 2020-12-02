//
// Student names: Esther Xin, Sydney LeBlanc
//
// SYDE 121 assignment: 5
// file name: a5_main.cpp
//
// I hereby declare that this code, submitted for credit for the course
// SYDE121, is a product of my own efforts.  This coded solution has
// not been plagiarized from other sources and has not been knowingly
// plagiarized by others.
//
// Project: Book insertion and removal tester
// Purpose: to test insertion and removal methods of Books into a Library
//
// Due date: November 20, 2020
//***************************************************

#include <iostream>
#include <string>
#include <vector>
#include "a5_book.hpp"
#include "a5_library.hpp"

using namespace std;

Book test_constructor(int index);
//PURPOSE: to test each constructor in the Book class by returning a differnet book each loop
//INPUT: index- corresponding integer value
//OUTPUT: new_book– correpsonfing Book instance depending on index

void test_book_insertion(vector<Book>& new_books, Library& my_library);
//PURPOSE: to test each insertion method in the Library class
//INPUT: new_books– corresponding vector of books to pass into the class
//OUTPUT: nothing; values are passed by reference

void test_book_removal(vector<Book>& new_books, Library& my_library);
//PURPOSE: to test each removal method in the Library class
//INPUT: corresponding vector of books to pass into the class
//OUTPUT: nothing; values are passed by reference

void start_library_tests();
//PURPOSE: to evoke all the functions to test the constructors and methods
//INPUT: nothing
//OUTPUT: nothing

/* LIMITATIONS
    Limitations of our program:
     1. The input or what is being hardcoded is case sensitive, meaning
         the title, spacing and letters need to be identical (upper-case/lower-case
         same # of spaces) in order for the program to insert/remove the correct books
     2. This program takes in no user-input meaning within our testing functions, the
        books (author, title date) will need to be hardcoded. This also means that the code
        will need to be changed every time a new test case is inputted (ex. duplicates or
        trying to remove a book that is not there)
 
    Limitations of C++
    1. There is a max character length of 4294967295
    2. There is a max size for an vector.
            - 2^32 char values
            - 2^30 int values
            - 2^29 double values
 */

class Library;

Book test_constructor(int index){

    Book new_book1 ("Harry Potter"); // test case with same title but no author of date of publication
    Book new_book2 ("Percy Jackson", "Rick Riordan", "2005"); // test case with all 3 attributes
    Book new_book3 ("Harry Potter", "JK Rowling", "2007"); //test case with one book already inserted
    Book new_book4 ("Lord of Rings", "JRR Tolkien"); // test case with 2 attributes (title and author)
    Book new_book5; // test case with 0 attributes, calls default constructor
    
  // Return the corresponding Book each time it iternates through the for loop
    switch (index) {
        case 0:
            return new_book1;
        case 1:
            return new_book2;
        case 2:
            return new_book3;
        case 3:
            return new_book4;
        default:
            return new_book5;
    }
}

void test_book_insertion(vector<Book>& new_books, Library& my_library){
    
    cout << "Insertion Process:\n" << endl;
    
    string title, author, date;
    int index;
    
    // Step1. Test the insetion method by passing in a Book instance by value
    for (index = 0; index < 5; index++) {
        
        // Step1.1 test the constructors from Book class
        Book new_book = test_constructor(index);
        
         // Step1.2 Insert into library. If it succeeds, insert into new_books vector
         // and input vector into Library and output correpsonding statement
        if(my_library.insert(new_book)){
            new_books.push_back(new_book);
            Library my_libary(new_books);
            cout << "Book #" << index + 1 << " insertion was successful\n";
        }
        else {
            cout << "Book #" << index + 1 << " insertion was rejected\n";
        }
    }
    
    // Step2. Test the insetion method by passing in string values
    // If it succeeds, output correpsonding statement
    //hard coding in a book title, author and date of publication to be tested
    title = "1984";
    author = "George Owell";
    date = "1949";

    if(my_library.insert(title, author, date)){

        cout << "Book #" << index++ + 1 << " insertion was successful\n";
    }
    else {
        cout << "Book #" << index++ + 1 << " insertion was rejected\n";
    }
    
    // Step3 Test the insertion method by attempting to pass in string values
    // that already exist in the library
    title = "Harry Potter";
    author = "JK Rowling";
    date = "2007";
    
   if(my_library.insert(title, author, date)){
        cout << "Book #" << index++ + 1 << " insertion was successful\n";
    }
    else {
        cout << "Book #" << index++ + 1 << " insertion was rejected\n";
    }
    
    // Step4. Once insertion tests are complete, output all books currently in the Library
    // to confirm all insertions were successful
    cout << "\nAfter insertion, here is your library:";
    my_library.print();
}

void test_book_removal(vector<Book>& new_books, Library& my_library){

    cout << "\n\nRemoval Process:\n" << endl;
    
    string title, author, date;
    int index;
    
    // Step1. Test the removal method by passing in a Book instance by value
    for (index = 0; index < 1; index++) {
        Book new_book = test_constructor(index);
        
        // Step1.2 Remove from library. If it succeeds, remove from new_books vector
        // and output correpsonding statement
        if(my_library.remove(new_book)){
            Library my_libary(new_books);
            cout << "Book #" << index + 1 << " removal was successful\n";
       }
       else {
            cout << "Book #" << index + 1 << " removal was rejected\n";
       }
   }

    // Step2. Test the insetion method by passing in string values
    // If it succeeds, output correpsonding statement
      title = "Harry Potter";
      author = "JK Rowling";
      date = "2007";

     if(my_library.remove(title, author, date)){
          cout << "Book #" << index++ + 1<< " removal was successful\n";
      }
      else {
          cout << "Book #" << index++ + 1<< " removal was rejected\n";
      }
    
    //Step3 Test the removal method by attempting to pass in string values
    // that do not exist in the library
    title = "The Hunger Games";
    author = "Suzanne Collins";
    date = "2007";

    if(my_library.remove(title, author, date)){
        cout << "Book #" << index++ + 1 << " removal was successful\n";
    }
    else {
        cout << "Book #" << index++ + 1  << " removal was rejected\n";
    }
    // Step4. Once removal tests are complete, output all books currently in the Library
    // to confirm all removals were successful
    cout << "\nAfter removal, here is your library:";
    my_library.print();


}

void start_library(){
    
    cout << "Hello! Welcome to your library! \n " << endl;

    Library my_library;
    vector<Book> new_books;
    
    // Step1. Print library before insertion or removal to comfirm it is empty
    cout << "Here is your current library:\n\n";
    my_library.print();
    
    // Step2. Test insertion method
    test_book_insertion(new_books, my_library);
    
    // Step3. Test removal method
    test_book_removal(new_books, my_library);
}
  
int main() {
    start_library();
}


/* TEST CASES
 
    Test cases: Constructors
 
    1. Inserting a book that has all three attributes:
 
            Book #2:
            Title: Percy Jackson
            Author: Rick Riordan
            Publication Date: 2005
 
    2.Inserting a book that has two attributes
            Book #3:
            Title: Lord of Rings
            Author: JRR Tolkien
            Publication Date: n/a
 
    3. Inserting a book that has one attributes
            Book #1:
            Title: Harry Potter
            Author: n/a
            Publication Date: n/a
 
    4. Inserting a book that has no attributes
            Book #4:
            Title: n/a
            Author: n/a
            Publication Date: n/a

 
    Test Cases: Insert and Remove
 
    1.   Inserting in books by value
:
            Hello! Welcome to your library!
             
            Here is your current library:


            Insertion Process:

            Book #1 insertion was successful
            Book #2 insertion was successful
            Book #3 insertion was successful
            Book #4 insertion was successful
            Book #5 insertion was successful

            After insertion, here is your library:

            Book #1:
            Title: Harry Potter
            Author: n/a
            Publication Date: n/a

            Book #2:
            Title: Percy Jackson
            Author: Rick Riordan
            Publication Date: 2005

            Book #3:
            Title: Harry Potter
            Author: JK Rowling
            Publication Date: 2007

            Book #4:
            Title: Lord of Rings
            Author: JRR Tolkien
            Publication Date: n/a

            Book #5:
            Title: n/a
            Author: n/a
            Publication Date: n/a
 
    2. Insert by passing through strings:

             Hello! Welcome to your library!
              
             Here is your current library:


             Insertion Process:

             Book #32767 insertion was successful
             Book #32768 insertion was successful

             After insertion, here is your library:

             Book #1:
             Title: Harry Potter
             Author: JK Rowling
             Publication Date: 2007

             Book #2:
             Title: 1984
             Author: George Owell
 
    3.   Removing books by value:
            
        Removal Process:

        Book #1 removal was successful
        Book #2 removal was successful

        After removal, here is your library:

        Book #1:
        Title: Percy Jackson
        Author: Rick Riordan
        Publication Date: 2005

        Book #2:
        Title: Lord of Rings
        Author: JRR Tolkien
        Publication Date: n/a

        Book #3:
        Title: n/a
        Author: n/a
        Publication Date: n/a

        Book #4:
        Title: 1984
        Author: George Owell
        Publication Date: 1949
        Program ended with exit code: 0
 
 4. Remove books by string
 
        Removal Process:

        Book #8 removal was successful
        Book #9 removal was rejected

        After removal, here is your library:

        Book #1:
        Title: Harry Potter
        Author: n/a
        Publication Date: n/a

        Book #2:
        Title: Percy Jackson
        Author: Rick Riordan
        Publication Date: 2005

        Book #3:
        Title: Lord of Rings
        Author: JRR Tolkien
        Publication Date: n/a

        Book #4:
        Title: n/a
        Author: n/a
        Publication Date: n/a

        Book #5:
        Title: 1984
        Author: George Owell
        Publication Date: 1949
        Program ended with exit code: 0

 
    5. Insert Duplicate (Book 6 is inserted twice) -->

         Hello! Welcome to your library!
          
         Here is your current library:

         Insertion Process:

         Book #1 insertion was successful
         Book #2 insertion was successful
         Book #3 insertion was successful
         Book #4 insertion was successful
         Book #5 insertion was successful
         Book #6 insertion was successful
         Book #7 insertion was rejected

         After insertion, here is your library:

         Book #1:
         Title: Harry Potter
         Author: n/a
         Publication Date: n/a

         Book #2:
         Title: Percy Jackson
         Author: Rick Riordan
         Publication Date: 2005

         Book #3:
         Title: Harry Potter
         Author: JK Rowling
         Publication Date: 2007

         Book #4:
         Title: Lord of Rings
         Author: JRR Tolkien
         Publication Date: n/a

         Book #5:
         Title: n/a
         Author: n/a
         Publication Date: n/a

         Book #6:
         Title: 1984
         Author: George Owell
         Publication Date: 1949
 
    6. Remove Book that is not in the library:
 
        Trying to remove "The Hunger Games" by "Suzanna Collins" released in "2012" (but book was never inserted):
 
         Hello! Welcome to your library!
          
         Here is your current library:


         Insertion Process:

         Book #1 insertion was successful
         Book #2 insertion was successful
         Book #3 insertion was successful
         Book #4 insertion was successful
         Book #5 insertion was successful
         Book #6 insertion was successful
         Book #7 insertion was rejected
         

         After insertion, here is your library:

         Book #1:
         Title: Great Gatsby
         Author: n/a
         Publication Date: n/a

         Book #2:
         Title: Percy Jackson
         Author: Rick Riordan
         Publication Date: 2005

         Book #3:
         Title: Harry Potter
         Author: JK Rowling
         Publication Date: 2007

         Book #4:
         Title: Lord of Rings
         Author: JRR Tolkien
         Publication Date: n/a

         Book #5:
         Title: n/a
         Author: n/a
         Publication Date: n/a

         Book #6:
         Title: 1984
         Author: George Owell
         Publication Date: 1949


         Removal Process:

         Book #1 removal was successful
         Book #2 removal was successful
         Book #3 removal was rejected

         After removal, here is your library:

         Book #1:
         Title: Percy Jackson
         Author: Rick Riordan
         Publication Date: 2005

         Book #2:
         Title: Lord of Rings
         Author: JRR Tolkien
         Publication Date: n/a

         Book #3:
         Title: n/a
         Author: n/a
         Publication Date: n/a

         Book #4:
         Title: 1984
         Author: George Owell
         Publication Date: 1949
         Program ended with exit code: 0
 
    7. Trying to Remove the same book twice (book three is the duplicate):
 
        Removal Process:
        Book #1 removal was successful
        Book #2 removal was successful
        Book #3 removal was rejected
 */
