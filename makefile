# my personal makefile modified

WARN := -Wall -Wextra -Wshadow

# this line should be uncommented if you want a debug build
#CFLAGS := $(WARN) -Og -std=c99 -g
CFLAGS  := $(WARN) -O3 -std=c99 -D NDEBUG -D BUF_SIZE=999999

SRCR = *.c
SRCS = $(wildcard $(SRCR))
OBJS = $(SRCS:.c=.o)

TARGET = av

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(CFLAGS)

clean:
	@rm -vf $(OBJS) $(TARGET)
