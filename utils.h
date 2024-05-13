#include "structs.h"
#include "gotoxy.h"

vector<Cita> citas;
User currentUser;

vector<string> mainMenuOptions = {"Crear cita", "Buscar Cita", "Modificar cita", "Eliminar cita","Imprimir cita", "Salir"};

// Validacion de datos
bool validateUser(User currentUser);

void login();
void crearCita();
void buscarCita();
void mostrarCita(int id);
void imprimirCita();
string getFechaActual();
void mainMenu(vector<string> menuOptions, User currentUser);

// TODO
void modificarCita(){}
void eliminarCita(){}


// Definición de funciones

bool validateUser(User currentUser) {
  ifstream file("users.txt");
  string line;

  if(!file.is_open()) {
    cout << "No se pudo abrir el archivo." << endl;
    return false;
  }

  while(getline(file, line)) {
    size_t pos = line.find(":");
    string user = line.substr(0, pos);
    string pass = line.substr(pos + 1);

    if(user == currentUser.username && pass == currentUser.password) {
      file.close();
      return true;
    }
  }
  return false;
}

void login() {
control:
  system("cls");
  gotoxy(40, 5);
  cout << "Username: ";
  getline(cin, currentUser.username);
  gotoxy(40, 6);
  cout << "Password: ";
  getline(cin, currentUser.password);

  if(validateUser(currentUser)) {
    mainMenu(mainMenuOptions, currentUser);
  }else {
    gotoxy(40, 7);
    color(4);
    cout << "Usuario o contrasenha incorrectos." << endl;
    color(7);
    system("pause");
    goto control;
  }
}

void mainMenu(vector<string> menuOptions, User currentUser) {
    bool repeat = true;
    int opt = 1; // Opción seleccionada
    const int numOptions = menuOptions.size();
    
    do {
        system("cls");
        gotoxy(92, 1);
        color(3);
        cout << "User: " << currentUser.username << endl;
        color(7);
        gotoxy(50, 2);
        cout << "*****************************************************" << endl;
        gotoxy(50, 3);
        cout << "*                                                   *" << endl; 
        gotoxy(50, 4);
        cout << "*     GESTION DE CITAS - CLINICA COLITA DE RANA     *" << endl;
        gotoxy(50, 5);
        cout << "*                                                   *" << endl; 
        gotoxy(50, 6);
        cout << "*  RUC: 20131257750                                 *" << endl; 
        gotoxy(50, 7);
        cout << "*  SEDE: San Borja - Lima                           *" << endl; 
        gotoxy(50,8);
        cout << "*  Telefono: 123456789                              *" << endl;
        gotoxy(50,9);
        cout << "*  Correo: pepito123@gmail.com                      *" << endl;
        gotoxy(50,10);
        cout << "*  Direccion: Av. San Borja Sur 123 Lima, Peru      *" << endl;
        gotoxy(50, 11);
        cout << "*  Horario de atencion: Todos los dias 8:00 - 18:00 *" << endl;
        gotoxy(50, 12);
        cout << "*                                                   *" << endl; 
        gotoxy(50, 13);
        cout << "*****************************************************" << endl;

        for (int i = 0; i < numOptions; ++i) {
            if (i == opt - 1) {
                color(2);
                gotoxy(55, 15 + 2 * i);
                cout << "=>";
                color(2);
                gotoxy(57, 15 + 2 * i);
                cout << menuOptions[i] << endl;
                color(7);
            } else {
                gotoxy(57, 15 + 2 * i);
                cout << "   " << menuOptions[i] << endl;
            }
        }
        
        // Capturar la entrada del teclado
        char input = _getch();
        switch(input) {
            case 72: // Flecha arriba
                opt = (opt == 1) ? numOptions : opt - 1;
                break;
            case 80: // Flecha abajo
                opt = (opt == numOptions) ? 1 : opt + 1;
                break;
            case 13: // Tecla Enter
                cin.ignore(); // Limpia el búfer después de usar cin
                switch(opt) {
                    case 1:
                        crearCita();
                        break;
                    case 2:
                        buscarCita();
                        break;
                    case 3:
                        modificarCita();
                        break;
                    case 4:
                        eliminarCita();
                        break;
                    case 5:
                        imprimirCita();
                        break;
                    case 6:
                        cout << "Salir" << endl;
                        repeat = false;
                        break;
                }
                break;
        }
    } while (repeat);
}
void crearCita() {
    Cita cita;
    system("cls");

    gotoxy(50, 2);
    cout << "*****************************************************" << endl;
    gotoxy(50, 3);
    cout << "Nombre del paciente: ";
    getline(cin, cita.paciente.nombre);

    gotoxy(50, 4);
    cout << "Apellido del paciente: ";
    getline(cin, cita.paciente.apellido);

    gotoxy(50, 5);
    cout << "Ingrese edad del paciente: ";
    cin >> cita.paciente.edad;

    gotoxy(50, 6);
    cout << "DNI del paciente: ";
    cin >> cita.paciente.dni;
    cin.ignore();

    gotoxy(50, 7);
    cout << "Telefono del paciente: ";
    getline(cin, cita.paciente.telefono);

    gotoxy(50, 8);
    cout << "Correo del paciente: ";
    getline(cin, cita.paciente.correoPaciente);

    gotoxy(50, 9);
    cout << "Especialidad: ";
    getline(cin, cita.paciente.especialidad);

    gotoxy(50, 10);
    cout << "Medico asignado: ";
    getline(cin, cita.paciente.medico);

    gotoxy(50, 11);
    cout << "El paciente cuenta con SIS? (1: Si, 0: No): ";
    cin >> cita.paciente.SIS;
    cin.ignore();

    gotoxy(50, 12);
    cout << "Motivo de consulta: ";
    getline(cin, cita.descripcion);

    gotoxy(50, 13);
    cout << "Fecha a programar (dd/mm/yyyy): ";
    cin >> cita.fecha.dia >> cita.fecha.mes >> cita.fecha.anio;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpia el búfer después de usar cin

    gotoxy(50, 14);
    cout << "Hora (hh:mm): ";
    cin >> cita.fecha.hora.hora >> cita.fecha.hora.minuto;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpia el búfer después de usar cin

    gotoxy(50, 15);
    cout << "Asigne un ID a la cita: ";
    cin >> cita.id;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpia el búfer después de usar cin

    citas.push_back(cita);
    gotoxy(50, 16);
    cout << "Cita creada exitosamente." << endl;
    system("pause");
}

