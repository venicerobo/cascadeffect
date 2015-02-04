// CG_DEADON = zero deg
// CG_ANGLED = 45 deg
// CG_AWAY = 90 deg


//General Stuff
#define ENCODER_RESET 0
#define NINETY_TURN_TICKS 1120
#define TURNING_SPEED 100
#define DEAD_RECKONING 100
#define HALF_SPEED 50

// Initial state of servos
#define AUTO_ARM_STARTING_POSITION 110

// Find IR
#define FIRST_DETECT_TICKS 1800
#define SECOND_DETECT_TICKS 540
#define CG_DEADON_READING 4
#define CG_ANGLED_READING 3
#define CG_AWAY_READING 0

//45 DEGREE
#define CG_ANGLED_DRIVE_TICKS 855
#define CG_ANGLED_TURN_TICKS 750 // currently at 60 deg turn

// 90 DEGREE
#define CG_AWAY_DRIVE_TICKS 720

//Dumping Mechanism
#define SCISSOR_LIFT_MOTOR 100
#define AUTO_ARM_DUMP 255
#define LIFTING_TIME 5000
#define DUMPING_TIME 500

//Kickstand
#define KS_TINY_BACKUP 540
#define KS_DRIVE_TICKS 1500
