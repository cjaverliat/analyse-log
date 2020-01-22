COMP=g++
FLAGS=-g -ansi -pedantic -Wall -std=c++11 #-DMAP
EXEC=analyse-log analyse-log-test

#Répertoire des sources (.cpp et .h)
SRC_DIR=src
#Répertoire des sources pour les tests
SRC_TEST_DIR=test
#Répertoire des fichiers objets (.o)
OBJ_DIR=build
#Répertoire des exécutables
BIN_DIR=bin
#Répertoire de la documentation (compte rendu + diagramme)
DOC_DIR=doc

PLANTUML_PATH=$(DOC_DIR)/plantuml.jar

#Récupère la liste des fichiers .cpp sauf le main.cpp
SRC := $(shell find $(SRC_DIR) -name '*.cpp' ! -name 'main.cpp')

#Récupère tous les headers des sources
HEADERS := $(shell find $(SRC_DIR) -name '*.h')

#Récupère la liste $(SRC) et remplace le répertoire $(SRC_DIR) par $(OBJ_DIR) et
#toutes les extensions .cpp en .o
OBJ	:= $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC:.cpp=.o))

LOG_SRC = $(SRC_DIR)/main.cpp $(SRC)
LOG_OBJ = $(OBJ_DIR)/main.o $(OBJ)

LOG_TEST_SRC = $(SRC_TEST_DIR)/test.cpp $(SRC)
LOG_TEST_OBJ = $(OBJ_DIR)/test.o $(OBJ)

all:
	make analog
	@echo
	@echo ">>> Pour lancer le programme principal: './bin/analog [-e] [-t heure] [-g nomGraphe.dot] <fichierLogs.log|fichierLogs.txt>'"

doc:
	make -B class-diagram

class-diagram: $(DOC_DIR)/diagramme_classe.pu


%.pu:
	java -jar $(PLANTUML_PATH) -tsvg $@
	java -jar $(PLANTUML_PATH) -tpng $@

$(DOC_DIR)/compte_rendu.tex:
	./doc/build_latex.sh

analog: $(LOG_OBJ) $(HEADERS)
	@mkdir -p bin
	$(COMP) -o $(BIN_DIR)/$@ $(LOG_OBJ)

analyse-log-test: $(LOG_TEST_OBJ) $(HEADERS)
	@mkdir -p bin
	$(COMP) -o $(BIN_DIR)/$@ $(LOG_TEST_OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p build
	$(COMP) $(FLAGS) -o $@ -c $<

$(OBJ_DIR)/%.o: $(SRC_TEST_DIR)/%.cpp
	@mkdir -p build
	$(COMP) $(FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*
	rm -rf $(DOC_DIR)/diagram.latex $(DOC_DIR)/diagram.png

.PHONY: clean doc
