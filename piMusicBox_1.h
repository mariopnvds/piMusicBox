 /* *
 * Descripcion: Programa que simula un juguete musical que reproduce melodias mediante su implementacion en una RaspberryPi
 * Autores: Mario Penavades Suárez y Alejandro Marcos Arias
 * Version: 5.0
 * Fecha de entrega: 17/5/2018
 * Grupo: VC-20
 * */

#ifndef PIMUSICBOX_1_H_
#define PIMUSICBOX_1_H_

#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#include "lcd.h"
#include <softTone.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>
#include "kbhit.h" // Para poder detectar teclas pulsadas sin bloqueo y leer las teclas pulsadas
#include "fsm.h"
#include "tmr.h"
#include "mfrc522.h"
#include "rfid.h"


#define CLK_MS 10 // PERIODO DE ACTUALIZACION DE LA MAQUINA ESTADOS

#define FLAGS_KEY 1
#define STD_IO_BUFFER_KEY 2

#define FLAG_PLAYER_START 0x01
#define FLAG_NOTA_TIMEOUT 0x02
#define FLAG_PLAYER_STOP 0x04
#define FLAG_NUEVA_NOTA  0x08
#define FLAG_PLAYER_END 0x10
#define FLAG_VALID_CARD 0x20
#define FLAG_CARD_IN 0x40
#define FLAG_SYSTEM_START 0x80
#define FLAG_SYSTEM_END 0x100

#define SPI_ADC_CH 0
#define SPI_ADC_FREQ 1000000

//USE WIRINGPI PIN NUMBERS
#define GPIO_PIN_20 20 // Use BCM GPIO-20
#define GPIO_PIN_16 16 // Use BCM GPIO-16
#define GPIO_PIN_18 18 // Use BCM GPIO-18

//USE WIRINGPI PIN NUMBERS FOR RFID
#define GPIO_PIN_MOSI 10 // Use BCM GPIO-10
#define GPIO_PIN_MISO 9 // Use BCM GPIO-9
#define GPIO_PIN_SCLK 11 // Use BCM GPIO-11
#define GPIO_PIN_SPICS0 8 // Use BCM GPIO-8

//USE WIRINGPI PIN NUMBERS FOR LCD
#define LCD_RS  12               //Register select pin
#define LCD_E   24               //Enable Pin
#define LCD_D4  26               //Data pin 4
#define LCD_D5  19              //Data pin 5
#define LCD_D6  13               //Data pin 6
#define LCD_D7  6             //Data pin 7

extern int frecuenciaDespacito[];
extern int tiempoDespacito[];
extern int frecuenciaGOT[];
extern int tiempoGOT[];
extern int frecuenciaTetris[];
extern int tiempoTetris[];
extern int frecuenciaStarwars[];
extern int tiempoStarwars[];
extern int tiempoMarcha[];
extern int frecuenciaMarcha[];

//------------------------------------------------------
// SUBRUTINAS DE ATENCION A LAS INTERRUPCIONES
//------------------------------------------------------
PI_THREAD (thread_explora_teclado);

typedef enum {
	WAIT_START=0,
	WAIT_NEXT=1,
	WAIT_END=2,
	WAIT_CARD=3,
	WAIT_PLAY=4,
	WAIT_EMPIEZA=5,
	WAIT_CHECK=6} TipoEstadosSistema;

#define MAX_NUM_TARJETAS	5
#define MAX_NUM_NOTAS 		600
#define MAX_NUM_CHAR_NOMBRE	100
#define MAX_NUM_CHAR_UID	100

#define DEBOUNCE_TIME 200

typedef struct {
	char nombre[MAX_NUM_CHAR_NOMBRE]; // String con el nombre de la melodia
	int frecuencias[MAX_NUM_NOTAS]; // Array con las frecuencias de las notas de la melodia
	int duraciones[MAX_NUM_NOTAS]; // Array con las duraciones de las notas de la melodia
	int num_notas; // Numero de notas de que consta la melodia
} TipoMelodia;

typedef struct {
	int posicion_nota_actual;	// Valor correspondiente a la posicion de la nota actual en los arrays de frecuencias y duraciones
	int frecuencia_nota_actual; // Valor correspondiente a la frecuencia de la nota actual
	int duracion_nota_actual; // Valor correspondiente a la duracion de la nota actual
	TipoMelodia* melodia;
} TipoPlayer;

typedef struct {
	int		size;			// Number of bytes in the UID. 4, 7 or 10.
	int		uidByte[10];
} Uid;

typedef struct {
	Uid uid;  // Identificador correspondiente a la tarjeta (tipo de datos complejo definido en libreria control RFID)
	TipoMelodia melodia;
} TipoTarjeta;

typedef struct {
	TipoPlayer player; // Reproductor de melodias
	int num_tarjetas_activas; // Numero de tarjetas validas
	TipoTarjeta tarjetas_activas[MAX_NUM_TARJETAS]; // Array con todas las tarjetas validas
	Uid uid_tarjeta_actual; // Identificador de la tarjeta actual (tipo de datos complejo definido en liberia control RFID)
	int pos_tarjeta_actual; // Posicion de la tarjeta actual en el array de tarjetas validas
	unsigned char uid_tarjeta_actual_string[MAX_NUM_CHAR_UID]; // Identificador de la tarjeta actual a modo de string de caracteres
	TipoEstadosSistema estado; // Variable que almacena el estado actual del sistema
	char teclaPulsada; // Variable que almacena la ultima tecla pulsada
	int debug; // Variable que habilita o deshabilita la impresion de mensajes por salida estandar
} TipoSistema;

//------------------------------------------------------
// FUNCIONES DE ENTRADA O DE TRANSICION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------
// Prototipos de funciones de entrada
int CompruebaPlayerStart (fsm_t* this);
int CompruebaNotaTimeout (fsm_t* this);
int CompruebaFinalMelodia (fsm_t* this);
int CompruebaNuevaNota (fsm_t* this);
int CompruebaPlayerStop (fsm_t* this);
int CompruebaComienzo(fsm_t* this);
int CompruebaFinalReproduccion(fsm_t* this);
int TarjetaDisponible(fsm_t* this);
int TarjetaValida(fsm_t* this);
int TarjetaNoDisponible(fsm_t* this);
int TarjetaValida(fsm_t* this);
int TarjetaNoValida(fsm_t* this);
//------------------------------------------------------
// FUNCIONES DE SALIDA O DE ACCION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------
// Prototipos de funciones de salida
void InicializaPlayer(fsm_t*);
void ActualizaPlayer(fsm_t*);
void FinalMelodia(fsm_t*);
void ComienzaNuevaNota(fsm_t*);
void StopPlayer(fsm_t*);
void FinalizaReproduccion(fsm_t*);
void ComienzaSistema(fsm_t*);
void CancelaReproduccion(fsm_t*);
void ComienzaReproduccion(fsm_t*);
void ComprueboTarjeta(fsm_t*);
void LeerTarjeta(fsm_t*);
void EsperoTarjeta(fsm_t*);
void DescartaTarjeta(fsm_t*);
void ArrancaSistema();

int InicializaMelodia (TipoMelodia *melodia, char *nombre, int *array_frecuencias, int *array_duraciones, int num_notas);
int systemSetup (void);
void delay_until (unsigned int next);
static void timer_isr(union sigval arg);
void myInterrupt0(void);
void myInterrupt1(void);

#endif /* PIMUSICBOX_1_H_ */
