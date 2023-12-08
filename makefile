COURSE = cs310
SEMESTER = Fall2023
CP_NUMBER = 4
LASTNAME = Lewis
GITUSERID = mlewis608
EXE = movie_db
MENU_EXE = menu_sample

# REPODIR = ../$(COURSE)-$(SEMESTER)-$(CP_NUMBER)-$(GITUSERID)
REPODIR = ../$(COURSE)-$(SEMESTER)-CP4-Sample
TARFILE = CP$(CP_NUMBER)_$(LASTNAME)_$(USER)_$(GITUSERID).tar

FLAGS = -Wall -Wextra -g
# FLAGS = -Wall -O3
CC = g++
BIN = bin
OBJ = obj

all: $(EXE)

$(EXE): $(OBJ)/ActorDB.o $(OBJ)/Actor.o $(OBJ)/Heap.o $(OBJ)/movie_db.o
	$(CC) $(FLAGS) $(OBJ)/ActorDB.o $(OBJ)/Actor.o $(OBJ)/Heap.o $(OBJ)/movie_db.o -o $(BIN)/$@

$(OBJ)/Actor.o: Actor.cpp Actor.h Array.h
	$(CC) $(FLAGS) -c Actor.cpp -o $@

$(OBJ)/Heap.o: Heap.cpp Heap.h Array.h 
	$(CC) $(FLAGS) -c Heap.cpp -o $@

$(OBJ)/ActorDB.o: ActorDB.cpp ActorDB.h Array.h BST.h
	$(CC) $(FLAGS) -c ActorDB.cpp -o $@

$(OBJ)/movie_db.o: movie_db.cpp ActorDB.h Array.h BST.h
	$(CC) $(FLAGS) -c movie_db.cpp -o $@
# $(BIN)/$(MENU_EXE): $(OBJ)/sample_menu.o
# 	$(CC) $(FLAGS) $(OBJ)/sample_menu.o -o $@

# $(OBJ)/sample_menu.o: sample_menu.cpp Parser.h
# 	$(CC) $(FLAGS) -c sample_menu.cpp -o $@

tar:	clean
	tar cvvf $(TARFILE) $(REPODIR)
	gzip $(TARFILE)

clean:
	rm -f $(OBJ)/*.o $(EXE) *.tar.gz