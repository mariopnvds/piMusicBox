 /* *
 * Descripcion: Programa que simula un juguete musical que reproduce melodias mediante su implementacion en una RaspberryPi
 * Autores: Mario Penavades Suárez y Alejandro Marcos Arias
 * Version: 5.0
 * Fecha de entrega: 17/5/2018
 * Grupo: VC-20
 * */

/* Includes ------------------------------------------------------------------*/
#include "piMusicBox_1.h"

/* Variables ------------------------------------------------------------------*/
int frecuenciaDespacito[160] = {0,1175,1109,988,740,740,740,740,740,740,988,988,988,988,880,988,784,0,784,784,784,784,784,988,988,988,988,1109,1175,880,0,880,880,880,880,880,1175,1175,1175,1175,1318,1318,1109,0,1175,1109,988,740,740,740,740,740,740,988,988,988,988,880,988,784,0,784,784,784,784,784,988,988,988,988,1109,1175,880,0,880,880,880,880,880,1175,1175,1175,1175,1318,1318,1109,0,1480,1318,1480,1318,1480,1318,1480,1318,1480,1318,1480,1568,1568,1175,0,1175,1568,1568,1568,0,1568,1760,1568,1480,0,1480,1480,1480,1760,1568,1480,1318,659,659,659,659,659,659,659,659,554,587,1480,1318,1480,1318,1480,1318,1480,1318,1480,1318,1480,1568,1568,1175,0,1175,1568,1568,1568,1568,1760,1568,1480,0,1480,1480,1480,1760,1568,1480,1318};
int tiempoDespacito[160] = {1200,600,600,300,300,150,150,150,150,150,150,150,150,300,150,300,343,112,150,150,150,150,150,150,150,150,300,150,300,300,150,150,150,150,150,150,150,150,150,300,150,300,800,300,600,600,300,300,150,150,150,150,150,150,150,150,300,150,300,343,112,150,150,150,150,150,150,150,150,300,150,300,300,150,150,150,150,150,150,150,150,150,300,150,300,450,1800,150,150,150,150,300,150,300,150,150,150,300,150,300,450,450,300,150,150,225,75,150,150,300,450,800,150,150,300,150,150,300,450,150,150,150,150,150,150,150,150,300,300,150,150,150,150,150,150,450,150,150,150,300,150,300,450,450,300,150,150,150,300,150,300,450,800,150,150,300,150,150,300,450};
int frecuenciaGOT[518] = {1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,1175,0,1397,0,932,0,1244,0,1175,0,1397,0,932,0,1244,0,1175,0,1046,0,831,0,698,0,523,0,349,0,784,0,523,0,523,0,587,0,622,0,698,0,784,0,523,0,622,0,698,0,784,0,523,0,622,0,698,0,587,0,698,0,466,0,622,0,587,0,698,0,466,0,622,0,587,0,523,0,523,0,587,0,622,0,698,0,784,0,523,0,622,0,698,0,784,0,523,0,622,0,698,0,587,0,698,0,466,0,622,0,587,0,698,0,466,0,622,0,587,0,523,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1175,0,587,0,622,0,587,0,523,0,587,0,784,0,880,0,932,0,1046,0,1175,0,0,1397,0,0,932,0,0,1244,0,0,1175,0,0,1397,0,0,932,0,0,1244,0,0,1175,0,0,1046,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1175,0,880,0,784,0,932,0,1244,0,0,1397,0,0,932,0,0,1175,0,0,1244,0,0,1175,0,0,932,0,0,1046,0,0,2093,0,622,0,831,0,932,0,1046,0,622,0,831,0,1046,0,0,1865,0,622,0,784,0,831,0,932,0,622,0,784,0,932,0,0,1661,0,523,0,698,0,784,0,831,0,523,0,698,0,831,0,0,1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,0,0,1661,0,1046,0,1175,0,1244,0,831,0,1175,0,1244,0,0,0,0,2489,0,0,0,0,2794,0,0,0,0,3136,0,0,2093,0,622,0,831,0,932,0,1046,0,622,0,831,0,1046,0,0,1865,0,622,0,784,0,831,0,932,0,622,0,784,0,932,0,0,1661,0,523,0,698,0,784,0,831,0,523,0,698,0,831,0,0,1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,0,0,1661,0,1046,0,1175,0,1244,0,831,0,1175,0,1244,0,0,0,0,2489,0,1397,0,0,0,2350,0,0,0,2489,0,0,0,2350,0,0,0,0,2093,0,392,0,415,0,466,0,523,0,392,0,415,0,466,0,523,0,392,0,415,0,466,0,2093,0,1568,0,1661,0,1865,0,2093,0,1568,0,1661,0,1865,0,2093,0,1568,0,1661,0,1865};
int tiempoGOT[518] = {900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1400,1400,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,116,267,28,267,28,267,28,900,89,900,89,1400,89,69,7,69,7,69,7,69,7,900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1800,1800,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,2400,69,7,69,7,69,7,69,7,900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1800,1800,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,2400,3600,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,600,59,600,133,13,150,133,13,150,1200,400,69,7,69,7,69,7,69,7,267,28,400,45,133,13,267,28,267,28,267,28,300,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,900,89,900,133,13,150,133,13,150,1200,1800,3600,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,600,59,600,133,13,150,133,13,150,1200,400,267,28,1200,400,133,13,133,13,150,900,89,900,900,89,900,600,59,600,267,28,300,600,59,600,267,28,300,1200,2400,3600,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,133,13,267,28,267,28,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,150,600,59,133,13,133,13,267,28,267,28,133,13,133,13,150,150,150,900,89,900,900,900,900,89,900,900,900,1200,2400,3600,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,150,600,59,133,13,133,13,267,28,267,28,133,13,133,13,150,150,150,600,212,133,13,150,150,267,28,300,300,400,45,450,450,133,13,150,150,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,267,28,267,28,133,13,2400,116,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,267,28,267,28,133,13,2400};
int frecuenciaTetris[55] = {1319,988,1047,1175,1047,988,880,880,1047,1319,1175,1047,988,988,1047,1175,1319,1047,880,880,0,1175,1397,1760,1568,1397,1319,1047,1319,1175,1047,988,988,1047,1175,1319,1047,880,880,0,659,523,587,494,523,440,415,659,523,587,494,523,659,880,831};
int tiempoTetris[55] = {450,225,225,450,225,225,450,225,225,450,225,225,450,225,225,450,450,450,450,450,675,450,225,450,225,225,675,225,450,225,225,450,225,225,450,450,450,450,450,450,900,900,900,900,900,900,1800,900,900,900,900,450,450,900,1800};
int frecuenciaStarwars[59] = {523,0,523,0,523,0,698,0,1046,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,1760,0,0,784,0,523,0,0,523,0,0,523,0};
int tiempoStarwars[59] = {134,134,134,134,134,134,536,134,536,134,134,134,134,134,134,536,134,402,134,134,429,357,134,134,134,134,536,134,402,134,134,429,357,134,134,134,134,536,134,402,134,134,429,357,134,134,134,429,357,1071,268,67,67,268,67,67,67,67,67};
int frecuenciaMarcha[66]={440,440,440,349,523,440,349,523,400,659,659,659,698,523,415,349,523,440,880,440,440,880,830,784,740,698,740,455,622,587,554,523,466,523,349,784,349,440,523,440,523,659,880,440,440,880,830,784,740,698,740,455,622,587,554,523,466,523,349,415,349,523,440,349,261,440};
int tiempoMarcha[66]={500,500,500,350,150,500,350,150,1000,500,500,500,350,150,500,350,150,1000,500,350,150,500,250,250,125,125,250,250,500,250,250,125,125,250,125,500,375,125,500,375,125,1000,500,350,150,500,250,250,125,125,250,250,500,250,250,125,125,250,250,500,375,125,500,375,125,1000};
volatile int flags = 0;
int count = 0;
static tmr_t* timer;
TipoSistema sistema;
TipoMelodia melodia;
TipoPlayer p_player;
int debounceTime=0;
TipoMelodia melodiaGOT;
TipoMelodia melodiaTetris;
int lcd;

