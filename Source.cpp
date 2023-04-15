#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;


enum BookType { Fiction, NoFiction };


class Book {

public:
	
	Book(const string& author, const string& title, BookType type) :_author(author), _title(title), _type(type) {};
	virtual ~Book() {};
	BookType getType() const { return _type; };
	string GetAuthor() const { return _author; };
	string GetTitle() const { return _title; };

private:
	
	string _author;
	string _title;
	BookType _type;
};


class Library {

public:

	void addBook(const string& author, const string& title, const BookType& type) {
		if (author.empty() or title.empty()) {
			cout << "error" << endl;
		}
		books.push_back(Book(author, title, type));
	};
	
	vector <Book> books;

};


void countBooksSwitch(const vector <Book>& books) {
	
	int countFiction = 0;
	int countNoFiction = 0;
	
	for (const Book& book : books) {
		
		switch (book.getType()) {
		case BookType::Fiction:
			++countFiction;
			break;
		case BookType::NoFiction:
			++countNoFiction;
			break;
		}
	
	}
	
	cout << "count of Fiction but with switch:" << countFiction << endl;
	cout << "count of non Fiction but wuth switch:" << countNoFiction << endl;
}


void countBooksNoSwitch(const vector <Book>& books) {
	
	int countFiction = 0;
	int countNoFiction = 0;
	
	for (const Book& book : books) {
		if (book.getType() == BookType::Fiction) {
			++countFiction;
		}
		else {
			++countNoFiction;
		}
	}
	
	cout << "count of fiction:" << countFiction << endl;
	cout << "count of non fiction:" << countNoFiction << endl;
}

int main() {
	
	Library myLibrary;
	
	myLibrary.addBook("Lesha Popovich", "Five gnomes", NoFiction);
	myLibrary.addBook("Ilya Murometz ", "Twenty gnomes", NoFiction);
	myLibrary.addBook("Dobryinya Nikitich", "Five snakes", Fiction);
	myLibrary.addBook("Horse Julius", "Twenty snakes", Fiction);
	myLibrary.addBook("Russian nation", "The Tale of the Three Russian Heroes", NoFiction);
	
	countBooksSwitch(myLibrary.books);
	countBooksNoSwitch(myLibrary.books);
	
	return 0;

}