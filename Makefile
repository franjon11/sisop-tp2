#**********************************#
#             Carpetas             #
#**********************************#
SOURCE_FOLDER=$(PWD)/source

CONSUM_PRODS=consum-prods
CONTROLS=controladores
INCLUDES=includes

TMP_FOLDER=tmp   #los .o generados
BUILD_FOLDER=bin #los .exe generados

#**********************************#
#            Codigos               #
#**********************************#
INCLUDE = $(SOURCE_FOLDER)/$(INCLUDES)/includes.h
AREA = $(SOURCE_FOLDER)/$(INCLUDES)/Area.h
MENSAJE = $(SOURCE_FOLDER)/$(INCLUDES)/Mensaje.h

BALSA= $(SOURCE_FOLDER)/$(INCLUDES)/balsas.cpp

SV_SEM = $(SOURCE_FOLDER)/$(INCLUDES)/sv_sem.h
SV_SHM = $(SOURCE_FOLDER)/$(INCLUDES)/sv_shm.h

SERFS = serfs
NERDS = nerds
BALSAS = balsas2

INIT = inicializa
FIN = finaliza
LIB = libera

#**********************************#
#            Compilacion           #
#**********************************#
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -w

TODOS = $(SERFS) $(NERDS) $(BALSAS) $(INIT) $(FIN) $(LIB)

INCLUDE1 = ${INCLUDE} ${AREA} ${MENSAJE} ${SV_SEM} ${SV_SHM}
INCLUDE2 = ${INCLUDE} ${SV_SEM}
INCLUDE3 = ${INCLUDE} ${SV_SEM} ${SV_SHM} ${AREA}

#**********************************#
#             Reglas               #
#**********************************#

#.PHONY: all clean
all: $(TODOS)

$(SERFS): $(BUILD_FOLDER) $(INCLUDE1) $(SOURCE_FOLDER)/$(CONSUM_PRODS)/$(SERFS).cc
	cd $(BUILD_FOLDER); $(CXX) $(CXXFLAGS) $(SOURCE_FOLDER)/$(CONSUM_PRODS)/$(SERFS).cc -o $(SERFS)

$(NERDS): $(BUILD_FOLDER) $(INCLUDE1) $(SOURCE_FOLDER)/$(CONSUM_PRODS)/$(SERFS).cc
	cd $(BUILD_FOLDER); $(CXX) $(CXXFLAGS) $(SOURCE_FOLDER)/$(CONSUM_PRODS)/$(NERDS).cc -o $(NERDS)

$(BALSAS): $(BUILD_FOLDER) $(INCLUDE1) $(SOURCE_FOLDER)/$(CONSUM_PRODS)/$(SERFS).cc
	cd $(BUILD_FOLDER); $(CXX) $(CXXFLAGS) $(SOURCE_FOLDER)/$(CONSUM_PRODS)/$(BALSAS).cc -o $(BALSAS)

$(INIT): $(BUILD_FOLDER) $(INCLUDE2) $(SOURCE_FOLDER)/$(CONTROLS)/$(INIT).cc
	cd $(BUILD_FOLDER); $(CXX) $(CXXFLAGS) $(SOURCE_FOLDER)/$(CONTROLS)/$(INIT).cc -o $(INIT)

$(FIN): $(BUILD_FOLDER) $(INCLUDE3) $(SOURCE_FOLDER)/$(CONTROLS)/$(FIN).cc
	cd $(BUILD_FOLDER); $(CXX) $(CXXFLAGS) $(SOURCE_FOLDER)/$(CONTROLS)/$(FIN).cc -o $(FIN)

$(LIB): $(BUILD_FOLDER) $(INCLUDE3) $(SOURCE_FOLDER)/$(CONTROLS)/$(LIB).cc
	cd $(BUILD_FOLDER); $(CXX) $(CXXFLAGS) $(SOURCE_FOLDER)/$(CONTROLS)/$(LIB).cc -o $(LIB)

clean:
	rm $(BUILD_FOLDER) $(TMP_FOLDER)
