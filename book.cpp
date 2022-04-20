//	Michael Tafuri
//	COP3330-0001
#include <iostream>
#include <iomanip>
#include <cstring>
#include "book.h"

using namespace std;

Book::Book()		//Creates default book, genre is FICTION
{
	strcpy(title, " ");
	strcpy(author, " ");
	price = 0;
	type = FICTION;
}

void Book::Set(const char* t, const char* a, Genre g, double p)		//Sets created book to parameters
{
	strcpy(title, t);
	strcpy(author, a);
	type = g;
	if (p < 0)
		price = 0;
	else
		price = p;
}

// the Set function should allow incoming data to be received through
//  parameters and loaded into the member data of the object.  (i.e.
//  this function "sets" the state of the object to the data passed in).
//  The parameters t, a, g, and p represent the title, author, genre,
//  and price of the book, respectively.

const char* Book::GetTitle() const		// Returns the title stored in the object
{
	return title;
}
const char* Book::GetAuthor() const		// Returns the author
{
	return author;
}

double Book::GetPrice() const			// Returns the price
{
	return price;
}
Genre Book::GetGenre() const			//	Returns Genre
{
	return type;
}		// returns the genre

void Book::Display() const				//	Displays book information
{
	cout << setiosflags(ios::left) << setw(32) << title;
	cout << setiosflags(ios::left) << setw(22) << author;
	cout << setiosflags(ios::left) << setw(12);
	switch (type)
	{
		case FICTION:
			cout << "Fiction";
			break;
		case MYSTERY:
			cout << "Mystery";
			break;
		case SCIFI:
			cout << "Sci-Fi";
			break;
		case COMPUTER:
			cout << "Computer";
			break;
	}
	cout << setiosflags(ios::left) << "$\t";

	int oldprecision = cout.precision();
	cout << setprecision(2) << fixed << price << endl;
    cout.precision(oldprecision);
}
