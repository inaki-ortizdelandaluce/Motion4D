// -------------------------------------------------------------------------------
/*
    m4dMetricGoedel.cpp

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
// -------------------------------------------------------------------------------

#include "m4dMetricGoedel.h"

namespace m4d {
//
// ---------------------------------------------------
//    constructur/destructor
// ---------------------------------------------------
MetricGoedel::MetricGoedel(double a, double zeta) {
    mMetricName  = "Goedel";
    setCoordType(enum_coordinate_cylinder);

    mPhysicalUnits = enum_physical_constants_geom;
    mSpeedOfLight = 1.0;
    mGravConstant = 1.0;

    addParam("a");
    setParam("a", a);
    addParam("zeta");
    setParam("zeta", zeta);

    mA = a;
    mZeta = zeta;

    mDrawTypes.push_back(enum_draw_twoplusone);

    setStandardValues();
}

MetricGoedel::~MetricGoedel() {

}


// *********************************** public methods ******************************
// ---------------------------------------------------
//    public::calculateMetric
// ---------------------------------------------------
bool MetricGoedel
::calculateMetric(const double* pos) {
    double a = mA;
    double r = pos[1];

    double t1 = r * r;
    double t2 = sqrt(2.0);
    double t6 = 1.0 / a * t2 * t1 / 2.0;
    double t7 = a * a;
    double t8 = 1.0 / t7;
    double t13 = t1 * t1;

    g_compts[0][0] = -1.0;
    g_compts[0][1] = 0.0;
    g_compts[0][2] = -t6;
    g_compts[0][3] = 0.0;
    g_compts[1][0] = 0.0;
    g_compts[1][1] = 1.0 / (1.0 + t8 * t1 / 4.0);
    g_compts[1][2] = 0.0;
    g_compts[1][3] = 0.0;
    g_compts[2][0] = -t6;
    g_compts[2][1] = 0.0;
    g_compts[2][2] = t1 - t8 * t13 / 4.0;
    g_compts[2][3] = 0.0;
    g_compts[3][0] = 0.0;
    g_compts[3][1] = 0.0;
    g_compts[3][2] = 0.0;
    g_compts[3][3] = 1.0;

    return true;
}

// ---------------------------------------------------
//    public::calculateChristoffels
// ---------------------------------------------------
bool MetricGoedel
::calculateChristoffels(const double* pos) {
    double a = mA;
    double r = pos[1];

    double t1 = a * a;
    double t3 = r * r;
    double t4 = 4.0 * t1 + t3;
    double t5 = 1.0 / t4;
    double t6 = t5 * r;
    double t7 = 2.0 * t6;
    double t8 = 1.0 / r;
    double t10 = sqrt(2.0);
    double t13 = 2.0 * a * t8 * t5 * t10;
    double t19 = t4 / t1 / a * r * t10 / 8.0;
    double t25 = t3 * r * t10 / a * t5 / 2.0;
    double t28 = 4.0 * t1 * t8 * t5;
    double t29 = t1 * t1;

    christoffel[0][0][0] = 0.0;
    christoffel[0][0][1] = 0.0;
    christoffel[0][0][2] = 0.0;
    christoffel[0][0][3] = 0.0;
    christoffel[0][1][0] = t7;
    christoffel[0][1][1] = 0.0;
    christoffel[0][1][2] = -t13;
    christoffel[0][1][3] = 0.0;
    christoffel[0][2][0] = 0.0;
    christoffel[0][2][1] = t19;
    christoffel[0][2][2] = 0.0;
    christoffel[0][2][3] = 0.0;
    christoffel[0][3][0] = 0.0;
    christoffel[0][3][1] = 0.0;
    christoffel[0][3][2] = 0.0;
    christoffel[0][3][3] = 0.0;
    christoffel[1][0][0] = t7;
    christoffel[1][0][1] = 0.0;
    christoffel[1][0][2] = -t13;
    christoffel[1][0][3] = 0.0;
    christoffel[1][1][0] = 0.0;
    christoffel[1][1][1] = -t6;
    christoffel[1][1][2] = 0.0;
    christoffel[1][1][3] = 0.0;
    christoffel[1][2][0] = t25;
    christoffel[1][2][1] = 0.0;
    christoffel[1][2][2] = t28;
    christoffel[1][2][3] = 0.0;
    christoffel[1][3][0] = 0.0;
    christoffel[1][3][1] = 0.0;
    christoffel[1][3][2] = 0.0;
    christoffel[1][3][3] = 0.0;
    christoffel[2][0][0] = 0.0;
    christoffel[2][0][1] = t19;
    christoffel[2][0][2] = 0.0;
    christoffel[2][0][3] = 0.0;
    christoffel[2][1][0] = t25;
    christoffel[2][1][1] = 0.0;
    christoffel[2][1][2] = t28;
    christoffel[2][1][3] = 0.0;
    christoffel[2][2][0] = 0.0;
    christoffel[2][2][1] = t4 / t29 * r * (-2.0 * t1 + t3) / 8.0;
    christoffel[2][2][2] = 0.0;
    christoffel[2][2][3] = 0.0;
    christoffel[2][3][0] = 0.0;
    christoffel[2][3][1] = 0.0;
    christoffel[2][3][2] = 0.0;
    christoffel[2][3][3] = 0.0;
    christoffel[3][0][0] = 0.0;
    christoffel[3][0][1] = 0.0;
    christoffel[3][0][2] = 0.0;
    christoffel[3][0][3] = 0.0;
    christoffel[3][1][0] = 0.0;
    christoffel[3][1][1] = 0.0;
    christoffel[3][1][2] = 0.0;
    christoffel[3][1][3] = 0.0;
    christoffel[3][2][0] = 0.0;
    christoffel[3][2][1] = 0.0;
    christoffel[3][2][2] = 0.0;
    christoffel[3][2][3] = 0.0;
    christoffel[3][3][0] = 0.0;
    christoffel[3][3][1] = 0.0;
    christoffel[3][3][2] = 0.0;
    christoffel[3][3][3] = 0.0;
    return true;
}


// ---------------------------------------------------
//    public::localToCoord
// ---------------------------------------------------
void MetricGoedel
::localToCoord(const double* pos, const double* ldir, double* dir,
               enum_nat_tetrad_type) {
    double r = pos[1];
    double r2a  = r / (2.0 * mA);
    if (r > m4dGoedelEps) {
        //full metric
        calcVars(pos);

        //local to coord to cylindrical coordinates  (direction)
        dir[0] = ldir[0] * Gamma      + ldir[2] * Gamma * Xi * A;
        dir[1] = ldir[1] * sqrt(1.0 + r2a * r2a);
        dir[2] = ldir[0] * Gamma * mZeta + ldir[2] * Gamma * Xi * B;
        dir[3] = ldir[3];

    } else {
        //metric converges to minkowski metric
        dir[0] = ldir[0];
        dir[1] = ldir[1];
        dir[2] = ldir[2];
        dir[3] = ldir[3];
    }
}

// ---------------------------------------------------
//    public::coordToLocal
// ---------------------------------------------------
void MetricGoedel
::coordToLocal(const double* pos, const double* cdir, double* ldir,
               enum_nat_tetrad_type) {
    double r = pos[1];
    //double r2 = r*r;
    double r2a  = r / (2.0 * mA);
    if (r > m4dGoedelEps) {
        //full metric
        calcVars(pos);

        //local to coord to cylindrical coordinates  (direction)

        ldir[0] = (cdir[0] * B - cdir[2] * A) / (Gamma * (B - mZeta * A));
        ldir[1] = cdir[1] / sqrt(1.0 + r2a * r2a);
        ldir[2] = (mZeta * cdir[0] - cdir[2]) / (Gamma * Xi * (mZeta * A - B));
        ldir[3] = cdir[3];

//     printf("Gamma Delta F1 F2: %f %f %f %f\n",Gamma,Delta,F1,F2);
    } else {
        //metric converges to minkowski metric
        ldir[0] = cdir[0];
        ldir[1] = cdir[1];
        ldir[2] = cdir[2];
        ldir[3] = cdir[3];
    }

}


// ---------------------------------------------------
//    public::breakCondition
// ---------------------------------------------------
bool MetricGoedel
::breakCondition(const double*) {
    return false;
}

// ---------------------------------------------------
//    public::setParam
// ---------------------------------------------------
bool MetricGoedel
::setParam(std::string pName, double val) {
    Metric::setParam(pName, val);
    if (pName == "a") {
        mA = val;
    } else if (pName == "zeta") {
        mZeta = val;
    }

    return true;
}

/*! Transform point p to 2+1 coordinates.
 *
 *  \param  p  : point in proper metric coordinates.
 *  \param  cp : reference to transformed point.
 *  \return true : success.
 */
