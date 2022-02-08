#pragma once

#include "CIShape.hpp"

class Rectangle
{
public:
	// Just a constructor for the example
	explicit constexpr Rectangle( float const length, float const width )
		: m_length( length )
		, m_width( width )
	{}


	//
	// CIShape Interface implementation
	//


	// requires CIStaticMember<ShapeType, T::SHAPE_TYPE>; 
	static const ShapeType SHAPE_TYPE = ShapeType::Rectangle;

	// { shape.shapeName }		-> std::same_as<char const *const>;
	char const *const shapeName = "Rectangle";

	// { shape.unsafeValue }	-> std::same_as<int>;
	int unsafeValue = 1;


	// requires CIStaticMember<ShapeType, T::get_shape_type()>;
	static constexpr auto get_shape_type() -> ShapeType
	{
		return SHAPE_TYPE;
	}


	// { const_shape.get_area() } -> std::same_as<float>;
	[[nodiscard]] inline constexpr auto get_area() const -> float
	{
		return m_length * m_width;
	}


	// { const_shape.get_perimeter() } -> std::same_as<float>;
	[[nodiscard]] inline constexpr auto get_perimeter() const -> float
	{
		return ( m_length + m_width ) * 2;
	}


	// { shape.set_width( std::declval<float>() ) } -> std::same_as<void>;
	auto set_width( float const width ) -> void
	{
		m_width = width;
	}


	// { shape.set_length( std::declval<float>() ) } -> std::same_as<void>;
	auto set_length( float const length ) -> void
	{
		m_length = length;
	}


	// requires EqualityComparable<T>;
	constexpr bool operator==( Rectangle const &rhs ) const
	{
		return m_length == rhs.m_length and m_width == rhs.m_width;
	}


private:
	float m_length;
	float m_width;
};

// Ensure that the interface is correctly implemented
static_assert(is_shape_v<Rectangle>, "Rectangle doesn't implement correctly the CIShape interface.");
