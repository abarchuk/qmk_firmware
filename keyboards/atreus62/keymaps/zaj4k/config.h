#include "../../config.h"

#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#undef DIODE_DIRECTION

#define MATRIX_ROW_PINS { B6, B5, B4, D7, D4 }
#define MATRIX_COL_PINS { F0, F1, F4, F5, F6, F7, D1, D0, B7, B3, B2, B1, B0 }

#define DIODE_DIRECTION COL2ROW


