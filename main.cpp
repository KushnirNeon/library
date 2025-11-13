#include "libraryItem.h"
#include "book.h"
#include "magazine.h"
#include "library.h"
#include "interactWithSystem.h"

int main()
{
    // Creating some sample books and magazines.
    Book book1 ("BTo Kill a Mockingbird", "Harper Lee", 1960, 1001, "Fiction", 150, 1);
    Book book2 ("A1984", "George Orwell", 1949, 1002, "Fiction", 300, false);
    Book book3 ("DThe Great Gatsby", "F. Scott Fitzgerald", 1925, 1003, "Fiction", 500, 0);
    Book book4 ("CThe Catcher in the Rye", "J.D. Salinger", 1951, 1004, "Fiction", 260, false);
    Book book5 ("EThe Hobbit", "J.R.R. Tolkien", 1937, 1005, "Fiction", 300, true);
    Magazine magazine1 ("Time", "Time Inc.", 2000, 2001, "News", 203, 2);
    Magazine magazine2 ("The Economist", "The Economist Group", 2021, 2002, "News", 16, 10);
    Magazine magazine3 ("National Geographic", "National Geographic Partners", 2023, 2003, "Science", 2, 1);
    Magazine magazine4 ("Vogue", "Conde Nast Publications", 2023, 2004, "Fashion", 19, 1);

    // Adding sample books and magazines to library object.
    Library books;
    books.addBook(book1);
    books.addBook(book2);
    books.addBook(book3);
    books.addBook(book4);
    books.addBook(book5);
    Library magazines;
    magazines.addMagazine(magazine1);
    magazines.addMagazine(magazine2);
    magazines.addMagazine(magazine3);
    magazines.addMagazine(magazine4);

    interactWithSystem (books.getBooksList(), magazines.getMagazinesList());

    return 0;
}
