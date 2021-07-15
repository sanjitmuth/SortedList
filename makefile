main: Student.cpp SortedList.cpp SortedListDr.cpp
	g++ -o SortedListDr Student.cpp SortedList.cpp SortedListDr.cpp
Student.o: Student.cpp
	g++ -c Student.cpp
SortedList.o: SortedList.cpp
	g++ -c SortedList.cpp
SortedListDr.o: SortedListDr.cpp
	g++ -c SortedListDr.cpp
run: SortedListDr
	./SortedListDr
clean:
	rm -rf SortedListDr
	rm -rf *.o
