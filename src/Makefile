
TARGET = routerSettings

OBJS = main.o md5.o parse_request.o session_info.o util.o \
       login.o contents.o data_request.o do_process.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC)	-o	$@	$(OBJS)

main.o: main.c
	$(CC)	-c   main.c

md5.o: md5.c md5.h
	$(CC)	-c   md5.c
	
contents.o: contents.c contents.h
	$(CC)	-c    contents.c
	
parse_request.o: parse_request.c parse_request.h
	$(CC)	-c    parse_request.c

session_info.o: session_info.c session_info.h
	$(CC)	-c    session_info.c

util.o: util.c util.h
	$(CC)	-c    util.c


login.o: login.c login.h
	$(CC)	-c    login.c
	
data_request.o: data_request.c data_request.h
	$(CC)	-c    data_request.c
	
do_process.o: do_process.c do_process.h
	$(CC)	-c    do_process.c


clean:  
	rm -f *.o $(TARGET)

install:
	@echo "you should be copy the bin file by yourself."

	
	
	