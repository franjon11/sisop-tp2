#**********************************#
#             Carpetas             #
#**********************************#
SOURCE_FOLDER=source	#los .cc

CONSUM_PRODS=consum-prods
CONTROLS=controladores
INCLUDES=Sem-SV

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
NERFS = nerfs
BALSAS = balsas

INIT = inicializa
FIN = finaliza
LIB = libera

#**********************************#
#            Compilacion           #
#**********************************#
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

TODOS = $(SERFS) $(NERFS) $(BALSAS) $(INIT) $(FIN) $(LIB)

INCLUDE1 = ${INCLUDE} ${AREA} ${MENSAJE} ${SV_SEM} ${SV_SHM}
INCLUDE2 = ${INCLUDE} ${SV_SEM}
INCLUDE3 = ${INCLUDE} ${SV_SEM} ${SV_SHM} ${AREA}

#**********************************#
#             Reglas               #
#**********************************#

#.PHONY: all clean
all: $(TODOS)

$(SERFS).o: $(SERFS).cc $(INCLUDE1)
	$(CXX) $(CXXFLAGS) -c $(SOURCE_FOLDER)/$(CONSUM_PRODS)/$(SERFS).cc

$(NERFS).o: $(NERFS).cc $(INCLUDE1)
	$(CXX) $(CXXFLAGS) -c $(SOURCE_FOLDER)/$(CONSUM_PRODS)/$(NERFS).cc

$(BALSAS).o: $(BALSAS).cc $(INCLUDE1)
	$(CXX) $(CXXFLAGS) -c $(SOURCE_FOLDER)/$(CONSUM_PRODS)/$(BALSAS).cc

$(INIT).o: $(INIT).cc $(INCLUDE2)
	$(CXX) $(CXXFLAGS) -c $(SOURCE_FOLDER)/$(CONTROLS)/$(INIT).cc

$(FIN).o: $(FIN).cc $(INCLUDE3)
	$(CXX) $(CXXFLAGS) -c $(SOURCE_FOLDER)/$(CONTROLS)/$(FIN).cc

$(LIB).o: $(LIB).cc $(INCLUDE3)
	$(CXX) $(CXXFLAGS) -c $(SOURCE_FOLDER)/$(CONTROLS)/$(LIB).cc

clean:
	rm -r $(BUILD_FOLDER) $(TMP_FOLDER)
