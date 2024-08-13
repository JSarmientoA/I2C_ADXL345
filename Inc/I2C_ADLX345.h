#ifndef I2C_ADLX345_H_
#define I2C_ADLX345_H_

#include <stdint.h>
#include"I2C.h"

#define Id_ADLX_R			(0x00) // Id del dispositivo Id_ADLX_R
#define DEVICE_ADDR		    (0x53) // Direccion del dipositivo
#define DATA_FORMAT_R		(0x31) // Formato de datos
#define	POWER_CTL_R			(0x2D) // Control de energia
#define DTA_START_ADDR		(0x32) // Inicio de datos
#define FPUR_G				(0x01)
#define RESET				(0x00)
#define SET_MEASURE_B		(0x08)

/*#define ADDR_STAR_R			(0x02)

#define XYZ_DATA_CFG_R		(0x0E)

#define CTRL_REG2_R     	(0x2B)

#define Four_G				(0x01)
#define RESET				(1U<<6)

#define CTRL_REG1_R			(0x2A)

#define SET_STANDBY_B		(0x01)
*/


void ADLX_init(void);
void ADLX_read_values(uint8_t reg);
//void ADLX_write(uint8_t reg, char value);
//void ADLX_read_address(uint8_t reg);

#endif /* I2C_ADLX345_H_ */
