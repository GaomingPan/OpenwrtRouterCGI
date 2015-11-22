
TARGET = routerSettings

OBJS = main.o md5.o parse_request.o session_info.o util.o \
       login.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC)	-o	$@	$(OBJS)

main.o: main.c
	$(CC)	-c   main.c

md5.o: md5.c md5.h
	$(CC)	-c   md5.c
	
parse_request.o: parse_request.c parse_request.h
	$(CC)	-c    parse_request.c

session_info.o: session_info.c session_info.h
	$(CC)	-c    session_info.c

util.o: util.c util.h
	$(CC)	-c    util.c


login.o: login.c login.h
	$(CC)	-c    login.c

clean:  
	rm -f *.o $(TARGET)

install:
	@echo "you should be copy the bin file by yourself."

	
	
	