bool MetricGoedel::transToTwoPlusOne(vec4 p, vec4 &cp) {
    vec4 tp;
    TransCoordinates::toCartesianCoord(mCoordType, p, tp);
    cp = vec4(tp[0], tp[1], tp[2], tp[0]);
    return true;
}



/*! Generate report.
 */
bool MetricGoedel::report(const vec4 pos, const vec4 cdir, std::string &text) {
    std::stringstream ss;
    ss << "Report for Goedel metric\n\tcoordinate : (t,r,phi,z)\n";
    ss << "\tIncreasing parameter a -> straight geodesics\n";
    ss << "---------------------------------------------------------------\n";
    ss << "  physical units ........... no\n";
    ss.precision(DEF_FIXED_REPORT_PRECISION);
    ss.setf(std::ios::fixed);
    ss.precision(DEF_FIXED_REPORT_PRECISION);
    ss.setf(std::ios::fixed);
    vec4 locStartDir;
    coordToLocal(pos.data(), cdir.data(), locStartDir.data());
    double k0  = -locStartDir[0];
    double k2  = (pos[1] * sqrt(1.0 + pos[1] * pos[1] / 4.0 / mA / mA) * locStartDir[2] - sqrt(2.0) * pos[1] * pos[1] * locStartDir[0]) / 2.0 / mA;
    double k3  = locStartDir[3];
    ss << "  Goedel radius ............ rG = 2a = " << 2.0 * mA << std::endl;
    ss << "  constant of motion ....... k_0 = " << k0 << std::endl;
    ss << "  constant of motion ....... k_2 = " << k2 << std::endl;
    ss << "  constant of motion ....... k_3 = " << k3;
    text = ss.str();
    return true;
}

