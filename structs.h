#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

struct User {
  string username;
  string password;
};

// Estructuras anidadas necesarias para la creacion de una nueva cita
struct Hora {
  int hora;
  int minuto;
};

struct Fecha {
  int dia;
  int mes;
  int anio;
  Hora hora;
};

// TODO: Agregar enfermedades al historial clinico
/*
struct historialClinico {
  set<string> enfermedades;
  Fecha fecha;
  int id;
};
*/

struct Paciente {
  string nombre;
  string apellido;
  int edad;
  string telefono;
  int dni;
  string correoPaciente;
  string especialidad;
  string medico;

  // TODO: Agregar historial clinico
  int numHistoriaClinica;
  bool SIS;

};

struct Cita {
  Paciente paciente;
  string descripcion;
  Fecha fecha;
  int id;
};
