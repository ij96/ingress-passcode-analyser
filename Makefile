SRC		= main.cpp format_check.cpp decoders.cpp
TARGET	= analyser
OBJS	= $(subst .cpp,.o,$(SRC))

CC		= g++
CFLAGS	= -g -I.
LDFLAGS	= -g

ifeq ($(OS),Windows_NT)
	RM	= del /Q /F
else
    RM	= rm -f
endif

.PHONY: all
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	$(RM) $(TARGET).exe $(OBJS)