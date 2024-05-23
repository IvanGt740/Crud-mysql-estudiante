#include <iostream>
#include <mysql.h>
#include "Estudiante.h"
#include "Sangre.h"

using namespace std;
char respuesta;

int main() {

	/*MYSQL* conectar;
	MYSQL_ROW fila;
	MYSQL_RES* resultado;

	conectar = mysql_init(0);
	conectar = mysql_real_connect(conectar, "localhost", "root", "52935159", "db_estudiante", 3306, NULL, 0);
	if (conectar) {
		cout << "Conexion exitosa...." << endl;

		int codigo;
		string nombres;
		string apellidos;
		string direccion;
		int telefono;
		string fecha_nacimiento;

		cout << "Ingrese el tipo de sangre: ";
		cin >> tipo_sangre;
		string insert = "INSERT INTO tipo_sangre(tipo_sangre) VALUES('" + tipo_sangre + "')";
	
		const char* i = insert.c_str();
		q_estado = mysql_query(conectar, i);
		if (!q_estado) {
			cout << "Ingreso exitoso...." << endl;
		}
		else {
			cout << "XXX ERROR AL INGRESAR XXX" << endl;
		
		}
		

		string consulta = "select * from estudiantes";
		const char* c = consulta.c_str();
		q_estado = mysql_query(conectar, c);

		if (!q_estado) {
			resultado = mysql_store_result(conectar);
			while (fila = mysql_fetch_row(resultado) ){
				cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << endl;
			}
		}
		else {
			cout << "XXX ERROR AL CONSULTAR XXX" << endl;
		}
	}
	else {
		cout << "Error en la conexion" << endl;
	}
	*/
	
	string nombres, apellidos, direccion, fecha_nacimiento;
	int codigo = 0; 

	int telefono=0;
	int id = 0;

	cout << "Desea ingresar un nuevo estudiante? (S/N):" << endl;
	cin >> respuesta;
	cin.ignore();

	if ((respuesta == 's') || (respuesta == 'S')) {

		cout << "Ingrese codigo: ";
		cin >> codigo;
		cin.ignore();

		cout << "Ingrese nombres: ";
		getline(cin, nombres);

		cout << "Ingrese apellidos: ";
		getline(cin, apellidos);

		cout << "Ingrese direccion: ";
		getline(cin, direccion);

		cout << "Ingrese telefono: ";
		cin >> telefono;
		cin.ignore();

		cout << "Ingrese fecha de nacimiento: ";
		getline(cin, fecha_nacimiento);




	}

	
	Estudiante estudiante = Estudiante(id, codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento);
	
	
	estudiante.crear();
	estudiante.leer();
	
	cout << "Desea eliminar a un estudiante? (S/N)" << endl;

	cin >> respuesta;
	cin.ignore();

	if ((respuesta == 'S') || (respuesta == 's')) {

		cout << "Ingrese el ID a eliminar: ";
		cin >> id;
		cin.ignore();

		estudiante.setId(id);

		estudiante.borrar();
		estudiante.actualizar();
		estudiante.leer();
	}


	system("pause");
	return 0;

}