/* Funciones ------------------------------------------------------------------*/
/*
 * @brief Funcion que inicializa los parametros del objeto melodia
 * @param Atributos necesarios para la inicializacion de una melodia
 * @return num_notas numero de notas que posee la melodia
 * @note
 * */
int InicializaMelodia (TipoMelodia *melodia, char *nombre, int *array_frecuencias, int *array_duraciones, int num_notas) {
	int i;
	for(i=0; i<num_notas; i++){
		melodia->duraciones[i]=array_duraciones[i];
		melodia->frecuencias[i]=array_frecuencias[i];
	}
	strcpy(melodia->nombre, nombre);
	melodia->num_notas = num_notas;
	return melodia->num_notas;
}
/* FUNCIONES DE SALIDA O ACTUALIZACION */
/*
 * @brief Funcion que incializa los parametros del objeto player para la maquina de estados
 * @param fsm_t* this maquina de estados
 * @note Se anulan todos los flags para que no haya autolazos y se inicia el timer
 * */
void InicializaPlayer(fsm_t* this){
	TipoPlayer *p_player;
	p_player = (TipoPlayer*)(this->user_data);
	p_player->posicion_nota_actual=0;
	p_player->frecuencia_nota_actual=0;
	p_player->duracion_nota_actual=0;
	/* Bloqueo este mutex para poder modificar los flags */
	piLock(FLAGS_KEY);
	flags &= ~FLAG_PLAYER_START;
	flags &= ~FLAG_NOTA_TIMEOUT;
	flags &= ~FLAG_PLAYER_END;
	flags &= ~FLAG_PLAYER_STOP;
	piUnlock(FLAGS_KEY);
	/* Activacion o inicio del timer */
	tmr_startms(timer, melodia.duraciones[p_player->posicion_nota_actual]);
	softToneCreate(GPIO_PIN_18);
	softToneWrite(GPIO_PIN_18,melodia.frecuencias[p_player->posicion_nota_actual]);
	/* Bloqueo este mutex para poder imprimir por pantalla*/
	piLock(STD_IO_BUFFER_KEY);
	printf("[PLAYER][InicializaPlayer][NOTA %d][FREC %d][DURA %d]\n", p_player->posicion_nota_actual+1, melodia.frecuencias[p_player->posicion_nota_actual],melodia.duraciones[p_player->posicion_nota_actual]);
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
}
/*
 * @brief Funcion que actualiza los parametros del objeto player para la maquina de estados
 * @param fsm_t* this maquina de estados
 * @note Se anulan todos los flags para que no haya autolazos y se actualiza la posicion de las notas
 * */
