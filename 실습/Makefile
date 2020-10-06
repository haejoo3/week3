CC = g++
TARGET = GrowableArray
CFLAGS = -g -w -O3
  
INCLUDES =
OBJS = main.o Array.o GrowableArray.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm $(OBJS) $(TARGET)
	
