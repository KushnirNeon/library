#pragma once

#include <string>
#include <vector>
#include <cmath>

#ifndef BOOK_H
#define BOOK_H

#include "libraryItem.h"

class Book : public LibraryItem
{
    public:
        Book();
        Book (std::string title, std::string author, int publicationYear, int id, std::string category, int numPages, bool illustrations);
        ~Book();
        int bookAge(); // calculates age of book based on year of publication
        int readingTime(); // calculates reading time of book in hours; speed - pages per hour
        friend bool operator < (const Book & book1, const Book & book2);

        int getNumPages() const;
        bool getIllustrations() const;

        void setNumPages (int numPages);
        void setIllustrations (bool illustrations);

    private:
        int numPages_;
        bool illustrations_;
        static const int CURRENT_YEAR = 2023;
        static const int SPEED = 50;
};

#endif