void ActualizaPlayer(fsm_t* this){
	TipoPlayer *p_player;
	p_player = (TipoPlayer*)(this->user_data);
	p_player->posicion_nota_actual++;
	/* Bloqueo este mutex para poder modificar los flags */
	piLock(FLAGS_KEY);
	flags &= ~FLAG_NOTA_TIMEOUT;
	piUnlock(FLAGS_KEY);
	softToneCreate(GPIO_PIN_18); // MODIFICADO
	softToneWrite(GPIO_PIN_18, melodia.frecuencias[p_player->posicion_nota_actual]); // MODIFICADO
	piLock(STD_IO_BUFFER_KEY);
	/* Bloqueo este mutex para poder imprimir por pantalla*/
	if (p_player->posicion_nota_actual < melodia.num_notas){ // Mientras que la posicion actual sea menor que el numero total de notas
		printf("[PLAYER][ActualizaPlayer][NUEVA NOTA (%d de %d)]\n", p_player->posicion_nota_actual+1, melodia.num_notas);
		fflush(stdout);
	} else { // Si la posicion es justo la ultima nota
		printf("[PLAYER][ActualizaPlayer][REPRODUCIDAS TODAS LAS NOTAS]\n");
		fflush(stdout);
		piLock(FLAGS_KEY);
		flags |= FLAG_PLAYER_END;
		piUnlock(FLAGS_KEY);
	}
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
}
/*
 * @brief Funcion que detiene la reproduccion del objeto player para la maquina de estados
 * @param fsm_t* this maquina de estados
 * @note Se anulan todos los flags para que no haya autolazos y se sobreescribe en la señal otra con frecuencia 0
 * */
void StopPlayer(fsm_t* this){
	softToneWrite(GPIO_PIN_18,0); // MODIFICADO
	/* Bloqueo este mutex para poder modificar los flags */
	piLock(FLAGS_KEY);
	flags &= ~FLAG_PLAYER_STOP;
	piUnlock(FLAGS_KEY);
	/* Bloqueo este mutex para poder imprimir por pantalla*/
	piLock(STD_IO_BUFFER_KEY);
	printf("\n[PLAYER][StopPlayer]");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	lcdClear(lcd);
	lcdPrintf(lcd, "Inserte tarjeta");
}
/*
 * @brief Funcion que indica el final de la melodia
 * @param fsm_t* this maquina de estados
 * @note Se anulan todos los flags para que no haya autolazos
 * */
void FinalMelodia(fsm_t* this){
	/* Bloqueo este mutex para poder modificar los flags */
	piLock(FLAGS_KEY);
	flags &= ~FLAG_PLAYER_END;
	piUnlock(FLAGS_KEY);
	/* Bloqueo este mutex para poder imprimir por pantalla*/
	piLock(STD_IO_BUFFER_KEY);
	printf("[PLAYER][FinalMelodia]\n");
	printf("[FinalMelodia][FLAG_PLAYER_END]\n");
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
	lcdClear(lcd);
	lcdPrintf(lcd, "Inserte tarjeta");
}
/*
 * @brief Funcion que indica que comienza una nueva nota
 * @param fsm_t* this maquina de estados
 * @note Se anulan todos los flags para que no haya autolazos y se inicia el timer
 * */
