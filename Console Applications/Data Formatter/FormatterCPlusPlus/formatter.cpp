
#include <iostream>
#include <math.h>
#include "formatter.h"
using namespace std;

// DLL internal state variables:
/* Fractional data types */
typedef signed long long frac64_t;
typedef signed long frac32_t;
typedef signed short frac16_t;

/* Accumulator data types */
typedef signed long long acc64_t;
typedef signed long acc32_t;
typedef signed short acc16_t;

short FRAC16(float x) {
	return (x < 1 ? ((x) >= -1 ? (x) * 0x8000 : 0x8000) : 0x7FFF);
}

float Q15TOFLOAT(short x) {
	return ((float)((x) < 32768 ? ((x) >= -32768 ? (float)(x) / (float)0x8000 : 1) : -1));
}

long FRAC32(float x) {
	return  ((frac32_t)((x) < 1 ? ((x) >= -1 ? (x) * 0x80000000 : 0x80000000) : 0x7FFFFFFF));
}

float Q32TOFLOAT(long x) {
	return ((float)((x) < 2147483648 ? ((x) >= -2147483648 ? (float)(x) / (float)0x80000000 : 1) : -1));
}

short ACC16(float x) {
	return ((acc16_t)((x) < 256 ? ((x) >= -256 ? (x) * 0x80 : 0x8000) : 0x7FFF));
}

float ACC16TOFLOAT(short x) {
	return ((float)((x) < 32768 ? ((x) >= -32768 ? (float)(x) / (float)0x80 : 256) : -256));
}

long ACC32(float x) {
	return  ((acc32_t)((x) < 65536 ? ((x) >= -65536 ? (x) * 0x8000 : 0x80000000) : 0x7FFFFFFF));
}

float ACC32TOFLOAT(long x) {
	return ((float)((x) < 2147483648 ? ((x) >= -2147483648 ? (float)(x) / (float)0x8000 : 65536) : -65536));
}

uint16_t float_to_L11(float input_val)
{
	// set exponent to -16
	int exponent = -16;
	// extract mantissa from input value
	int mantissa = (int)(input_val / pow(2.0, exponent));
	// Search for an exponent that produces
	// a valid 11-bit mantissa
	do {
		if ((mantissa >= -1024) && (mantissa <= +1023))  break; // stop if mantissa valid
		exponent++;
		mantissa = (int)(input_val / pow(2.0, exponent));
	} while (exponent < +15);

	// Format the exponent of the L11
	uint16_t uExponent = exponent << 11;
	// Format the mantissa of the L11 
	uint16_t uMantissa = mantissa & 0x07FF;
	// Compute value as exponent | mantissa 
	return uExponent | uMantissa;
}

float L11_to_float(uint16_t input_val)
{
	// extract exponent as MS 5 bits 
	int8_t exponent = input_val >> 11;
	// extract mantissa as LS 11 bits 
	int16_t mantissa = input_val & 0x7ff;
	// sign extend exponent from 5 to 8 bits 
	if (exponent > 0x0F) exponent |= 0xE0;
	// sign extend mantissa from 11 to 16 bits 
	if (mantissa > 0x03FF) mantissa |= 0xF800;
	// compute value as mantissa * 2^(exponent) 
	return mantissa * pow(2, exponent);
}

float L16_to_float(unsigned int input_val)
{
	int mantissa = input_val;
	// compute value as mantissa * 2^(exponent)
	return mantissa * pow(2, -9);  //pow2[exponent+16]
}

uint16_t float_to_L16(float input_val)
{
	// The length of the L16 value
	// Read the VOUT_MODE register of your
	// particular device for the value to use
	// LTC3880 = -12
	// LTC2978 = -13
	// set exponent to 2^L16_Length
	float exponent = pow(2.0, -9);
	// convert value to UWord16 and return
	return (uint16_t)(input_val / exponent);
}

short floatToShort(float x) {
	short val = (short)x;
	return val;
}

int16_t floatToInt16(float x)
{
	int16_t val = (int16_t)x;
	return val;
}

long floatToLong(float x)
{
	long val = (long)x;
	return val;
}

int main()
{

	cout << FRAC16(0.5) << endl;
	cout << Q15TOFLOAT(FRAC16(0.5)) << endl;
	cout << FRAC32(0.5) << endl;
	cout << Q32TOFLOAT(FRAC32(0.5)) << endl;
	cout << float_to_L11(10.02) << endl;
	cout << L11_to_float(float_to_L11(10.02)) << endl;
	cout << float_to_L16(20) << endl;
	cout << L16_to_float(float_to_L16(20)) << endl;
	cout << ACC16(20) << endl;
	cout << ACC16TOFLOAT(ACC16(20)) << endl;
	cout << ACC32(20) << endl;
	cout << ACC32TOFLOAT(ACC32(20)) << endl;
	return 0;
}

