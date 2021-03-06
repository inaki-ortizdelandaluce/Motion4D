// -------------------------------------------------------------------------------
/*
    m4dMetricEddFinkIn.h

  Copyright (c) 2009-2014  Thomas Mueller, Frank Grave


   This file is part of the m4d-library.

   The m4d-library is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   The m4d-library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with the m4d-library.  If not, see <http://www.gnu.org/licenses/>.

*/

/*!  \class  m4d::MetricEddFinkIn
     \brief  Ingoing Eddington-Finkelstein metric in spherical coordinates
             with advanced null coordinate (v,r,theta,phi).

        The line element is given by
             \f[ds^2 = -\left(1-\frac{r_s}{r}\right)c^2 dv^2 + 2c dv dr + r^2 \left(d\vartheta^2 + \sin(\vartheta)^2 d\varphi^2\right)\f]
             where \f$r_s=2GM/c^2\f$ is the Schwarzschild radius. G is Newton's constant, M is the mass of the black hole, and c is the
             speed of light.

             There are two natural local tetrads:
                  - Static tetrad:  (enum_nat_tetrad_static)
                  \f[ \mathbf{e}_{(0)}^s = \frac{1}{c\,\sqrt{1-r_s/r}}\partial_v,\quad \mathbf{e}_{(1)}^s = \frac{1}{c\,\sqrt{1-r_s/r}}\partial_v+\sqrt{1-\frac{r_s}{r}}\partial_r,\quad \mathbf{e}_{(2)}^s = \frac{1}{r}\partial_{\vartheta},\quad \mathbf{e}_{(3)}^s = \frac{1}{r\sin\vartheta}\partial_{\varphi}. \f]
                  - Freely falling tetrad from infinity: (enum_nat_tetrad_freefall)
                  \f[ \mathbf{e}_{(0)}^f = \frac{1}{1+\sqrt{r_s/r}}\frac{\partial_v}{c}-\sqrt{\frac{r_s}{r}}\partial_r,\quad \mathbf{e}_{(1)}^f = \frac{1}{1+\sqrt{r_s/r}}\frac{\partial_v}{c}+\partial_r,\quad \mathbf{e}_{(2)}^f = \frac{1}{r}\partial_{\vartheta},\quad \mathbf{e}_{(3)}^f = \frac{1}{r\sin\vartheta}\partial_{\varphi}.\f]

             Detailed discussions about the Eddington-Finkelstein metric can be found
             in the standard literature, e.g. \ref lit_rindler "Rindler", \ref lit_mtw "MTW".
*/
// -------------------------------------------------------------------------------

#ifndef M4D_METRIC_EDDINGTON_FINKELSTEIN_IN_H
#define M4D_METRIC_EDDINGTON_FINKELSTEIN_IN_H

#include "m4dMetric.h"

namespace m4d {

/**
 * @brief The MetricEddFinkIn class
 */
class MetricEddFinkIn : public Metric {
public:
    MetricEddFinkIn(double mass = 1.0);
    virtual ~MetricEddFinkIn();

    // --------- public methods -----------
public:
    virtual bool   calculateMetric(const double* pos);
    virtual bool   calculateChristoffels(const double* pos);
    virtual bool   calculateChrisD(const double* pos);

    virtual void   localToCoord(const double* pos, const double* ldir, double* dir,
                                enum_nat_tetrad_type  type = enum_nat_tetrad_default);
    virtual void   coordToLocal(const double* pos, const double* cdir, double* ldir,
                                enum_nat_tetrad_type  type = enum_nat_tetrad_default);


    virtual bool   breakCondition(const double* pos);

    virtual bool   calcDerivsSachsJacobi(const double y[], double dydx[]);

    virtual double testConstraint(const double y[], const double kappa);

    virtual bool   setParam(std::string pName, double val);

    virtual void   usePhysicalUnits(const enum_physical_constants  units);
    virtual void   setUnits(const double speed_of_light, const double grav_const, const double diel_perm);

    virtual bool   report(const vec4 pos, const vec4 cdir, std::string &text);

    bool  GetCriticalAngle(const double r0, const double r, double &ca);
    bool  GetCurrPosition(const double r0, const double tau, double &r);
    bool  GetFreefallVel(const double r0, const double r, double &beta);
    bool  GetTauCrash(const double r0, double &tau);

    // --------- protected methods -----------
protected:
    virtual void  setStandardValues();
    virtual void  contrChrisVecVec(const double y[], const double v[], const double w[], double* z, bool calc = true);
    virtual void  contrChrDVecVecVec(const double y[], const double u[], const double v[], const double w[], double* z, bool calc = true);

    // -------- protected attribute ---------
protected:
    double rs;
    double mMass;
};


struct EddFinkParams {
    double rs;
    double r0;
    double tau;
};

} // end namespace m4d

#endif
