#pragma once
#ifndef __VECTOR2D__
#define __VECTOR2D__

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "Mathf.h"

template <class T>
class Vector2D
{
public:
	// constructor
	Vector2D(T x = 0.0, T y = 0.0);
	~Vector2D() = default;

	// copy constructor
	Vector2D(const Vector2D& rhs);

	// arithmetic operators
	Vector2D operator+(const Vector2D& rhs) const;
	Vector2D operator-(const Vector2D& rhs) const;
	Vector2D operator*(const Vector2D& rhs) const;
	Vector2D operator*(T scale) const;
	Vector2D operator/(const Vector2D& rhs) const;
	Vector2D operator/(T scale) const;
	Vector2D &operator=(const Vector2D& rhs);

	// shortcut operators
	Vector2D &operator+=(const Vector2D& rhs);
	Vector2D &operator-=(const Vector2D& rhs);
	Vector2D &operator*=(const Vector2D& rhs);
	Vector2D &operator/=(const Vector2D& rhs);

	// comparison operators
	bool operator==(const Vector2D& rhs) const;
	bool operator!=(const Vector2D& rhs) const;
	bool operator>(const Vector2D& rhs) const;
	bool operator<(const Vector2D& rhs) const;
	bool operator>=(const Vector2D& rhs) const;
	bool operator<=(const Vector2D& rhs) const;

	// other operator overloads
	T& operator[](int component);

	// increment / decrement operators
	Vector2D &operator++();
	Vector2D operator++(int);
	Vector2D &operator--();
	Vector2D operator--(int);

	// input/output operator overloads
	friend std::ostream& operator<<(std::ostream& out, const Vector2D& rhs)
	{
		out << rhs.ToString();
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Vector2D& rhs)
	{
		in >> rhs.m_x;
		in.ignore();
		in >> rhs.m_y;

		return in;
	}

	// overload string cast
	explicit operator std::string() const;

	// Getters and Setters
	T GetX() const;
	T GetY() const;
	void SetX(T x = 0.0);
	void SetY(T y = 0.0);
	void Set(T x = 0.0, T y = 0.0);

	std::string ToString(int precision = 2) const;

	// utility functions
	T GetMagnitude() const;
	T GetSqrMagnitude() const;
	void SetScale(const Vector2D& scale);
	Vector2D GetNormalized() const;
	void Normalize();

	// static functions
	static Vector2D Zero();
	static Vector2D One();
	static Vector2D Up();
	static Vector2D Down();
	static Vector2D Right();
	static Vector2D Left();
	static Vector2D Lerp(const Vector2D& a, const Vector2D& b, T t);
	static Vector2D LerpUnclamped(const Vector2D& a, const Vector2D& b, T t);
	static Vector2D MoveTowards(const Vector2D& current, const Vector2D& target, T max_distance_delta);
	static Vector2D Scale(const Vector2D& a, const Vector2D& b);
	static Vector2D Reflect(const Vector2D& in_direction, const Vector2D& in_normal);
	static Vector2D Perpendicular(const Vector2D& in_direction);
	static T Dot(const Vector2D& lhs, const Vector2D& rhs);
	static T Angle(const Vector2D& from, const Vector2D& to);
	static T SignedAngle(const Vector2D& from, const Vector2D& to);
	static T Distance(const Vector2D& a, const Vector2D& b);
	static Vector2D ClampMagnitude(const Vector2D& vector, T max_length);
	static T SqrMagnitude(const Vector2D& a);
	static Vector2D Min(const Vector2D& lhs, const Vector2D& rhs);
	static Vector2D Max(const Vector2D& lhs, const Vector2D& rhs);

private:
	float m_x{};
	float m_y{};
};

/* Implementation section */

template <class T>
Vector2D<T>::Vector2D(T x, T y): m_x(x), m_y(y)
{}


