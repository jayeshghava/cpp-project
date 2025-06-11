#include <iostream>
#include <string>
#include <vector>
#include <regex>
using namespace std;

const int MAX_ITEMS = 10;

class LibraryItem {
private:
    string title;
    string author;
    string dueDate;

public:
    virtual ~LibraryItem() {}
  
    void setTitle(string newTitle) { title = newTitle; }
    void setAuthor(string newAuthor) { author = newAuthor; }
    void setDueDate(string newDueDate) { dueDate = newDueDate; }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
};

class Book : public LibraryItem {
private:
    string isbn;

public:
    Book(string title, string author, string isbn) {
        if (!regex_match(isbn, regex("\\d{3}-\\d{10}")))
            throw invalid_argument("Invalid ISBN format. Use XXX-XXXXXXXXXX format.");

        setTitle(title);
        setAuthor(author);
        setDueDate("Not set");
        this->isbn = isbn;
    }

    void checkOut() override {
        string date;
        cout << "Enter due date (dd-mm-yyyy): ";
        cin >> date;
        setDueDate(date);
        cout << "Book checked out.\n";
    }

    void returnItem() override {
        setDueDate("Returned");
        cout << "Book returned.\n";
    }

    void displayDetails() const override {
        cout << "Book Title: " << getTitle() << "\nAuthor: " << getAuthor()
             << "\nISBN: " << isbn << "\nDue Date: " << getDueDate() << "\n";
    }
};

class DVD : public LibraryItem {
private:
    int duration;

public:
    DVD(string title, string author, int duration) {
        if (duration <= 0)
            throw invalid_argument("Duration must be positive.");

        setTitle(title);
        setAuthor(author);
        setDueDate("Not set");
        this->duration = duration;
    }

    void checkOut() override {
        string date;
        cout << "Enter due date (dd-mm-yyyy): ";
        cin >> date;
        setDueDate(date);
        cout << "DVD checked out.\n";
    }

    void returnItem() override {
        setDueDate("Returned");
        cout << "DVD returned.\n";
    }

    void displayDetails() const override {
        cout << "DVD Title: " << getTitle() << "\nDirector: " << getAuthor()
             << "\nDuration: " << duration << " mins\nDue Date: " << getDueDate() << "\n";
    }
};

void menu() {
    cout << "\n--- Library Menu ---\n";
    cout << "1. Add Book\n";
    cout << "2. Add DVD\n";
    cout << "3. Display All Items\n";
    cout << "4. Check Out Item\n";
    cout << "5. Return Item\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    LibraryItem* libraryItems[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    do {
        menu();
        cin >> choice;
        cin.ignore();

        try {
            if (choice == 1 && itemCount < MAX_ITEMS) {
                string title, author, isbn;
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN (XXX-XXXXXXXXXX): ";
                getline(cin, isbn);
                libraryItems[itemCount++] = new Book(title, author, isbn);
                cout << "Book added.\n";
            } else if (choice == 2 && itemCount < MAX_ITEMS) {
                string title, director;
                int duration;
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter director: ";
                getline(cin, director);
                cout << "Enter duration (in minutes): ";
                cin >> duration;
                cin.ignore();
                libraryItems[itemCount++] = new DVD(title, director, duration);
                cout << "DVD added.\n";
            } else if (choice == 3) {
                for (int i = 0; i < itemCount; i++) {
                    cout << "\nItem " << i + 1 << ":\n";
                    libraryItems[i]->displayDetails();
                }
            } else if (choice == 4) {
                int idx;
                cout << "Enter item number to check out: ";
                cin >> idx;
                if (idx > 0 && idx <= itemCount)
                    libraryItems[idx - 1]->checkOut();
                else
                    cout << "Invalid item number.\n";
            } else if (choice == 5) {
                int idx;
                cout << "Enter item number to return: ";
                cin >> idx;
                if (idx > 0 && idx <= itemCount)
                    libraryItems[idx - 1]->returnItem();
                else
                    cout << "Invalid item number.\n";
            } else if (choice == 6) {
                cout << "Exiting...\n";
            } else {
                cout << "Invalid choice or max limit reached.\n";
            }
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }

    } while (choice != 6);

    for (int i = 0; i < itemCount; i++) {
        delete libraryItems[i];
    }

}
/*output
--- Library Menu ---
1. Add Book
2. Add DVD
3. Display All Items
4. Check Out Item
5. Return Item
6. Exit
Enter your choice: 1
Enter title: our selfconfidabce
Enter author: mr.mehta
Enter ISBN (XXX-XXXXXXXXXX): 123-3253446879
Book added.

--- Library Menu ---
1. Add Book
2. Add DVD
3. Display All Items
4. Check Out Item
5. Return Item
6. Exit
Enter your choice: 2
Enter title: our selfconfidabce
Enter director: mr.mehta
Enter duration (in minutes): 6
DVD added.

--- Library Menu ---
1. Add Book
2. Add DVD
3. Display All Items
4. Check Out Item
5. Return Item
6. Exit
Enter your choice:
3

Item 1:
Book Title: our selfconfidabce
Author: mr.mehta
ISBN: 123-3253446879
Due Date: Not set

Item 2:
DVD Title: our selfconfidabce
Director: mr.mehta
Duration: 6 mins
Due Date: Not set

--- Library Menu ---
1. Add Book
2. Add DVD
3. Display All Items
4. Check Out Item
5. Return Item
6. Exit
Enter your choice: 4
Enter item number to check out: 1
Enter due date (dd-mm-yyyy): 02-4-1919
Book checked out.

--- Library Menu ---
1. Add Book
2. Add DVD
3. Display All Items
4. Check Out Item
5. Return Item
6. Exit
Enter your choice: 5
Enter item number to return: 1
Book returned.

--- Library Menu ---
1. Add Book
2. Add DVD
3. Display All Items
4. Check Out Item
5. Return Item
6. Exit
Enter your choice: 6
Exiting...
*/
