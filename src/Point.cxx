
/*------------------------------------------------------------------------------
BezierLite Library

Copyright (c) 2018 - 2021, Osarobo Famous Okhuahesogie, famous.osarobo@gmail.com

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


// Class header
#include "Point.hxx"

namespace BezierLite
{

Point::Point()
{

}

Point::Point(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(const Point& p)
{
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
}

Point& Point::operator =(const Point& p)
{
	if (&p != this)
	{
    this->x = p.x;
    this->y = p.y;
    this->z = p.z;
	}

	return *this;
}

Point::~Point()
{

}

void Point::Print()
{
    std::cout << std::left << std::setw(10) << this->x;
    std::cout << std::left << std::setw(10) << this->y;
    std::cout << std::left << std::setw(10) << this->z;
    std::cout << std::endl;
}

// Setters ***
void Point::SetX(double x)
{
    this->x = x;
}

void Point::SetY(double y)
{
    this->y = y;
}

void Point::SetZ(double z)
{
    this->z = z;
}

void Point::SetXYZ(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
// End of setters ***


// Getters ***
double Point::GetX() const
{
    return this->x;
}

double Point::GetY() const
{
    return this->y;
}

double Point::GetZ() const
{
    return this->z;
}

double Point::GetDistanceBetweenPoints(const Point &p1, const Point &p2)
{
    return std::sqrt(std::pow(p2.x - p1.x, 2) +
    std::pow(p2.y - p1.y, 2) +
    std::pow(p2.z - p1.z, 2));
}

double Point::GetDistanceToPoint(const Point &p) const
{
    return BezierLite::Point::GetDistanceBetweenPoints(*this, p);
}
// End of getters ***

Point& Point::operator+(const Point& p) const
{
    auto point = std::make_shared<BezierLite::Point>(0, 0, 0);

    point->SetX(this->x + p.x);
    point->SetY(this->y + p.y);
    point->SetZ(this->z + p.z);

    return *point;
}

Point& Point::operator-(const Point& p) const
{
    auto point = std::make_shared<BezierLite::Point>(0, 0, 0);

    point->SetX(this->x - p.x);
    point->SetY(this->y - p.y);
    point->SetZ(this->z - p.z);

    return *point;
}


Point& Point::operator*(const Point& p) const
{
    auto point = std::make_shared<BezierLite::Point>(0, 0, 0);

    point->SetX(this->x * p.x);
    point->SetY(this->y * p.y);
    point->SetZ(this->z * p.z);

    return *point;
}

Point& Point::operator*(double val) const
{
    auto point = std::make_shared<BezierLite::Point>(0, 0, 0);

    point->SetX(this->x * val);
    point->SetY(this->y * val);
    point->SetZ(this->z * val);

    return *point;
}

const Point& Point::AddPoints(const Point& p1, const Point& p2)
{
    auto p = std::make_shared<BezierLite::Point>(0, 0, 0);

    p->SetX(p1.x + p2.x);
    p->SetY(p1.y + p2.y);
    p->SetZ(p1.z + p2.z);

    return *p;
}

const Point& Point::SubtractPoints(const Point& p1, const Point& p2)
{
    auto p = std::make_shared<BezierLite::Point>(0, 0, 0);

    p->SetX(p1.x - p2.x);
    p->SetY(p1.y - p2.y);
    p->SetZ(p1.z - p2.z);

    return *p;
}

const Point& Point::MultiplyPoints(const Point& p1, const Point& p2)
{
    auto p = std::make_shared<BezierLite::Point>(0, 0, 0);

    p->SetX(p1.x * p2.x);
    p->SetY(p1.y * p2.y);
    p->SetZ(p1.z * p2.z);

    return *p;
}

const Point& Point::MultiplyPointByValue(const Point& p1, double val)
{
    auto p = std::make_shared<BezierLite::Point>(0, 0, 0);

    p->SetX(p1.x * val);
    p->SetY(p1.y * val);
    p->SetZ(p1.z * val);

    return *p;
}

void Point::ScalePoint(double factor)
{
    this->SetX(this->x * factor);
    this->SetY(this->y * factor);
    this->SetZ(this->z * factor);
}

} // End of namespace BezierLite
