#include "stdafx.h"
#include "CCircle.h"

CCircle::CCircle(const Point & center, const double & radius, const std::string & outlineColor, const std::string & fillColor)
	:ISolidShape("Circle", outlineColor, fillColor),
	m_center(center),
	m_radius(radius)
{
}

const Point & CCircle::GetCenter() const
{
	return m_center;
}

const double & CCircle::GetRadius() const
{
	return m_radius;
}

double CCircle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::UniqueProperties() const
{
	std::stringstream strm;
	strm << ", Center: " << "(" << GetCenter().x
		<< ";" << GetCenter().y << ")"
		<< ", R:" << GetRadius();
	return ISolidShape::UniqueProperties() + strm.str();
}