void ComienzaNuevaNota(fsm_t* this){
	TipoPlayer *p_player;
	p_player = (TipoPlayer*)(this->user_data);
	/* Bloqueo este mutex para comprobar el flag*/
	piLock(FLAGS_KEY);
	flags &= ~FLAG_PLAYER_END;
	piUnlock(FLAGS_KEY);
	/* Activacion o inicio del timer */
	tmr_startms(timer, melodia.duraciones[p_player->posicion_nota_actual]);
	/* Bloqueo este mutex para poder imprimir por pantalla*/
	piLock(STD_IO_BUFFER_KEY);
	printf("[PLAYER][ComienzaNuevaNota][NOTA %d][FREC %d][DURA %d]\n", p_player->posicion_nota_actual+1, melodia.frecuencias[p_player->posicion_nota_actual],melodia.duraciones[p_player->posicion_nota_actual]);
	fflush(stdout);
	piUnlock(STD_IO_BUFFER_KEY);
}

/* FUNCIONES DE ENTRADA O COMPROBACION */
/*
 * @brief Funcion que comprueba si la reproduccion se ha detenido
 * @param fsm_t* this maquina de estados
 * @return 1 o 0 según este activado o no el flag correspondiente
 * @note Uso de flags y FLAG_PLAYER_STOP
 * */
int CompruebaPlayerStop(fsm_t* this){
	int result;
	/* Bloqueo este mutex para comprobar el flag*/
	piLock (FLAGS_KEY);
	result = (flags & FLAG_PLAYER_STOP);
	piUnlock (FLAGS_KEY);
	return result;
}
/*
 * @brief Funcion que comprueba si se ha llegado al final de la melodia
 * @param fsm_t* this maquina de estados
 * @return 1 o 0 según este activado o no el flag correspondiente
 * @note Uso de flags y FLAG_PLAYER_END
 * */
int CompruebaFinalMelodia(fsm_t* this){
	int result;
	/* Bloqueo este mutex para comprobar el flag*/
	piLock (FLAGS_KEY);
	result = (flags & FLAG_PLAYER_END);
	piUnlock (FLAGS_KEY);
	return result;
}
/*
 * @brief Funcion que comprueba si ha empezado la reproduccion de la melodia
 * @param fsm_t* this maquina de estados
 * @return 1 o 0 según este activado o no el flag correspondiente
 * @note Uso de flags y FLAG_PLAYER_START
 * */
int CompruebaPlayerStart(fsm_t* this){
	int result;
	/* Bloqueo este mutex para comprobar el flag*/
	piLock (FLAGS_KEY);
	result = (flags & FLAG_PLAYER_START);
	piUnlock (FLAGS_KEY);
	return result;
}
/*
 * @brief Funcion que comprueba que se esta reproduciendo una nueva nota
 * @param fsm_t* this maquina de estados
 * @return 1 o 0 según este activado o no el flag correspondiente
 * @note Uso de flags y FLAG_PLAYER_END
 * */
int CompruebaNuevaNota(fsm_t* this){
	int result;
	/* Bloqueo este mutex para comprobar el flag*/
	piLock (FLAGS_KEY);
	result = ~(flags & FLAG_PLAYER_END);
	piUnlock (FLAGS_KEY);
	return result;
}
/*
 * @brief Funcion que comprueba si ha terminado una nota
 * @param fsm_t* this maquina de estados
 * @return 1 o 0 según este activado o no el flag correspondiente
 * @note Uso de flags y FLAG_NOTA_TIMEOUT
 * */
int CompruebaNotaTimeout(fsm_t* this){
	int result;
	/* Bloqueo este mutex para comprobar el flag*/
	piLock (FLAGS_KEY);
	result = (flags & FLAG_NOTA_TIMEOUT);
	piUnlock (FLAGS_KEY);
	return result;
}

/*----------------------
 *-------VERSION 5.0--------
 *--------------------------*/
/*--------------------------
 *---FUNCIONES DE SALIDA----
 *--------------------------*/
/*Funcion que inicializa el sistema*/
/*
 * @brief Funcion encargada de la inicializacion del sistema
 * */
void ComienzaSistema(fsm_t* this){
	piLock(FLAGS_KEY);
	flags &= ~FLAG_SYSTEM_START;
	piUnlock(FLAGS_KEY);
	MFRC522_Init('A');
	initialize_rfid();
}
/*
 * @brief Funcion que espera a que se inserte una tarjeta
 *
 * */