// ********************************* protected methods *****************************
// ---------------------------------------------------
//    protected::setViewerVal
// ---------------------------------------------------
void MetricGoedel::setStandardValues() {
    mInitPos[0] = 0.0;
    mInitPos[1] = 0.05;
    mInitPos[2] = 0.0;
    mInitPos[3] = 0.0;
    mInitDir[0] = 1.0;
    mInitDir[1] = 0.0;
    mInitDir[2] = 0.0;

    mCoordNames[0] = std::string("t");
    mCoordNames[1] = std::string("r");
    mCoordNames[2] = std::string("phi");
    mCoordNames[3] = std::string("z");
}

// ---------------------------------------------------
//    protected::calcVars
// ---------------------------------------------------
void MetricGoedel::calcVars(const double* pos) {
    double r = pos[1];
    double r2 = r * r;
    double r2a  = r / (2.0 * mA);

    if (r > m4dGoedelEps) {
        //full metric
        Gamma = sqrt(
                    + mSpeedOfLight * mSpeedOfLight
                    + mZeta * r2 * mSpeedOfLight * sqrt(2.0) / mA
                    - mZeta * mZeta * r2 * (1.0 - r2a * r2a)
                );
        Gamma = 1.0 / Gamma;

        Xi = r * mSpeedOfLight * sqrt(1.0 + r2a * r2a);
        Xi = 1.0 / Xi;

        A = (-r2 * mSpeedOfLight / (sqrt(2.0) * mA) + mZeta * r2 * (1.0 - r2a * r2a));
        B = (mSpeedOfLight * mSpeedOfLight + mZeta * r2 * mSpeedOfLight / (sqrt(2.0) * mA));
    } else {
        printf("error in MetricGoedelCart::setStandardValues -> r too small\n");
    }

}

} // end namespace m4d
