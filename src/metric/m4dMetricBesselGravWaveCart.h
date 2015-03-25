// -------------------------------------------------------------------------------
/*
   m4dMetricBesselGravWaveCart.h

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

/*!  \class  m4d::MetricBesselGravWaveCart
     \brief  Gravitational Bessel-Wave metric in cartesian coordinates (t,x,y,z).

             The line element is given by
             \f[ \mathrm{d} s^{2} = -\mathrm{e}^{2\left(K-U\right)} \mathrm{d}t^{2}
                                    + \frac{\mathrm{e}^{-2U}}{x^{2}+y^{2}} \left[
                                    \left(\mathrm{e}^{2K}x^{2}+y^{2}\right) \mathrm{d}x^{2}
                                    + 2xy\left(\mathrm{e}^{2K}-1\right) \mathrm{d}x \mathrm{d}y
                                    + \left(x^{2}+\mathrm{e}^{2K}y^{2}\right) \mathrm{d}y^{2} \right]
                                    + \mathrm{e}^{2U} \mathrm{d}z^{2}. \f]
             With \f$ \rho=\sqrt{x^2+y^2} \f$ the Functions \f$ U \f$ and \f$ K \f$
             are given by
             \f[ U = CJ_{0}\left(\rho\right)\cos\left(t\right) \f]
             \f[ K = \frac{1}{2}C^{2}\rho\left\{\rho\right[J_{0}\left(\rho\right)^{2}+J_{1}\left(\rho\right)^{2}\left]
                     -2J_{0}\left(\rho\right)J_{1}\left(\rho\right)\cos^{2}\left(t\right)\right\}, \f]
             where \f$ J_{n} \f$ are the Bessel functions of the first kind and
             \f$ C \f$ is a free Parameter.
             The metric is taken from
             D. Kramer, "An exact gravitational wave solution", Ann. Phys. Volume 9 (2000), 331-334,
             with the modification \f$ \left(\omega t-kz\right) \rightarrow t \f$,
             \f$ \left(kt-\omega z\right) \rightarrow z\f$ and a transformation
             to cartesian coordinates.
*/
// -------------------------------------------------------------------------------

#ifndef M4D_METRIC_BESSELGRAVWAVECART_H
#define M4D_METRIC_BESSELGRAVWAVECART_H

#include "m4dMetric.h"
#include "gsl/gsl_sf_bessel.h"

namespace m4d {

// ---------------------------------------------------
//    class definition:   MetricBesselGravWaveCart
// ---------------------------------------------------
class MetricBesselGravWaveCart : public Metric {
public:
    MetricBesselGravWaveCart(double C = 1.0);
    virtual ~MetricBesselGravWaveCart();

// --------- public methods -----------
public:
    virtual bool   calculateMetric(const double* pos);
    virtual bool   calculateChristoffels(const double* pos);
    virtual bool	 calculateChrisD(const double* pos);

    virtual void   localToCoord(const double* pos, const double* ldir, double* dir,
                                enum_nat_tetrad_type  type = enum_nat_tetrad_default);
    virtual void   coordToLocal(const double* pos, const double* cdir, double* ldir,
                                enum_nat_tetrad_type  type = enum_nat_tetrad_default);

    virtual bool   breakCondition(const double* pos);

    virtual double testConstraint(const double y[], const double kappa);

    virtual bool   setParam(std::string pName, double val);

    virtual bool   transToTwoPlusOne(vec4 p, vec4 &cp);

    virtual bool   report(const vec4 pos, const vec4 cdir, std::string &text);

// --------- protected methods -----------
protected:
    virtual void setStandardValues();

// ----- specific protected methods ------
    void calcLTcoeffs(const double* pos);

// -------- protected attribute ----------
protected:
    double mC;
    // Coefficients for local Tetrad
    double ltA;
    double ltB;
    double ltC;
    double ltD;
    double ltE;
    double ltF;
    double ltT;
    double ltZ;

};

} // end namespace m4d

#endif
