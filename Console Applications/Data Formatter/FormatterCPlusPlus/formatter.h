#pragma once
#include <cstdint>

#ifdef FORMATTER_EXPORTS
#define FORMATTER_API __declspec(dllexport)
#else
#define FORMATTER_API __declspec(dllimport)
#endif

extern "C" FORMATTER_API short FRAC16(float x);
extern "C" FORMATTER_API float Q15TOFLOAT(short x);
extern "C" FORMATTER_API long FRAC32(float x);
extern "C" FORMATTER_API float Q32TOFLOAT(long x);
extern "C" FORMATTER_API short ACC16(float x);
extern "C" FORMATTER_API float ACC16TOFLOAT(short x);
extern "C" FORMATTER_API long ACC32(float x);
extern "C" FORMATTER_API float ACC32TOFLOAT(long x);
extern "C" FORMATTER_API uint16_t float_to_L11(float input_val);
extern "C" FORMATTER_API float L11_to_float(uint16_t input_val);
extern "C" FORMATTER_API float L16_to_float(unsigned int input_val);
extern "C" FORMATTER_API uint16_t float_to_L16(float input_val);
extern "C" FORMATTER_API short floatToShort(float x);
extern "C" FORMATTER_API int16_t floatToInt16(float x);
extern "C" FORMATTER_API long floatToLong(float x);