CC         = g++
CFLAGS     = -std=c++14 -O2 -Wall -Wextra
# LFLAGS     = -std=c++14
SOURCES    = src/01.cpp \
             src/02.cpp \
             src/03.cpp \
             src/04.cpp \
             src/04_generator.cpp \
             src/05.cpp \
             src/06.cpp \
             src/07.cpp \
             src/08.cpp \
             src/09.cpp \
             src/10.cpp
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
