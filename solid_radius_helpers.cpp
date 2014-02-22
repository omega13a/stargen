#include "solid_radius_helpers.h"
#include "const.h"
#include "enviro.h"
#include "stargen.h"
#include "structs.h"
#include "utils.h"
#include <map>

using namespace std;

long double water_radius(long double mass, planet *the_planet)
{
  long double radius;
  bool adjust_for_carbon;
  long double radius1;
  long double radius2;
  map<long double, long double> mass_radii;
  mass_radii[0.04663] = 0.58;
  mass_radii[0.06174] = 0.63;
  mass_radii[0.08208] = 0.6853;
  mass_radii[0.1091] = 0.7455;
  mass_radii[0.1445] = 0.8102;
  mass_radii[0.1904] = 0.879;
  mass_radii[0.2494] = 0.9515;
  mass_radii[0.3249] = 1.028;
  mass_radii[0.4206] = 1.107;
  mass_radii[0.5416] = 1.19;
  mass_radii[0.6938] = 1.276;
  mass_radii[0.8866] = 1.366;
  mass_radii[1.132] = 1.461;
  mass_radii[1.444] = 1.562;
  mass_radii[1.841] = 1.699;
  mass_radii[2.346] = 1.782;
  mass_radii[2.985] = 1.901;
  mass_radii[3.77] = 2.023;
  mass_radii[4.735] = 2.147;
  mass_radii[5.909] = 2.274;
  mass_radii[7.325] = 2.401;
  mass_radii[9.038] = 2.529;
  mass_radii[11.11] = 2.66;
  mass_radii[13.55] = 2.789;
  mass_radii[16.42] = 2.915;
  mass_radii[19.77] = 3.039;
  mass_radii[23.68] = 3.16;
  mass_radii[28.21] = 3.278;
  mass_radii[33.49] = 3.393;
  mass_radii[39.62] = 3.506;
  mass_radii[46.72] = 3.616;
  mass_radii[54.92] = 3.724;
  mass_radii[64.22] = 3.826;
  mass_radii[74.79] = 3.924;
  mass_radii[86.85] = 4.017;
  mass_radii[100.3] = 4.104;
  mass_radii[115.3] = 4.183;
  mass_radii[131.9] = 4.256;
  mass_radii[150.3] = 4.322;
  mass_radii[170.8] = 4.382;
  mass_radii[193.6] = 4.435;
  mass_radii[218.7] = 4.483;
  mass_radii[246.6] = 4.525;
  mass_radii[277.3] = 4.561;
  mass_radii[311.3] = 4.592;
  mass_radii[348.7] = 4.618;
  mass_radii[390.1] = 4.639;
  mass_radii[435.9] = 4.656;
  mass_radii[486.4] = 4.669;
  if (mass <= 0.04663)
  {
    adjust_for_carbon = false;
    radius1 = fraction_radius(mass, 1.0, 0, 0);
    radius2 = planet_radius_helper(mass, 0.04663, mass_radii[0.04663], 0.06174, mass_radii[0.06174], 0.08208, mass_radii[0.08208]);
    radius = rangeAdjust(mass, radius1, radius2, 0.0, 0.04663);
  }
  else if (mass <= 0.06174)
  {
    //radius = quad_trend(-16.65123034, 5.113560675, 0.3777603833, mass);
    radius = planet_radius_helper(mass, 0.04663, mass_radii[0.04663], 0.06174, mass_radii[0.06174], 0.08208, mass_radii[0.08208]);
  }
  else if (mass <= 0.08208)
  {
    //radius = quad_trend(-10.36320636, 4.209217066, 0.4096256944, mass);
    radius1 = planet_radius_helper(mass, 0.04663, mass_radii[0.04663], 0.06174, mass_radii[0.06174], 0.08208, mass_radii[0.08208]);
    radius2 = planet_radius_helper(mass, 0.06174, mass_radii[0.06174], 0.08208, mass_radii[0.08208], 0.1091, mass_radii[0.1091]);
    radius = rangeAdjust(mass, radius1, radius2, 0.06174, 0.08208);
  }
  else if (mass <= 0.1091)
  {
    //radius = quad_trend(-6.412939103, 3.454004972, 0.450000532, mass);
    radius1 = planet_radius_helper(mass, 0.06174, mass_radii[0.06174], 0.08208, mass_radii[0.08208], 0.1091, mass_radii[0.1091]);
    radius2 = planet_radius_helper(mass, 0.08208, mass_radii[0.08208], 0.1091, mass_radii[0.1091], 0.1445, mass_radii[0.1445]);
    radius = rangeAdjust(mass, radius1, radius2, 0.08208, 0.1091);
  }
  else if (mass <= 0.1445)
  {
    //radius = quad_trend(-4.043947607, 2.853228729, 0.4823470857, mass);
    radius1 = planet_radius_helper(mass, 0.08208, mass_radii[0.08208], 0.1091, mass_radii[0.1091], 0.1445, mass_radii[0.1445]);
    radius2 = planet_radius_helper(mass, 0.1091, mass_radii[0.1091], 0.1445, mass_radii[0.1445], 0.1904, mass_radii[0.1904]);
    radius = rangeAdjust(mass, radius1, radius2, 0.1091, 0.1445);
  }
  else if (mass <= 0.1904)
  {
    //radius = quad_trend(-2.574805682, 2.361213098, 0.5227672936, mass);
    radius1 = planet_radius_helper(mass, 0.1091, mass_radii[0.1091], 0.1445, mass_radii[0.1445], 0.1904, mass_radii[0.1904]);
    radius2 = planet_radius_helper(mass, 0.1445, mass_radii[0.1445], 0.1904, mass_radii[0.1904], 0.2494, mass_radii[0.2494]);
    radius = rangeAdjust(mass, radius1, radius2, 0.1445, 0.1904);
  }
  else if (mass <= 0.2494)
  {
    //radius = quad_trend(-1.602739972, 1.933698599, 0.5689265727, mass);
    radius1 = planet_radius_helper(mass, 0.1445, mass_radii[0.1445], 0.1904, mass_radii[0.1904], 0.2494, mass_radii[0.2494]);
    radius2 = planet_radius_helper(mass, 0.1904, mass_radii[0.1904], 0.2494, mass_radii[0.2494], 0.3249, mass_radii[0.3249]);
    radius = rangeAdjust(mass, radius1, radius2, 0.1904, 0.2494);
  }
  else if (mass <= 0.3249)
  {
    //radius = quad_trend(-1.096662911, 1.643058543, 0.6099340273, mass);
    radius1 = planet_radius_helper(mass, 0.1904, mass_radii[0.1904], 0.2494, mass_radii[0.2494], 0.3249, mass_radii[0.3249]);
    radius2 = planet_radius_helper(mass, 0.2494, mass_radii[0.2494], 0.3249, mass_radii[0.3249], 0.4206, mass_radii[0.4206]);
    radius = rangeAdjust(mass, radius1, radius2, 0.2494, 0.3249);
  }
  else if (mass <= 0.4206)
  {
    //radius = quad_trend(-0.6439590656, 1.305567826, 0.6717973387, mass);
    radius1 = planet_radius_helper(mass, 0.2494, mass_radii[0.2494], 0.3249, mass_radii[0.3249], 0.4206, mass_radii[0.4206]);
    radius2 = planet_radius_helper(mass, 0.3249, mass_radii[0.3249], 0.4206, mass_radii[0.4206], 0.5416, mass_radii[0.5416]);
    radius = rangeAdjust(mass, radius1, radius2, 0.3249, 0.4206);
  }
  else if (mass <= 0.5416)
  {
    //radius = quad_trend(-0.4425491256, 1.111771182, 0.7176779107, mass);
    radius1 = planet_radius_helper(mass, 0.3249, mass_radii[0.3249], 0.4206, mass_radii[0.4206], 0.5416, mass_radii[0.5416]);
    radius2 = planet_radius_helper(mass, 0.4206, mass_radii[0.4206], 0.5416, mass_radii[0.5416], 0.6938, mass_radii[0.6938]);
    radius = rangeAdjust(mass, radius1, radius2, 0.4206, 0.5416);
  }
  else if (mass <= 0.6938)
  {
    //radius = quad_trend(-0.284756559, 0.9168342451, 0.7769703738, mass);
    radius1 = planet_radius_helper(mass, 0.4206, mass_radii[0.4206], 0.5416, mass_radii[0.5416], 0.6938, mass_radii[0.6938]);
    radius2 = planet_radius_helper(mass, 0.5416, mass_radii[0.5416], 0.6938, mass_radii[0.6938], 0.8866, mass_radii[0.8866]);
    radius = rangeAdjust(mass, radius1, radius2, 0.5416, 0.6938);
  }
  else if (mass <= 0.8866)
  {
    //radius = quad_trend(-0.1818391485, 0.7541835695, 0.8402772483, mass);
    radius1 = planet_radius_helper(mass, 0.5416, mass_radii[0.5416], 0.6938, mass_radii[0.6938], 0.8866, mass_radii[0.8866]);
    radius2 = planet_radius_helper(mass, 0.6938, mass_radii[0.6938], 0.8866, mass_radii[0.8866], 1.132, mass_radii[1.132]);
    radius = rangeAdjust(mass, radius1, radius2, 0.6938, 0.8866);
  }
  else if (mass <= 1.132)
  {
    //radius = quad_trend(-0.113751553, 0.6167419494, 0.9086120834, mass);
    radius1 = planet_radius_helper(mass, 0.6938, mass_radii[0.6938], 0.8866, mass_radii[0.8866], 1.132, mass_radii[1.132]);
    radius2 = planet_radius_helper(mass, 0.8866, mass_radii[0.8866], 1.132, mass_radii[1.132], 1.444, mass_radii[1.444]);
    radius = rangeAdjust(mass, radius1, radius2, 0.8866, 1.132);
  }
  else if (mass <= 1.444)
  {
    //radius = quad_trend(-0.0764408154, 0.5206294893, 0.9696005136, mass);
    radius1 = planet_radius_helper(mass, 0.8866, mass_radii[0.8866], 1.132, mass_radii[1.132], 1.444, mass_radii[1.444]);
    radius2 = planet_radius_helper(mass, 1.132, mass_radii[1.132], 1.444, mass_radii[1.444], 1.841, mass_radii[1.841]);
    radius = rangeAdjust(mass, radius1, radius2, 1.132, 1.444);
  }
  else if (mass <= 1.841)
  {
    //radius = quad_trend(-0.0507306367, 0.4361715523, 1.037948555, mass);
    radius1 = planet_radius_helper(mass, 1.132, mass_radii[1.132], 1.444, mass_radii[1.444], 1.841, mass_radii[1.841]);
    radius2 = planet_radius_helper(mass, 1.444, mass_radii[1.444], 1.841, mass_radii[1.841], 2.346, mass_radii[2.346]);
    radius = rangeAdjust(mass, radius1, radius2, 1.444, 1.841);
  }
  else if (mass <= 2.346)
  {
    //radius = quad_trend(-0.0328093481, 0.3611351168, 1.11535035, mass);
    radius1 = planet_radius_helper(mass, 1.444, mass_radii[1.444], 1.841, mass_radii[1.841], 2.346, mass_radii[2.346]);
    radius2 = planet_radius_helper(mass, 1.841, mass_radii[1.841], 2.346, mass_radii[2.346], 2.985, mass_radii[2.985]);
    radius = rangeAdjust(mass, radius1, radius2, 1.841, 2.346);
  }
  else if (mass <= 2.985)
  {
    //radius = quad_trend(-0.0216393745, 0.3015879874, 1.193571553, mass);
    radius1 = planet_radius_helper(mass, 1.841, mass_radii[1.841], 2.346, mass_radii[2.346], 2.985, mass_radii[2.985]);
    radius2 = planet_radius_helper(mass, 2.346, mass_radii[2.346], 2.985, mass_radii[2.985], 3.77, mass_radii[3.77]);
    radius = rangeAdjust(mass, radius1, radius2, 2.346, 2.985);
  }
  else if (mass <= 3.77)
  {
    //radius = quad_trend(-0.0153809162, 0.2593121019, 1.2640008, mass);
    radius1 = planet_radius_helper(mass, 2.346, mass_radii[2.346], 2.985, mass_radii[2.985], 3.77, mass_radii[3.77]);
    radius2 = planet_radius_helper(mass, 2.985, mass_radii[2.985], 3.77, mass_radii[3.77], 4.735, mass_radii[4.735]);
    radius = rangeAdjust(mass, radius1, radius2, 2.985, 3.77);
  }
  else if (mass <= 4.735)
  {
    //radius = quad_trend(-0.0094998772, 0.2092938647, 1.368982934, mass);
    radius1 = planet_radius_helper(mass, 2.985, mass_radii[2.985], 3.77, mass_radii[3.77], 4.735, mass_radii[4.735]);
    radius2 = planet_radius_helper(mass, 3.77, mass_radii[3.77], 4.735, mass_radii[4.735], 5.909, mass_radii[5.909]);
    radius = rangeAdjust(mass, radius1, radius2, 3.77, 4.735);
  }
  else if (mass <= 5.909)
  {
    //radius = quad_trend(-0.0071381878, 0.1841560435, 1.435060912, mass);
    radius1 = planet_radius_helper(mass, 3.77, mass_radii[3.77], 4.735, mass_radii[4.735], 5.909, mass_radii[5.909]);
    radius2 = planet_radius_helper(mass, 4.735, mass_radii[4.735], 5.909, mass_radii[5.909], 7.325, mass_radii[7.325]);
    radius = rangeAdjust(mass, radius1, radius2, 4.735, 5.909);
  }
  else if (mass <= 7.325)
  {
    //radius = quad_trend(-0.0047831757, 0.1529898131, 1.536993902, mass);
    radius1 = planet_radius_helper(mass, 4.735, mass_radii[4.735], 5.909, mass_radii[5.909], 7.325, mass_radii[7.325]);
    radius2 = planet_radius_helper(mass, 5.909, mass_radii[5.909], 7.325, mass_radii[7.325], 9.038, mass_radii[9.038]);
    radius = rangeAdjust(mass, radius1, radius2, 5.909, 7.325);
  }
  else if (mass <= 9.038)
  {
    //radius = quad_trend(-0.0030379843, 0.1244332454, 1.652531423, mass);
    radius1 = planet_radius_helper(mass, 5.909, mass_radii[5.909], 7.325, mass_radii[7.325], 9.038, mass_radii[9.038]);
    radius2 = planet_radius_helper(mass, 7.325, mass_radii[7.325], 9.038, mass_radii[9.038], 11.11, mass_radii[11.11]);
    radius = rangeAdjust(mass, radius1, radius2, 7.325, 9.038);
  }
  else if (mass <= 11.11)
  {
    //radius = quad_trend(-0.0022950101, 0.1094638026, 1.727135075, mass);
    radius1 = planet_radius_helper(mass, 7.325, mass_radii[7.325], 9.038, mass_radii[9.038], 11.11, mass_radii[11.11]);
    radius2 = planet_radius_helper(mass, 9.038, mass_radii[9.038], 11.11, mass_radii[11.11], 13.55, mass_radii[13.55]);
    radius = rangeAdjust(mass, radius1, radius2, 9.038, 11.11);
  }
  else if (mass <= 13.55)
  {
    //radius = quad_trend(-0.0016885901, 0.0945094843, 1.818425851, mass);
    radius1 = planet_radius_helper(mass, 9.038, mass_radii[9.038], 11.11, mass_radii[11.11], 13.55, mass_radii[13.55]);
    radius2 = planet_radius_helper(mass, 11.11, mass_radii[11.11], 13.55, mass_radii[13.55], 16.42, mass_radii[16.42]);
    radius = rangeAdjust(mass, radius1, radius2, 11.11, 13.55);
  }
  else if (mass <= 16.42)
  {
    //radius = quad_trend(-0.0011073173, 0.0770887387, 1.947753816, mass);
    radius1 = planet_radius_helper(mass, 11.11, mass_radii[11.11], 13.55, mass_radii[13.55], 16.42, mass_radii[16.42]);
    radius2 = planet_radius_helper(mass, 13.55, mass_radii[13.55], 16.42, mass_radii[16.42], 19.77, mass_radii[19.77]);
    radius = rangeAdjust(mass, radius1, radius2, 13.55, 16.42);
  }
  else if (mass <= 19.77)
  {
    //radius = quad_trend(-8.359E-4, 0.0672661454, 2.035862234, mass);
    radius1 = planet_radius_helper(mass, 13.55, mass_radii[13.55], 16.42, mass_radii[16.42], 19.77, mass_radii[19.77]);
    radius2 = planet_radius_helper(mass, 16.42, mass_radii[16.42], 19.77, mass_radii[19.77], 23.68, mass_radii[23.68]);
    radius = rangeAdjust(mass, radius1, radius2, 16.42, 19.77);
  }
  else if (mass <= 23.68)
  {
    //radius = quad_trend(-5.802993E-4, 0.0561602979, 2.15552259, mass);
    radius1 = planet_radius_helper(mass, 16.42, mass_radii[16.42], 19.77, mass_radii[19.77], 23.68, mass_radii[23.68]);
    radius2 = planet_radius_helper(mass, 19.77, mass_radii[19.77], 23.68, mass_radii[23.68], 28.21, mass_radii[28.21]);
    radius = rangeAdjust(mass, radius1, radius2, 19.77, 23.68);
  }
  else if (mass <= 28.21)
  {
    //radius = quad_trend(-4.35093E-4, 0.0486255396, 2.252522301, mass);
    radius1 = planet_radius_helper(mass, 19.77, mass_radii[19.77], 23.68, mass_radii[23.68], 28.21, mass_radii[28.21]);
    radius2 = planet_radius_helper(mass, 23.68, mass_radii[23.68], 28.21, mass_radii[28.21], 33.49, mass_radii[33.49]);
    radius = rangeAdjust(mass, radius1, radius2, 23.68, 28.21);
  }
  else if (mass <= 33.49)
  {
    //radius = quad_trend(-2.932841E-4, 0.0398759318, 2.38649665, mass);
    radius1 = planet_radius_helper(mass, 23.68, mass_radii[23.68], 28.21, mass_radii[28.21], 33.49, mass_radii[33.49]);
    radius2 = planet_radius_helper(mass, 28.21, mass_radii[28.21], 33.49, mass_radii[33.49], 39.62, mass_radii[39.62]);
    radius = rangeAdjust(mass, radius1, radius2, 28.21, 33.49);
  }
  else if (mass <= 39.62)
  {
    //radius = quad_trend(-2.222958E-4, 0.0346859791, 2.480689131, mass);
    radius1 = planet_radius_helper(mass, 28.21, mass_radii[28.21], 33.49, mass_radii[33.49], 39.62, mass_radii[39.62]);
    radius2 = planet_radius_helper(mass, 33.49, mass_radii[33.49], 39.62, mass_radii[39.62], 46.72, mass_radii[46.72]);
    radius = rangeAdjust(mass, radius1, radius2, 33.49, 39.62);
  }
  else if (mass <= 46.72)
  {
    //radius = quad_trend(-1.517795E-4, 0.028597598, 2.611218155, mass);
    radius1 = planet_radius_helper(mass, 33.49, mass_radii[33.49], 39.62, mass_radii[39.62], 46.72, mass_radii[46.72]);
    radius2 = planet_radius_helper(mass, 39.62, mass_radii[39.62], 46.72, mass_radii[46.72], 54.92, mass_radii[54.92]);
    radius = rangeAdjust(mass, radius1, radius2, 39.62, 46.72);
  }
  else if (mass <= 54.92)
  {
    //radius = quad_trend(-1.258851E-4, 0.0259656963, 2.677659493, mass);
    radius1 = planet_radius_helper(mass, 39.62, mass_radii[39.62], 46.72, mass_radii[46.72], 54.92, mass_radii[54.92]);
    radius2 = planet_radius_helper(mass, 46.72, mass_radii[46.72], 54.92, mass_radii[54.92], 64.22, mass_radii[64.22]);
    radius = rangeAdjust(mass, radius1, radius2, 46.72, 54.92);
  }
  else if (mass <= 64.22)
  {
    //radius = quad_trend(-8.536582E-5, 0.0211382252, 2.820569591, mass);
    radius1 = planet_radius_helper(mass, 46.72, mass_radii[46.72], 54.92, mass_radii[54.92], 64.22, mass_radii[64.22]);
    radius2 = planet_radius_helper(mass, 54.92, mass_radii[54.92], 64.22, mass_radii[64.22], 74.79, mass_radii[74.79]);
    radius = rangeAdjust(mass, radius1, radius2, 54.92, 64.22);
  }
  else if (mass <= 74.79)
  {
    //radius = quad_trend(-6.893859E-5, 0.0188546772, 2.899469761, mass);
    radius1 = planet_radius_helper(mass, 54.92, mass_radii[54.92], 64.22, mass_radii[64.22], 74.79, mass_radii[74.79]);
    radius2 = planet_radius_helper(mass, 64.22, mass_radii[64.22], 74.79, mass_radii[74.79], 86.85, mass_radii[86.85]);
    radius = rangeAdjust(mass, radius1, radius2, 64.22, 74.79);
  }
  else if (mass <= 86.85)
  {
    //radius = quad_trend(-4.872761E-5, 0.0155877735, 3.030750451, mass);
    radius1 = planet_radius_helper(mass, 64.22, mass_radii[64.22], 74.79, mass_radii[74.79], 86.85, mass_radii[86.85]);
    radius2 = planet_radius_helper(mass, 74.79, mass_radii[74.79], 86.85, mass_radii[86.85], 100.3, mass_radii[100.3]);
    radius = rangeAdjust(mass, radius1, radius2, 74.79, 86.85);
  }
  else if (mass <= 100.3)
  {
    //radius = quad_trend(-4.224024E-5, 0.0143736624, 3.087262279, mass);
    radius1 = planet_radius_helper(mass, 74.79, mass_radii[74.79], 86.85, mass_radii[86.85], 100.3, mass_radii[100.3]);
    radius2 = planet_radius_helper(mass, 86.85, mass_radii[86.85], 100.3, mass_radii[100.3], 115.3, mass_radii[115.3]);
    radius = rangeAdjust(mass, radius1, radius2, 86.85, 100.3);
  }
  else if (mass <= 115.3)
  {
    //radius = quad_trend(-2.750241E-5, 0.0111961873, 3.257699183, mass);
    radius1 = planet_radius_helper(mass, 86.85, mass_radii[86.85], 100.3, mass_radii[100.3], 115.3, mass_radii[115.3]);
    radius2 = planet_radius_helper(mass, 100.3, mass_radii[100.3], 115.3, mass_radii[115.3], 131.9, mass_radii[131.9]);
    radius = rangeAdjust(mass, radius1, radius2, 100.3, 115.3);
  }
  else if (mass <= 131.9)
  {
    //radius = quad_trend(-2.316097E-5, 0.0101229814, 3.323724226, mass);
    radius1 = planet_radius_helper(mass, 100.3, mass_radii[100.3], 115.3, mass_radii[115.3], 131.9, mass_radii[131.9]);
    radius2 = planet_radius_helper(mass, 115.3, mass_radii[115.3], 131.9, mass_radii[131.9], 150.3, mass_radii[150.3]);
    radius = rangeAdjust(mass, radius1, radius2, 115.3, 131.9);
  }
  else if (mass <= 150.3)
  {
    //radius = quad_trend(-1.696985E-5, 0.0083758488, 3.44646041, mass);
    radius1 = planet_radius_helper(mass, 115.3, mass_radii[115.3], 131.9, mass_radii[131.9], 150.3, mass_radii[150.3]);
    radius2 = planet_radius_helper(mass, 131.9, mass_radii[131.9], 150.3, mass_radii[150.3], 170.8, mass_radii[170.8]);
    radius = rangeAdjust(mass, radius1, radius2, 131.9, 150.3);
  }
  else if (mass <= 170.8)
  {
    //radius = quad_trend(-1.390919E-5, 0.0073930697, 3.525031443, mass);
    radius1 = planet_radius_helper(mass, 131.9, mass_radii[131.9], 150.3, mass_radii[150.3], 170.8, mass_radii[170.8]);
    radius2 = planet_radius_helper(mass, 150.3, mass_radii[150.3], 170.8, mass_radii[170.8], 193.6, mass_radii[193.6]);
    radius = rangeAdjust(mass, radius1, radius2, 150.3, 170.8);
  }
  else if (mass <= 193.6)
  {
    //radius = quad_trend(-8.605654E-6, 0.0054604616, 3.700402798, mass);
    radius1 = planet_radius_helper(mass, 150.3, mass_radii[150.3], 170.8, mass_radii[170.8], 193.6, mass_radii[193.6]);
    radius2 = planet_radius_helper(mass, 170.8, mass_radii[170.8], 193.6, mass_radii[193.6], 218.7, mass_radii[218.7]);
    radius = rangeAdjust(mass, radius1, radius2, 170.8, 193.6);
  }
  else if (mass <= 218.7)
  {
    //radius = quad_trend(-7.67876E-6, 0.0050783031, 3.73964779, mass);
    radius1 = planet_radius_helper(mass, 170.8, mass_radii[170.8], 193.6, mass_radii[193.6], 218.7, mass_radii[218.7]);
    radius2 = planet_radius_helper(mass, 193.6, mass_radii[193.6], 218.7, mass_radii[218.7], 246.6, mass_radii[246.6]);
    radius = rangeAdjust(mass, radius1, radius2, 193.6, 218.7);
  }
  else if (mass <= 246.6)
  {
    //radius = quad_trend(-5.678121E-6, 0.0041474062, 3.847545049, mass);
    radius1 = planet_radius_helper(mass, 193.6, mass_radii[193.6], 218.7, mass_radii[218.7], 246.6, mass_radii[246.6]);
    radius2 = planet_radius_helper(mass, 218.7, mass_radii[218.7], 246.6, mass_radii[246.6], 277.3, mass_radii[277.3]);
    radius = rangeAdjust(mass, radius1, radius2, 218.7, 246.6);
  }
  else if (mass <= 277.3)
  {
    //radius = quad_trend(-4.032051E-6, 0.0032850302, 3.960106892, mass);
    radius1 = planet_radius_helper(mass, 218.7, mass_radii[218.7], 246.6, mass_radii[246.6], 277.3, mass_radii[277.3]);
    radius2 = planet_radius_helper(mass, 246.6, mass_radii[246.6], 277.3, mass_radii[277.3], 311.3, mass_radii[311.3]);
    radius = rangeAdjust(mass, radius1, radius2, 246.6, 277.3);
  }
  else if (mass <= 311.3)
  {
    //radius = quad_trend(-3.033299E-6, 0.0026971644, 4.046322701, mass);
    radius1 = planet_radius_helper(mass, 246.6, mass_radii[246.6], 277.3, mass_radii[277.3], 311.3, mass_radii[311.3]);
    radius2 = planet_radius_helper(mass, 277.3, mass_radii[277.3], 311.3, mass_radii[311.3], 348.7, mass_radii[348.7]);
    radius = rangeAdjust(mass, radius1, radius2, 277.3, 311.3);
  }
  else if (mass <= 348.7)
  {
    //radius = quad_trend(-2.385035E-6, 0.0022693105, 4.116691904, mass);
    radius1 = planet_radius_helper(mass, 277.3, mass_radii[277.3], 311.3, mass_radii[311.3], 348.7, mass_radii[348.7]);
    radius2 = planet_radius_helper(mass, 311.3, mass_radii[311.3], 348.7, mass_radii[348.7], 390.1, mass_radii[390.1]);
    radius = rangeAdjust(mass, radius1, radius2, 277.3, 311.3);
  }
  else if (mass <= 390.1)
  {
    //radius = quad_trend(-1.560405E-6, 0.0016600738, 4.228864586, mass);
    radius1 = planet_radius_helper(mass, 311.3, mass_radii[311.3], 348.7, mass_radii[348.7], 390.1, mass_radii[390.1]);
    radius2 = planet_radius_helper(mass, 348.7, mass_radii[348.7], 390.1, mass_radii[390.1], 435.9, mass_radii[435.9]);
    radius = rangeAdjust(mass, radius1, radius2, 311.3, 390.1);
  }
  else if (mass <= 435.9)
  {
    //radius = quad_trend(-1.181239E-6, 0.0013468823, 4.293339789, mass);
    radius1 = planet_radius_helper(mass, 348.7, mass_radii[348.7], 390.1, mass_radii[390.1], 435.9, mass_radii[435.9]);
    radius2 = planet_radius_helper(mass, 390.1, mass_radii[390.1], 435.9, mass_radii[435.9], 486.4, mass_radii[486.4]);
    radius = rangeAdjust(mass, radius1, radius2, 390.1, 435.9);
  }
  else if (mass <= 486.4)
  {
    radius1 = planet_radius_helper(mass, 390.1, mass_radii[390.1], 435.9, mass_radii[435.9], 486.4, mass_radii[486.4]);
    radius2 = planet_radius_helper2(mass, 435.9, mass_radii[435.9], 486.4, mass_radii[486.4]);
    radius = rangeAdjust(mass, radius1, radius2, 390.1, 435.9);
  }
  else
  {
    //radius = ln_trend(3.935260455, 0.1185931516, mass);
    radius = rangeAdjust(mass, radius1, radius2, 390.1, 435.9);
  }
  if (flag_verbose & 0x80000)
  {
    radiusDebug("100% water/ice", the_planet, radius, mass_radii);
  }
  return radius;
}