void EsperoTarjeta(fsm_t* this){
	//Función no necesaria
}

/*
 * @brief Funcion que compara y lee la tarjeta insertada
 * */
void LeerTarjeta(fsm_t* this){
	piLock(FLAGS_KEY);
	flags &= ~FLAG_CARD_IN;
	piUnlock(FLAGS_KEY);
	char * res = read_id();
	char* id_tarjeta=(char*)malloc(9*sizeof(char)); // CAMBIAR TARJETAS
	snprintf(id_tarjeta, 9, "%02X%02X%02X%02X\n",sistema.tarjetas_activas[0].uid.uidByte[0], sistema.tarjetas_activas[0].uid.uidByte[1], sistema.tarjetas_activas[0].uid.uidByte[2], sistema.tarjetas_activas[0].uid.uidByte[3]);
	char* id_tarjeta_2=(char*)malloc(9*sizeof(char));
	snprintf(id_tarjeta_2, 9, "%02X%02X%02X%02X\n",sistema.tarjetas_activas[1].uid.uidByte[0], sistema.tarjetas_activas[1].uid.uidByte[1], sistema.tarjetas_activas[1].uid.uidByte[2], sistema.tarjetas_activas[1].uid.uidByte[3]);
	MFRC522_Status_t sta2 = MFRC522_Compare((uint8_t*)res,(uint8_t*)id_tarjeta);
	MFRC522_Status_t sta1 = MFRC522_Compare((uint8_t*)res,(uint8_t*)id_tarjeta_2);
	if(sta2 == MI_OK){ // Comparacion de las tarjetas
		piLock(FLAGS_KEY);
		flags |= FLAG_VALID_CARD;
		piUnlock(FLAGS_KEY);
		piLock(STD_IO_BUFFER_KEY);
		printf("Valid card!!!\n");
		fflush(stdout);
		piUnlock(STD_IO_BUFFER_KEY);
		InicializaMelodia(&melodia, "GOT", frecuenciaGOT, tiempoGOT, 518); // Inicializacion de la melodia correspondiente
		lcdClear(lcd);
		lcdPuts(lcd, "PLAYING GOT");
	} else if(sta1==MI_OK){ // Comparacion de las tarjetas
		piLock(FLAGS_KEY);
		flags |= FLAG_VALID_CARD;
		piUnlock(FLAGS_KEY);
		piLock(STD_IO_BUFFER_KEY);
		printf("Muy valida la tarjeta\n");
		fflush(stdout);
		piUnlock(STD_IO_BUFFER_KEY);
		InicializaMelodia(&melodia, "TETRIS", frecuenciaTetris, tiempoTetris, 55); // Inicializacion de la melodia correspondiente
		lcdClear(lcd);
		lcdPuts(lcd, "PLAYING TETRIS");
	}else{
		piLock(STD_IO_BUFFER_KEY);
		printf("Invalid card!!!\n");
		fflush(stdout);
		piUnlock(STD_IO_BUFFER_KEY);
		piLock(FLAGS_KEY);
		flags &= ~FLAG_VALID_CARD;
		piUnlock(FLAGS_KEY);
		lcdClear(lcd);
		lcdPrintf(lcd, "Tarjeta invalida");
		delay(3000);
		lcdClear(lcd);
		lcdPrintf(lcd, "Inserte tarjeta");
	}
}

/*
@brief Funcion que descarta una tarjeta
*/
void DescartaTarjeta(fsm_t* this){
	piLock(FLAGS_KEY);
	flags &= ~FLAG_VALID_CARD;
	piUnlock(FLAGS_KEY);
}
/*
 * @brief Funcion que da comienzo a la reproduccion de la melodia
 * */
void ComienzaReproduccion(fsm_t* this){
	piLock (FLAGS_KEY);
	flags |= FLAG_CARD_IN;
	piUnlock (FLAGS_KEY);
	piLock(FLAGS_KEY);
	flags |= FLAG_PLAYER_START;
	piUnlock(FLAGS_KEY);
}
/*
 * @brief Funcion que comprueba la tarjeta*/
void ComprueboTarjeta(fsm_t* this){
	//No es necesario incluir nada
}
/*
 * @brief Funcion que cancela la reproduccion de la melodia*/
void CancelaReproduccion(fsm_t* this){
	piLock(FLAGS_KEY);
	flags |= FLAG_PLAYER_STOP;
	piUnlock(FLAGS_KEY);
	piLock(FLAGS_KEY);
	flags |= FLAG_SYSTEM_START;
	piUnlock(FLAGS_KEY);
}
/*
 * @brief Funcion que da por finalizada la reproduccion de la melodia*/
