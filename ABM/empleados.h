
typedef struct{

    int id;
    char name[51];
    char lastName[51];
    float salary;
    int idSector;
    int isEmpty;
}employee;


typedef struct{

    int idSector;
    char descripcionSector[51];
    float totalSalary;
}eSector;

void inicializarEmpleados(employee*,int );
int buscarLibre(employee* empleado, int tam);
int estudiante_baja(employee empleado[], int tam);
int estudiante_buscarID(employee empleado[], int tam, int valorBuscado, int* posicion);
int estudiante_modificar(employee empleado[], int tam);
int getDescripcionSector(eSector* arraySector, int ts, int buscar, char* descripcion);
int estudiante_listar(employee empleado[], int tam, eSector arraySector[], int ts);





