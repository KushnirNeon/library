#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdexcept>

#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include "magazine.h"

class Library
{
    public:
        Library();
        Library(std::vector <Book> & books);
        Library(std::vector <Magazine> & magazines);
        void addBook (const Book & book);
        void addMagazine (const Magazine & magazine);
        bool removeBook (const std::string & bookTitle);
        bool removeMagazine (const std::string & magazineTitle);
        Book book_searchById (int id);
        Magazine magazine_searchById (int id);
        void displayAllBooks() const;
        void displayAllMagazines() const;
        void books_sortByTitle ();
        void magazines_sortByTitle ();
        ~Library();

        std::vector <Book> getBooksList() const;
        std::vector <Magazine> getMagazinesList() const;

    private:
        std::vector <Book> booksList_;
        std::vector <Magazine> magazinesList_;
};

#endif
