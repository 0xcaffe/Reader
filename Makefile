CXX=g++
CXXFLAGS=-c
LDFLAGS=
SOURCES=Reader.cpp ReaderTest.cpp
READER_OBJ=main.o
TEST_OBJ=test.o
OBJECTS=$(SOURCES:.cpp=.o)

EXE_NAME = reader
TEST_EXE_NAME = readerTest

all: clean test run

test: $(OBJECTS) $(TEST_OBJ)
	$(CXX) $(CXXLDFLAGS) $^ -o $(TEST_EXE_NAME)
	./$(TEST_EXE_NAME)

run: $(OBJECTS) $(READER_OBJ)
	$(CXX) $(CXXLDFLAGS) $^ -o $(EXE_NAME)
	./$(EXE_NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ 

clean:
	rm -f $(OBJECTS) $(READER_OBJ) $(TEST_OBJ) $(EXE_NAME) $(TEST_EXE_NAME)
