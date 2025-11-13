#pragma once

#include <string>

#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

class LibraryItem
{
    public:
        LibraryItem();
        LibraryItem (std::string title, std::string author, int publicationYear, int id, std::string category);
        ~LibraryItem();

        std::string getTitle() const;
        std::string getAuthor() const;
        int getPublicationYear() const;
        int getId() const;
        std::string getCategory() const;

        void setTitle (std::string title);
        void setAuthor (std::string author);
        void setPublicationYear (int publicationYear);
        void setId (int id);
        void setCategory (std::string category);

    protected:
        std::string title_;
        std::string author_;
        int publicationYear_;
        int id_;
        std::string category_;
};

#endif