void FinalizaReproduccion(fsm_t* this){
	piLock(FLAGS_KEY);
	flags &= ~FLAG_SYSTEM_END;
	flags |= FLAG_SYSTEM_START;
	piUnlock(FLAGS_KEY);
}
/*--------------------------
 *---FUNCIONES DE ENTRADA---
 *--------------------------*/
/*
 * @brief Funcion encargada de comprobar el comienzo de la reproduccion
 * @param fsm_t* this maquina de estados
 * */
int CompruebaComienzo(fsm_t* this){ // FUNCIONA
	int result;
	/* Bloqueo este mutex para comprobar el flag*/
	piLock (FLAGS_KEY);
	result = (flags & FLAG_SYSTEM_START);
	piUnlock (FLAGS_KEY);
	return result;
}
/*
 * @brief Funcion encargada de comprobar el final de la reproduccion
 * @param fsm_t* this maquina de estados
 * */
int CompruebaFinalReproduccion(fsm_t* this){
	int result;
	/* Bloqueo este mutex para comprobar el flag*/
	piLock (FLAGS_KEY);
	result = (flags & FLAG_SYSTEM_END);
	piUnlock (FLAGS_KEY);
	return result;
}
/*
 * @brief Funcion encargada de comprobar si la tarjeta esta disponible
 * @param fsm_t* this maquina de estados
 * */
int TarjetaDisponible(fsm_t* this){
	int result;
	/* Bloqueo este mutex para comprobar el flag*/
	piLock (FLAGS_KEY);
	result = (flags & FLAG_CARD_IN);
	piUnlock (FLAGS_KEY);
	return result;
}
/*
 * @brief Funcion encargada de comprobar si la tarjeta no esta disponible
 * @param fsm_t* this maquina de estados
 * */
int TarjetaNoDisponible(fsm_t* this){
	int result;
	/* Bloqueo este mutex para comprobar el flag*/
	piLock (FLAGS_KEY);
	result = ~(flags & FLAG_CARD_IN);
	piUnlock (FLAGS_KEY);
	return result;
}
/*
 * @brief Funcion encargada de comprobar si la tarjeta es valida
 * @param fsm_t* this maquina de estados
 * */
int TarjetaValida(fsm_t* this){
	int result;
	/* Bloqueo este mutex para comprobar el flag*/
	piLock (FLAGS_KEY);
	result = (flags & FLAG_VALID_CARD);
	piUnlock (FLAGS_KEY);
	return result;
}
/*
 * @brief Funcion encargada de comprobar si la tarjeta es no valida
 * @param fsm_t* this maquina de estados
 * */
int TarjetaNoValida(fsm_t* this){
	int result;
	/* Bloqueo este mutex para comprobar el flag*/
	piLock (FLAGS_KEY);
	result = ~(flags & FLAG_VALID_CARD);
	piUnlock (FLAGS_KEY);
	return result;
}
/*----------------------
 *---------CONTADOR---------
 *--------------------------*/
/*
 * @brief Espera hasta la proxima activacion del reloj
 * @param unsigned int next que es un contador de tiempo
 * */
void delay_until (unsigned int next){
	unsigned int now = millis();
	if (next>now){
		delay(next-now);
	}
}
/*----------------------
 *-----INICIALIZACION-------
 *--------------------------*/
/*
 * @brief Procedimiento de configuracion del sistema
 * @return -1 o 1 según se configure correctamente o no
 * @note Se utiliza wiringPiSetupGpio y piThreadCreate de la librería wiringPi
 * */
