#include "libraryItem.h"

LibraryItem::LibraryItem() {}

LibraryItem::LibraryItem (std::string title, std::string author, int publicationYear, int id, std::string category) : title_(title), author_(author), publicationYear_(publicationYear), id_(id), category_(category) {}

LibraryItem::~LibraryItem() {}

std::string LibraryItem::getTitle() const
{
    return title_;
}

std::string LibraryItem::getAuthor() const
{
    return author_;
}

int LibraryItem::getPublicationYear() const
{
    return publicationYear_;
}

int LibraryItem::getId()  const
{
    return id_;
}

std::string LibraryItem::getCategory() const
{
    return category_;
}

void LibraryItem::setTitle (std::string title)
{
    title_ = title;
}

void LibraryItem::setAuthor (std::string author)
{
    author_ = author;
}

void LibraryItem::setPublicationYear (int publicationYear)
{
    publicationYear_ = publicationYear;
}

void LibraryItem::setId (int id)
{
    id_ = id;
}

void LibraryItem::setCategory (std::string category)
{
    category_ = category;
}
