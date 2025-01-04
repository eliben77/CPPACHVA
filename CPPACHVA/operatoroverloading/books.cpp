#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int pages;
    double price;

public:
    // Constructor
    Book(const std::string& t = "", const std::string& a = "", int p = 0, double pr = 0.0)
        : title(t), author(a), pages(p), price(pr) {}

    // Overloading the >> operator for input
    friend std::istream& operator>>(std::istream& in, Book& b) {
        std::cout << "Enter title: ";
        std::getline(in, b.title);
        std::cout << "Enter author: ";
        std::getline(in, b.author);
        std::cout << "Enter number of pages: ";
        in >> b.pages;
        std::cout << "Enter price: ";
        in >> b.price;
        in.ignore();  // To ignore the newline character after the price
        return in;
    }

    // Overloading the << operator for output
    friend std::ostream& operator<<(std::ostream& out, const Book& b) {
        out << "Title: " << b.title << "\nAuthor: " << b.author
            << "\nPages: " << b.pages << "\nPrice: $" << b.price << std::endl;
        return out;
    }

    // Overloading the == operator
    bool operator==(const Book& other) const {
        return (title == other.title && author == other.author);
    }

    // Overloading the < operator (for sorting purposes)
    bool operator<(const Book& other) const {
        if (title < other.title) {
            return true;
        } else if (title == other.title) {
            return author < other.author;
        }
        return false;
    }

    // Overloading the + operator (for combining page counts)
    Book operator+(const Book& other) const {
        Book combined(*this);
        combined.pages += other.pages;
        return combined;
    }

    // Overloading the += operator (for adding price)
    Book& operator+=(double additionalPrice) {
        price += additionalPrice;
        return *this;
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277, 8.99);
    Book book2;

    // Using >> operator to input book details
    std::cin >> book2;

    // Using << operator to output book details
    std::cout << "\nBook 1 Details:\n" << book1;
    std::cout << "\nBook 2 Details:\n" << book2;

    // Using == operator to compare books
    if (book1 == book2) {
        std::cout << "The books are the same.\n";
    } else {
        std::cout << "The books are different.\n";
    }

    // Using < operator to compare and sort books by title and author
    if (book1 < book2) {
        std::cout << "Book 1 comes before Book 2.\n";
    } else {
        std::cout << "Book 2 comes before Book 1.\n";
    }

    // Using + operator to combine page counts
    Book combinedBook = book1 + book2;
    std::cout << "\nCombined Book Page Count: " << combinedBook << std::endl;

    // Using += operator to add price
    book1 += 2.00;
    std::cout << "Book 1 after price increase:\n" << book1 << std::endl;

    return 0;
}
