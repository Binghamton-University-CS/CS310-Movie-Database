COURSE = cs310
SEMESTER = Fall2023
CP_NUMBER = 1
LASTNAME = Lewis
GITUSERID = mlewis608
EXE = movie_db
MENU_EXE = menu_sample

# REPODIR = ../$(COURSE)-$(SEMESTER)-$(CP_NUMBER)-$(GITUSERID)
REPODIR = ../$(COURSE)-$(SEMESTER)-CP1-Sample
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(EXE)

$(BIN)/$(EXE): $(OBJ)/Array.o $(OBJ)/ActorDB.o $(OBJ)/Actor.o $(OBJ)/sample_menu.o
	$(CC) $(FLAGS) $(OBJ)/Array.o $(OBJ)/ActorDB.o $(OBJ)/Actor.o $(OBJ)/sample_menu.o -o $@

$(OBJ)/Actor.o: Actor.cpp Actor.h Array.h
	$(CC) $(FLAGS) -c Actor.cpp -o $@

$(OBJ)/Heap.o: Heap.cpp Heap.h Arrah.h 
	$(CC) $(FLAGS) -c Heap.cpp -o $@

$(OBJ)/ActorDB.o: ActorDB.cpp ActorDB.h Arrah.h 
	$(CC) $(FLAGS) -c ActorDB.cpp -o $@

$(BIN)/$(MENU_EXE): $(OBJ)/sample_menu.o
	$(CC) $(FLAGS) $(OBJ)/sample_menu.o -o $@

$(OBJ)/sample_menu.o: sample_menu.cpp Parser.h
	$(CC) $(FLAGS) -c sample_menu.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(BIN)/$(EXE) *.tar.gz