#ifndef SOLID_RADIUS_HELPERS_H
#define SOLID_RADIUS_HELPERS_H
#include "structs.h"

long double water_radius(long double, planet *);
long double one_quater_rock_three_fourths_water_radius(long double, long double, planet *);
long double half_rock_half_water_radius(long double, long double, planet *);
long double rock_radius(long double, long double, planet *);
long double half_rock_half_iron_radius(long double, long double, planet *);
long double iron_radius(long double, planet *);
long double fraction_radius(long double, long double, long double, long double);

#endif
