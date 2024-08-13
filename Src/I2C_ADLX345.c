#include"I2C_ADLX345.h"
#include <stdint.h>
char Datos;
uint8_t data_rec[6];
/*Esta funcion lee un registro*/
void ADLX_read_address(uint8_t reg){
	I2C1_byteRead(DEVICE_ADDR,reg,&Datos);
}

/*Esta funcion escribe en byte*/
void ADLX_write(uint8_t reg, char value){

	char data[1];
	data[0] = value;

	I2C1_burstWrite(DEVICE_ADDR,reg,1,data);
}

/*Esta funcion lee los registros de datos (X0,X1) (Y0,Y1) (Z0,Z1)*/
void ADLX_read_values(uint8_t reg){
	I2C1_burstRead(DEVICE_ADDR,reg,6,(char *) data_rec);
}

void ADLX_init(void){
	/*Habilitamos el I2C*/
	I2C_int();

	/*Leer el ID del dispositivo. Esto deberia retornar 0xE5*/
	ADLX_read_address(Id_ADLX_R);

	/*Una vez que hayamos hecho esto, configuraremos los datos para un amplio rango 4g*/
	ADLX_write(DATA_FORMAT_R,FPUR_G);

	/*Una vez que hayamos hecho esto, reiniciaremos todo*/
	ADLX_write(POWER_CTL_R,RESET);

	/*Establecer el bit de medida de control de potencia*/
	ADLX_write(POWER_CTL_R,SET_MEASURE_B);
}


