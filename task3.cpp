#include <iostream>

using namespace std;

class Publication {
public:
    virtual void display() = 0; 
};


class Book : public Publication {
public:
    Book() : title(""), author(""), pages(0) {} 
    Book(const string& title, const string& author, int pages)
        : title(title), author(author), pages(pages) {}

    void display()  {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }

    int getPages() const {
        return pages;
    }

    string getTitle() const {
        return title;
    }

private:
    string title;
    string author;
    int pages;
};


class Newspaper : public Publication {
public:
    Newspaper() : name(""), date(""), edition("") {}
    Newspaper(const string& name, const string& date, const string& edition)
        : name(name), date(date), edition(edition) {}

    void display()  {
        cout << "Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }

    string fetchNewspaperED() const {
        return edition;
    }

    string getNewspaperName() const {
        return name;
    }

private:
    string name;
    string date;
    string edition;
};


class Library {
public:
    Library() : numBooks(0), numNewspapers(0) {}

    void addBook(const Book& book) {
        if (numBooks >= maxBooks) {
            cout << "Library is full. Cannot add more books." << endl;
            return;
        }
        books[numBooks++] = book;
    }

    void addNewspaper(const Newspaper& newspaper) {
        if (numNewspapers >= maxNewspapers) {
            cout << "Library is full. Cannot add more newspapers." << endl;
            return;
        }
        newspapers[numNewspapers++] = newspaper;
    }

    void sortBooksByPages() {
        for (int i = 0; i < numBooks - 1; ++i) {
            for (int j = i + 1; j < numBooks; ++j) {
                if (books[i].getPages() > books[j].getPages()) {
                    swap(books[i], books[j]);
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < numNewspapers - 1; ++i) {
            for (int j = i + 1; j < numNewspapers; ++j) {
                if (newspapers[i].fetchNewspaperED() > newspapers[j].fetchNewspaperED()) {
                    swap(newspapers[i], newspapers[j]);
                }
            }
        }
    }

    void displayCollection() {
        cout << "Books:\n";
        for (int i = 0; i < numBooks; ++i) {
            books[i].display();
        }
        cout << "\nNewspapers:\n";
        for (int i = 0; i < numNewspapers; ++i) {
            newspapers[i].display();
        }
    }

    Book* searchBookByTitle(const string& title) {
        for (int i = 0; i < numBooks; ++i) {
            if (books[i].getTitle() == title) {
                return &books[i];
            }
        }
        return nullptr;
    }

    Newspaper* searchNewspaperByName(const string& name) {
        for (int i = 0; i < numNewspapers; ++i) {
            if (newspapers[i].getNewspaperName() == name) {
                return &newspapers[i];
            }
        }
        return nullptr;
    }

private:
    Book books[100]; 
    Newspaper newspapers[100]; 
    int numBooks = 0;
    int numNewspapers = 0;
    const int maxBooks = 100;
    const int maxNewspapers = 100;
};

int main() {
    
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    
    Library library;

    
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    
    cout << "Before Sorting:" << endl;
    library.displayCollection();

    
    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:" << endl;
    library.displayCollection();

    
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:" << endl;
        foundBook->display();
    }
    else {
        cout << "\nBook not found." << endl;
    }

    
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:"<<endl;
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found."<<endl;
    }

    return 0;
}