void mostrarCita(int id){
  system("cls");
  for (int i = 0; i < citas.size(); ++i) {
    if (citas[i].id == id) {
      gotoxy(60, 3);
      color(3);
      cout << "TICKET DE CITA\n";
      color(7);
      gotoxy(40, 4);
      cout << "---------------------------------------------------------------------"<< endl;
      gotoxy(47, 5);
      cout << "Centro de salud Colita de Rana\n";
      gotoxy(47, 6);
      cout << "RUC: 20131257750\n";
      gotoxy(47, 7);
      cout << "Av. San Borja Sur 123 Lima, Peru\n";
      gotoxy(47, 8);
      cout << "Telefono: 123456789\n";
      gotoxy(47,9);
      cout << "Correo: pepito123@gmail.com\n" << endl;
      gotoxy(47,10);
      cout << "Direccion: Av. San Borja Sur 123 Lima, Peru\n" << endl;
      gotoxy(47, 11);
      cout << "Horario de atencion: Todos los dias 8:00 - 18:00\n" << endl;
      gotoxy(40, 12);
      cout << "---------------------------------------------------------------------"<< endl;
      gotoxy(47, 13);
      cout << "Hora programada: " << citas[i].fecha.hora.hora << ":" << citas[i].fecha.hora.minuto << endl;
      gotoxy(47, 14);
      cout << "Nombre del paciente: " << citas[i].paciente.nombre << " " << citas[i].paciente.apellido << endl;
      gotoxy(47, 15);
      cout << "Edad del paciente: " << citas[i].paciente.edad << endl;
      gotoxy(47, 16);
      cout << "Telefono del paciente: " << citas[i].paciente.telefono << endl;
      gotoxy(47, 17);
      cout << "Correo del paciente: " << citas[i].paciente.correoPaciente << endl;
      gotoxy(47, 18);
      cout << "Especialidad: " << citas[i].paciente.especialidad << endl;
      gotoxy(47, 19);
      cout << "Medico asignado: " << citas[i].paciente.medico << endl;
      gotoxy(47, 20);
      cout << "Descripcion de la cita: " << citas[i].descripcion << endl;
      gotoxy(47, 21);
      cout << "Fecha programada: " << citas[i].fecha.dia << "/" << citas[i].fecha.mes << "/" << citas[i].fecha.anio << endl;
      gotoxy(47, 22);

      gotoxy(85, 23);
      cout << "SIS Activo:";
      if (citas[i].paciente.SIS) {
        color(2);
        cout << "Si\n";
        color(7);
      } else {
        color(4);
        cout << "No\n";
        color(7);
      }
    }
  }
  system("pause");
}

