// Bob Myers
//
// book.h -- header file for the Book class
//
// An object of type Book will store information about a single
// book.  The variable "type" stores the category of the book
 // (one of the four items in the enumerated type Genre).

#ifndef _BOOK_H
#define _BOOK_H

enum Genre {FICTION, MYSTERY, SCIFI, COMPUTER};

class Book
{
public:
  Book();		// default constructor, sets up blank book object

  void Set(const char* t, const char* a, Genre g, double p);

  // the Set function should allow incoming data to be received through
  //  parameters and loaded into the member data of the object.  (i.e.
  //  this function "sets" the state of the object to the data passed in).
  //  The parameters t, a, g, and p represent the title, author, genre,
  //  and price of the book, respectively.

  const char* GetTitle() const;		// returns the title stored in the object
  const char* GetAuthor() const;	// returns the author
  double GetPrice() const;		// returns the price
  Genre GetGenre() const;		// returns the genre

  void Display() const;			// described below

private:
	char title[31];	// may assume title is 30 characters or less
  char author[21];	// may assume author name is 20 characters or less
  Genre type;
  double price;
};

/* Display() function

The member function Display() should print out a Book object on one line
as follows, in an organized manner. (Monetary output should be in dollars
and cents notation, to two decimal places):
Title		              Author		  Genre		Price

Examples:
Programming for Dummies       Marvin Dipwart      Computer   $  24.95
Mutant Space Weasels          Bob Myers           Sci-Fi     $   5.95

*/

#endif
