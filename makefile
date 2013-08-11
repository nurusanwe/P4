CC = g++
CFLAGS = -Wl,-rpath api/lib
EXEC_NAME = puiss4
INCLUDES =  -I/home/morinehtar/Documents/Puissance_4/inc -I/api/inc/
LIBS = /home/morinehtar/Documents/Puissance_4/api/lib/libfmodex64.so
OBJ_FILES = main.o src/Joueur.o src/Grille.o src/fonction.o
INSTALL_DIR = out/

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.cc
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

%.o: %.c
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

install :
	cp $(EXEC_NAME) $(INSTALL_DIR)