
#define HAND_SENSE 12
#define RIGHT_HAND false
#define LEFT_HAND true

#define ALPHA_SENSE 20
#define ALPABETICAL false

// left hand pins

#define L_S11 23
#define L_S12 22
#define L_S13 21
#define L_S14 20
#define L_S21 29
#define L_S22 28
#define L_S23 25
#define L_S24 24
#define L_S31 0
#define L_S32 30
#define L_S33 11
#define L_S34 12
#define L_S41 5
#define L_S42 4
#define L_S43 3
#define L_S44 2
#define L_S45 1
#define L_S51 9
#define L_S52 8
#define L_S53 7
#define L_S54 6
#define L_S55 10
#define L_S61 13
#define L_S62 14
#define L_S63 15
#define L_S64 16
#define L_S65 17
#define L_S71 18

#define L_MASK (1<<L_S11 | \
 				1<<L_S12 | \
				1<<L_S13 | \
				1<<L_S14 | \
				1<<L_S21 | \
				1<<L_S22 | \
				1<<L_S23 | \
				1<<L_S24 | \
				1<<L_S31 | \
				1<<L_S32 | \
				1<<L_S33 | \
				1<<L_S34 | \
				1<<L_S41 | \
				1<<L_S42 | \
				1<<L_S43 | \
				1<<L_S44 | \
				1<<L_S45 | \
				1<<L_S51 | \
				1<<L_S52 | \
				1<<L_S53 | \
				1<<L_S54 | \
				1<<L_S55 | \
				1<<L_S61 | \
				1<<L_S62 | \
				1<<L_S63 | \
				1<<L_S64 | \
				1<<L_S65 | \
				1<<L_S71)

// right hand pins

#define R_S11 17
#define R_S12 18
#define R_S13 19
#define R_S14 20
#define R_S21 13
#define R_S22 14
#define R_S23 15
#define R_S24 16
#define R_S31 9
#define R_S32 10
#define R_S33 11
#define R_S34 12
#define R_S41 4
#define R_S42 5
#define R_S43 6
#define R_S44 7
#define R_S45 8
#define R_S51 0
#define R_S52 1
#define R_S53 2
#define R_S54 3
#define R_S55 30
#define R_S61 29
#define R_S62 28
#define R_S63 25
#define R_S64 24
#define R_S65 23
#define R_S71 22

#define R_MASK (1<<R_S11 | \
 				1<<R_S12 | \
				1<<R_S13 | \
				1<<R_S14 | \
				1<<R_S21 | \
				1<<R_S22 | \
				1<<R_S23 | \
				1<<R_S24 | \
				1<<R_S31 | \
				1<<R_S32 | \
				1<<R_S33 | \
				1<<R_S34 | \
				1<<R_S41 | \
				1<<R_S42 | \
				1<<R_S43 | \
				1<<R_S44 | \
				1<<R_S45 | \
				1<<R_S51 | \
				1<<R_S52 | \
				1<<R_S53 | \
				1<<R_S54 | \
				1<<R_S55 | \
				1<<R_S61 | \
				1<<R_S62 | \
				1<<R_S63 | \
				1<<R_S64 | \
				1<<R_S65 | \
				1<<R_S71)

#ifdef COMPILE_LEFT

#define PIPE_NUMBER 0

#define S11 L_S11
#define S12 L_S12
#define S13 L_S13
#define S14 L_S14
#define S21 L_S21
#define S22 L_S22
#define S23 L_S23
#define S24 L_S24
#define S31 L_S31
#define S32 L_S32
#define S33 L_S33
#define S34 L_S34
#define S41 L_S41
#define S42 L_S42
#define S43 L_S43
#define S44 L_S44
#define S45 L_S45
#define S51 L_S51
#define S52 L_S52
#define S53 L_S53
#define S54 L_S54
#define S55 L_S55
#define S61 L_S61
#define S62 L_S62
#define S63 L_S63
#define S64 L_S64
#define S65 L_S65
#define S71 L_S71

#define INPUT_MASK L_MASK

#endif

#ifdef COMPILE_RIGHT

#define PIPE_NUMBER 1

#define S11 R_S11
#define S12 R_S12
#define S13 R_S13
#define S14 R_S14
#define S21 R_S21
#define S22 R_S22
#define S23 R_S23
#define S24 R_S24
#define S31 R_S31
#define S32 R_S32
#define S33 R_S33
#define S34 R_S34
#define S41 R_S41
#define S42 R_S42
#define S43 R_S43
#define S44 R_S44
#define S45 R_S45
#define S51 R_S51
#define S52 R_S52
#define S53 R_S53
#define S54 R_S54
#define S55 R_S55
#define S61 R_S61
#define S62 R_S62
#define S63 R_S63
#define S64 R_S64
#define S65 R_S65
#define S71 R_S71

#define INPUT_MASK R_MASK

#endif



// Low frequency clock source to be used by the SoftDevice
#define NRF_CLOCK_LFCLKSRC      {.source        = NRF_CLOCK_LF_SRC_XTAL,            \
                                 .rc_ctiv       = 0,                                \
                                 .rc_temp_ctiv  = 0,                                \
                                 .xtal_accuracy = NRF_CLOCK_LF_XTAL_ACCURACY_20_PPM}
