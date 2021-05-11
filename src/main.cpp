#include <iostream>
#include <vector>
#include "../includes/regex.hpp"
#include "../includes/simbolos.hpp"
#include <fstream>
#include "../includes/tokens.hpp"
#include "../includes/verificador.hpp"
#include <string>

int main()
{
    //CREANDO LISTAS PARA GUARDAS LOS  LEXEMAS
    std::vector<std::string> tokensIdentificadores;
    std::vector<std::string> tokensOperadores;
    std::vector<std::string> tokensReservadas;
    std::vector<std::string> tokensConstantes;
    std::vector<std::string> lista_errores;
    
    using std::ifstream; //USO A NIVEL DE ARCHIVO DE STD::IFSTREAM

    ifstream archivo; // CREACION DE UN OBJETO IFSTREAM ,(EL FLUJO DE LECTURA DE DATOS)

    std::string texto; //ALMACENARA LINEA POR LINEA EL ARCHIVO

    //SE PROCEDE A CONECTAR EL FLUJO DE LECTURA CON EL ARCHIVO ejemplos1.txt
    archivo.open("ejemplos//ejemplo1.txt", std::ios::in);

    //SI EN CASO FALLE LA CONEXION CON EL ARCHIVO
    if (archivo.fail())
    {
        std::cout << "no se pudo abrir el archivo";
        return 1;
    }

    //SE CREA UNA VARIABLE ENCARGADA DE CONTAR LAS LINEAS
    int count_linea{1};

    //MIENTRAS NO SE LLEGUE AL FINAL DEL ARCHIVO
    while (!archivo.eof())
    {

        getline(archivo, texto); //almacena en la cadena "texto" la linea actual del fichero
        texto.push_back(' ');    //se le agrega un espacio vacio al final para evitar errores

        //las 3 siguientes lineas almacenan el la cadena "lineaActual"
        //la linea actual en la que se encuentra el fichero
        std::string lineaActual = " linea ";
        std::string num_linea = std::to_string(count_linea); //convirtiendo a string
        lineaActual += num_linea;                            //resultado ejemplo:  linea 1

        for (int i = 0; i < texto.size();)
        {
            //1) VERIFICAR QUE NO SE LEAN LOS COMENTARIOS O ESPACIOS VACIOS
            if (VF::verificar_espacio_comentarios(texto, i))
                continue;

            //2) SI EL CARACTER EMPIEZA CON UNA "COMILLA" VERIFICAR SI SE TRATA
            //DE UNA CADENA CONSTANTE
            if (texto[i] == '"')
            {
                std::string auxiliar; //la variable auxiliar almacena las sub cadenas

                //si es una cadena constante
                if (VF::verificador_cadena_constante(texto, i, auxiliar))
                    //se guarda en la lista de constantes
                    tokensConstantes.push_back(auxiliar);
                else // de lo contrario
                {
                    //se le concatena a la cadena auxiliar la linea actual
                    auxiliar += lineaActual;
                    //finalmente se guarda en la lista de errores
                    lista_errores.push_back(auxiliar);
                }
                continue;
            }

            //3) SI LA CADENA COMIENZA CON UNA LETRA VERIFICAR SI SE TRATA DE UNA PALABRA
            //RESERVADA O UN IDENTIFICADOR DEFINIDO POR EL USUARIO
            if (Sy::isLetter(texto[i]))
            {
                std::string auxiliar; //para las subcadenas

                //"VF::verificar_identificador_reservada" si devuelve true se trata de
                // una palabra reservada ,si retorna false se trata de un identificador
                if (VF::verificar_identificador_reservada(texto, i, auxiliar))
                    tokensReservadas.push_back(auxiliar);
                else
                    tokensIdentificadores.push_back(auxiliar);
                continue;
            }

            //4) SI LA CADENA EMPIEZA CON UN NUMERO VERIFICAR SI SE TRATA DE UN CONSTANTE NUMERICO
            if (Sy::isDigit(texto[i]))
            {
                std::string auxiliar; //para almacenar las subcadenas de texto
                if (VF::verificar_constante_numerico(texto, i, auxiliar))
                    tokensConstantes.push_back(auxiliar);
                else
                {
                    auxiliar += lineaActual;
                    lista_errores.push_back(auxiliar);
                }
                continue;
            }

            //5) SI LA CADENA EMPIEZA CON UN SIMBOLO VERIFICAR SI SE TRATA DE UN OPERADOR
            //RECONOCIDO POR EL LENGUAJE
            if (Sy::isSymbol(texto[i]))
            {
                std::string auxiliar;
                //verificar si se trata de un caracter constante
                if (VF::verificar_caracter(texto, i, auxiliar))
                {
                    tokensConstantes.push_back(auxiliar);
                    continue;
                }
                if (VF::verificar_operador(texto, i, auxiliar))
                    tokensOperadores.push_back(auxiliar);
                else
                {
                    auxiliar += lineaActual;
                    lista_errores.push_back(auxiliar);
                }
                continue;
            }
        }

        //aumenta en uno el contador de linea
        ++count_linea;
    }

    using std::cout;

    printf("\033[33m");
    cout << "******** TOKENS ********\n";
    printf("\033[0m");

    //-----------------------------------------------------------

    printf("\033[36m");
    cout << "--------------------------";
    printf("\033[0m");

    printf("\033[5;32m");
    cout << "\nTOKENS IDENTIFICADORES";
    printf("\033[0m\n");

    printf("\033[36m");
    cout << "--------------------------";
    printf("\033[0m\n");

    printf("\033[31m");
    Tk::imprimirTokens(tokensIdentificadores);
    printf("\033[0m");

    //---------------------------------------------------------

    printf("\033[36m");
    cout << "\n--------------------------";
    printf("\033[0m");

    printf("\033[5;32m");
    cout << "\nTOKENS CONSTANTES";
    printf("\033[0m\n");

    printf("\033[36m");
    cout << "--------------------------";
    printf("\033[0m\n");

    printf("\033[31m");
    Tk::imprimirTokens(tokensConstantes);
    printf("\033[0m");

    //---------------------------------------------------------

    printf("\033[36m");
    cout << "\n--------------------------";
    printf("\033[0m");

    printf("\033[5;32m");
    cout << "\nTOKENS RESERVADAS";
    printf("\033[0m\n");

    printf("\033[36m");
    cout << "--------------------------\n";
    printf("\033[0m\n");

    printf("\033[31m");
    Tk::imprimirTokens(tokensReservadas);
    printf("\033[0m");

    //---------------------------------------------------------

    printf("\033[36m");
    cout << "\n--------------------------";
    printf("\033[0m");

    printf("\033[5;32m");
    cout << "\nTOKENS OPERADORES";
    printf("\033[0m\n");

    printf("\033[36m");
    cout << "--------------------------\n";
    printf("\033[0m\n");

    printf("\033[31m");
    Tk::imprimirTokens(tokensOperadores);
    printf("\033[0m");

    //---------------------------------------------------------

    printf("\033[36m");
    cout << "\n--------------------------";
    printf("\033[0m");

    printf("\033[5;32m");
    cout << "\nERRORES";
    printf("\033[0m\n");

    printf("\033[36m");
    cout << "--------------------------";
    printf("\033[0m\n");

    printf("\033[31m");
    Tk::imprimirErrores(lista_errores);
    printf("\033[0m");

    //---------------------------------------------------------

    archivo.close();
    return 0;
}