long double one_quater_rock_three_fourths_water_radius(long double mass, long double cmf, planet *the_planet)
{
  long double radius;
  long double radius1;
  long double radius2;
  bool adjust_for_carbon;
  long double carbon_fraction;
  long double grow_factor;
  long double rmf;
  map<long double, long double> mass_radii;
  mass_radii[0.01217] = 0.3616;
  mass_radii[0.01699] = 0.4009;
  mass_radii[0.02351] = 0.4432;
  mass_radii[0.03213] = 0.4869;
  mass_radii[0.04399] = 0.535;
  mass_radii[0.06029] = 0.588;
  mass_radii[0.08255] = 0.6461;
  mass_radii[0.1127] = 0.7093;
  mass_radii[0.1533] = 0.7777;
  mass_radii[0.2074] = 0.8509;
  mass_radii[0.2789] = 0.9289;
  mass_radii[0.3726] = 1.011;
  mass_radii[0.4946] = 1.098;
  mass_radii[0.6517] = 1.188;
  mass_radii[0.8529] = 1.282;
  mass_radii[1.107] = 1.38;
  mass_radii[1.42] = 1.477;
  mass_radii[1.818] = 1.58;
  mass_radii[2.321] = 1.688;
  mass_radii[2.957] = 1.802;
  mass_radii[3.752] = 1.92;
  mass_radii[4.732] = 2.041;
  mass_radii[5.936] = 2.164;
  mass_radii[7.407] = 2.289;
  mass_radii[9.127] = 2.411;
  mass_radii[11.12] = 2.529;
  mass_radii[13.52] = 2.647;
  mass_radii[16.37] = 2.765;
  mass_radii[19.72] = 2.882;
  mass_radii[23.68] = 2.998;
  mass_radii[28.31] = 3.111;
  mass_radii[33.71] = 3.222;
  mass_radii[39.97] = 3.33;
  mass_radii[47.15] = 3.434;
  mass_radii[55.31] = 3.534;
  mass_radii[64.47] = 3.627;
  mass_radii[74.65] = 3.713;
  mass_radii[86.14] = 3.793;
  mass_radii[99.08] = 3.87;
  mass_radii[113.6] = 3.94;
  mass_radii[129.7] = 4.006;
  mass_radii[147.6] = 4.064;
  mass_radii[167.2] = 4.116;
  mass_radii[188.8] = 4.162;
  mass_radii[212.5] = 4.202;
  mass_radii[238.4] = 4.236;
  mass_radii[266.8] = 4.265;
  mass_radii[297.9] = 4.288;
  mass_radii[332.1] = 4.307;
  adjust_for_carbon = true;
  rmf = 0.25;
  if (mass <= 0.01217)
  {
    radius1 = fraction_radius(mass, 0.75, 0.25, cmf);
    radius2 = planet_radius_helper(mass, 0.01217, mass_radii[0.01217], 0.01699, mass_radii[0.01699], 0.02351, mass_radii[0.02351]);
    radius = rangeAdjust(mass, radius1, radius2, 0.0, 0.01217);
  }
  else if (mass <= 0.01699)
  {
    //radius = quad_trend(-146.895671, 12.43700474, 0.2319982086, mass);
    radius = planet_radius_helper(mass, 0.01217, mass_radii[0.01217], 0.01699, mass_radii[0.01699], 0.02351, mass_radii[0.02351]);
  }
  else if (mass <= 0.02351)
  {
    //radius = quad_trend(-93.66740376, 10.28125991, 0.2532594362, mass);
    radius1 = planet_radius_helper(mass, 0.01217, mass_radii[0.01217], 0.01699, mass_radii[0.01699], 0.02351, mass_radii[0.02351]);
    radius2 = planet_radius_helper(mass, 0.01699, mass_radii[0.01699], 0.02351, mass_radii[0.02351], 0.03213, mass_radii[0.03213]);
    radius = rangeAdjust(mass, radius1, radius2, 0.01699, 0.02351);
  }
  else if (mass <= 0.03213)
  {
    //radius = quad_trend(-49.50958629, 7.82431895, 0.286615205, mass);
    radius1 = planet_radius_helper(mass, 0.01699, mass_radii[0.01699], 0.02351, mass_radii[0.02351], 0.03213, mass_radii[0.03213]);
    radius2 = planet_radius_helper(mass, 0.02351, mass_radii[0.02351], 0.03213, mass_radii[0.03213], 0.04399, mass_radii[0.04399]);
    radius = rangeAdjust(mass, radius1, radius2, 0.02351, 0.03213);
  }
  else if (mass <= 0.04399)
  {
    //radius = quad_trend(-28.55523788, 6.229273949, 0.3162320538, mass);
    radius1 = planet_radius_helper(mass, 0.02351, mass_radii[0.02351], 0.03213, mass_radii[0.03213], 0.04399, mass_radii[0.04399]);
    radius2 = planet_radius_helper(mass, 0.03213, mass_radii[0.03213], 0.04399, mass_radii[0.04399], 0.06029, mass_radii[0.06029]);
    radius = rangeAdjust(mass, radius1, radius2, 0.03213, 0.04399);
  }
  else if (mass <= 0.06029)
  {
    //radius = quad_trend(-16.6356548, 4.986299825, 0.3478446607, mass);
    radius1 = planet_radius_helper(mass, 0.03213, mass_radii[0.03213], 0.04399, mass_radii[0.04399], 0.06029, mass_radii[0.06029]);
    radius2 = planet_radius_helper(mass, 0.04399, mass_radii[0.04399], 0.06029, mass_radii[0.06029], 0.08255, mass_radii[0.08255]);
    radius = rangeAdjust(mass, radius1, radius2, 0.04399, 0.06029);
  }
  else if (mass <= 0.08255)
  {
    //radius = quad_trend(-9.804944764, 4.010601203, 0.3818406913, mass);
    radius1 = planet_radius_helper(mass, 0.04399, mass_radii[0.04399], 0.06029, mass_radii[0.06029], 0.08255, mass_radii[0.08255]);
    radius2 = planet_radius_helper(mass, 0.06029, mass_radii[0.06029], 0.08255, mass_radii[0.08255], 0.1127, mass_radii[0.1127]);
    radius = rangeAdjust(mass, radius1, radius2, 0.06029, 0.08255);
  }
  else if (mass <= 0.1127)
  {
    //radius = quad_trend(-5.815642034, 3.231689845, 0.4189547105, mass);
    radius1 = planet_radius_helper(mass, 0.06029, mass_radii[0.06029], 0.08255, mass_radii[0.08255], 0.1127, mass_radii[0.1127]);
    radius2 = planet_radius_helper(mass, 0.08255, mass_radii[0.08255], 0.1127, mass_radii[0.1127], 0.1533, mass_radii[0.1533]);
    radius = rangeAdjust(mass, radius1, radius2, 0.08255, 0.1127);
  }
  else if (mass <= 0.1533)
  {
    //radius = quad_trend(-3.502419815, 2.616372735, 0.4589200426, mass);
    radius1 = planet_radius_helper(mass, 0.08255, mass_radii[0.08255], 0.1127, mass_radii[0.1127], 0.1533, mass_radii[0.1533]);
    radius2 = planet_radius_helper(mass, 0.1127, mass_radii[0.1127], 0.1533, mass_radii[0.1533], 0.2074, mass_radii[0.2074]);
    radius = rangeAdjust(mass, radius1, radius2, 0.1127, 0.1533);
  }
  else if (mass <= 0.2074)
  {
    //radius = quad_trend(-2.087108413, 2.105869912, 0.5039190477, mass);
    radius1 = planet_radius_helper(mass, 0.1127, mass_radii[0.1127], 0.1533, mass_radii[0.1533], 0.2074, mass_radii[0.2074]);
    radius2 = planet_radius_helper(mass, 0.1533, mass_radii[0.1533], 0.2074, mass_radii[0.2074], 0.2789, mass_radii[0.2789]);
    radius = rangeAdjust(mass, radius1, radius2, 0.1533, 0.2074);
  }
  else if (mass <= 0.2789)
  {
    //radius = quad_trend(-1.299687957, 1.722947345, 0.5494664863, mass);
    radius1 = planet_radius_helper(mass, 0.1533, mass_radii[0.1533], 0.2074, mass_radii[0.2074], 0.2789, mass_radii[0.2789]);
    radius2 = planet_radius_helper(mass, 0.2074, mass_radii[0.2074], 0.2789, mass_radii[0.2789], 0.3726, mass_radii[0.3726]);
    radius = rangeAdjust(mass, radius1, radius2, 0.2074, 0.2789);
  }
  else if (mass <= 0.3726)
  {
    //radius = quad_trend(-0.7560773586, 1.368785039, 0.6059574886, mass);
    radius1 = planet_radius_helper(mass, 0.2074, mass_radii[0.2074], 0.2789, mass_radii[0.2789], 0.3726, mass_radii[0.3726]);
    radius2 = planet_radius_helper(mass, 0.2789, mass_radii[0.2789], 0.3726, mass_radii[0.3726], 0.4946, mass_radii[0.4946]);
    radius = rangeAdjust(mass, radius1, radius2, 0.2789, 0.3726);
  }
  else if (mass <= 0.4946)
  {
    //radius = quad_trend(-0.5024408471, 1.148831457, 0.6526996439, mass);
    radius1 = planet_radius_helper(mass, 0.2789, mass_radii[0.2789], 0.3726, mass_radii[0.3726], 0.4946, mass_radii[0.4946]);
    radius2 = planet_radius_helper(mass, 0.3726, mass_radii[0.3726], 0.4946, mass_radii[0.4946], 0.6517, mass_radii[0.6517]);
    radius = rangeAdjust(mass, radius1, radius2, 0.3726, 0.4946);
  }
  else if (mass <= 0.6517)
  {
    //radius = quad_trend(-0.2949670516, 0.911004245, 0.7195748425, mass);
    radius1 = planet_radius_helper(mass, 0.3726, mass_radii[0.3726], 0.4946, mass_radii[0.4946], 0.6517, mass_radii[0.6517]);
    radius2 = planet_radius_helper(mass, 0.4946, mass_radii[0.4946], 0.6517, mass_radii[0.6517], 0.8529, mass_radii[0.8529]);
    radius = rangeAdjust(mass, radius1, radius2, 0.4946, 0.6517);
  }
  else if (mass <= 0.8529)
  {
    //radius = quad_trend(-0.179050929, 0.7365968468, 0.7840050724, mass);
    radius1 = planet_radius_helper(mass, 0.4946, mass_radii[0.4946], 0.6517, mass_radii[0.6517], 0.8529, mass_radii[0.8529]);
    radius2 = planet_radius_helper(mass, 0.6517, mass_radii[0.6517], 0.8529, mass_radii[0.8529], 1.107, mass_radii[1.107]);
    radius = rangeAdjust(mass, radius1, radius2, 0.6517, 0.8529);
  }
  else if (mass <= 1.107)
  {
    //radius = quad_trend(-0.1336109642, 0.6475390598, 0.8269076832, mass);
    radius1 = planet_radius_helper(mass, 0.6517, mass_radii[0.6517], 0.8529, mass_radii[0.8529], 1.107, mass_radii[1.107]);
    radius2 = planet_radius_helper(mass, 0.8529, mass_radii[0.8529], 1.107, mass_radii[1.107], 1.42, mass_radii[1.42]);
    radius = rangeAdjust(mass, radius1, radius2, 0.8529, 1.107);
  }
  else if (mass <= 1.42)
  {
    //radius = quad_trend(-0.0718849276, 0.4915573653, 0.9239373092, mass);
    radius1 = planet_radius_helper(mass, 0.8529, mass_radii[0.8529], 1.107, mass_radii[1.107], 1.42, mass_radii[1.42]);
    radius2 = planet_radius_helper(mass, 1.107, mass_radii[1.107], 1.42, mass_radii[1.42], 1.818, mass_radii[1.818]);
    radius = rangeAdjust(mass, radius1, radius2, 1.107, 1.42);
  }
  else if (mass <= 1.818)
  {
    //radius = quad_trend(-0.0489259048, 0.4172160496, 0.983207404, mass);
    radius1 = planet_radius_helper(mass, 1.107, mass_radii[1.107], 1.42, mass_radii[1.42], 1.818, mass_radii[1.818]);
    radius2 = planet_radius_helper(mass, 1.42, mass_radii[1.42], 1.818, mass_radii[1.818], 2.321, mass_radii[2.321]);
    radius = rangeAdjust(mass, radius1, radius2, 1.42, 1.818);
  }
  else if (mass <= 2.321)
  {
    //radius = quad_trend(-0.0311382323, 0.3435928732, 1.058263876, mass);
    radius1 = planet_radius_helper(mass, 1.42, mass_radii[1.42], 1.818, mass_radii[1.818], 2.321, mass_radii[2.321]);
    radius2 = planet_radius_helper(mass, 1.818, mass_radii[1.818], 2.321, mass_radii[2.321], 2.957, mass_radii[2.957]);
    radius = rangeAdjust(mass, radius1, radius2, 1.818, 2.321);
  }
  else if (mass <= 2.957)
  {
    //radius = quad_trend(-0.0215357163, 0.2929107938, 1.124167834, mass);
    radius1 = planet_radius_helper(mass, 1.818, mass_radii[1.818], 2.321, mass_radii[2.321], 2.957, mass_radii[2.957]);
    radius2 = planet_radius_helper(mass, 2.321, mass_radii[2.321], 2.957, mass_radii[2.957], 3.752, mass_radii[3.752]);
    radius = rangeAdjust(mass, radius1, radius2, 2.321, 2.957);
  }
  else if (mass <= 3.752)
  {
    //radius = quad_trend(-0.0140610057, 0.2427629605, 1.207097237, mass);
    radius1 = planet_radius_helper(mass, 2.321, mass_radii[2.321], 2.957, mass_radii[2.957], 3.752, mass_radii[3.752]);
    radius2 = planet_radius_helper(mass, 2.957, mass_radii[2.957], 3.752, mass_radii[3.752], 4.732, mass_radii[4.732]);
    radius = rangeAdjust(mass, radius1, radius2, 2.957, 3.752);
  }
  else if (mass <= 4.732)
  {
    //radius = quad_trend(-0.0097572891, 0.2062502282, 1.28350742, mass);
    radius1 = planet_radius_helper(mass, 2.957, mass_radii[2.957], 3.752, mass_radii[3.752], 4.732, mass_radii[4.732]);
    radius2 = planet_radius_helper(mass, 3.752, mass_radii[3.752], 4.732, mass_radii[4.732], 5.936, mass_radii[5.936]);
    radius = rangeAdjust(mass, radius1, radius2, 3.752, 4.732);
  }
  else if (mass <= 5.936)
  {
    //radius = quad_trend(-0.0064236493, 0.1706869588, 1.377146535, mass);
    radius1 = planet_radius_helper(mass, 3.752, mass_radii[3.752], 4.732, mass_radii[4.732], 5.936, mass_radii[5.936]);
    radius2 = planet_radius_helper(mass, 4.732, mass_radii[4.732], 5.936, mass_radii[5.936], 7.407, mass_radii[7.407]);
    radius = rangeAdjust(mass, radius1, radius2, 4.732, 5.936);
  }
  else if (mass <= 7.407)
  {
    //radius = quad_trend(-0.0044017468, 0.1437087145, 1.466045444, mass);
    radius1 = planet_radius_helper(mass, 4.732, mass_radii[4.732], 5.936, mass_radii[5.936], 7.407, mass_radii[7.407]);
    radius2 = planet_radius_helper(mass, 5.936, mass_radii[5.936], 7.407, mass_radii[7.407], 9.127, mass_radii[9.127]);
    radius = rangeAdjust(mass, radius1, radius2, 5.936, 7.407);
  }
  else if (mass <= 9.127)
  {
    //radius = quad_trend(-0.0031572872, 0.1231328187, 1.550175507, mass);
    radius1 = planet_radius_helper(mass, 5.936, mass_radii[5.936], 7.407, mass_radii[7.407], 9.127, mass_radii[9.127]);
    radius2 = planet_radius_helper(mass, 7.407, mass_radii[7.407], 9.127, mass_radii[9.127], 11.12, mass_radii[11.12]);
    radius = rangeAdjust(mass, radius1, radius2, 7.407, 9.127);
  }
  else if (mass <= 11.12)
  {
    //radius = quad_trend(-0.0022855813, 0.1054833897, 1.63864689, mass);
    radius1 = planet_radius_helper(mass, 7.407, mass_radii[7.407], 9.127, mass_radii[9.127], 11.12, mass_radii[11.12]);
    radius2 = planet_radius_helper(mass, 9.127, mass_radii[9.127], 11.12, mass_radii[11.12], 13.52, mass_radii[13.52]);
    radius = rangeAdjust(mass, radius1, radius2, 9.127, 11.12);
  }
  else if (mass <= 13.52)
  {
    //radius = quad_trend(-0.0014786967, 0.0856017544, 1.75995585, mass);
    radius1 = planet_radius_helper(mass, 9.127, mass_radii[9.127], 11.12, mass_radii[11.12], 13.52, mass_radii[13.52]);
    radius2 = planet_radius_helper(mass, 11.12, mass_radii[11.12], 13.52, mass_radii[13.52], 16.37, mass_radii[16.37]);
    radius = rangeAdjust(mass, radius1, radius2, 11.12, 13.52);
  }
  else if (mass <= 16.37)
  {
    //radius = quad_trend(-0.0010448606, 0.0726343917, 1.855973509, mass);
    radius1 = planet_radius_helper(mass, 11.12, mass_radii[11.12], 13.52, mass_radii[13.52], 16.37, mass_radii[16.37]);
    radius2 = planet_radius_helper(mass, 13.52, mass_radii[13.52], 16.37, mass_radii[16.37], 19.72, mass_radii[19.72]);
    radius = rangeAdjust(mass, radius1, radius2, 13.52, 16.37);
  }
  else if (mass <= 19.72)
  {
    //radius = quad_trend(-7.705122E-4, 0.0627331568, 1.944537682, mass);
    radius1 = planet_radius_helper(mass, 13.52, mass_radii[13.52], 16.37, mass_radii[16.37], 19.72, mass_radii[19.72]);
    radius2 = planet_radius_helper(mass, 16.37, mass_radii[16.37], 19.72, mass_radii[19.72], 23.68, mass_radii[23.68]);
    radius = rangeAdjust(mass, radius1, radius2, 16.37, 19.72);
  }
  else if (mass <= 23.68)
  {
    //radius = quad_trend(-5.689036E-4, 0.0539833448, 2.038682756, mass);
    radius1 = planet_radius_helper(mass, 16.37, mass_radii[16.37], 19.72, mass_radii[19.72], 23.68, mass_radii[23.68]);
    radius2 = planet_radius_helper(mass, 19.72, mass_radii[19.72], 23.68, mass_radii[23.68], 28.31, mass_radii[28.31]);
    radius = rangeAdjust(mass, radius1, radius2, 19.72, 23.68);
  }
  else if (mass <= 28.31)
  {
    //radius = quad_trend(-3.838975E-4, 0.0443648787, 2.162707279, mass);
    radius1 = planet_radius_helper(mass, 19.72, mass_radii[19.72], 23.68, mass_radii[23.68], 28.31, mass_radii[28.31]);
    radius2 = planet_radius_helper(mass, 23.68, mass_radii[23.68], 28.31, mass_radii[28.31], 33.71, mass_radii[33.71]);
    radius = rangeAdjust(mass, radius1, radius2, 19.72, 23.68);
  }
  else if (mass <= 33.71)
  {
    //radius = quad_trend(-2.832898E-4, 0.0381251907, 2.258720213, mass);
    radius1 = planet_radius_helper(mass, 23.68, mass_radii[23.68], 28.31, mass_radii[28.31], 33.71, mass_radii[33.71]);
    radius2 = planet_radius_helper(mass, 28.31, mass_radii[28.31], 33.71, mass_radii[33.71], 39.97, mass_radii[39.97]);
    radius = rangeAdjust(mass, radius1, radius2, 19.72, 23.68);
  }
  else if (mass <= 39.97)
  {
    //radius = quad_trend(-2.059313E-4, 0.0324254134, 2.362952236, mass);
    radius1 = planet_radius_helper(mass, 28.31, mass_radii[28.31], 33.71, mass_radii[33.71], 39.97, mass_radii[39.97]);
    radius2 = planet_radius_helper(mass, 33.71, mass_radii[33.71], 39.97, mass_radii[39.97], 47.15, mass_radii[47.15]);
    radius = rangeAdjust(mass, radius1, radius2, 23.68, 39.97);
  }
  else if (mass <= 47.15)
  {
    //radius = quad_trend(-1.453571E-4, 0.027148189, 2.477109496, mass);
    radius1 = planet_radius_helper(mass, 33.71, mass_radii[33.71], 39.97, mass_radii[39.97], 47.15, mass_radii[47.15]);
    radius2 = planet_radius_helper(mass, 39.97, mass_radii[39.97], 47.15, mass_radii[47.15], 55.31, mass_radii[55.31]);
    radius = rangeAdjust(mass, radius1, radius2, 39.97, 47.15);
  }
  else if (mass <= 55.31)
  {
    //radius = quad_trend(-1.213663E-4, 0.0246900884, 2.539674382, mass);
    radius1 = planet_radius_helper(mass, 39.97, mass_radii[39.97], 47.15, mass_radii[47.15], 55.31, mass_radii[55.31]);
    radius2 = planet_radius_helper(mass, 47.15, mass_radii[47.15], 55.31, mass_radii[55.31], 64.47, mass_radii[64.47]);
    radius = rangeAdjust(mass, radius1, radius2, 47.15, 55.31);
  }
  else if (mass <= 64.47)
  {
    //radius = quad_trend(-8.815415E-5, 0.0207119427, 2.658103285, mass);
    radius1 = planet_radius_helper(mass, 47.15, mass_radii[47.15], 55.31, mass_radii[55.31], 64.47, mass_radii[64.47]);
    radius2 = planet_radius_helper(mass, 55.31, mass_radii[55.31], 64.47, mass_radii[64.47], 74.65, mass_radii[74.65]);
    radius = rangeAdjust(mass, radius1, radius2, 55.31, 64.47);
  }
  else if (mass <= 74.65)
  {
    //radius = quad_trend(-6.854458E-5, 0.0179838587, 2.752478002, mass);
    radius1 = planet_radius_helper(mass, 55.31, mass_radii[55.31], 64.47, mass_radii[64.47], 74.65, mass_radii[74.65]);
    radius2 = planet_radius_helper(mass, 64.47, mass_radii[64.47], 74.65, mass_radii[74.65], 86.14, mass_radii[86.14]);
    radius = rangeAdjust(mass, radius1, radius2, 64.47, 74.65);
  }
  else if (mass <= 86.14)
  {
    //radius = quad_trend(-4.142592E-5, 0.0136234496, 2.926860492, mass);
    radius1 = planet_radius_helper(mass, 64.47, mass_radii[64.47], 74.65, mass_radii[74.65], 86.14, mass_radii[86.14]);
    radius2 = planet_radius_helper(mass, 74.65, mass_radii[74.65], 86.14, mass_radii[86.14], 99.08, mass_radii[99.08]);
    radius = rangeAdjust(mass, radius1, radius2, 74.65, 86.14);
  }
  else if (mass <= 99.08)
  {
    //radius = quad_trend(-4.113636E-5, 0.0135698167, 2.929331843, mass);
    radius1 = planet_radius_helper(mass, 74.65, mass_radii[74.65], 86.14, mass_radii[86.14], 99.08, mass_radii[99.08]);
    radius2 = planet_radius_helper(mass, 86.14, mass_radii[86.14], 99.08, mass_radii[99.08], 113.6, mass_radii[113.6]);
    radius = rangeAdjust(mass, radius1, radius2, 86.14, 99.08);
  }
  else if (mass <= 113.6)
  {
    //radius = quad_trend(-2.356492E-5, 0.0098327232, 3.127106958, mass);
    radius1 = planet_radius_helper(mass, 86.14, mass_radii[86.14], 99.08, mass_radii[99.08], 113.6, mass_radii[113.6]);
    radius2 = planet_radius_helper(mass, 99.08, mass_radii[99.08], 113.6, mass_radii[113.6], 129.7, mass_radii[129.7]);
    radius = rangeAdjust(mass, radius1, radius2, 99.08, 113.6);
  }
  else if (mass <= 129.7)
  {
    //radius = quad_trend(-2.526928E-5, 0.010247394, 3.101995053, mass);
    radius1 = planet_radius_helper(mass, 99.08, mass_radii[99.08], 113.6, mass_radii[113.6], 129.7, mass_radii[129.7]);
    radius2 = planet_radius_helper(mass, 113.6, mass_radii[113.6], 129.7, mass_radii[129.7], 147.6, mass_radii[147.6]);
    radius = rangeAdjust(mass, radius1, radius2, 113.6, 129.7);
  }
  else if (mass <= 147.6)
  {
    //radius = quad_trend(-1.565766E-5, 0.0075820925, 3.285997163, mass);
    radius1 = planet_radius_helper(mass, 113.6, mass_radii[113.6], 129.7, mass_radii[129.7], 147.6, mass_radii[147.6]);
    radius2 = planet_radius_helper(mass, 129.7, mass_radii[129.7], 147.6, mass_radii[147.6], 167.2, mass_radii[167.2]);
    radius = rangeAdjust(mass, radius1, radius2, 129.7, 147.6);
  }
  else if (mass <= 167.2)
  {
    //radius = quad_trend(-1.270465E-5, 0.0066524852, 3.358873654, mass);
    radius1 = planet_radius_helper(mass, 129.7, mass_radii[129.7], 147.6, mass_radii[147.6], 167.2, mass_radii[167.2]);
    radius2 = planet_radius_helper(mass, 147.6, mass_radii[147.6], 167.2, mass_radii[167.2], 188.8, mass_radii[188.8]);
    radius = rangeAdjust(mass, radius1, radius2, 147.6, 167.2);
  }
  else if (mass <= 188.8)
  {
    //radius = quad_trend(-9.754214E-6, 0.00560213, 3.452011125, mass);
    radius1 = planet_radius_helper(mass, 147.6, mass_radii[147.6], 167.2, mass_radii[167.2], 188.8, mass_radii[188.8]);
    radius2 = planet_radius_helper(mass, 167.2, mass_radii[167.2], 188.8, mass_radii[188.8], 212.5, mass_radii[212.5]);
    radius = rangeAdjust(mass, radius1, radius2, 167.2, 188.8);
  }
  else if (mass <= 212.5)
  {
    //radius = quad_trend(-7.560935E-6, 0.0047219671, 3.540005479, mass);
    radius1 = planet_radius_helper(mass, 167.2, mass_radii[167.2], 188.8, mass_radii[188.8], 212.5, mass_radii[212.5]);
    radius2 = planet_radius_helper(mass, 188.8, mass_radii[188.8], 212.5, mass_radii[212.5], 238.4, mass_radii[238.4]);
    radius = rangeAdjust(mass, radius1, radius2, 188.8, 212.5);
  }
  else if (mass <= 238.4)
  {
    //radius = quad_trend(-5.370434E-6, 0.0037342699, 3.650976298, mass);
    radius1 = planet_radius_helper(mass, 188.8, mass_radii[188.8], 212.5, mass_radii[212.5], 238.4, mass_radii[238.4]);
    radius2 = planet_radius_helper(mass, 212.5, mass_radii[212.5], 238.4, mass_radii[238.4], 266.8, mass_radii[266.8]);
    radius = rangeAdjust(mass, radius1, radius2, 212.5, 238.4);
  }
  else if (mass <= 266.8)
  {
    //radius = quad_trend(-4.732385E-6, 0.0034229278, 3.69155945, mass);
    radius1 = planet_radius_helper(mass, 212.5, mass_radii[212.5], 238.4, mass_radii[238.4], 266.8, mass_radii[266.8]);
    radius2 = planet_radius_helper(mass, 238.4, mass_radii[238.4], 266.8, mass_radii[266.8], 297.9, mass_radii[297.9]);
    radius = rangeAdjust(mass, radius1, radius2, 238.4, 266.8);
  }
  else if (mass <= 297.9)
  {
    //radius = quad_trend(-2.817677E-6, 0.0023306918, 3.843739954, mass);
    radius1 = planet_radius_helper(mass, 238.4, mass_radii[238.4], 266.8, mass_radii[266.8], 297.9, mass_radii[297.9]);
    radius2 = planet_radius_helper(mass, 266.8, mass_radii[266.8], 297.9, mass_radii[297.9], 332.1, mass_radii[332.1]);
    radius = rangeAdjust(mass, radius1, radius2, 266.8, 297.9);
  }
  else if (mass <= 332.1)
  {
    radius1 = planet_radius_helper(mass, 266.8, mass_radii[266.8], 297.9, mass_radii[297.9], 332.1, mass_radii[332.1]);
    radius2 = planet_radius_helper2(mass, 297.9, mass_radii[297.9], 332.1, mass_radii[332.1]);
    radius = rangeAdjust(mass, radius1, radius2, 297.9, 332.1);
  }
  else
  {
    //radius = ln_trend(3.292047445, 0.1748279599, mass);
    radius = planet_radius_helper2(mass, 297.9, mass_radii[297.9], 332.1, mass_radii[332.1]);
  }
  if (adjust_for_carbon)
  {
    carbon_fraction = rmf * cmf;
    grow_factor = (0.05 * carbon_fraction) + 1.0; // not very scientific but guested by eye-balling an image on wikipedia.
    radius *= grow_factor;
  }
  if (flag_verbose & 0x80000)
  {
    radiusDebug("25% rock, 75% water/ice", the_planet, radius, mass_radii);
  }
  return radius;
}

