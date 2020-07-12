/**
 * WatchDogRest.cpp - A libary for Arduino that will run the NimbleLink Modem
 * Copyright (C) 2020 Donald Boissonneault
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "WatchDogReset.h"

void WatchDogResetClass::start()
{
	cli();;
	// disable all interrupts
	wdt_reset();
	// reset the WDT timer
	/*
	WDTCSR configuration:
	WDIE = 1: Interrupt Enable
	WDE = 1 :Reset Enable
	WDP3 = 0 :For 2000ms Time-out
	WDP2 = 1 :For 2000ms Time-out
	WDP1 = 1 :For 2000ms Time-out
	WDP0 = 1 :For 2000ms Time-out
	*/
	// Enter Watchdog Configuration mode:
	WDTCSR |= (1<<WDCE) | (1<<WDE);
	// Set Watchdog settings:
	WDTCSR = (0<<WDIE) | (1<<WDE) | (1<<WDP3) | (0<<WDP2) | (0<<WDP1) | (1<<WDP0);
	sei();
}
void WatchDogResetClass::resetCounter()
{
	wdt_reset();
}
void WatchDogResetClass::turnOff()
{
	WDTCSR = 0;
}

WatchDogResetClass WatchDogReset;
