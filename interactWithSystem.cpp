#include "interactWithSystem.h"

bool interactWithSystem (std::vector <Book> books, std::vector <Magazine> magazines)
{
    Library myBooks(books);
    Library myMagazines(magazines);
    std::cout << "Welcome to Library Management System" << std::endl;
    while (true)
    {
        std::cout << "---------------------------------------------------------------------------------------------------------------------------" << std::endl
                  << "Seven commands available:" << std::endl
                  << "\t1. " << "Add library item." << std::endl
                  << "\t2. " << "Remove library item." << std::endl
                  << "\t3. " << "Search for library item." << std::endl
                  << "\t4. " << "Sort library items by title alphabetically." << std::endl
                  << "\t5. " << "Display all library items." << std::endl
                  << "\t6. " << "Get additional characteristics of items." << std::endl
                  << "\t7. " << "Exit system." << std::endl
                  << "Choose one of the commands (1-7): ";
        int choice;
        std::cin >> choice;
        switch (choice)
        {
            case 1:
            {
                std::cout << "Which library item you want to add (Book / Magazine)? ";
                std::string option;
                std::cin >> option;
                if (option != "Book" && option != "Magazine")
                {
                    std::cout << "*** Unsupported data ***" << std::endl;
                    return false;
                }
                int id;
                std::cout << "Enter id of new item: ";
                if (!(std::cin >> id))
                {
                    std::cout << "*** Unsupported data ***" << std::endl;
                    return false;
                }
                try
                {
                    if (option == "Book")
                    {
                        myBooks.book_searchById (id);
                    }
                    if (option == "Magazine")
                    {
                        myMagazines.magazine_searchById (id);
                    }
                }
                catch (const std::runtime_error & e)
                {
                    std::string title, author, category;
                    int year;
                    std::cout << "Enter title of new item: ";
                    std::cin >> title;
                    std::cout << "Enter author of new item: ";
                    std::cin >> author;
                    std::cout << "Enter year of publication of new item: ";
                    if (!(std::cin >> year))
                    {
                        std::cout << "*** Unsupported data ***" << std::endl;
                        return false;
                    }
                    std::cout << "Enter category of new item: ";
                    std::cin >> category;
                    if (option == "Book")
                    {
                        int pages;
                        bool illustrations;
                        Book new_book;
                        std::cout << "Enter number of pages of new item: ";
                        if (!(std::cin >> pages))
                        {
                            std::cout << "*** Unsupported data ***" << std::endl;
                            return false;
                        }
                        std::cout << "Enter whether new item has illustrations (true, 1 / false, 0): ";
                        if (!(std::cin >> illustrations))
                        {
                            std::cout << "*** Unsupported data ***" << std::endl;
                            return false;
                        }
                        new_book.setTitle(title);
                        new_book.setAuthor(author);
                        new_book.setPublicationYear(year);
                        new_book.setId(id);
                        new_book.setCategory(category);
                        new_book.setNumPages(pages);
                        new_book.setIllustrations(illustrations);
                        myBooks.addBook(new_book);
                    }
                    else if (option == "Magazine")
                    {
                        int issue, frequency;
                        Magazine new_magazine;
                        std::cout << "Enter number of issue of new item: ";
                        if (!(std::cin >> issue))
                        {
                            std::cout << "*** Unsupported data ***" << std::endl;
                            return false;
                        }
                        std::cout << "Enter enter new item release frequency (in years): ";
                        if (!(std::cin >> frequency))
                        {
                            std::cout << "*** Unsupported data ***" << std::endl;
                            return false;
                        }
                        new_magazine.setTitle(title);
                        new_magazine.setAuthor(author);
                        new_magazine.setPublicationYear(year);
                        new_magazine.setId(id);
                        new_magazine.setCategory(category);
                        new_magazine.setNumIssue(issue);
                        new_magazine.setFrequency(frequency);
                        myMagazines.addMagazine(new_magazine);
                    }
                    std::cout << "*** New item is successfully added ***" << std::endl;
                    break;
                }
                std::cout << "*** Library item with this id already exists ***";
                return false;
            }
            case 2:
            {
                std::cout << "Which library item you want to remove (Book / Magazine)? ";
                std::string option;
                std::cin >> option;
                if (option != "Book" && option != "Magazine")
                {
                    std::cout << "*** Unsupported data ***" << std::endl;
                    return false;
                }
                std::cout << "Enter the title of library item you want to remove: ";
                std::string item_remove;
                std::cin >> item_remove;
                if (option == "Book")
                {
                    if (!myBooks.removeBook(item_remove))
                    {
                        std::cout << "*** Book with this title was not found ***"  << std::endl;
                        break;
                    }
                }
                else if (option == "Magazine")
                {
                    if (!myMagazines.removeMagazine(item_remove))
                    {
                        std::cout << "*** Magazine with this title was not found ***"  << std::endl;
                        break;
                    }
                }
                std::cout << "*** Removing is successful ***"  << std::endl;
                break;
            }
            case 3:
            {
                std::cout << "Which library item you want to find (Book / Magazine)? " ;
                std::string option;
                std::cin >> option;
                if (option != "Book" && option != "Magazine")
                {
                    std::cout << "*** Unsupported data ***" << std::endl;
                    return false;
                }
                std::cout << "Enter the ID of the item you want to find: ";
                int user_id;
                std::cin >> user_id;
                if (option == "Book")
                {
                    try
                    {
                         Book result = myBooks.book_searchById (user_id);
                    }
                    catch (const std::runtime_error & e)
                    {
                        std::cerr << e.what() << std::endl;
                        break;
                    }
                    Book result = myBooks.book_searchById (user_id);
                    std::cout << "Title: " << result.getTitle() << std::endl << "Author: " << result.getAuthor() << std::endl
                              << "Year of Publication: " << result.getPublicationYear() << std::endl << "Category: "
                              << result.getCategory() << std::endl << "Pages: " << result.getNumPages() << std::endl << "Illustrations: " << result.getIllustrations() << std::endl;
                    std::cout << "*** Requested information is successfully displayed ***"  << std::endl;
                }
                else if (option == "Magazine")
                {
                    try
                    {
                         Magazine result = myMagazines.magazine_searchById (user_id);
                    }
                    catch (const std::runtime_error & e)
                    {
                        std::cerr << e.what() << std::endl;
                        break;
                    }
                    Magazine result = myMagazines.magazine_searchById (user_id);
                    std::cout << "Title: " << result.getTitle() << std::endl << "Author: " << result.getAuthor() << std::endl
                              << "Year of Publication: " << result.getPublicationYear() << std::endl << "Category: "
                              << result.getCategory() << std::endl << "Issue: " << result.getNumIssue() << std::endl << "Frequency: " << result.getFrequency() << std::endl;
                    std::cout << "*** Requested information is successfully displayed ***"  << std::endl;
                }
                break;
            }
            case 4:
            {
                myBooks.books_sortByTitle();
                myMagazines.magazines_sortByTitle();
                std::cout << "*** All items were successfully sorted by title ***" << std::endl;
                break;
            }
            case 5:
            {
                myBooks.displayAllBooks();
                myMagazines.displayAllMagazines();
                std::cout << "*** All items were successfully displayed ***" << std::endl;
                break;
            }
            case 6:
            {
                std::cout << "Additional characteristics of which item do you want to know (Book / Magazine)? ";
                std::string option;
                std::cin >> option;
                if (option != "Book" && option != "Magazine")
                {
                    std::cout << "*** Unsupported data ***" << std::endl;
                    return false;
                }
                std::cout << "Enter id of library item: ";
                int user_id;
                if (!(std::cin >> user_id))
                {
                    std::cout << "*** Unsupported data ***" << std::endl;
                    return 0;
                }
                if (option == "Book")
                {
                    try
                    {
                         Book result = myBooks.book_searchById (user_id);
                    }
                    catch (const std::runtime_error & e)
                    {
                        std::cerr << e.what() << std::endl;
                        break;
                    }
                    Book result = myBooks.book_searchById (user_id);
                    std::cout << "Book's age is: " << result.bookAge() << std::endl;
                    std::cout << "Reading time is: " << std::fixed << std::setprecision(2) << result.readingTime() << std::endl; // in hours
                    std::cout << "*** Requested information is successfully displayed ***"  << std::endl;
                }
                else if (option == "Magazine")
                {
                    try
                    {
                         Magazine result = myMagazines.magazine_searchById (user_id);
                    }
                    catch (const std::runtime_error & e)
                    {
                        std::cerr << e.what() << std::endl;
                        break;
                    }
                    Magazine result = myMagazines.magazine_searchById (user_id);
                    std::cout << "Whether magazine is recent? " << result.isRecent() << std::endl;
                    std::cout << "When next issue of magazine will be published? " << result.nextIssue() << std::endl;
                    std::cout << "*** Requested information is successfully displayed ***"  << std::endl;
                }
                break;
            }
            case 7:
                return false;
            default:
                std::cout << "*** Invalid command ***" << std::endl;
                return false;
        }
    }
}