long double half_rock_half_water_radius(long double mass, long double cmf, planet *the_planet)
{
  long double radius;
  bool adjust_for_carbon;
  long double range;
  long double upper_fraction;
  long double lower_fraction;
  long double carbon_fraction;
  long double grow_factor;
  long double rmf;
  
  adjust_for_carbon = true;
  rmf = 0.5;
  if (mass <= 0.008278)
  {
    adjust_for_carbon = false;
    range = 0.008278 - 0;
    upper_fraction = mass / range;
    lower_fraction = (1.0 - upper_fraction);
    radius = (quad_trend(-251.097088, 14.82282406, 0.1908031617, mass) * upper_fraction) + (fraction_radius(mass, 0.5, 0.5, cmf) * lower_fraction);
  }
  else if (mass <= 0.01156)
  {
    radius = quad_trend(-251.097088, 14.82282406, 0.1908031617, mass);
  }
  else if (mass <= 0.01615)
  {
    radius = quad_trend(-144.1013419, 11.85797193, 0.2107786256, mass);
  }
  else if (mass <= 0.02255)
  {
    radius = quad_trend(-86.45685997, 9.627130481, 0.2317717371, mass);
  }
  else if (mass <= 0.0313)
  {
    radius = quad_trend(-52.75830191, 7.812463129, 0.2555566849, mass);
  }
  else if (mass <= 0.04314)
  {
    radius = quad_trend(-27.9087717, 5.9626641, 0.2891105582, mass);
  }
  else if (mass <= 0.05943)
  {
    radius = quad_trend(-15.88199788, 4.72907791, 0.3199449236, mass);
  }
  else if (mass <= 0.0817)
  {
    radius = quad_trend(-9.401792072, 3.814526464, 0.3514091157, mass);
  }
  else if (mass <= 0.112)
  {
    radius = quad_trend(-5.4572037, 3.050459697, 0.3875036772, mass);
  }
  else if (mass <= 0.1528)
  {
    radius = quad_trend(-3.312524816, 2.482548728, 0.4242068537, mass);
  }
  else if (mass <= 0.2072)
  {
    radius = quad_trend(-1.983760111, 2.003927681, 0.466316364, mass);
  }
  else if (mass <= 0.2799)
  {
    radius = quad_trend(-1.206466699, 1.625152602, 0.5114392259, mass);
  }
  else if (mass <= 0.3754)
  {
    radius = quad_trend(-0.7427608407, 1.321286153, 0.5601628686, mass);
  }
  else if (mass <= 0.4998)
  {
    radius = quad_trend(-0.4356758148, 1.052525338, 0.617779672, mass);
  }
  else if (mass <= 0.6607)
  {
    radius = quad_trend(-0.279489115, 0.8712706729, 0.6693553098, mass);
  }
  else if (mass <= 0.8653)
  {
    radius = quad_trend(-0.1823992238, 0.7231114989, 0.7248619608, mass);
  }
  else if (mass <= 1.117)
  {
    radius = quad_trend(-0.1131126774, 0.5857647781, 0.7918301862, mass);
  }
  else if (mass <= 1.437)
  {
    radius = quad_trend(-0.0723180077, 0.4815751916, 0.8573108937, mass);
  }
  else if (mass <= 1.842)
  {
    radius = quad_trend(-0.0460469153, 0.3954322797, 0.9268492667, mass);
  }
  else if (mass <= 2.351)
  {
    radius = quad_trend(-0.0313721992, 0.3339011952, 0.990398741, mass);
  }
  else if (mass <= 2.988)
  {
    radius = quad_trend(-0.0192555176, 0.269210232, 1.075515861, mass);
  }
  else if (mass <= 3.78)
  {
    radius = quad_trend(-0.0123380727, 0.2223929652, 1.15364591, mass);
  }
  else if (mass <= 4.763)
  {
    radius = quad_trend(-0.0092219964, 0.1957723254, 1.209748184, mass);
  }
  else if (mass <= 5.972)
  {
    radius = quad_trend(-0.006005431, 0.1612424952, 1.301242218, mass);
  }
  else if (mass <= 7.392)
  {
    radius = quad_trend(-0.0046758803, 0.1434743798, 1.359935265, mass);
  }
  else if (mass <= 9.043)
  {
    radius = quad_trend(-0.0029585423, 0.1152499298, 1.474732193, mass);
  }
  else if (mass <= 11.03)
  {
    radius = quad_trend(-0.0019751495, 0.0955102856, 1.572820013, mass);
  }
  else if (mass <= 13.4)
  {
    radius = quad_trend(-0.0014930172, 0.0837317945, 1.644080125, mass);
  }
  else if (mass <= 16.18)
  {
    radius = quad_trend(-0.0010753359, 0.0713767814, 1.734638445, mass);
  }
  else if (mass <= 19.48)
  {
    radius = quad_trend(-7.235726E-4, 0.058832903, 1.845509445, mass);
  }
  else if (mass <= 23.36)
  {
    radius = quad_trend(-5.028683E-4, 0.049377928, 1.945941584, mass);
  }
  else if (mass <= 27.94)
  {
    radius = quad_trend(-4.006219E-4, 0.0441326902, 2.012675568, mass);
  }
  else if (mass <= 33.24)
  {
    radius = quad_trend(-2.667319E-4, 0.0359413008, 2.137022627, mass);
  }
  else if (mass <= 39.33)
  {
    radius = quad_trend(-2.098119E-4, 0.0318106148, 2.211435834, mass);
  }
  else if (mass <= 46.26)
  {
    radius = quad_trend(-1.493274E-4, 0.0266337427, 2.321481765, mass);
  }
  else if (mass <= 54.07)
  {
    radius = quad_trend(-1.209301E-4, 0.0237846466, 2.392511186, mass);
  }
  else if (mass <= 62.77)
  {
    radius = quad_trend(-8.655674E-5, 0.019768462, 2.509173507, mass);
  }
  else if (mass <= 72.58)
  {
    radius = quad_trend(-6.040906E-5, 0.0162293732, 2.628298337, mass);
  }
  else if (mass <= 83.62)
  {
    radius = quad_trend(-5.504085E-5, 0.0153908584, 2.66087877, mass);
  }
  else if (mass <= 95.97)
  {
    radius = quad_trend(-3.355431E-5, 0.0115320909, 2.833308489, mass);
  }
  else if (mass <= 109.8)
  {
    radius = quad_trend(-2.64817E-5, 0.0100767608, 2.907836114, mass);
  }
  else if (mass <= 125.1)
  {
    radius = quad_trend(-2.23638E-5, 0.0091094666, 2.964399476, mass);
  }
  else if (mass <= 142)
  {
    radius = quad_trend(-1.716093E-5, 0.0077197786, 3.056824394, mass);
  }
  else if (mass <= 160.6)
  {
    radius = quad_trend(-1.325841E-5, 0.0065388751, 3.145822216, mass);
  }
  else if (mass <= 181)
  {
    radius = quad_trend(-1.031141E-5, 0.0055321815, 3.231487246, mass);
  }
  else if (mass <= 203.3)
  {
    radius = quad_trend(-8.158076E-6, 0.0047046552, 3.310724123, mass);
  }
  else if (mass <= 227.7)
  {
    radius = quad_trend(-5.557254E-6, 0.0035837009, 3.431119842, mass);
  }
  else if (mass <= 254.2)
  {
    radius = quad_trend(-4.545683E-6, 0.0030962202, 3.489671491, mass);
  }
  else
  {
    radius = ln_trend(3.012162161, 0.1753009325, mass);
  }
  if (adjust_for_carbon)
  {
    carbon_fraction = rmf * cmf;
    grow_factor = (0.05 * carbon_fraction) + 1.0; // not very scientific but guested by eye-balling an image on wikipedia.
    radius *= grow_factor;
  }
  return radius;
}

