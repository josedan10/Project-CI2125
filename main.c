#include <stdio.h>
#include "headers/menus.h"

void ConsultaCasilla(coordenada){ //(Personaje que la está ocupando y sus detalles, items en el
                                  //suelo, efecto y tiempo restante)
}

int main(){

    int opc, opcinv, opcsist; //opcinv es la seleccion del inventario (8) y opcsist es la del sistema (9)

    //Cada vez que sea turno del jugador humano se desplegará el siguiente menú de opciones:
    do{
		opc = mostrarMenuPrincipal();

        switch(opc){

            case 1: printf("ABCDEFGHIJKLMNOPQRST");
                    printf("ASCII 176"); //default, no asi en comillas

                    break;
            case 2: printf("\n\nIngrese una coordenada: ");
                    scanf("",);

                    ConsultaCasilla(coordenada);

                    break;
            case 3: printf("\n\nIngrese una coordenada: ");
                    break;
            case 4: printf("\n\nIngrese una coordenada: ");
                    break;
            case 5: printf("\n\nIngrese una coordenada: ");
                    break;
            case 6: printf("\n\nIngrese una coordenada: ");
                    break;
            case 7: printf("\n\n*********Fin del turno.**********\n\n");
                    break;
            case 8: do{
                        printf("\n\n1. Recoger item"
                       "\n2. Soltar item"
                       "\n3. Equipar item"
                       "\n4. Consultar tope"
                       "\n5. Volver"
                       "\nSelecciona una opcion: ");
                        scanf("%i", &opcinv);

                        switch(opcinv){

                            case 1: //enum en orden items del piso, especificar y recoger
                                    break;
                            case 2: //elimina tope y tira en casilla
                                    break;
                            case 3: //revisa tope, si es arma(dura) lo equipa, y lo que tenia encima pasa al tope del inventario
                                    break;
                            case 4: //imprime tope inventario
                                    break;
                            case 5: break; //done
                        }
                    } while(opcinv < 1 || opcinv > 5);

                    break;
            case 9: do{
                        printf("\n\n1. Guardar"
                       "\n2. Cargar"
                       "\n3. Volver"
                       "\n4. Salir"
                       "\nSelecciona una opcion: ");
                        scanf("%i", &opcsist);

                        switch(opcsist){

                            case 1: //guardar archivo
                                    break;
                            case 2: //abrir archivo
                                    break;
                            case 3: //listo
                            case 4: break; //done
                        }

                    } while(opcsist < 1 || opcsist > 4);

                    break;
        }
    } while(opc < 1 || opc > 9 || opcinv == 5 || opcsist == 3);

    return 0;
}
