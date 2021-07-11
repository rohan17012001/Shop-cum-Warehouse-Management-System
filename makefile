project: main.o product.o customer.o employee.o owner.o
	g++ main.o product.o customer.o employee.o owner.o -o project

main.o: main.cpp
	g++ -c main.cpp

product.o: product.cpp
	g++ -c product.cpp

customer.o: customer.cpp
	g++ -c customer.cpp

employee.o: employee.cpp
	g++ -c employee.cpp

owner.o: owner.cpp
	g++ -c owner.cpp

clean:
	rm *.o project