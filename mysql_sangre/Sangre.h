#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include <string>


class Sangre
{
public:
	string tipo_sangre;
	
	Sangre() {
	}
	Sangre(string sang) {
		tipo_sangre = sang;
	}

};

