typedef struct
{
    int dni;
    char nombre[50];
    int edad;
    int estado;
} EPersona;

void iniPer(EPersona[], int);

int buscarLibre(EPersona[], int);

void mostrarPersona(EPersona);

EPersona crearPersona(int, char[], int);

void ordPer(EPersona[], int);

void mostrarLista(EPersona[], int);

void graEda(int,int,int);
