#ifndef _SIMBOLOS_H_
#define _SIMBOLOS_H_



namespace Symbol
{
    //devuelve true si el parametro "digito" es un numero entre 0-9 
    bool isDigit(char digito);
    //devuelve true si el parametro "letter" es una letra entre a-z o A-Z
    bool isLetter(char letter);

    //devuelve true si el parametro simbolo es un caracter diferente de numero,letra o espacio
    bool isSymbol (char simbolo);
}
namespace Sy = Symbol;


#endif