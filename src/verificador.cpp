#include "verificador.hpp"
#include "regex.hpp"
#include "simbolos.hpp"
#include <fstream>
#include <vector>
namespace Verificar
{
    bool verificar_espacio_comentarios(std::string texto, int &i)
    {
        //si el caracter en la posicion i se trata de un espacio en blanco 
        if (texto[i] == ' ')
        {
            ++i;
            return true; //retornara un true
        }
        //si se trata de un "//"
        if (texto[i] == '/')
        {
            if (texto[i + 1] == '/')
            {
                i = texto.size();
                return true;
            }
        }
        //si no cumple con ninguno de los dos retornara un false
        return false;
    }

    bool verificar_identificador_reservada(std::string texto, int &i, std::string &auxiliar)
    {
        //mientras no sea un simbolo o no sea un espacio en blanco
        while (!(Sy::isSymbol(texto[i]) || texto[i] == ' ')) //parada
        {
            //agregaremos caracter a caracter al auxiliar 
            auxiliar.push_back(texto[i]);
            ++i;
        }

        //una vez auxiliar este completo entonces procedemos a evaluarlo
        //si se trata de una palabra reservada o en su defecto una variable
        if (Regex::isReserved(auxiliar))
            return true;
        if (Regex::isVariable(auxiliar))
            return false;
        return false;
    }

    bool verificar_constante_numerico(std::string texto, int &i, std::string &auxiliar)
    {
        /*los numero decimales tienes un solo punto en su estructura es por ello
        que crearemos la variable contador punto como medida de restriccion
        */
        int contadorPunto{};

    etiqueta://label que sera necesario para la instruccion "goto"
        //mientras no sea un simbolo o no sea un espacio en blaco
        while (!(Sy::isSymbol(texto[i]) || texto[i] == ' ')) //parada
        {
            //agregaremos caracter a caracer a la cadena auxiliar
            auxiliar.push_back(texto[i]);
            ++i;
        }

        //si el contador es mayor a 0 y texto en el indice "i" es un punto
        // y ademas el contador de puntos sea 0 entonces:
        if (i > 0 && texto[i] == '.' && contadorPunto == 0)
        {
            //agregaremos dicho punto a la cadena auxiliar
            auxiliar.push_back(texto[i]);
            ++i;
            ++contadorPunto;//incrementamos en contador de puntos
            goto etiqueta;//y regresanmos nuevamente seguir agregando elementos 
                          //a la cadena auxliar
        }

        if (Regex::isCostante(auxiliar))
            return true;
        else
            return false;
    }


    bool verificar_operador(std::string texto, int &i, std::string &auxiliar)
    {
        //la cadena operador servira par almacenar el primer simbolo
        std::string operador;
        operador.push_back(texto[i]);//almacenando el simbolo en operador

        //if el siguiente caracter es un simbolo y el la cadena "operador"
        // no esta reconocido como operador del lenguaje de programacion entonces:
        if (Sy::isSymbol(texto[i + 1]) && (!Regex::isOperator(operador)))
        {
            //almacenamos ambos simbolos al auxiliar 
            auxiliar.push_back(texto[i]);
            auxiliar.push_back(texto[i + 1]);
            i += 2;
        }
        else//de lo contrario solo se almacena el primero
        {
            auxiliar.push_back(texto[i]);
            ++i;
        }
        //evaluaremos si el auxiliar esta reconocido como operador del lenguaje de programacion
        if (Regex::isOperator(auxiliar))
            return true;
        else
            return false;
    }

    bool verificador_cadena_constante(std::string texto, int &i, std::string &auxiliar)
    {
        auxiliar.push_back(texto[i]);
        ++i;
        //mientras no sea el final de la cadena o se encuentre un operador comilla
        while (i < (texto.size() - 1))
        {
            //agregar caracter a caracter a la cadena auxiliar
            auxiliar.push_back(texto[i]);
            //si texto en la posicion i es una comilla saldra del bucle
            if (texto[i] == '"')
            {
                ++i;
                break;
            }
            ++i;
        }
        //se evalua si la cadena auxuiliar almacena una constante literal o no
        if (Regex::isConstanteLiteral(auxiliar))
            return true; //retorna verdadero de ser reconocido como constante cadena
        else
            return false; //retorna falso si no lo es
    }


    bool verificar_caracter(std::string texto, int &i,std::string &auxiliar)
    {
        //se evalua los caracteres constantes que empiezen con comilla simple " ' "
        if(texto[i] == '\'')
        {
            if(texto[i+2] == '\'')
            {
                for(size_t j = 0; j <= 2;++j)
                    auxiliar.push_back(texto[i+j]);
                i+=3;
                return true;
            }   
        }
        return false;
    }


} // namespace Verificar
