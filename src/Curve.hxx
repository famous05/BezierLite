
/*------------------------------------------------------------------------------
BezierLite Library

Copyright (c) 2017 - 2021, Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com

License
    This file is part of BezierLite library.
    BezierLite is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    BezierLite is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with BezierLite.  If not, see <http://www.gnu.org/licenses/>.



This file is part of BezierLite library
------------------------------------------------------------------------------*/


// C++ Headers
#include <algorithm>
#include <vector>


// Developer Headers
#include "Point.hxx"
#include "CurveWriter.hxx"


namespace BezierLite
{

#ifndef CURVE
#define CURVE

class Curve
{
    public:

        /// Default constructor
        Curve();


        /// Copy constructor
        /// @param curve Curve to copy
        Curve(const Curve& curve);


        /// Assignment operator
        /// @param curve Curve to be assigned
        Curve& operator = (const Curve& curve);


        /// Default destructor
        virtual ~Curve();

        /// Prints the curve
        void PrintCurve();

        /// @returns Curve as vector of Point points
        const std::vector<BezierLite::Point>& GetCurve() const;

        /// @returns Number of points in the curve
        int GetNumberOfCurvePoints();

        /// Prints a curve to the screen
        /// @param vp Curve to print
        template <typename T> static void PrintCurve(const std::vector<T>& vp)
        {
            for(auto p : vp) p.Print();
        }

        /// Scles the curve
        /// @param vp Curve to scale
        /// @param sclaeFactor Scale factor
        template <typename T> static void ScaleCurve (std::vector<T>& vp, double scaleFactor)
        {
            for (auto &p : vp) p.ScalePoint(scaleFactor);
        }


        /// Appends a point to the curve
        /// @param p Point to append
        void AppendPointToCurve(const BezierLite::Point& p);

        /// Clear the curve
        void ClearCurve();

        /// Scales the curve
        /// @param factor Scale factor
        void ScaleCurve(double factor);

        /// Writes a curve to comma seperated file format
        /// @param <Input> Outpuf file name
        /// @param <Input/Optional> Column width. Default = 10
        void WriteCurveToCSV(std::string fileName, int colWidth = 10);


        /// Writes a curve to tab seperated file format
        /// @param <Input> Outpuf file name
        /// @param <Input/Optional> Column width. Default = 10
        void WriteCurveToTSV(std::string fileName, int colWidth = 10);


    private:
        std::vector<BezierLite::Point> m_CurvePoints;
};
#endif

}  // End of namespace BezierLite