long double rock_radius(long double mass, long double cmf, planet *the_planet)
{
  long double radius;
  bool adjust_for_carbon;
  long double range;
  long double upper_fraction;
  long double lower_fraction;
  long double carbon_fraction;
  long double grow_factor;
  long double rmf;
  
  adjust_for_carbon = true;
  rmf = 1.0;
  if (mass <= 0.00623)
  {
    adjust_for_carbon = false;
    range = 0.00623 - 0;
    upper_fraction = mass / range;
    lower_fraction = (1.0 - upper_fraction);
    radius = (quad_trend(-315.395589, 14.2950833, 0.1260830485, mass) * upper_fraction) + (fraction_radius(mass, 0, 1, cmf) * lower_fraction);
  }
  else if (mass <= 0.008748)
  {
    radius = quad_trend(-315.395589, 14.2950833, 0.1260830485, mass);
  }
  else if (mass <= 0.01227)
  {
    radius = quad_trend(-188.1341907, 11.62030323, 0.1397430274, mass);
  }
  else if (mass <= 0.01717)
  {
    radius = quad_trend(-103.5492715, 9.130123207, 0.1575630314, mass);
  }
  else if (mass <= 0.02399)
  {
    radius = quad_trend(-60.94197703, 7.376406965, 0.1751133296, mass);
  }
  else if (mass <= 0.03343)
  {
    radius = quad_trend(-34.72166711, 5.870836769, 0.1961416432, mass);
  }
  else if (mass <= 0.04644)
  {
    radius = quad_trend(-20.17535427, 4.709022763, 0.2187246368, mass);
  }
  else if (mass <= 0.0643)
  {
    radius = quad_trend(-11.55708954, 3.754636127, 0.2444595682, mass);
  }
  else if (mass <= 0.08866)
  {
    radius = quad_trend(-6.878989996, 3.039074021, 0.2711286558, mass);
  }
  else if (mass <= 0.1217)
  {
    radius = quad_trend(-4.009273679, 2.435400496, 0.302092671, mass);
  }
  else if (mass <= 0.1661)
  {
    radius = quad_trend(-2.404094408, 1.973429902, 0.3345403587, mass);
  }
  else if (mass <= 0.2255)
  {
    radius = quad_trend(-1.446140999, 1.598295347, 0.3704210305, mass);
  }
  else if (mass <= 0.3042)
  {
    radius = quad_trend(-0.8656081038, 1.290787073, 0.4102439036, mass);
  }
  else if (mass <= 0.4075)
  {
    radius = quad_trend(-0.5362568931, 1.056387816, 0.4510707737, mass);
  }
  else if (mass <= 0.542)
  {
    radius = quad_trend(-0.330761771, 0.8612701975, 0.4964574539, mass);
  }
  else if (mass <= 0.7143)
  {
    radius = quad_trend(-0.2162384806, 0.7173945877, 0.5407952145, mass);
  }
  else if (mass <= 0.927)
  {
    radius = quad_trend(-0.1354314862, 0.5847660678, 0.5943020587, mass);
  }
  else if (mass <= 1.2)
  {
    radius = quad_trend(-0.0814344419, 0.4699143547, 0.6543683708, mass);
  }
  else if (mass <= 1.545)
  {
    radius = quad_trend(-0.0570319452, 0.4029295012, 0.6996105997, mass);
  }
  else if (mass <= 1.981)
  {
    radius = quad_trend(-0.0352606639, 0.3261639633, 0.766244763, mass);
  }
  else if (mass <= 2.525)
  {
    radius = quad_trend(-0.024640974, 0.2783647176, 0.8193647176, mass);
  }
  else if (mass <= 3.203)
  {
    radius = quad_trend(-0.0150740628, 0.2235123732, 0.8967378292, mass);
  }
  else if (mass <= 4.043)
  {
    radius = quad_trend(-0.0098938279, 0.1859763911, 0.9638204674, mass);
  }
  else if (mass <= 5.077)
  {
    radius = quad_trend(-0.0075670613, 0.1647562803, 1.011580401, mass);
  }
  else if (mass <= 6.297)
  {
    radius = quad_trend(-0.0049514253, 0.1350060359, 1.095201943, mass);
  }
  else if (mass <= 7.714)
  {
    radius = quad_trend(-0.003587277, 0.1158929542, 1.161465525, mass);
  }
  else if (mass <= 9.423)
  {
    radius = quad_trend(-0.002262228, 0.0931855895, 1.257782041, mass);
  }
  else if (mass <= 11.47)
  {
    radius = quad_trend(-0.0017062124, 0.0815687551, 1.317877216, mass);
  }
  else if (mass <= 13.87)
  {
    radius = quad_trend(-0.0011721485, 0.0680355766, 1.402840849, mass);
  }
  else if (mass <= 16.73)
  {
    radius = quad_trend(-8.290313E-4, 0.057536189, 1.482459524, mass);
  }
  else if (mass <= 20.1)
  {
    radius = quad_trend(-5.903191E-4, 0.0487444197, 1.562731982, mass);
  }
  else if (mass <= 24.07)
  {
    radius = quad_trend(-3.920942E-4, 0.0399888266, 1.658634568, mass);
  }
  else if (mass <= 28.68)
  {
    radius = quad_trend(-3.135081E-4, 0.035843407, 1.712884759, mass);
  }
  else if (mass <= 33.99)
  {
    radius = quad_trend(-2.488584E-4, 0.0317918141, 1.775907375, mass);
  }
  else if (mass <= 40.05)
  {
    radius = quad_trend(-1.5098E-4, 0.0245448927, 1.909149277, mass);
  }
  else if (mass <= 46.88)
  {
    radius = quad_trend(-1.447629E-4, 0.024004441, 1.920822137, mass);
  }
  else if (mass <= 54.49)
  {
    radius = quad_trend(-9.444827E-5, 0.0189040505, 2.04935033, mass);
  }
  else if (mass <= 63.08)
  {
    radius = quad_trend(-7.602327E-5, 0.0167378233, 2.112681274, mass);
  }
  else if (mass <= 72.75)
  {
    radius = quad_trend(-5.173226E-5, 0.0134383755, 2.224154419, mass);
  }
  else if (mass <= 83.59)
  {
    radius = quad_trend(-4.216159E-5, 0.119420964, 2.282355333, mass);
  }
  else if (mass <= 95.68)
  {
    radius = quad_trend(-2.871507E-5, 0.0095315392, 2.389899117, mass);
  }
  else if (mass <= 109.1)
  {
    radius = quad_trend(-2.46556E-5, 0.0087002408, 2.432774665, mass);
  }
  else if (mass <= 124)
  {
    radius = quad_trend(-1.99273E-5, 0.007598074, 2.496241005, mass);
  }
  else if (mass <= 140.3)
  {
    radius = quad_trend(-1.262711E-5, 0.0056686323, 2.623243968, mass);
  }
  else if (mass <= 158.2)
  {
    radius = quad_trend(-1.255653E-5, 0.0056475658, 2.624810399, mass);
  }
  else if (mass <= 177.8)
  {
    radius = quad_trend(-8.629392E-6, 0.0043280472, 2.735272806, mass);
  }
  else if (mass <= 199.2)
  {
    radius = quad_trend(-5.801246E-6, 0.0032618362, 2.835439392, mass);
  }
  else if (mass <= 222.5)
  {
    radius = quad_trend(-5.492344E-6, 0.0031315723, 2.849130541, mass);
  }
  else
  {
    radius = ln_trend(2.57918226, 0.128552657, mass);
  }
  if (adjust_for_carbon)
  {
    carbon_fraction = rmf * cmf;
    grow_factor = (0.05 * carbon_fraction) + 1.0; // not very scientific but guested by eye-balling an image on wikipedia.
    radius *= grow_factor;
  }
  return radius;
}

