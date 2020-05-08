CC = g++
CC_OPTS="-Wall"
prefix = /usr
OBJS = connect_4.o connect_4_grid.o player.o

all:	connect_4

connect_4:	$(OBJS)
	$(CC) $(CC_OPTS) -o connect_4 $(OBJS)

$(OBJS):	%.o:	%.cpp
	$(CC) $(CC_OPTS) -c -o $@ $<

install:	connect_4
	[ -d ${prefix}/bin ] || mkdir ${prefix}/bin
	cp connect_4 $(prefix)/bin
	cp connect_4.6.gz /usr/share/man/man6/

uninstall:	install
	[ -f ${prefix}/bin/connect_4 ] && rm ${prefix}/bin/connect_4 
	rm /usr/share/man/man6/

clean:
	if [ -f connect_4 ]; then rm connect_4; fi
	if [ -f connect_4.o ]; then rm *.o; fi
