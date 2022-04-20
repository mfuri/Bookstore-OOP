menu: menu.o store.o book.o
	g++ menu.o store.o book.o -o menu

menu.o: menu.cpp store.h book.h
	g++ -c menu.cpp

store.o: store.cpp store.h book.h
	g++ -c store.cpp

book.o: book.cpp book.h
	g++ -c book.cpp

clean:
	rm -f menu *.o
