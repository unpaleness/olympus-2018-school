CC         = g++
CFLAGS     = -std=c++14 -O2 -Wall -Wextra
# LFLAGS     = -std=c++14
SOURCES    = src/03.cpp
# OBJECTS    = $(SOURCES:src/%.cpp=obj/%.o)
EXECUTABLE = $(SOURCES:src/%.cpp=%.out)

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(@:%.out=src/%.cpp) -o $@

# $(OBJECTS): $(SOURCES)
# 	$(CC) $(CFLAGS) $(@:obj/%.o=src/%.cpp) -o $@

# .cpp.o:
# 	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -rfv $(EXECUTABLE)
