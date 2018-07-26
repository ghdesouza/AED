TARGET = main
LIBS = -lm
CC = g++
CFLAGS = -g -Wall
RM = rm -f
DIR = Libs
DIR_OBJ = Obj
DIR_INC = Include

main: main.o Grafo.o Listas.o
	
	$(CC) $(DIR_OBJ)/$(TARGET).o $(DIR_OBJ)/Grafo.o $(DIR_OBJ)/Listas.o $(LIBS) -o $@ $(CFLAGS)
	@echo "Executavel ./main gerado."

main.o: $(TARGET).cpp
	mkdir -p $(DIR_OBJ)
	$(CC) -c $(TARGET).cpp -o $(DIR_OBJ)/$@

Grafo.o: $(DIR)/Grafo.cpp $(DIR_INC)/Grafo.h
	$(CC) -c $(DIR)/Grafo.cpp -o $(DIR_OBJ)/$@

Listas.o: $(DIR)/Listas.cpp $(DIR_INC)/Listas.h
	$(CC) -c $(DIR)/Listas.cpp -o $(DIR_OBJ)/$@

clean:
	$(RM) $(TARGET) *.o $(DIR_OBJ)/*.o
