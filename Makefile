CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O0
TARGET = dicionario
SRC = src/main.cpp src/palavra.cpp src/grafo.cpp src/dicionario.cpp src/menu.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET) $(TARGET).exe *.o

.PHONY: all clean
