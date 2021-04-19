/*
 * Synth.cpp
 *
 *  Created on: Apr 19, 2021
 *      Author: michalb
 */

#include "Synth.h"

#include "wavetable.h"

Synth::Synth() {
	// TODO Auto-generated constructor stub

}

Synth::~Synth() {
	// TODO Auto-generated destructor stub
}

float Synth::calculate_oscilator() {
	uint16_t a, b;
	float da, db;

	float osc_wtb_incr = WTB_LEN * (pitch) / SAMPLERATE;
	osc_wtb_pointer = osc_wtb_pointer + osc_wtb_incr;
	if (osc_wtb_pointer > WTB_LEN)
	{
		osc_wtb_pointer = osc_wtb_pointer - WTB_LEN;
	}

	a = (int)osc_wtb_pointer;
	da = osc_wtb_pointer - a;
	b = a + 1;
	db = b - osc_wtb_pointer;

	if (b >= WTB_LEN)
		b = 0;

	osc = db * triangle[a] + da * triangle[b];

	signal = osc * 32767.0f;
	if (signal > 32767.0f)
		signal = 32767.0f;
	if (signal < -32767.0f)
		signal = -32767.0f;
	return signal;
}
