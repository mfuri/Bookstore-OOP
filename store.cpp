//	Michael Tafuri
//	COP3330-0001
//----------------- store.cpp -----------------
// Definitions for class Store

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include "store.h"

using namespace std;

Store::Store()			//Default constructor
{
   maxsize = 5;
   currentsize = 0;
   inventory = new Book[maxsize];
	 cashreg = 0;
}

Store::Store(double c)	//Allows intialization of Cash
{
   maxsize = 5;
   currentsize = 0;
   inventory = new Book[maxsize];
	 if (c < 0)
	 	cashreg = 0;
	 else
	 	cashreg = c;
}

Store::~Store()			//Deletes Dynamic Array
{
	delete [] inventory;
}

void Store::Add(char * t,char * a, char g, double p)		//Adds a book to inventory
{
	Genre user = GenreChoice(g);
	if (currentsize == maxsize)
		Grow();
	inventory[currentsize++].Set(t, a, user, p);

}

void Store::FindItem(char* search) const		//	Searches inventory and displays title or books by same author
{
    int Author = AuthorSearch(search);
    int Title = TitleSearch(search);

    if (Author == -1 && Title == -1)
        cout << search << ": Not Found" << endl;
    
    if (Author == 0)
    {
        cout << "Book(s) Found:" << endl;
        for (int i = 0; i < currentsize; i++)
            if (strcmp(inventory[i].GetAuthor(), search) == 0)
                inventory[i].Display();
    }
    
    else if (Title >= 0)
    {
        cout << "Book Found:" << endl;
        inventory[Title].Display();
    }

}

void Store::Sell(char * title)			//	Removes an entry and resizes array if needed
{
	
	
	int sell = TitleSearch(title);
	
	if (sell == -1)
	{
		cout << "\n" << title << " not found in the inventory" << endl;
		cout << "* No sale made *" << endl;
	}
	else
	{
		cashreg = inventory[sell].GetPrice() + cashreg;
		for (int i = sell; i < currentsize; i++)
			inventory[i] = inventory[i+1];
		cout << "\nSale complete!" << endl;
		currentsize--;
		
		if (currentsize + 5 < maxsize)
			Grow();
	}
	
	
	
}



void Store::DisplayInventory() const	//	Displays inventory of current books
{
	if (currentsize == 0)
	{
	cout << "\nCurrent inventory is empty.\n";
	return;
	}
    cout << "\n";
	cout << setiosflags(ios::left) << setw(32) << "**Title**";
	cout << setiosflags(ios::left) << setw(22) << "**Author**";
	cout << setiosflags(ios::left) << setw(12) << "**Genre**";
	cout << setiosflags(ios::left) << "**Price**\n" << endl;
	for (int i = 0; i < currentsize; i++)
	{

		inventory[i].Display();

	}
	cout << "\nNumber of books = " << currentsize << endl;
	cout << "Money in register = $ ";
	int oldprecision = cout.precision();
	cout << setprecision(2) << fixed << cashreg << endl;
	cout.precision(oldprecision);
}

void Store::GenreSummary(char user) const		// Displays inventory of a specific genre of books
{
	double GenreTotal = 0;
	int Count = 0;
	
	Genre g;
	g = GenreChoice(user);
	
	for (int i = 0; i < currentsize; i++)
	{
		if (inventory[i].GetGenre() == g)
			inventory[i].Display();
		GenreTotal = inventory[i].GetPrice() + GenreTotal;
		Count++;
	}
	
	cout << "\nTotal books in this genre = " << Count << endl;
	cout << "Total price of books in this genre = $";
	int oldprecision = cout.precision();
	cout << setprecision(2) << fixed << GenreTotal << endl;
	cout.precision(oldprecision);
}

//	Helper functions

void Store::Grow()			//	Grows/shrinks inventory when called
{
	maxsize = currentsize + 5;
	
	cout << "** Array being resized to " << maxsize << " allocated slots" << endl;
	Book* temp = new Book[maxsize];

	for (int i = 0; i < currentsize; i++)
		temp[i] = inventory[i];
	inventory = temp;
	delete [] inventory;
}


int Store::TitleSearch(char* String) const
{
   for (int i = 0; i < currentsize; i++)
   {
    if (strcmp(inventory[i].GetTitle(), String) == 0)
        return i;
   }
   return -1;
}

int Store::AuthorSearch(char* String) const
{
	for (int i = 0; i < currentsize; i++)
		if (strcmp(inventory[i].GetAuthor(), String) == 0)
			return 0;
	
	return -1;
}

Genre Store::GenreChoice(char g) const		//	Used to set letter to genre
{
	Genre user;
	switch (toupper(g))
		{
			case 'F':
				user = FICTION;
				break;
			case 'M':
				user =  MYSTERY;
				break;
			case 'S':
				user = SCIFI;
				break;
			case 'C':
				user = COMPUTER;
				break;
			default:
				user = FICTION;
				break;
		}
	return user;
}

void Store::Sort(char c)
{
	Book temp;
	
	switch (toupper(c))
	{
		case 'T':
			for(int i = 0 ; i < currentsize; i++)
			{
				for(int j = i + 1; j < currentsize; j++)
				{
					if(strcmp(inventory[i].GetTitle(), inventory[j].GetTitle()) > 0)
					{
						temp = inventory[i];
						inventory[i] = inventory[j];
						inventory[j] = temp;
					}
				}
			}
			cout << "Sort Complete" << endl;
			break;
		case 'A':
			for(int i = 0 ; i < currentsize; i++)
			{
				for(int j = i + 1; j < currentsize; j++)
				{
					if(strcmp(inventory[i].GetAuthor(), inventory[j].GetAuthor()) > 0)
					{
						temp = inventory[i];
						inventory[i] = inventory[j];
						inventory[j] = temp;
					}
				}
			}
			cout << "Sort Complete" << endl;
			break;
		default:
			cout << "Invalid option." << endl;
			break;
	}
}
