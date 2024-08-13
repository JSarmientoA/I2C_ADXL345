#include <stdint.h>
#include <stdio.h> // Para poder usar printf()
#include "stm32f4xx.h"
#include "I2C_ADLX345.h"

int16_t x,y,z;
double	xg,yg,zg;
extern uint8_t data_rec[6];
//const float FOUR_G_SCALE_FACTOR = 0.0078;
int main(void){

 	ADLX_init();
	while(1){
		 ADLX_read_values(DTA_START_ADDR);

		/*Vamos a tomar el índice cero y luego realizar una operación or con el índice uno desplazado . Esto se realiza
		 * para X,Y y Z*/
		x = ((data_rec[1]<<8)|data_rec[0]);// Donde los valores de X0 empiezan en 0, y X1 empiezan en 1
		y = ((data_rec[3]<<8)|data_rec[2]);// Donde los valores de Y0 empiezan en 2, y Y1 empiezan en 3
		z = ((data_rec[5]<<8)|data_rec[4]);// Donde los valores de Z0 empiezan en 4, y Z1 empiezan en 5

		xg = (x*0.0078);
		yg = (y*0.0078);
		zg = (z*0.0078);
	}
}
