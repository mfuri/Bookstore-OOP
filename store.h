//	Michael Tafuri
//	COP3330-0001
#include "book.h"

class Store
{
public:
	Store();			//	Creates blank inventory
	Store(double = 0);	//	Cashreg is set to 0
	~Store();			//	Deletes allocated memory

	//Mutators
	void Add(char *,char *, char, double);
	void Sell(char *);
	
	//Accessors/Showers
	void DisplayInventory() const;
    void FindItem(char *) const;
	void GenreSummary(char) const;
	void Sort(char);
	
	//Helper functions
    int TitleSearch(char *) const;
    int AuthorSearch(char *) const;
	
	//Setters
	Genre GenreChoice(char) const;

private:
	Book * inventory;
	int currentsize;
	int maxsize;
	double cashreg;
	void Grow();
};
