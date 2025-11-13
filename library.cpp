#include "library.h"

Library::Library() {}

Library::Library(std::vector <Book> & books) : booksList_(books) {}

Library::Library(std::vector <Magazine> & magazines) : magazinesList_(magazines) {}

void Library::addBook (const Book & book)
{
    booksList_.push_back(book);
}

void Library::addMagazine (const Magazine & magazine)
{
    magazinesList_.push_back(magazine);
}

bool Library::removeBook (const std::string & bookTitle)
{
    for (auto it = booksList_.begin(); it != booksList_.end(); it++)
    {
        if (it -> getTitle() == bookTitle)
        {
            booksList_.erase(it);
            return true;
        }
    }
    return false;
}

bool Library::removeMagazine (const std::string & magazineTitle)
{
    for (auto it = magazinesList_.begin(); it != magazinesList_.end(); it++)
    {
        if (it -> getTitle() == magazineTitle)
        {
            magazinesList_.erase(it);
            return true;
        }
    }
    return false;
}

Book Library::book_searchById(int id)
{
    for (int i = 0; i < booksList_.size(); i++)
    {
        if (booksList_[i].getId() == id)
        {
            return booksList_[i];
        }
    }
    throw std::runtime_error("*** Book with this ID was not found ***");
}

Magazine Library::magazine_searchById (int id)
{
    for (int i = 0; i < magazinesList_.size(); i++)
    {
        if (magazinesList_[i].getId() == id)
        {
            return magazinesList_[i];
        }
    }
    throw std::runtime_error("*** Magazine with this ID was not found ***");
}

void Library::displayAllBooks() const
{
    std::cout << "BOOKS" << std::endl << std::left << std::setw(35) << "TITLE" << std::setw(35) << "AUTHOR" << std::setw(8) << "YEAR" << std::setw(8) << "ID"
              << std::setw(15) << "CATEGORY" << std::setw(8) << "PAGES" << std::setw(15) << "ILLUSTRATIONS" << std::endl;
    for (int i = 0; i < booksList_.size(); i++)
    {
        std::cout << std::setw(35) << booksList_[i].getTitle() << std::setw(35) << booksList_[i].getAuthor() << std::setw(8)
        << booksList_[i].getPublicationYear() << std::setw(8) << booksList_[i].getId() << std::setw(15) << booksList_[i].getCategory()
        << std::setw(8) << booksList_[i].getNumPages() << std::setw(15) << booksList_[i].getIllustrations() << std::endl;
    }
}

void Library::displayAllMagazines() const
{
    std::cout << "MAGAZINES" << std::endl << std::left << std::setw(35) << "TITLE" << std::setw(35) << "AUTHOR" << std::setw(8) << "YEAR" << std::setw(8) << "ID"
              << std::setw(15) << "CATEGORY" << std::setw(8) << "ISSUE" << std::setw(15) << "FREQUENCY" << std::endl;
    for (int i = 0; i < magazinesList_.size(); i++)
    {
        std::cout << std::setw(35) << magazinesList_[i].getTitle() << std::setw(35) << magazinesList_[i].getAuthor() << std::setw(8)
        << magazinesList_[i].getPublicationYear() << std::setw(8) << magazinesList_[i].getId() << std::setw(15) << magazinesList_[i].getCategory()
        << std::setw(8) << magazinesList_[i].getNumIssue() << std::setw(15) << magazinesList_[i].getFrequency() << std::endl;
    }
}

void Library::books_sortByTitle()
{
    std::sort(booksList_.begin(), booksList_.end());
}

void Library::magazines_sortByTitle()
{
    std::sort(magazinesList_.begin(), magazinesList_.end());
}

Library::~Library() {}

std::vector <Book> Library::getBooksList() const
{
    return booksList_;
}

std::vector <Magazine> Library::getMagazinesList() const
{
    return magazinesList_;
}