template <class T>
Vector2D<T>::Vector2D(const Vector2D& rhs)
{
	Set(rhs.GetX(), rhs.GetY());
}

template <class T>
Vector2D<T> Vector2D<T>::operator+(const Vector2D& rhs) const
{
	Vector2D vector;
	vector.Set(GetX() + rhs.GetX(), GetY() + rhs.GetY());
	return vector;
}

template <class T>
Vector2D<T> Vector2D<T>::operator-(const Vector2D& rhs) const
{
	Vector2D vector;
	vector.Set(GetX() - rhs.GetX(), GetY() - rhs.GetY());
	return vector;
}

template <class T>
Vector2D<T> Vector2D<T>::operator*(const Vector2D& rhs) const
{
	Vector2D vector;
	vector.Set(GetX() * rhs.GetX(), GetY() * rhs.GetY());
	return vector;
}

template <class T>
Vector2D<T> Vector2D<T>::operator*(T scale) const
{
	return Vector2D(GetX() * scale, GetY() * scale);
}

template <class T>
Vector2D<T> Vector2D<T>::operator/(const Vector2D& rhs) const
{
	Vector2D vector;
	vector.Set(GetX() / rhs.GetX(), GetY() / rhs.GetY());
	return vector;
}

template <class T>
Vector2D<T> Vector2D<T>::operator/(T scale) const
{
	return Vector2D(GetX() / scale, GetY() / scale);
}

template <class T>
Vector2D<T>& Vector2D<T>::operator=(const Vector2D& rhs)
{
	Set(rhs.GetX(), rhs.GetY());
	return *this;
}

template <class T>
Vector2D<T>& Vector2D<T>::operator+=(const Vector2D& rhs)
{
	Set(GetX() + rhs.GetX(), GetY() + rhs.GetY());
	return *this;
}

template <class T>
Vector2D<T>& Vector2D<T>::operator-=(const Vector2D& rhs)
{
	Set(GetX() - rhs.GetX(), GetY() - rhs.GetY());
	return *this;
}

template <class T>
Vector2D<T>& Vector2D<T>::operator*=(const Vector2D& rhs)
{
	Set(GetX() * rhs.GetX(), GetY() * rhs.GetY());
	return *this;
}

template <class T>
Vector2D<T>& Vector2D<T>::operator/=(const Vector2D& rhs)
{
	Set(GetX() / rhs.GetX(), GetY() / rhs.GetY());
	return *this;
}

template <class T>
bool Vector2D<T>::operator==(const Vector2D& rhs) const
{
	return ((GetX() == rhs.GetX()) && (GetY() == rhs.GetY()));
}

template <class T>
bool Vector2D<T>::operator!=(const Vector2D& rhs) const
{
	return ((GetX() != rhs.GetX()) && (GetY() != rhs.GetY()));
}

template <class T>
bool Vector2D<T>::operator>(const Vector2D& rhs) const
{
	return ((GetX() > rhs.GetX()) && (GetY() > rhs.GetY()));
}

template <class T>
bool Vector2D<T>::operator<(const Vector2D& rhs) const
{
	return ((GetX() < rhs.GetX()) && (GetY() > rhs.GetY()));
}

template <class T>
bool Vector2D<T>::operator>=(const Vector2D& rhs) const
{
	return ((GetX() >= rhs.GetX()) && (GetY() >= rhs.GetY()));
}

template <class T>
bool Vector2D<T>::operator<=(const Vector2D& rhs) const
{
	return ((GetX() <= rhs.GetX()) && (GetY() <= rhs.GetY()));
}

template <class T>
T& Vector2D<T>::operator[](int component)
{
	if ((component == 0) || (component == 1))
	{
		return (component == 0) ? m_x : m_y;
	}
	throw std::out_of_range("index out of range: can only be 0 to return x or 1 to return y");

}

template <class T>
Vector2D<T>& Vector2D<T>::operator++()
{
	Set(GetX() + 1, GetY() + 1);
	return *this;
}

