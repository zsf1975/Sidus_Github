#pragma once
/*
This header file define all the configurable variables including constants, pin mapping, etc.
*/

//Wifi, UDP Definitions
#define WIFI_SSID	"AAGCA"
#define WIFI_PASS	"ahmet(12082004)"
#define UDP_PORT	8080




//Pin Definitions
#define PIN_LED				5
#define PIN_MPU_POWER_ON	16
#define PIN_MCU_SDA			12
#define PIN_MCU_SCL			14



//Constant Variables
#define SERIAL_PACKET_SIZE	13
#define SERIAL_START_CHAR_1	'$'
#define SERIAL_START_CHAR_2	'<'
#define SERIAL_END_CHAR		'>'


//Global Variable Declarations
int test_task_counter = 0;


// MPU control/status vars
bool mpuStatus;
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer
						// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
int16_t gg[3];         // [x, y, z]            gyro sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector

float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector


unsigned long mpuProcessStartTime = 0;
short mpuProcessTaskDuration = 0;


double mpuPitchAngle, mpuRollAngle, mpuYawAngle;