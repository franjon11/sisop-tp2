#**********************************#
#             Carpetas             #
#**********************************#
SOURCE_FOLDER=source	#los .cpp
TMP_FOLDER=tmp          #los .o generados
BUILD_FOLDER=build      #los .exe generados

#**********************************#
#            Compilacion           #
#**********************************#
CXX=g++
CFLAGS=-Wall
CPPFLAGS=-lstdc++

#**********************************#
#             Reglas               #
#**********************************#

.PHONY: all clean
all: $(SOURCE_FOLDER) $(TMP_FOLDER) $(BUILD_FOLDER)
	$(CXX) $(CFLAGS) -c $(SOURCE_FOLDER)/main.cpp -o $(TMP_FOLDER)/main.o
	$(CXX) $(TMP_FOLDER)/main.o $(CPPFLAGS) -o $(BUILD_FOLDER)/main

clean:
	rm -r $(TMP_FOLDER) $(BUILD_FOLDER)


