/**
 * WatchDogReset.h - A libary for Arduino that will run the NimbleLink Modem
 * Copyright (C) 2019 Donald Boissonneault
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
#ifndef WATCHDOGRESET_WATCHDOGRESET_H_
#define WATCHDOGRESET_WATCHDOGRESET_H_

#include <avr/wdt.h>
#if defined(__DOXYGEN__)
/** \def sei()
    \ingroup avr_interrupts

    Enables interrupts by setting the global interrupt mask. This function
    actually compiles into a single line of assembly, so there is no function
    call overhead.  However, the macro also implies a <i>memory barrier</i>
    which can cause additional loss of optimization.

    In order to implement atomic access to multi-byte objects,
    consider using the macros from <util/atomic.h>, rather than
    implementing them manually with cli() and sei().
*/
#define sei()
#else  /* !DOXYGEN */
# define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#endif /* DOXYGEN */

#if defined(__DOXYGEN__)
/** \def cli()
    \ingroup avr_interrupts

    Disables all interrupts by clearing the global interrupt mask. This function
    actually compiles into a single line of assembly, so there is no function
    call overhead.  However, the macro also implies a <i>memory barrier</i>
    which can cause additional loss of optimization.

    In order to implement atomic access to multi-byte objects,
    consider using the macros from <util/atomic.h>, rather than
    implementing them manually with cli() and sei().
*/
#define cli()
#else  /* !DOXYGEN */
# define cli()  __asm__ __volatile__ ("cli" ::: "memory")
#endif /* DOXYGEN */

class WatchDogResetClass
{
public:
	void start();
	void resetCounter();
	void turnOff();
private:
}; extern WatchDogResetClass WatchDogReset;

#endif /* WATCHDOGRESET_WATCHDOGRESET_H_ */
