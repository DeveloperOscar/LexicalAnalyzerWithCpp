#ifndef _VERIFICADOR_H_
#define _VERIFICADOR_H_
#include <iostream>

namespace Verificar
{
    //prototipos de funcion
    bool verificar_espacio_comentarios(std::string texto, int &i);
    bool verificar_identificador_reservada(std::string texto, int &i,std::string &auxiliar);
    bool verificar_constante_numerico(std::string texto, int &i,std::string &auxliar);
    bool verificar_operador(std::string texto, int &i,std::string &auxiliar);
    bool verificador_cadena_constante(std::string texto, int &i,std::string &auxiliar);
    bool verificar_caracter(std::string texto, int &i,std::string &auxiliar);
} // namespace Verificar
namespace VF = Verificar;//alias de espacio de nombres




#endif
