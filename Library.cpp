#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Book
{
    int id;
    string title;
    string author;
    bool isAvailable;
};

void displayBook(const Book &book)
{
    cout << "ID: " << book.id
         << ", Title: " << book.title
         << ", Author: " << book.author
         << ", Availability: " << (book.isAvailable ? "Available" : "Checked Out") << endl;
    cout << endl;
}

void displayAllBooks(const vector<Book> &books)
{
    if (books.empty())
    {
        cout << "No books found in the library." << endl;
        cout << endl;
        return;
    }
    for (const auto &book : books)
    {
        displayBook(book);
    }
}

void addBook(vector<Book> &books, int id, const string &title, const string &author)
{
    books.push_back({id, title, author, true});
    cout << "Book added successfully." << endl;
}

void updateBook(vector<Book> &books, int id, const string &title, const string &author)
{
    auto it = find_if(books.begin(), books.end(), [id](const Book &b)
                      { return b.id == id; });
    if (it != books.end())
    {
        it->title = title;
        it->author = author;
        cout << "Book updated successfully." << endl;
    }
    else
    {
        cout << "Book with ID " << id << " not found." << endl;
    }
}

void deleteBook(vector<Book> &books, int id)
{
    auto it = remove_if(books.begin(), books.end(), [id](const Book &b)
                        { return b.id == id; });
    if (it != books.end())
    {
        books.erase(it, books.end());
        cout << "Book deleted successfully." << endl;
    }
    else
    {
        cout << "Book with ID " << id << " not found." << endl;
    }
}

void viewBook(const vector<Book> &books, int id)
{
    auto it = find_if(books.begin(), books.end(), [id](const Book &b)
                      { return b.id == id; });
    if (it != books.end())
    {
        displayBook(*it);
    }
    else
    {
        cout << "Book with ID " << id << " not found." << endl;
    }
}

void checkOutBook(vector<Book> &books, int id)
{
    auto it = find_if(books.begin(), books.end(), [id](const Book &b)
                      { return b.id == id; });
    if (it != books.end())
    {
        if (it->isAvailable)
        {
            it->isAvailable = false;
            cout << "Book checked out successfully." << endl;
        }
        else
        {
            cout << "Book is already checked out." << endl;
        }
    }
    else
    {
        cout << "Book with ID " << id << " not found." << endl;
    }
}

void returnBook(vector<Book> &books, int id)
{
    auto it = find_if(books.begin(), books.end(), [id](const Book &b)
                      { return b.id == id; });
    if (it != books.end())
    {
        if (!it->isAvailable)
        {
            it->isAvailable = true;
            cout << "Book returned successfully." << endl;
        }
        else
        {
            cout << "Book is already available in the library." << endl;
        }
    }
    else
    {
        cout << "Book with ID " << id << " not found." << endl;
    }
}

int main()
{
    vector<Book> books = {
        {1, "Introduction to Algorithms", "Thomas H. Cormen", true},
        {2, "Clean Code", "Robert C. Martin", true},
        {3, "The Pragmatic Programmer", "Andrew Hunt", true},
        {4, "Design Patterns", "Erich Gamma", false},
        {5, "Artificial Intelligence: A Modern Approach", "Stuart Russell", true},
    };

    int choice;
    do
    {
        cout << "\n--- Library Management System ---\n";
        cout << "1. View All Books\n";
        cout << "2. Add Book\n";
        cout << "3. Update Book\n";
        cout << "4. Delete Book\n";
        cout << "5. View Specific Book\n";
        cout << "6. Check Out Book\n";
        cout << "7. Return Book\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            displayAllBooks(books);
            break;
        case 2:
        {
            int id;
            string title, author;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            addBook(books, id, title, author);
            break;
        }
        case 3:
        {
            int id;
            string title, author;
            cout << "Enter ID of the book to update: ";
            cin >> id;
            cin.ignore();
            cout << "Enter New Title: ";
            getline(cin, title);
            cout << "Enter New Author: ";
            getline(cin, author);
            updateBook(books, id, title, author);
            break;
        }
        case 4:
        {
            int id;
            cout << "Enter ID of the book to delete: ";
            cin >> id;
            deleteBook(books, id);
            break;
        }
        case 5:
        {
            int id;
            cout << "Enter ID of the book to view: ";
            cin >> id;
            viewBook(books, id);
            break;
        }
        case 6:
        {
            int id;
            cout << "Enter ID of the book to check out: ";
            cin >> id;
            checkOutBook(books, id);
            break;
        }
        case 7:
        {
            int id;
            cout << "Enter ID of the book to return: ";
            cin >> id;
            returnBook(books, id);
            break;
        }
        case 8:
            cout << "Exiting the system. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 8);

    return 0;
}