template <class T>
Vector2D<T> Vector2D<T>::operator++(int)
{
	Vector2D vector = *this;
	++* this;
	return vector;
}

template <class T>
Vector2D<T>& Vector2D<T>::operator--()
{
	Set(GetX() - 1, GetY() - 1);
	return *this;
}

template <class T>
Vector2D<T> Vector2D<T>::operator--(int)
{
	Vector2D vector = *this;
	--* this;
	return vector;
}



template <class T>
Vector2D<T>::operator std::string() const
{
	return ToString();
}

template <class T>
T Vector2D<T>::GetX() const
{
	return m_x;
}

template <class T>
T Vector2D<T>::GetY() const
{
	return m_y;
}

template <class T>
void Vector2D<T>::SetX(T x)
{
	m_x = x;
}

template <class T>
void Vector2D<T>::SetY(T y)
{
	m_y = y;
}

template <class T>
void Vector2D<T>::Set(T x, T y)
{
	m_x = x;
	m_y = y;
}

template <class T>
std::string Vector2D<T>::ToString(int precision) const
{
	std::stringstream out;

	out << std::fixed << std::setprecision(precision);
	out << "(" << m_x << ", " << m_y << ")";
	return out.str();
}

template <class T>
T Vector2D<T>::GetMagnitude() const
{
	return Mathf::Sqrt(static_cast<float>(static_cast<double>(GetX()) * static_cast<double>(GetX()) + static_cast<double>(GetY()) * static_cast<double>(GetY())));

}

template <class T>
T Vector2D<T>::GetSqrMagnitude() const
{
	return static_cast<float>(static_cast<double>(GetX()) * static_cast<double>(GetX()) + static_cast<double>(GetY()) * static_cast<double>(GetY()));

}

template <class T>
void Vector2D<T>::SetScale(const Vector2D& scale)
{
	*this *= scale;
}

template <class T>
Vector2D<T> Vector2D<T>::GetNormalized() const
{
	Vector2D vector = Vector2D(GetX(), GetY());
	vector.Normalize();
	return vector;
}

template <class T>
void Vector2D<T>::Normalize()
{
	const auto magnitude = GetMagnitude();
	if (static_cast<double>(magnitude) > 9.99999974737875E-06)
	{
		Set(GetX() / magnitude, GetY() / magnitude);
	}
	else
	{
		*this = Vector2D::Zero();
	}
}

template <class T>
Vector2D<T> Vector2D<T>::Zero()
{
	return Vector2D(0.0, 0.0);
}

template <class T>
Vector2D<T> Vector2D<T>::One()
{
	return Vector2D(1.0, 1.0);

}

template <class T>
Vector2D<T> Vector2D<T>::Up()
{
	return Vector2D(0.0, 1.0);
}

template <class T>
Vector2D<T> Vector2D<T>::Down()
{
	return Vector2D(0.0, -1.0);
}

template <class T>
Vector2D<T> Vector2D<T>::Right()
{
	return Vector2D(1.0, 0.0);
}

template <class T>
Vector2D<T> Vector2D<T>::Left()
{
	return Vector2D(-1.0, 0.0);
}

template <class T>
Vector2D<T> Vector2D<T>::Lerp(const Vector2D& a, const Vector2D& b, T t)
{
	t = Mathf::Clamp01(t);
	return Vector2D(a.GetX() + (b.GetX() - a.GetX()) * t, a.GetY() + (b.GetY() - a.GetY()) * t);

}

template <class T>
Vector2D<T> Vector2D<T>::LerpUnclamped(const Vector2D& a, const Vector2D& b, T t)
{
	return Vector2D(a.GetX() + (b.GetX() - a.GetX()) * t, a.GetY() + (b.GetY() - a.GetY()) * t);

}