int systemSetup (void) {
	pinMode(GPIO_PIN_18, OUTPUT);
	pinMode(GPIO_PIN_20, INPUT);
	pinMode(GPIO_PIN_16, INPUT);
	pinMode(GPIO_PIN_MOSI, OUTPUT);
	pinMode(GPIO_PIN_MISO, INPUT);
	pinMode(GPIO_PIN_SPICS0, INPUT);
	pinMode(GPIO_PIN_SCLK, INPUT);
	pinMode(LCD_RS, OUTPUT);
	pinMode(LCD_E, OUTPUT);
	pinMode(LCD_D4, OUTPUT);
	pinMode(LCD_D5, OUTPUT);
	pinMode(LCD_D6, OUTPUT);
	pinMode(LCD_D7, OUTPUT);
	int x = 0;
	/* Bloqueo este mutex para poder imprimir por pantalla*/
	piLock(STD_IO_BUFFER_KEY);
	wiringPiSetup();
	// sets up the wiringPi library
	if (wiringPiSetupGpio () < 0) {
		printf ("Unable to setup wiringPi\n");
		piUnlock (STD_IO_BUFFER_KEY);
		return -1;
	 }
	// sets up the wiringPiSPI library
	if (wiringPiSPISetup (SPI_ADC_CH,SPI_ADC_FREQ) < 0) {
		/* DEBUG */
		 printf ("No se pudo inicializar el dispositivo SPI (CH 0)") ;
		 piUnlock (STD_IO_BUFFER_KEY);
		 /* /DEBUG */
		 exit (1);
		 return -2;
	}
	wiringPiISR(GPIO_PIN_16, INT_EDGE_RISING, myInterrupt0); // RISING
	wiringPiISR(GPIO_PIN_20, INT_EDGE_FALLING, myInterrupt1); // FALLING
	// Lanzamos thread para exploracion del teclado convencional del PC
	x = piThreadCreate (thread_explora_teclado);
	if (x != 0) {
		printf ("it didn't start!!!\n");
		piUnlock (STD_IO_BUFFER_KEY);
		return -3;
	}
	piUnlock (STD_IO_BUFFER_KEY);
return 1;
}
/*
 * @brief Procedimiento de configuracion de la maquina de estado
 * @param fsm_t* this: maquina de estados
 * @note Inicializo la variable global flags
 * */
void fsm_setup(fsm_t* this) {
	/* Bloqueo este mutex para iniciar la variable global flag*/
	piLock (FLAGS_KEY);
	flags = 0;
	piUnlock (FLAGS_KEY);
	/* Bloqueo este mutex para poder imprimir por pantalla*/
	piLock (STD_IO_BUFFER_KEY);
	printf("Inserte una tarjeta para la reproduccion FSM_SETUP");
	fflush(stdout);
	piUnlock (STD_IO_BUFFER_KEY);
}
/*
 * @brief Hebra que se encarga de leer el teclado y activar el flag correspondiente para la ejecucion de la maquina de estados
 * @param thread_explora_teclado nombre del thread que explora el uso del teclado
 * @note se pueden usar 3 teclas la "s", la "t" y la "q"
 * */
PI_THREAD (thread_explora_teclado) {
	piHiPri(0);
	while(1) {
		delay(10); // Wiring Pi function: pauses program execution for at least 10 ms
		piLock (STD_IO_BUFFER_KEY);
		if(kbhit()) {
			sistema.teclaPulsada = kbread();
			printf("\n[KBHIT][%c]\n", sistema.teclaPulsada);
			switch(sistema.teclaPulsada) {
				case 'q':
					lcdClear(lcd);
					exit(0);
					break;
				default:
					printf("INVALID KEY!!!\n");
					break;
			}
		}
		piUnlock (STD_IO_BUFFER_KEY);
	}
}
/*
 * @brief Definicion de timer que bloquea el mutex para poner todos los flags a 0 y poner el flag correspondiente del fin de las notas a 1
 * @param
 * */
static void timer_isr(union sigval arg){
	piHiPri(2);
	/* Bloqueo este mutex para modificar los flags*/
	piLock(FLAGS_KEY);
	flags &= ~FLAG_PLAYER_START;
	flags &= ~FLAG_PLAYER_END;
	flags &= ~FLAG_PLAYER_STOP;
	flags |= FLAG_NOTA_TIMEOUT;
	piUnlock(FLAGS_KEY);
}
/*
 * @brief Funcion encargada de la interrupcion de bajada
 * */
void myInterrupt0(void){
	// Condicion que tiene como objetivo eliminar rebotes
	if(millis()<debounceTime){
		debounceTime = millis() + DEBOUNCE_TIME;
		return;
	}
	debounceTime = 0;
	// Funcionamiento de T
	piLock (FLAGS_KEY);
	flags &= ~FLAG_CARD_IN;
	flags |= FLAG_PLAYER_STOP;
	piUnlock (FLAGS_KEY);
	while(digitalRead(GPIO_PIN_16)==LOW){
		delay(1);
	}
	debounceTime = millis()+DEBOUNCE_TIME;
}
/*
 * @brief Funcion encargada de la interrupcion de subida
 * */
void myInterrupt1(void){
	// Condicion que tiene como objetivo eliminar rebotes
	if(millis()<debounceTime){
		debounceTime = millis() + DEBOUNCE_TIME;
		return;
	}
	debounceTime = 0;
	//Funcionamiento de S
	piLock (FLAGS_KEY);
	flags |= FLAG_CARD_IN;
	piUnlock (FLAGS_KEY);
	while(digitalRead(GPIO_PIN_20)==HIGH){
		delay(1);
	}
	debounceTime = millis()+DEBOUNCE_TIME;
}

