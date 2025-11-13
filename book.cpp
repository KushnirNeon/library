#include "book.h"

Book::Book() {}

Book::Book (std::string title, std::string author, int publicationYear, int id, std::string category, int numPages, bool illustrations) : LibraryItem (title, author, publicationYear, id, category), numPages_(numPages), illustrations_(illustrations) {}

Book::~Book() {}

int Book::bookAge()
{
    return CURRENT_YEAR - publicationYear_;
}

int Book::readingTime()
{
    return ceil((double) numPages_ / SPEED);
}

bool operator < (const Book & book1, const Book & book2)
{
    return book1.title_ < book2.title_;
}

int Book::getNumPages() const
{
    return numPages_;
}

bool Book::getIllustrations() const
{
    return illustrations_;
}

void Book::setNumPages (int numPages)
{
    numPages_ = numPages;
}

void Book::setIllustrations (bool illustrations)
{
    illustrations_ = illustrations;
}