long double half_rock_half_iron_radius(long double mass, long double cmf, planet *the_planet)
{
  long double radius;
  bool adjust_for_carbon;
  long double range;
  long double upper_fraction;
  long double lower_fraction;
  long double carbon_fraction;
  long double grow_factor;
  long double rmf;
  
  adjust_for_carbon = true;
  rmf = 0.5;
  if (mass <= 0.00177)
  {
    adjust_for_carbon = false;
    range = 0.00177 - 0;
    upper_fraction = mass / range;
    lower_fraction = (1.0 - upper_fraction);
    radius = (quad_trend(-2449.6900769892, 30.6438989610363, 0.0744348930965843, mass) * upper_fraction) + (fraction_radius(mass, 0, 0.5, cmf) * lower_fraction);
  }
  else if (mass <= 0.002481)
  {
    radius = quad_trend(-2449.6900769892, 30.6438989610363, 0.0744348930965843, mass);
  }
  else if (mass <= 0.003472)
  {
    radius = quad_trend(-1373.39582492175, 24.2607963117367, 0.0836627150671445, mass);
  }
  else if (mass <= 0.004848)
  {
    radius = quad_trend(-799.3217849, 19.51372934, 0.0931839832, mass);
  }
  else if (mass <= 0.006752)
  {
    radius = quad_trend(-446.2529913, 15.41813134, 0.1047412297, mass);
  }
  else if (mass <= 0.00938)
  {
    radius = quad_trend(-260.7214329, 12.42513624, 0.1164916409, mass);
  }
  else if (mass <= 0.01299)
  {
    radius = quad_trend(-152.0702736, 9.994609805, 0.1297303718, mass);
  }
  else if (mass <= 0.01792)
  {
    radius = quad_trend(-89.11289838, 8.048597336, 0.14438564, mass);
  }
  else if (mass <= 0.02464)
  {
    radius = quad_trend(-52.58495246, 6.493967957, 0.1605145107, mass);
  }
  else if (mass <= 0.03372)
  {
    radius = quad_trend(-31.03774295, 5.236472811, 0.1784172424, mass);
  }
  else if (mass <= 0.04595)
  {
    radius = quad_trend(-18.41664973, 4.230950314, 0.1979727934, mass);
  }
  else if (mass <= 0.06231)
  {
    radius = quad_trend(-11.08681604, 3.437422519, 0.2189591664, mass);
  }
  else if (mass <= 0.08408)
  {
    radius = quad_trend(-6.715816383, 2.797551879, 0.241858942, mass);
  }
  else if (mass <= 0.1129)
  {
    radius = quad_trend(-4.069306668, 2.276242395, 0.2669812848, mass);
  }
  else if (mass <= 0.1508)
  {
    radius = quad_trend(-2.532586328, 1.871009242, 0.2931444403, mass);
  }
  else if (mass <= 0.2003)
  {
    radius = quad_trend(-1.57175725, 1.533662152, 0.3221665132, mass);
  }
  else if (mass <= 0.2647)
  {
    radius = quad_trend(-0.9812585362, 1.25908025, 0.3534744066, mass);
  }
  else if (mass <= 0.348)
  {
    radius = quad_trend(-0.6134611137, 1.03373077, 0.3873542869, mass);
  }
  else if (mass <= 0.455)
  {
    radius = quad_trend(-0.3947160298, 0.8580784672, 0.4219903835, mass);
  }
  else if (mass <= 0.5919)
  {
    radius = quad_trend(-0.251475037, 0.7081194719, 0.4605672598, mass);
  }
  else if (mass <= 0.7659)
  {
    radius = quad_trend(-0.1614376955, 0.5858667696, 0.501384447, mass);
  }
  else if (mass <= 0.986)
  {
    radius = quad_trend(-0.1082398009, 0.4926693781, 0.5415582947, mass);
  }
  else if (mass <= 1.261)
  {
    radius = quad_trend(-0.0690127077, 0.4045260997, 0.5903311441, mass);
  }
  else if (mass <= 1.606)
  {
    radius = quad_trend(-0.0446111528, 0.3345668417, 0.6397483435, mass);
  }
  else if (mass <= 2.036)
  {
    radius = quad_trend(-0.0323446774, 0.2898923383, 0.679857461, mass);
  }
  else if (mass <= 2.568)
  {
    radius = quad_trend(-0.0188541262, 0.2277818406, 0.7503921064, mass);
  }
  else if (mass <= 3.226)
  {
    radius = quad_trend(-0.0131731218, 0.1948661011, 0.7974556375, mass);
  }
  else if (mass <= 4.032)
  {
    radius = quad_trend(-0.0089795106, 0.1644288708, 0.8520029117, mass);
  }
  else if (mass <= 5.018)
  {
    radius = quad_trend(-0.0063563019, 0.1406888322, 0.9050771807, mass);
  }
  else if (mass <= 6.216)
  {
    radius = quad_trend(-0.0042731856, 0.1172871044, 0.970053509, mass);
  }
  else if (mass <= 7.665)
  {
    radius = quad_trend(-0.0032875812, 0.1036059286, 1.017013265, mass);
  }
  else if (mass <= 9.39)
  {
    radius = quad_trend(-0.0019141267, 0.0801816636, 1.115866754, mass);
  }
  else if (mass <= 11.45)
  {
    radius = quad_trend(-0.0015393648, 0.0723716241, 1.156159475, mass);
  }
  else if (mass <= 13.91)
  {
    radius = quad_trend(-9.435581E-4, 0.057261966, 1.251053311, mass);
  }
  else if (mass <= 16.81)
  {
    radius = quad_trend(-7.534048E-4, 0.0514204578, 1.295516297, mass);
  }
  else if (mass <= 20.21)
  {
    radius = quad_trend(-5.047244E-4, 0.0422143076, 1.380000531, mass);
  }
  else if (mass <= 24.2)
  {
    radius = quad_trend(-3.750415E-4, 0.0364550938, 1.443426061, mass);
  }
  else if (mass <= 28.85)
  {
    radius = quad_trend(-2.610787E-4, 0.0304093647, 1.522991503, mass);
  }
  else if (mass <= 34.23)
  {
    radius = quad_trend(-1.90016E-4, 0.0259267321, 1.593168402, mass);
  }
  else if (mass <= 40.45)
  {
    radius = quad_trend(-1.446417E-4, 0.022538175, 1.655993898, mass);
  }
  else if (mass <= 47.59)
  {
    radius = quad_trend(-1.04715E-4, 0.0190230332, 1.732853309, mass);
  }
  else if (mass <= 55.76)
  {
    radius = quad_trend(-8.202615E-5, 0.016678137, 1.793060949, mass);
  }
  else if (mass <= 65.07)
  {
    radius = quad_trend(-5.984705E-5, 0.0139982359, 1.873533463, mass);
  }
  else if (mass <= 75.65)
  {
    radius = quad_trend(-4.398699E-5, 0.0117664086, 1.951605315, mass);
  }
  else if (mass <= 87.65)
  {
    radius = quad_trend(-2.918571E-5, 0.0093493602, 2.049748472, mass);
  }
  else if (mass <= 101.2)
  {
    radius = quad_trend(-2.427672E-5, 0.0084222976, 2.093292089, mass);
  }
  else if (mass <= 116.5)
  {
    radius = quad_trend(-1.821786E-5, 0.0071032835, 2.164724855, mass);
  }
  else if (mass <= 133.8)
  {
    radius = quad_trend(-1.286376E-5, 0.0057631526, 2.248182937, mass);
  }
  else
  {
    radius = ln_trend(1.335486915, 0.2968566848, mass);
  }
  if (adjust_for_carbon)
  {
    carbon_fraction = rmf * cmf;
    grow_factor = (0.05 * carbon_fraction) + 1.0; // not very scientific but guested by eye-balling an image on wikipedia.
    radius *= grow_factor;
  }
  return radius;
}

