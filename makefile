# my personal makefile modified

WARN = -Wall -Wextra -Wshadow

CFLAGS   = $(WARN) -Og -std=c99 -g
RFLAGS   = $(WARN) -O3 -std=c99 -D NDEBUG -D BUF_SIZE=100000

SRCR = *.c
SRCS = $(wildcard $(SRCR))
OBJS = $(SRCS:.c=.o)

TARGET = av

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS)

release:
	$(CC) $(OBJS) -o $(TARGET) $(RFLAGS)

clean:
	@rm -vf $(OBJS) $(TARGET)
