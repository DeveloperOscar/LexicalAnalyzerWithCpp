#include "tokens.hpp"

namespace token
{
    void imprimirTokens(std::vector<std::string> cadenas)
    {
        //recorremos todo el arreglo y  mostramos  cadena a cadena
        for (int i = 0; i < cadenas.size(); ++i)
            std::cout << cadenas[i] << ' ';
        std::cout << '\n';
    }

    void imprimirErrores(std::vector<std::string> cadenas)
    {
        //recorremos el vector y mostramos uno a uno la cadena
        if(cadenas.size() ==  0)
            std::cout << "No se encontro ningun error,... crack :)";
        for (int i = 0; i < cadenas.size(); ++i)
            std::cout << cadenas[i] << '\n';
    }
}