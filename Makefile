EXEC:=superb
CXX:=g++
LINKER:=g++
INC:=-I.
CXXFLAGS:=-Wall -Wextra -pedantic

SRC:=$(wildcard *.cpp)
OBJ:=$(patsubst %.cpp,%.o,$(SRC))
DEP:=$(patsubst %.cpp,%.d,$(SRC))

$(EXEC): $(OBJ) 
	$(LINKER) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@
	$(CXX) $(INC) -MM $< > $*.d

%.d: %.cpp

-include $(DEP)

echo:
	echo $(SRC)
	echo $(OBJ)
	echo $(DEP)

.PHONY: clean

clean:
	rm -f *.o *.d $(EXEC)
