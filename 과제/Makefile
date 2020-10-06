CC = g++
TARGET = str
CFLAGS = -g -w -O3
  
INCLUDES =
OBJS = main.o Str.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm $(OBJS) $(TARGET)
	
