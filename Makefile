COMP=g++
FLAGS=-g -ansi -pedantic -Wall -std=c++11 #-DMAP
EXEC=analyse-log analyse-log-test

#Répertoire des sources (.cpp et .h)
SRC_DIR=src
#Répertoire des fichiers objets (.o)
OBJ_DIR=build
#Répertoire des exécutables
BIN_DIR=bin

#Récupère la liste des fichiers .cpp sauf le main.cpp
SRC := $(shell find $(SRC_DIR) -name '*.cpp' ! -name 'main.cpp')

#Récupère tous les headers des sources
HEADERS := $(shell find $(SRC_DIR) -name '*.h')

#Récupère la liste $(SRC) et remplace le répertoire $(SRC_DIR) par $(OBJ_DIR) et
#toutes les extensions .cpp en .o
OBJ	:= $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC:.cpp=.o))

LOG_SRC = $(SRC_DIR)/main.cpp $(SRC)
LOG_OBJ = $(OBJ_DIR)/main.o $(OBJ)

all:
	make analog
	make test
	@echo
	@echo ">>> Pour lancer le programme principal: './bin/analog [-e] [-t heure] [-g nomGraphe.dot] <fichierLogs.log|fichierLogs.txt>'"

analog: $(LOG_OBJ) $(HEADERS)
	@mkdir -p bin
	$(COMP) -o $(BIN_DIR)/$@ $(LOG_OBJ)

test:
	make analog
	cd ./Tests/;bash ./mktest.sh

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p build
	$(COMP) $(FLAGS) -o $@ -c $<

$(OBJ_DIR)/%.o: $(SRC_TEST_DIR)/%.cpp
	@mkdir -p build
	$(COMP) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*

.PHONY: clean
