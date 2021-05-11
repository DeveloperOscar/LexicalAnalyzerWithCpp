#include "simbolos.hpp"
#include <string>
#include <iostream>
namespace Symbol
{
    bool isDigit(char digito)
    {
        if(digito == '0')//descartamos que no se trate del caracter 0
            return true;

        int dig = atoi(&digito);// convertiremos a entero par poder evaluarlo
        return ((dig > 0) && (dig <= 9));//si cumple dichas condiciones retornara true
    }

    bool isLetter(char letter)
    {
        //cuando convertimos a entero rescatamos su codigo ascci
        int letra = static_cast<int>(letter);//convertimos a entero para su evaluacion

        //evaluaremos con los codigo ascci 
        //letras minusculas  van de : 65 - 90
        //letras mayuscula van de : 97 - 122
        return ((letra >= 65 && letra <= 90) || (letra >= 97 && letra <= 122));
    }

    bool isSymbol(char simbolo)
    {
        //si no es digito ó no es letra ó no es espacio en blanco ó no es un _ 
        //entonces es un simbolo
        if(!(isDigit(simbolo) || isLetter(simbolo) || simbolo == ' ' || simbolo == '_'))
            return true;
        return false;
    }
}