#include <iostream>
#include <list>  
#include <vector>
#include <string>    

using namespace std;

class Book {
private:
    string title;
    string author;
    int quantity;

public:
    void setTitle(string title_name) {
        title = title_name;
    }
    void setAuthor(string author_name) {
        author = author_name;
    }
    void setQuantity(int quantity_in) {
        quantity = quantity_in;
    }

    string getTitle() {
        return title;
    }
    string getAuthor() {
        return author;
    }
    int getQuantity() {
        return quantity;
    }
};


class Inventory {
private:
    vector<Book> book_vec;

public:
    void addBook (string name, string author, int quantity) {
        Book book;
        book.setTitle(name);
        book.setAuthor(author);
        book.setQuantity(quantity);
        book_vec.push_back(book);
    }
    
    void removeBook(string name) {
        for (int i = 0; i < book_vec.size(); ) {
            if (book_vec[i].getTitle() == name) {
                book_vec.erase(book_vec.begin() + i);
            } else {
                ++i;
            }
        }
    }

    tuple<string, string, int> findBook(string name) {  
        for (int i = 0; i < book_vec.size(); i++) {
            if (book_vec[i].getTitle() == name) {
                return make_tuple(book_vec[i].getTitle(), book_vec[i].getAuthor(), book_vec[i].getQuantity());
            }
        }
        return make_tuple("Not found", "", 0);
    }

    void printInventory() {
        for (int i = 0; i < book_vec.size(); i++) {
            cout << "Title: " << book_vec[i].getTitle() << ", Author: " << book_vec[i].getAuthor() << ", Quantity: " << book_vec[i].getQuantity() << endl;
        }
    }
};


int main() {
    Inventory book_inventory;

    while (true) {
        string input;
        cout << "Enter command (a:add, s:search, l: list, q:quit):";
        cin >> input;

        if (input == "a") {
            string title;
            string author;
            int quantity;
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter Author: ";
            cin >> author;
            cout << "Enter quantity: ";
            cin >> quantity;

            book_inventory.addBook(title, author, quantity);
        
        } else if (input == "s") {
            string title;
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, title);

            auto [foundTitle, author, quantity] = book_inventory.findBook(title);
            if (foundTitle != "Not found") {
                cout << "Book found: " << foundTitle << ", Author: " << author << ", Quantity: " << quantity << endl;
            } else {
                cout << "Book not found." << endl;
            }

        } else if (input == "l") {
            book_inventory.printInventory();

        } else if (input == "q") {
            break;
        } else {
            cout << "Invalid Command\n" << endl;
        }
        continue;
    }
    return 0;
}
