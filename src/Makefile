CC = g++
CFLAGS = -c -Wall
INCPATH = -I/usr/share/qt/mkspecs/linux-g++ -I. -I/usr/include/QtCore -I/usr/include/QtGui -I/usr/include -I. -I.
LIBS = -L/usr/lib -lQtGui -lQtCore -lpthread -lmpdclient
OBJ = obj/
SRC = src/
BIN = bin/

all: EighthNote

EighthNote: base.o song.o mainwindow.o moc_mainwindow.o
	$(CC) $(INCPATH) $(LIBS) base.o song.o mainwindow.o moc_mainwindow.o -o EighthNote
	
base.o: base.cpp
	$(CC) $(CFLAGS) $(INCPATH) $(LIBS) -o base.o base.cpp
	
mainwindow.o: mainwindow.cpp mainwindow.h ui/ui_mainwindow.h
	$(CC) $(CFLAGS) $(INCPATH) $(LIBS) -o mainwindow.o mainwindow.cpp
	
moc_mainwindow.o: moc_mainwindow.cpp 
	$(CC) $(CFLAGS) $(INCPATH) $(LIBS) -o moc_mainwindow.o moc_mainwindow.cpp
	
moc_mainwindow.cpp: mainwindow.h
	moc mainwindow.h -o moc_mainwindow.cpp

song.o: song.cpp song.h
	$(CC) $(CFLAGS) $(LIBS) -o song.o song.cpp

clean:
	rm -f *.o EighthNote moc_*