/*
 * @brief Funcion que arranca el sistema
 * @note en ella se inicializa el sistema
 * */
void ArrancaSistema(){
	piLock(FLAGS_KEY);
	flags |= FLAG_SYSTEM_START;
	piUnlock(FLAGS_KEY);
}

/*
 * @brief Funcion principal del programa
 * @note en ella se inicializa tanto el timer como la maquina de estados y se configura to'do lo necesario para el correcto funcionamiento
 * */
int main(){
	piHiPri(1);
	lcd = lcdInit(2, 16, 4, LCD_RS, LCD_E,LCD_D4, LCD_D5, LCD_D6, LCD_D7,0,0,0,0);
	lcdPosition(lcd,0,0);  //Position cursor on the first line in the first column
	lcdClear(lcd);
	lcdPrintf(lcd, "Insert card!");
	unsigned int next;
	timer = tmr_new(timer_isr); //Inicializacion del timer
	sistema.tarjetas_activas[0].melodia = melodiaGOT;
	sistema.tarjetas_activas[0].uid.size = 4;
	sistema.tarjetas_activas[0].uid.uidByte[0]=22;
	sistema.tarjetas_activas[0].uid.uidByte[1]=130;
	sistema.tarjetas_activas[0].uid.uidByte[2]=23;
	sistema.tarjetas_activas[0].uid.uidByte[3]=18;
	sistema.tarjetas_activas[1].melodia = melodiaTetris;
	sistema.tarjetas_activas[1].uid.size = 4;
	sistema.tarjetas_activas[1].uid.uidByte[0]=123;
	sistema.tarjetas_activas[1].uid.uidByte[1]=132;
	sistema.tarjetas_activas[1].uid.uidByte[2]=129;
	sistema.tarjetas_activas[1].uid.uidByte[3]=115;
	fsm_trans_t tarjetero[] = {
		{WAIT_EMPIEZA, CompruebaComienzo, WAIT_CARD, ComienzaSistema},
		{WAIT_CHECK, TarjetaValida, WAIT_PLAY, ComienzaReproduccion},
		{WAIT_PLAY, TarjetaDisponible, WAIT_PLAY, ComprueboTarjeta},
		{WAIT_CARD, TarjetaDisponible, WAIT_CHECK, LeerTarjeta},
		{WAIT_CARD, TarjetaNoDisponible, WAIT_CARD, EsperoTarjeta},
		{WAIT_PLAY, CompruebaFinalReproduccion, WAIT_EMPIEZA, FinalizaReproduccion},
		{WAIT_PLAY, TarjetaNoDisponible, WAIT_EMPIEZA, CancelaReproduccion},
		{WAIT_CHECK, TarjetaNoValida, WAIT_CARD, DescartaTarjeta},
		{-1, NULL, -1, NULL}
		};
	/* TABLA DE TRANSICIONES PARA LA MAQUINA DE ESTADOS
	{EstadoOrigen, FuncionDeEntrada, EstadoDestino, FuncionDeSalida}*/
	fsm_trans_t reproductor[] = { // Creacion de la maquina de estados
		{WAIT_START, CompruebaPlayerStart, WAIT_NEXT, InicializaPlayer},
		{WAIT_NEXT, CompruebaPlayerStop, WAIT_START, StopPlayer},
		{WAIT_END, CompruebaFinalMelodia, WAIT_START, FinalMelodia},
		{WAIT_END, CompruebaNuevaNota, WAIT_NEXT, ComienzaNuevaNota},
		{WAIT_NEXT, CompruebaNotaTimeout, WAIT_END, ActualizaPlayer},
		{-1, NULL, -1, NULL}
	};
	//Inicializacion del objeto maquina de estado
	fsm_t* player_fsm = fsm_new(WAIT_START, reproductor, &(sistema.player)); // Creacion de la maquina de estados
	fsm_t* card_fsm = fsm_new(WAIT_EMPIEZA, tarjetero, &(sistema.player));
	//Llamada a la configuracion del sistema
	systemSetup();
	fsm_setup(card_fsm);
	fsm_setup(player_fsm); //
	ArrancaSistema();
	next = millis();
	while (1) {
		fsm_fire (card_fsm);/* Intenta ejecutar una transicion en funcion del valor de las entradas. */
		fsm_fire (player_fsm);
		next += CLK_MS;
		delay_until (next); /* Reposo durante 10 ms */
	}
tmr_destroy(timer); // Destruccion del timer
fsm_destroy(card_fsm);
fsm_destroy(player_fsm); // Destruccion de la maquina de estados
}
