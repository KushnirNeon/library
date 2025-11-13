# Library Management System (Option 1)

## Project Structure

The project consists of 11 files:

1. `libraryItem.cpp`, `libraryItem.h` – Implementation and declaration of **LibraryItem** class.  
2. `book.cpp`, `book.h` – Implementation and declaration of **Book** class.  
3. `magazine.cpp`, `magazine.h` – Implementation and declaration of **Magazine** class.  
4. `library.cpp`, `library.h` – Implementation and declaration of **Library** class.  
5. `interactWithSystem.cpp`, `interactWithSystem.h` – Implementation and declaration of function **interactWithSystem**.  
6. `main.cpp` – Main function, entry point of the program.

---

## Class Hierarchy

### LibraryItem
Represents a general item in the library. Properties include:
- `title_`
- `author_`
- `publicationYear_`
- `id_`
- `category_`

### Book
Derived from **LibraryItem**, with additional properties:
- `numPages_`
- `illustrations_` – Boolean indicating if book has illustrations.

**Unique Methods:**
- `bookAge()` – Calculates age of the book.  
- `readingTime()` – Calculates reading time in hours.

### Magazine
Derived from **LibraryItem**, with additional properties:
- `numIssue_`
- `frequency_` – Integer representing frequency of magazine in years.

**Unique Methods:**
- `isRecent()` – Checks if the magazine was published within the last 5 years.  
- `nextIssue()` – Returns year of the next issue.

### Library
Manages the collection of library items. Methods include:
- `addBook`, `addMagazine` – Add new items to the library.  
- `removeBook`, `removeMagazine` – Remove items based on title.  
- `book_searchById`, `magazine_searchById` – Search for items based on ID.  
- `displayAllBooks`, `displayAllMagazines` – Display all items in a table format.  
- `books_sortByTitle`, `magazines_sortByTitle` – Sort items alphabetically by title.

---

## How the Program Works

The program has a simple text-based user interface. It allows interaction with two collections: **books** and **magazines**.  

The menu has seven commands:
1. Add a library item  
2. Remove a library item  
3. Search for a library item  
4. Sort library items by title alphabetically  
5. Display all library items  
6. Get additional characteristics of items (see "Unique Methods")  
7. Exit the system

Follow on-screen instructions after selecting a command.

---

## Compilation and Execution

To compile and run the program:

1. Open an IDE, such as Visual Studio or Code::Blocks.  
2. Add all 11 files mentioned in the project structure to the project.  
3. Compile the project using the "Build" option.  
4. Run the program using "Run" or press **F9**.  
