#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title, author, isbn;
    bool available;

public:
    void setBookDetails(string t, string a, string i, bool av) {
        title = t;
        author = a;
        isbn = i;
        available = av;
    }

    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (available ? "Available" : "Borrowed") << endl;
    }

    bool borrowBook() {
        if (available) {
            available = false;
            return true;
        }
        return false;
    }

    void returnBook() {
        available = true;
    }

    string getISBN() {
        return isbn;
    }

    bool isAvailable() {
        return available;
    }
};

int main() {
    Book books[5];
    books[0].setBookDetails("Harry Potter and the Philosopher's Stone", "J.K. Rowling", "111", true);
    books[1].setBookDetails("It Ends With Us", "Colleen Hoover", "222", true);
    books[2].setBookDetails("Me Before You", "Jojo Moyes", "333", true);
    books[3].setBookDetails("The Chronicles of Narnia", "C.S. Lewis", "444", true);
    books[4].setBookDetails("The Fault in Our Stars", "John Green", "555", true);

    string inputISBN;
    while (true) {
        cout << "\nEnter ISBN to borrow or 0 to exit: ";
        cin >> inputISBN;

        if (inputISBN == "0") break;

        bool found = false;

        for (int i = 0; i < 5; ++i) {
            if (books[i].getISBN() == inputISBN) {
                found = true;
                if (books[i].isAvailable()) {
                    books[i].borrowBook();
                    cout << "Book borrowed successfully!\n";
                }
                else {
                    cout << "Book is already borrowed.\n";
                }
                books[i].displayBookDetails();
                break;
            }
        }

        if (!found) {
            cout << "Book not found.\n";
        }
    }

    return 0;
}