long double iron_radius(long double mass, planet *the_planet)
{
  long double radius;
  long double range;
  long double upper_fraction;
  long double lower_fraction;
  
  if (mass <= 0.001496)
  {
    range = 0.001496 - 0;
    upper_fraction = mass / range;
    lower_fraction = (1.0 - upper_fraction);
    radius = (quad_trend(-2681.77957240149, 29.1753892167919, 0.0618254642138286, mass) * upper_fraction) + (fraction_radius(mass, 0, 0, 0) * lower_fraction);
  }
  else if (mass <= 0.002096)
  {
    radius = quad_trend(-2681.77957240149, 29.1753892167919, 0.0618254642138286, mass);
  }
  else if (mass <= 0.002931)
  {
    radius = quad_trend(-1688.63294694608, 24.2372061422203, 0.0678174361405534, mass);
  }
  else if (mass <= 0.00409)
  {
    radius = quad_trend(-915.413258520028, 18.8629573194402, 0.0768735211649926, mass);
  }
  else if (mass <= 0.005694)
  {
    radius = quad_trend(-512.025546524638, 14.9254112879076, 0.086217430425244, mass);
  }
  else if (mass <= 0.007904)
  {
    radius = quad_trend(-292.3316061, 11.93892609, 0.0960976238, mass);
  }
  else if (mass <= 0.01094)
  {
    radius = quad_trend(-192.8510361, 10.06829345, 0.104668233, mass);
  }
  else if (mass <= 0.01507)
  {
    radius = quad_trend(-99.45862138, 7.642892436, 0.1200091513, mass);
  }
  else if (mass <= 0.0207)
  {
    radius = quad_trend(-59.86761779, 6.226722237, 0.1323595252, mass);
  }
  else if (mass <= 0.02829)
  {
    radius = quad_trend(-36.47985573, 5.080955774, 0.1460554689, mass);
  }
  else if (mass <= 0.0385)
  {
    radius = quad_trend(-21.31356831, 4.067999437, 0.1625740583, mass);
  }
  else if (mass <= 0.05212)
  {
    radius = quad_trend(-12.81381824, 3.297752085, 0.1796298268, mass);
  }
  else if (mass <= 0.07021)
  {
    radius = quad_trend(-7.888269424, 2.695209699, 0.1976541102, mass);
  }
  else if (mass <= 0.09408)
  {
    radius = quad_trend(-4.757963763, 2.180931782, 0.218330896, mass);
  }
  else if (mass <= 0.1254)
  {
    radius = quad_trend(-2.941685354, 1.782294997, 0.2397586803, mass);
  }
  else if (mass <= 0.1663)
  {
    radius = quad_trend(-1.784894626, 1.444859141, 0.2638824172, mass);
  }
  else if (mass <= 0.2193)
  {
    radius = quad_trend(-1.162328645, 1.204797699, 0.2865871433, mass);
  }
  else if (mass <= 0.2877)
  {
    radius = quad_trend(-0.699716184, 0.9702531813, 0.3157745709, mass);
  }
  else if (mass <= 0.3754)
  {
    radius = quad_trend(-0.4577736374, 0.8098210786, 0.3419049902, mass);
  }
  else if (mass <= 0.4875)
  {
    radius = quad_trend(-0.2880355042, 0.6633540435, 0.3729683416, mass);
  }
  else if (mass <= 0.6298)
  {
    radius = quad_trend(-0.1883400931, 0.5519643698, 0.4035775744, mass);
  }
  else if (mass <= 0.8096)
  {
    radius = quad_trend(-0.1194866451, 0.4528567076, 0.4386849891, mass);
  }
  else if (mass <= 1.036)
  {
    radius = quad_trend(-0.0787318553, 0.3776396675, 0.4728678898, mass);
  }
  else if (mass <= 1.319)
  {
    radius = quad_trend(-0.0512867047, 0.313006338, 0.5103712488, mass);
  }
  else if (mass <= 1.671)
  {
    radius = quad_trend(-0.0344294192, 0.2626030543, 0.5475255322, mass);
  }
  else if (mass <= 2.108)
  {
    radius = quad_trend(-0.0239715508, 0.2230827695, 0.584363039, mass);
  }
  else if (mass <= 2.648)
  {
    radius = quad_trend(-0.0140840757, 0.176057938, 0.6395547667, mass);
  }
  else if (mass <= 3.31)
  {
    radius = quad_trend(-0.0105419379, 0.154953881, 0.6706011795, mass);
  }
  else if (mass <= 4.119)
  {
    radius = quad_trend(-0.0070348211, 0.1288995104, 0.718416824, mass);
  }
  else if (mass <= 5.103)
  {
    radius = quad_trend(-0.0047115353, 0.1074741683, 0.7672505662, mass);
  }
  else if (mass <= 6.293)
  {
    radius = quad_trend(-0.003487465, 0.0935246637, 0.8065593536, mass);
  }
  else if (mass <= 7.727)
  {
    radius = quad_trend(-0.0021560003, 0.0748575287, 0.8713031702, mass);
  }
  else if (mass <= 9.445)
  {
    radius = quad_trend(-0.00160772, 0.0654424596, 0.9113174962, mass);
  }
  else if (mass <= 11.49)
  {
    radius = quad_trend(-0.0012172944, 0.0572688997, 0.9536876732, mass);
  }
  else if (mass <= 13.92)
  {
    radius = quad_trend(-7.485494E-4, 0.0453580881, 1.028659131, mass);
  }
  else if (mass <= 16.78)
  {
    radius = quad_trend(-5.83219E-4, 0.0402824467, 1.067276595, mass);
  }
  else if (mass <= 20.14)
  {
    radius = quad_trend(-3.979673E-4, 0.0334429539, 1.129882258, mass);
  }
  else if (mass <= 24.05)
  {
    radius = quad_trend(-2.896199E-4, 0.0286550795, 1.182362194, mass);
  }
  else if (mass <= 28.6)
  {
    radius = quad_trend(-2.251678E-4, 0.0252616764, 1.226694282, mass);
  }
  else if (mass <= 33.87)
  {
    radius = quad_trend(-1.591712E-4, 0.0211388691, 1.290623996, mass);
  }
  else if (mass <= 39.94)
  {
    radius = quad_trend(-1.04791E-4, 0.171250664, 1.364187783, mass);
  }
  else if (mass <= 46.92)
  {
    radius = quad_trend(-9.380878E-5, 0.0161711529, 1.38476825, mass);
  }
  else if (mass <= 54.93)
  {
    radius = quad_trend(-5.440961E-5, 0.0121583483, 1.486312324, mass);
  }
  else if (mass <= 64.08)
  {
    radius = quad_trend(-5.031019E-5, 0.0116704759, 1.500741944, mass);
  }
  else if (mass <= 74.51)
  {
    radius = quad_trend(-3.297829E-5, 0.0092684477, 1.583494853, mass);
  }
  else if (mass <= 86.37)
  {
    radius = quad_trend(-2.420693E-5, 0.0078573106, 1.639942343, mass);
  }
  else if (mass <= 99.8)
  {
    radius = quad_trend(-1.822424E-5, 0.0067435142, 1.691511445, mass);
  }
  else if (mass <= 115)
  {
    radius = quad_trend(-1.516304E-5, 0.0060859676, 1.726644882, mass);
  }
  else
  {
    radius = ln_trend(0.8568787518, 0.2885439056, mass);
  }
  return radius;
}

long double fraction_radius(long double mass, long double imf, long double rmf, long double cmf)
{
  long double ice_fraction;
  long double carbon_fraction;
  long double silicate_fraction;
  long double iron_fraction;
  long double density;
  long double radius;
  
  mass /= SUN_MASS_IN_EARTH_MASSES;
  ice_fraction = imf * ICE_DENSITY;
  carbon_fraction = (cmf * rmf) * CARBON_DENSITY;
  silicate_fraction = (rmf - (cmf * rmf)) * ROCK_DENSITY;
  iron_fraction = (1.0 - (rmf + imf)) * IRON_DENSITY;
  density = ice_fraction + silicate_fraction + carbon_fraction + iron_fraction;
  radius = volume_radius(mass, density) / KM_EARTH_RADIUS;
  return radius;
}
