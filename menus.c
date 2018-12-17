#include <stdio.h>
#include <stdlib.h>
#include "headers/menus.h"

void main(){

    int opc, opcinv, opcsist; //opcinv es la seleccion del inventario (8) y opcsist es la del sistema (9)

    //Cada vez que sea turno del jugador se desplegará el siguiente menú de opciones:
    do{
		opc = mostrarMenuPrincipal();

        switch(mostrarMenuPrincipal()){

            case 1: //Imprime tablero

                    break;
            case 2: printf("\n\nIngrese una coordenada: ");
                    //scanf("",); coordenada

                    //ConsultaCasilla(coordenada);

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
                        opcinv = mostrarMenuItems();

                        switch(mostrarMenuItems()){

                            case 1: //enum en orden items del piso, especificar y recoger
                                    break;
                            case 2: //elimina tope y tira en casilla
                                    break;
                            case 3: //revisa tope, si es arma o armadura lo equipa, y lo que tenia encima pasa al tope del inventario
                                    break;
                            case 4: //imprime tope inventario
                                    break;
                            case 5: break; //listo
                        }
                    } while(opcinv < 1 || opcinv > 5);

                    break;

            case 9: do{
                        opcsist = mostrarMenuSistema();

                        switch(mostrarMenuSistema()){

                            case 1: //guardar archivo
                                    break;
                            case 2: //abrir archivo
                                    break;
                            case 3: //listo

                            case 4: break; //listo
                        }

                    } while(opcsist < 1 || opcsist > 4);

                    break;
        }

    } while(opc < 1 || opc > 9 || opcinv == 5 || opcsist == 3);

}
