TARGET=a.out
CXX=g++
DEBUG=-g
OPT=-O2
WARN=-Wall -Werror
SFML=-lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS=$(DEBUG) $(OPT) $(WARN) $(SFML)
LD=g++
OBJS= main.o constructor.o pongball.o logic.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(CXXFLAGS)
	@rm *.o
	@./$(TARGET)

main.o: main.cpp
	$(CXX) -c $(CXXFLAGS) main.cpp -o main.o

constructor.o: constructor.cpp
	$(CXX) -c $(CXXFLAGS) constructor.cpp -o constructor.o

pongball.cpp.o: pongball.cpp.cpp
	$(CXX) -c $(CXXFLAGS) pongball.cpp.cpp -o pongball.cpp.o

logic.cpp.o: logic.cpp.cpp
	$(CXX) -c $(CXXFLAGS) logic.cpp.cpp -o logic.cpp.o
