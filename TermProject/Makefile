.SUFFIXES: .o .cpp

XX = g++
CFAGS = -W -Wall
TARGET = test
OBJECTS = main.o array_2d.o block.o big_block.o color_block.o fold_block.o tree_block.o cross_block.o

all : $(TARGET)

$(TARGET):	$(OBJECTS)
		$(XX) $(CFAGS) -o $@ $^
clean	:
		rm -rf *.o test



