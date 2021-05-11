-En el comprimido viene ya un archivo ejecutable.exe
 en consola solo se pone .\ejecutable.exe  para poder ejecutarlo

 si no se ejecuta, recuerda que tienes que estar la misma direccion donde esta
 el ejecutable.exe

Compilacion:

    -Por si borraste el ejecutable exe, entonces no hay de otra que volverlo 
     compilar 
        -para ello solo situate en la direccion del archivo makefile y escribe
         make  ejemplo:
         C:\Desktop\Escritorio\AnalizadorLexico\
         make 
        
         vemos que la primera linea te indica en que ruta te encuentras
         una ves ahi escribes make

    -Tienes que tener en cuenta que debes tener instalado el g++ y make
     
    -Por si no tienes el g++ con make entonces te recomiendo el siguiente video
    https://www.youtube.com/watch?v=amDcj6Od1f8

    ..con dicho video podras montarte un entorno de desarrollo en c++ en visual studio code
    y tambien te enseña  a instalar el g++,.. dentro de esa instalacion ya viene el make

    sigue los pasos del video y la compilacion del programa ya no deberia de fallar


    NOTA: en la carpeta analizadorLexico se encuentra ya un archivo makefile
          y ya estan implementados comandos como 
        
          make all: (es lo mismo que escribir make) compilara los archivos y 
                    como resultado obtendras un ejecutable.exe
          make clean: borra todos los archivos .o y los .exe 

          estos son solo dos comandos ya implementados para el funcionamiento del programa
          recuerda no modificar el makefile para evitar posibles errores a menos que 
          ya tengas experiencia con los makefiles


    Cualquier duda pues si me conoces no dudes en preguntarme que encantado te 
    ayudo :)

    
