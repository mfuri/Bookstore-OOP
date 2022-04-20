//	Michael Tafuri
//	COP3330-0001

#include <cctype>
#include <iostream>
#include <cstring>
#include "store.h"

using namespace std;

void ShowMenu()		// Displays menu.
{
	cout << "\n\t\t*** BOOKSTORE MENU ***";
	cout << "\n\tA\tAdd a Book to Inventory";
	cout << "\n\tF\tFind a book from Inventory";
	cout << "\n\tS\tSell a book";
	cout << "\n\tD\tDisplay the inventory list";
	cout << "\n\tG\tGenre summary";
	cout << "\n\tO\tSort inventory list";
	cout << "\n\tM\tShow this Menu";
	cout << "\n\tX\teXit Program\n";
}

char GetAChar(const char* promptString)

{
   char response;			// the char to be returned

   cout << promptString;		// Prompt the user
   cin >> response;			// Get a char,
   response = toupper(response);	// and convert it to uppercase
   cin.get();				// Discard newline char from input.
   return response;
}

bool Legal(char c)

{
	return	((c == 'A') || (c == 'F') || (c == 'S') || (c == 'D') ||
			 (c == 'G') || (c == 'M') || (c == 'X') || (c == 'O'));
}

char GetCommand()
{
   char cmd = GetAChar("\n>");

   while (!Legal(cmd))
  {
	cout << "\nInvalid menu choice.  Try again." << endl;
	ShowMenu();
	cmd = GetAChar("\n>");
  }
  return cmd;
}

bool ValidGenre(char g) //	Error checks valid genre
{
	switch (toupper(g))
	{
		case 'F':
			return true;
			break;
		case 'M':
			return true;
			break;
		case 'S':
			return true;
			break;
		case 'C':
			return true;
		default:
			return false;
			break;
	}
	return false;
}

int main()
{
	cout << "*** Welcome to Bookstore Inventory Manager ***\n";
	cout << "Please input the starting money in the cash register: ";
	double cash;
	cin >> cash;
	while (cash < 0)
	{
		cout << "Invalid entry, please try again: ";
		cin >> cash;
	}
	
	Store s(cash);

	ShowMenu();
	
	char command;			// menu command entered by user
	do
   {
	command = GetCommand();		// Retrieve a command.
	switch (command)
	{
		case 'A':
			char t[31];    // may assume title is 30 characters or less
			char a[21];    // may assume author name is 20 characters or less
			char g;
			double p;
			
			cout << "Enter title: ";
			cin.getline(t, 30);        // Gets a title; discards newline.

			cout << "Enter author: ";
			cin.getline(a, 20);    // Gets a phone; discards newline.
			
			cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer: ";
			cin >> g;
			
			while (ValidGenre(g) == false)
			{
				cout << "Invalid Genre entry.  Please re-enter" << endl;
				cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer: ";
				cin >> g;
			}
			
			cout << "Enter price: ";
			cin >> p;

			while (p < 0)
			{
				cout << "Must enter a positive price.  Please re-enter" << endl;
				cout << "Enter price: ";
				cin >> p;
			}
			s.Add(t, a, g, p);
			break;
		case 'F':
			char search[31];
			cout << "Enter search string (title or author): ";
			cin.getline(search, 30);
            s.FindItem(search);
            break;
		case 'S':
			char title[31];
			cout << "Enter title to sell: ";
			cin.getline(title, 30);
			s.Sell(title);
			break;
		case 'D':
			s.DisplayInventory();
			break;
		case 'G':
			char genre;
			cout << "Enter genre: ";
			cin >> genre;
			
			while (ValidGenre(genre) == false)
			{
				cout << "Invalid Genre entry.  Please re-enter" << endl;
				cout << "Enter genre: ";
				cin >> genre;
			}
			s.GenreSummary(genre);
			break;
		case 'M':
			ShowMenu();
			break;
		case 'O':
			char c;
			cout << "Sort Sort by (T)itle or (A)uthor? > ";
			cin >> c;
			s.Sort(c);
		case 'X':
			cout << "Goodbye!" << endl;
			break;
	}
} while (command != 'X');

   return 0;
}

