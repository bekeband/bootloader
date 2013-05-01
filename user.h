/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.>
 * These are the LED display's in/out lines.*/

#define CAL_BRG(BAUD_RATE) ((FCY/(16*BAUD_RATE))-1)
#define BAUDRATE 9600
#define BRGVAL          ((FCY/BAUDRATE)/16)-1

#define H1_TRIS     TRISEbits.TRISE4
#define H1_LAT      LATEbits.LATE4
#define H1_PORT     PORTEbits.RE4

#define H2_TRIS     TRISEbits.TRISE5
#define H2_LAT      LATEbits.LATE5
#define H2_PORT     PORTEbits.RE5

#define H3_TRIS     TRISEbits.TRISE8
#define H3_LAT      LATEbits.LATE8
#define H3_PORT     PORTEbits.RE8

#define H4_TRIS     TRISCbits.TRISC13
#define H4_LAT      LATCbits.LATC13
#define H4_PORT     PORTCbits.RC13

#define V1_TRIS     TRISCbits.TRISC14
#define V1_LAT      LATCbits.LATC14
#define V1_PORT     PORTCbits.RC14

#define V2_TRIS     TRISDbits.TRISD2
#define V2_LAT      LATDbits.LATD2
#define V2_PORT     PORTDbits.RD2

#define V3_TRIS     TRISDbits.TRISD3
#define V3_LAT      LATDbits.LATD3
#define V3_PORT     PORTDbits.RD3

#define V4_TRIS     TRISFbits.TRISF0
#define V4_LAT      LATFbits.LATF0
#define V4_PORT     PORTFbits.RF0

#define V5_TRIS     TRISFbits.TRISF1
#define V5_LAT      LATFbits.LATF1
#define V5_PORT     PORTFbits.RF1

#define RF6_TRIS    TRISFbits.TRISF6
#define RF6_LAT     LATFbits.LATF6
#define RF6_PORT    PORTFbits.RF6

#define RB7_TRIS    TRISBbits.TRISB7
#define RB7_LAT     LATBbits.LATB7
#define RB7_PORT    PORTBbits.RB7

#define RB8_TRIS    TRISBbits.TRISB8
#define RB8_LAT     LATBbits.LATB8
#define RB8_PORT    PORTBbits.RB8

#define SST01_TRIS    TRISDbits.TRISD0
#define SST01_LAT     LATDbits.LATD0
#define SST01_PORT    PORTDbits.RD0

#define INIT00_TRIS TRISEbits.TRISE0
#define INIT00_LAT  LATEbits.LATE0

#define INIT01_TRIS TRISEbits.TRISE1
#define INIT01_LAT  LATEbits.LATE1

#define INIT02_TRIS TRISEbits.TRISE2
#define INIT02_LAT  LATEbits.LATE2

#define INIT03_TRIS TRISEbits.TRISE3
#define INIT03_LAT  LATEbits.LATE3

    // U1RXD_TRIS register. Then must be set input.
#define U1RXD_TRIS  TRISFbits.TRISF2    
    // U1RXD_PORT register. Read this port to reading
#define U1RXD_PORT  PORTFbits.RF2
    // U1RXD_TRIS register. Then must be set output.
#define U1TXD_TRIS  TRISFbits.TRISF3
    /* U1RXD_PORT register. Read this port to reading
     * If U1TXD=1 then A=(-) B=(+), else A=(+), B=(-)*/
#define U1TXD_LAT   LATFbits.LATF3

    /* U1RTS_TRIS register. That must set output, because this is data transmit enabled.
     * bit of RS485 insulated signal.*/
#define U1RTS_TRIS  TRISFbits.TRISF5

    /* This is U1 RTS signal for RS485 line. If enabled this line, the RS485
     * channel can data transmit, therefore the line goes from high 
     * impedance mode mode to normal data transmit mode. Since the RS 485 line 
     * use only some data connection to data read, and data transmit, 
     * (half duplex mode) the data line we must released when we can it as is time.
     * If U1RTS_LAT=0, then the line connect to rail (transmitting mode),
     * and if U1RTS_LAT=1, then the RS485 port became high impedance. (Receiving mode)*/
#define U1RTS_LAT LATFbits.LATF5

/* These are datas to TRISX registers to input state with the or expressions the
 * input TRISE datas.
 */

#define DISPL_B_PORT_BITS 0b0000000110000000    // RB7, RB8
#define DISPL_C_PORT_BITS 0b0110000000000000    // RC13, RC14
#define DISPL_D_PORT_BITS 0b0000000000001100    // RD2, RD3
#define DISPL_E_PORT_BITS 0b0000000100110000
#define DISPL_F_PORT_BITS 0b0000000001000011
#define ADC_CHANNELS 4

/* TODO Application specific user parameters used in user.c may go here */

enum e_LED_COLOR { RED, GREEN };
enum e_LED_STATE { OFF = 0, ON = 1, BLINK = 2};
enum e_LED_POS { L1 = 0, L2 = 1, L3 = 2, L4 = 3, T1 = 4, T2 = 5, T3 = 6, T4 = 7,
    CO = 8, ST = 9 };

enum e_PROTOKOL {MODBUS = 0, PROFIBUS = 1};

extern int ADC_RAW_VALUES[ADC_CHANNELS];

/******************************************************************************/
/* struct LED_PORT                                                  */
/******************************************************************************/

typedef struct {
    volatile unsigned int* ADDRESS_GR;   // Portaddress, and bitnumber of green side
    int bitnumb_GR;
    volatile unsigned int* ADDRESS_RD;   // Portaddress, and bitnumber of red side
    int bitnumb_RD;
} LED_PORT;

/******************************************************************************/
/* struct LED_STATE contains LED_STATE, and color */
/******************************************************************************/

typedef struct {
    enum e_LED_STATE STATE;     // OFF, BLINK, ON
    enum e_LED_COLOR COLOR;     // RED, GREEN
} LED_STATE;

extern LED_STATE LED_STATES[10];
extern int BAUD_RATE_FEATURE;
extern enum e_PROTOKOL PROTOKOL_FEATURE;
extern int DEVICE_ADDRESS;

void InitApp(void); /* I/O and Peripheral Initialization */
void LED_ON(enum e_LED_COLOR color, int number); /* number'th LED ON */
void LED_OFF(enum e_LED_COLOR color, int number); /* number'th LED OFF */
void SetAllLEDOff(); /* Set ALL display LED to off state.*/
void SetAllLEDforInput(); /* Set ALL LED lines for input. */
void GetInputBits();