template <class T>
Vector2D<T> Vector2D<T>::MoveTowards(const Vector2D& current, const Vector2D& target, T max_distance_delta)
{
	const auto vector = target - current;
	const auto magnitude = vector.GetMagnitude();
	if (static_cast<double>(magnitude) <= static_cast<double>(max_distance_delta) || static_cast<double>(magnitude) == 0.0)
	{
		return target;
	}
	return current + vector / magnitude * max_distance_delta;
}

template <class T>
Vector2D<T> Vector2D<T>::Scale(const Vector2D& a, const Vector2D& b)
{
	return Vector2D(a.GetX() * b.GetX(), a.GetY() * b.GetY());
}

template <class T>
Vector2D<T> Vector2D<T>::Reflect(const Vector2D& in_direction, const Vector2D& in_normal)
{
	return in_normal * (-2.0 * Vector2D::Dot(in_normal, in_direction)) + in_direction;

}

template <class T>
Vector2D<T> Vector2D<T>::Perpendicular(const Vector2D& in_direction)
{
	return Vector2D(-in_direction.GetY(), in_direction.GetX());
}

template <class T>
T Vector2D<T>::Dot(const Vector2D& lhs, const Vector2D& rhs)
{
	return static_cast<float>(static_cast<double>(lhs.GetX()) * static_cast<double>(rhs.GetX()) + static_cast<double>(lhs.
		GetY()) * static_cast<double>(rhs.GetY()));
}

template <class T>
T Vector2D<T>::Angle(const Vector2D& from, const Vector2D& to)
{
	const auto denominator = static_cast<float>(Mathf::Sqrt(from.GetSqrMagnitude() * to.GetSqrMagnitude()));
	if (denominator < Mathf::EpsilonNormalSqrt)
	{
		return 0.0;
	}

	const auto dot = Mathf::Clamp(Vector2D::Dot(from, to) / denominator, -1.0F, 1.0F);
	return static_cast<float>(Mathf::Acos(dot)) * Mathf::Rad2Deg;
}

template <class T>
T Vector2D<T>::SignedAngle(const Vector2D& from, const Vector2D& to)
{
	const auto unsigned_angle = Vector2D::Angle(from, to);
	const auto sign = Mathf::Sign(from.GetX() * to.GetY() - from.GetY() * to.GetX());
	return unsigned_angle * sign;
}

template <class T>
T Vector2D<T>::Distance(const Vector2D& a, const Vector2D& b)
{
	const auto delta_x = static_cast<double>(b.GetX()) - static_cast<double>(a.GetX());
	const auto delta_y = static_cast<double>(b.GetY()) - static_cast<double>(a.GetY());

	return Mathf::Sqrt(static_cast<float>(delta_x * delta_x + delta_y * delta_y));

}

template <class T>
Vector2D<T> Vector2D<T>::ClampMagnitude(const Vector2D& vector, T max_length)
{
	if (static_cast<double>(vector.GetSqrMagnitude()) > static_cast<double>(max_length) * static_cast<double>(max_length))
	{
		return vector.GetNormalized() * max_length;
	}
	return vector;
}

template <class T>
T Vector2D<T>::SqrMagnitude(const Vector2D& a)
{
	return static_cast<float>(static_cast<double>(a.GetX()) * static_cast<double>(a.GetX()) + static_cast<double>(a.GetY()) *
		static_cast<double>(a.GetY()));
}

template <class T>
Vector2D<T> Vector2D<T>::Min(const Vector2D& lhs, const Vector2D& rhs)
{
	return Vector2D(Mathf::Min(lhs.GetX(), rhs.GetX()), Mathf::Min(lhs.GetY(), rhs.GetY()));

}

template <class T>
Vector2D<T> Vector2D<T>::Max(const Vector2D& lhs, const Vector2D& rhs)
{
	return Vector2D(Mathf::Max(lhs.GetX(), rhs.GetX()), Mathf::Max(lhs.GetY(), rhs.GetY()));

}
#endif /* defined (__VECTOR2D__) */

