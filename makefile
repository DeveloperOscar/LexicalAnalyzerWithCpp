#declara aqui tus archivos.o
OBJS = .\obj\simbolos.o .\obj\main.o  .\obj\tokens.o .\obj\regex.o .\obj\verificador.o

#declara aqui el nombre de tu ejecutable
BINARY = ejecutable 

#declara aqui el nombre de tu compilador
COMPILER = g++ 

# declara aqui el nombre de la carpeta donde estan tus archivos
INCLUDE = includes 

CCSTANDAR = -std=c++20

#la bandere -o siempre va al final
CCFLAGS = $(CCSTANDAR) -Wall -o


#declarando nuestros archivos cpp
ARCHIVO1 = .\src\main.cpp
ARCHIVO2 = .\src\simbolos.cpp
ARCHIVO3 = .\src\tokens.cpp
ARCHIVO4 = .\src\regex.cpp
ARCHIVO5 = .\src\verificador.cpp

all: ejecutable

#se linkean los objetos  y se genera un ejecutable
ejecutable: main.o simbolos.o tokens.o regex.o verificador.o
	mv *.o obj
	$(COMPILER) $(CCFLAGS) $(BINARY) $(OBJS)
	
main.o: $(ARCHIVO1)
	$(COMPILER) -c $(ARCHIVO1) -I$(INCLUDE)
	

simbolos.o: $(ARCHIVO2)
	$(COMPILER) -c $(ARCHIVO2) -I$(INCLUDE)
	

tokens.o: $(ARCHIVO3)
	$(COMPILER) -c $(ARCHIVO3) -I$(INCLUDE)
	
	
regex.o: $(ARCHIVO4)
	$(COMPILER) -c $(ARCHIVO4) -I$(INCLUDE)
	
verificador.o: $(ARCHIVO5)
	$(COMPILER) -c $(ARCHIVO5) -I$(INCLUDE)
	
#comandos adicionales
debug:
	$(COMPILER) -g $(ARCHIVO1) $(ARCHIVO2) $(ARCHIVO3) $(ARCHIVO4) -I$(INCLUDE)

clean:
	rm -f ./obj/*.o *.exe
	

