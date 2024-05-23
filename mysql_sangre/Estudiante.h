#pragma once
#include <mysql.h>
#include <iostream>
#include "ConexionBD.h"
#include <string>
#include "Sangre.h"

using namespace std;

class Estudiante {
	//atributos
	
	
public:

	int id = 0;
	int codigo = 0;
	string nombres, apellidos, direccion;
	int telefono = 0;
	string fecha_nacimiento;
	//constructor

public:
	Estudiante() {

	}
	Estudiante(int i, int cod, string nom, string ape, string dir, int tel, string fn) {
		
		id = i;
		codigo = cod;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;
		
	}

	//metodos
	//modificar
	void setId(int i) { id = i; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setFecha_Nacimiento(string fn) { fecha_nacimiento = fn; }
	void setCodigo(int cod) { codigo = cod; }
	void setTelefono(int tel) { telefono = tel; }
	
	//mostrar
	int getId() { return id; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	int getCodigo() { return codigo; }
	int getTelefono() { return telefono; }
	
	void borrar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string ii = to_string(id);
		if (cn.getConectar()) {

			string  borrar = "DELETE FROM estudiantes where id_estudiante = " + ii + "";
				
			const char* i = borrar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Eliminacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Conectado a la base de datos" << endl;
			string c = to_string(codigo);
			string t = to_string(telefono);
			string insert = "INSERT INTO estudiantes(codigo, nombres, apellidos, direccion, telefono, fecha_nacimiento) VALUES("+ c +",'" + nombres +"','" + apellidos + "', '" + direccion + "',"+ t +", '" + fecha_nacimiento + "');";
			
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso exitoso...." << endl;
			}
			else {
				cout << "XXX ERROR AL INGRESAR XXX" << endl;
			}
		}
		else {
			cout << "XXX Error en la conexion XXX" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		
		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Conectado a la base de datos" << endl;

			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "-------------------------------------Estudiantes----------------------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[0] << endl;
				}
			}
			else {
				cout << "XXX ERROR AL CONSULTAR XXX" << endl;

			}
		}
		else {

			cout << "XXX Error en la conexion XXX" << endl;
		}

		cn.cerrar_conexion();

	}

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();

		cn.abrir_conexion();
		string c = to_string(codigo);
		string t = to_string(telefono);
		string ii = to_string(id);
		if (cn.getConectar()) {
			string  actualizar = "update estudiantes set codigo = " + c + ", nombres ='" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono =" + t + ", fecha_nacimiento='" + fecha_nacimiento + "' where id_estudiante = " + ii + "";
			const char* i = actualizar.c_str();
			// executar el query
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Actualizacion Exitosa ..." << endl;
			}
			else {
				cout << " xxx Error al Ingresar  xxx" << endl;
			}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}

};