void buscarCita(){
  system("cls");
  int id;
  gotoxy(45, 15);
  cout << "Ingrese el ID de la cita a buscar";
  gotoxy(whereX(), whereY());
  color(3);
  cout << "=>";
  color(7);
  cin >> id;
  mostrarCita(id);
  system("pause");
}

void verCitas() {
    system("cls");
    for (int i = 0; i < citas.size(); ++i) {
        cout << "Cita " << i + 1 << endl;
        cout << "Nombre: " << citas[i].paciente.nombre << " " << citas[i].paciente.apellido << endl;
        cout << "Telefono: " << citas[i].paciente.telefono << endl;
        cout << "Correo: " << citas[i].paciente.correoPaciente << endl;
        cout << "Especialidad: " << citas[i].paciente.especialidad << endl;
        cout << "Medico: " << citas[i].paciente.medico << endl;
        cout << "Descripcion: " << citas[i].descripcion << endl;
        cout << "Fecha Programada: " << citas[i].fecha.dia << "/" << citas[i].fecha.mes << "/" << citas[i].fecha.anio << endl;
        cout << "Hora Programada: " << citas[i].fecha.hora.hora << ":" << citas[i].fecha.hora.minuto << endl;
        cout << "ID: " << citas[i].id << endl;
        cout << endl;
    }
    system("pause");
}

string getFechaActual() {
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);

    stringstream ss;

    ss << put_time(localtime(&now_c), "%Y-%m-%d %X");
    return ss.str();
}

void imprimirCita(){
  ofstream archivo("citas.txt", ios::app);
  system("cls");
  int id;
  cout << "Ingrese el ID de la cita a imprimir: ";
  cin >> id;

  for (int i = 0; i < citas.size(); ++i) {
    if (citas[i].id == id) {
      gotoxy(60, 3);
      color(3);
      archivo << "TICKET DE CITA\n";
      color(7);
      gotoxy(40, 4);
      archivo << "---------------------------------------------------------------------"<< endl;
      gotoxy(47, 5);
      archivo << "Centro de salud Colita de Rana\n";
      gotoxy(47, 6);
      archivo<< "RUC: 20131257750\n";
      gotoxy(47, 7);
      archivo << "Av. San Borja Sur 123 Lima, Peru\n";
      gotoxy(47, 8);
      archivo<< "Telefono: 123456789\n";
      gotoxy(47,9);
      archivo << "Correo: pepito123@gmail.com\n" << endl;
      gotoxy(47,10);
      archivo << "Direccion: Av. San Borja Sur 123 Lima, Peru\n" << endl;
      gotoxy(47, 11);
      archivo << "Horario de atencion: Todos los dias 8:00 - 18:00\n" << endl;
      gotoxy(40, 12);
      archivo << "---------------------------------------------------------------------"<< endl;
      gotoxy(47, 13);
      archivo<< "Hora programada: " << citas[i].fecha.hora.hora << ":" << citas[i].fecha.hora.minuto << endl;
      gotoxy(47, 14);
      archivo<< "Nombre: " << citas[i].paciente.nombre << " " << citas[i].paciente.apellido << endl;
      gotoxy(47, 15);
      archivo<< "Telefono: " << citas[i].paciente.telefono << endl;
      gotoxy(47, 16);
      archivo << "Correo: " << citas[i].paciente.correoPaciente << endl;
      gotoxy(47, 17);
      archivo << "Especialidad: " << citas[i].paciente.especialidad << endl;
      gotoxy(47, 18);
      archivo << "Medico asignado: " << citas[i].paciente.medico << endl;
      gotoxy(47, 19);
      archivo<< "Descripcion: " << citas[i].descripcion << endl;
      gotoxy(47, 20);
      archivo<< "Fecha programada: " << citas[i].fecha.dia << "/" << citas[i].fecha.mes << "/" << citas[i].fecha.anio << endl;
      break;
    }
  }
  archivo.close();
  cout << "Cita impresa" << endl;
  system("pause");
}
