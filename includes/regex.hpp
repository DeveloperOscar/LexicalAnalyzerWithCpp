#ifndef _REGEX_H_
#define _REGEX_H_

#include <iostream>
namespace Regex
{
    //devuelve true si es la cadena se reconoce como una variable
    bool isVariable(std::string cadena);
    //devuelve true si es la cadena se reconoce como una palabra reservada
    bool isReserved(std::string cadena);
    //devuelve true si es la cadena se reconoce como una variable
    bool isOperator(std::string cadena);
    //devuelve true si es la cadena se reconoce como una variable
    bool isCostante(std::string cadena);
    //devuelve true si es la cadena se reconoce como una variable
    bool isConstanteLiteral(std::string cadena);
}

#endif

