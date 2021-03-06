/*
 * \file
 *    spa_grena.h
 * \brief
 *    R Grena (2008), An algorithm for the computation of the solar position,
 *    Solar Energy (82), pp 462-470.
 *
 * This file is part of toolbox
 *
 * Copyright (C) 2014 Houtouridis Christos (http://www.houtouridis.net)
 *
 * This header file contains the declaration of a type which includes all the
 * input and output data, and the function that performs the calculation.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef __spa_grena_h__
#define __spa_grena_h__

#ifdef __cpluaplua
extern "C" {
#endif

#include <time.h>
#include <math.h>

#ifndef M_PI
#define M_PI      3.14159265358979323846
#endif

#define SPA_ELEVATION_REFRACTION_TH    (-0.01)

/*
 * ============ Data types ============
 */

/*!
 * Main sun position algo data type
 */
typedef struct {
   double njd;          //!< Normalized Julian Day, offset such that 0 = noon 1 Jan 2003.
   double delta_t;      //!< Difference between UT and Terrestrial Time, in seconds. Zero is probably OK here.
   double jd;
   double latitude;     //!< Latitude (N = positive), in RADIANS.
   double longitude;    //!< Longitude (E = positive), in RADIANS.
   double p;            //!< Pressure, in ATM (used for refraction calculation)
   double T;            //!< Temperature, in �C (used for refraction calculation)
}spa_t;


/*
 * ============= Link Functions ===========
 */

/*
 * ============= Set functions ============
 */
void spa_set_time (spa_t *spa, time_t utc, double dt);
void spa_set_latitude (spa_t *spa, double lat);
void spa_set_longitude (spa_t *spa, double lon);
void spa_set_pressure (spa_t *spa, double p);
void spa_set_temperature (spa_t *spa, double T);

/*
 * ============ User functions ===========
 */
void spa_init (spa_t *spa);
void spa_calculation (spa_t *spa, double *elev, double *azimuth);

#ifdef __cpluaplua
}
#endif

#endif   // #ifndef __spa_grena_h__
