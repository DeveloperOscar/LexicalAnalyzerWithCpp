#include "regex.hpp"
#include "simbolos.hpp"

namespace Regex 
{
    bool isVariable(std::string cadena)
    {
        int estado{};   //para recorrer los estados del automata
        int iterator{}; //para iterar en la cadena de caracteres
        
        while (true)
        {
            switch (estado)
            {
            case 0://ESTADO O
                //SI ES UNA LETRA Ó UN _ 
                if (Sy::isLetter(cadena[iterator]) || (cadena[iterator] == '_'))
                {
                    estado = 1;//SE TRASLADA AL ESTADO 1
                    ++iterator;
                }
                else
                    return false;
                break;
            case 1:
                //el estado 1 representa la estrella de kleen 
                if (Sy::isDigit(cadena[iterator]) || Sy::isLetter(cadena[iterator]) || cadena[iterator] == '_')
                    ++iterator;
                else
                    estado = 2;
                break;
            case 2:
                //el final de una cadena string siempre es el 0
                //por lo tanto si eso sucede se interpreta que el
                //automata reconoció la cadena
                //de lo contrario pudo aver encontrado otro operador invalido
                if (cadena[iterator] == 0)
                    return true;
                else
                    return false;
            }
        }
    }

    bool isReserved(std::string cadena)
    {
        //se crea un arreglo de cadenas con la mayoria de palabras reservadas 
        std::string reservadas[100]
        {
            "auto","bool","break","case","char","class","const","continue","dafault","delete",
            "do","double","endl","else","enum","extern","false","float","for","friend","goto","if","include","inline",
            "int","iostream","long","main","mutable","namespace","new","noexcept","nullptr","operator","private",
            "protected","public","return","short","signed","static_cast","std","string","struct","switch","template",
            "this","true","try","typedef","union","unsigned","using","virtual","void","while"
        };

        //se evalua uno por uno si la cadena corresponde a un elemento del arreglo 
        for(size_t i = 0;i < 100;++i)
        {
            if(cadena == reservadas[i])
                return true;
        }
        return false;
    }


    bool isOperator(std::string operador)
    {
        //el mismo funcionamiento que el reconocedor de las palabras reservadas
        std::string operadores[50]{
            "+","-","*","/","%","::",";","<<",">>","&&","||","==","=",">","<","!",
            "(",")","{","}",".","->",",","++","--","#","()","{}","/*","*/"
        };

        for(size_t i = 0;i < 50;++i)
        {
            if(operador == operadores[i])
                return true;
        }
        return false;
    }

    bool isCostante(std::string cadena)
    {
        //se evalua caracter por caracter si se trata
        //de puros digitos
        //si alguno no es un digito retornara un false
        for(int i = 0;i < cadena.size();++i)
        {
            //el punto es especial 
            //se le hace la condicion siguiente para que no cause un problema
            //al reconocedor de constantes
            //en otras palabras lo ignora con el fin de reconocer decimales
            //si el caracter actual es un punto Y el siguiente es un numero
            if(cadena[i] == '.' && isdigit(cadena[i+1])) continue;

            if(!Sy::isDigit(cadena[i]))
                return false;
        }
        return true;
    }

    bool isConstanteLiteral(std::string cadena)
    {
        //almacenando los caracteres  iniciales y finales de la cadena
        char caracterInicial = cadena[0];
        char caraceterFinal =  cadena[cadena.size()-1];

        //la expresion se evalua como true si tanto el caracterInicial como el final
        //sean comillas
        return (caracterInicial == '"' && caraceterFinal == '"');
    }


}
