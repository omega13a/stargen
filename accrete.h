#ifndef ACCRETE_H
#define ACCRETE_H
#include "structs.h"

void set_initial_conditions(long double, long double);
long double stellar_dust_limit(long double);
long double nearest_planet(long double, long double);
long double farthest_planet(long double);
long double inner_effect_limit(long double, long double, long double);
long double outer_effect_limit(long double, long double, long double);
bool dust_available(long double, long double);
void update_dust_lanes(long double, long double, long double, long double, long double, long double);
long double collect_dust(long double, long double &, long double &, long double, long double, long double, dust *);
long double critical_limit(long double, long double, long double);
void accrete_dust(long double &, long double &, long double &, long double, long double, long double, long double, long double);
void coalesce_planetesimals(long double, long double, long double, long double, long double, long double, long double, long double, long double, bool);
planet *dist_planetary_masses(sun &, long double, long double, long double, long double, long double, long double, planet *, bool);
void free_dust(dust *);
void free_planet(planet *);
void free_generations();
bool is_predefined_planet(planet *);
bool is_in_eriEps(planet *);
bool is_in_UMa47(planet *);
bool is_in_horIot(planet *);
bool is_in_xiumab(planet *);
bool is_in_51peg(planet *);
bool is_in_55can(planet *);
bool is_in_UPSAndA(planet *);
bool is_in_hd10180(planet *);
bool is_in_gliese581(planet *);
bool is_in_hd10647(planet *);
bool is_in_83leoB(planet *);
bool is_in_muari(planet *);
bool is_in_hd28185(planet *);
bool is_in_hd40307(planet *);
bool is_in_kepler22(planet *);
bool is_in_taucet(planet *);
bool is_in_alfcentb(planet *);
bool is_in_EPSEri(planet *);
bool is_cyteen(planet *);
bool is_in_GL849(planet *);
bool is_in_ILAqr(planet *);
bool is_in_HD20794(planet *);
bool is_in_BETHyi(planet *);
bool is_in_hd208527(planet *);
bool is_in_kepler11(planet *);
bool is_in_bajor(planet *);
bool is_in_gliese667C(planet *);
long double calcPerihelion(long double, long double);
#endif
