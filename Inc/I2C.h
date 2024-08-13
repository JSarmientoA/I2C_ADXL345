#ifndef I2C_H_
#define I2C_H_

void I2C_int(void);
void I2C1_byteRead(char DirEsclavo,char DirMemoriaEsclavo,char* Datos);
void I2C1_burstRead(char DirEsclavo,char DirMemoriaEsclavo,int n,char* Datos);
void I2C1_burstWrite(char DirEsclavo,char DirMemoriaEsclavo,int n,char* Datos);

#endif /* I2C_H_ */
