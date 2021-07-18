#**********************************#
#             Carpetas             #
#**********************************#
SOURCE_FOLDER=source

CONSUM_PRODS=consum-prods
CONTROLS=controladores
INCLUDES=includes

TMP_FOLDER=tmp      #los .o generados
BUILD_FOLDER=bin      #los .exe generados

#**********************************#
#            Codigos               #
#**********************************#
INCLUDE = $(SOURCE_FOLDER)/$(INCLUDES)/includes.h
AREA = $(SOURCE_FOLDER)/$(INCLUDES)/Area.h
MENSAJE = $(SOURCE_FOLDER)/$(INCLUDES)/Mensaje.h

SV_SEM = $(SOURCE_FOLDER)/$(INCLUDES)/sv_sem.h
SV_SHM = $(SOURCE_FOLDER)/$(INCLUDES)/sv_shm.h

SERFS = serfs
NERDS = nerds
BALSAS = balsas

INIT = inicializa
FIN = finaliza
LIB = libera

#**********************************#
#            Compilacion           #
#**********************************#
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g -c -w

TODOS = $(SERFS) $(NERDS) $(BALSAS) $(INIT) $(FIN) $(LIB)

INCLUDE1 = ${INCLUDE} ${AREA} ${MENSAJE} ${SV_SEM} ${SV_SHM}
INCLUDE2 = ${INCLUDE} ${SV_SEM}
INCLUDE3 = ${INCLUDE} ${SV_SEM} ${SV_SHM} ${AREA}

#**********************************#
#             Reglas               #
#**********************************#

#.PHONY: all clean
all: $(TODOS)

$(SERFS): 
	$(CXX) $(CXXFLAGS) -c $(SOURCE_FOLDER)/$(CONSUM_PRODS)/$(SERFS).cc

$(NERDS): 
	$(CXX) $(CXXFLAGS) -c $(SOURCE_FOLDER)/$(CONSUM_PRODS)/$(NERDS).cc

$(BALSAS): 
	$(CXX) $(CXXFLAGS) -c $(SOURCE_FOLDER)/$(CONSUM_PRODS)/$(BALSAS).cc

$(INIT): 
	$(CXX) $(CXXFLAGS) -c $(SOURCE_FOLDER)/$(CONTROLS)/$(INIT).cc

$(FIN): 
	$(CXX) $(CXXFLAGS) -c $(SOURCE_FOLDER)/$(CONTROLS)/$(FIN).cc

$(LIB): 
	$(CXX) $(CXXFLAGS) -c $(SOURCE_FOLDER)/$(CONTROLS)/$(LIB).cc

clean:
	rm -r $(BUILD_FOLDER) $(TMP_FOLDER)
