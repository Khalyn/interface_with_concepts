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


	// { T::SHAPE_TYPE } -> std::same_as<ShapeType const>; 
	static constexpr ShapeType SHAPE_TYPE = ShapeType::Rectangle;


	// { const_shape.get_area() } -> std::same_as<float>;
	[[nodiscard]] inline constexpr auto get_area() const -> float
	{
		return m_length * m_width;
	}


	// { const_shape.get_perimeter() } -> std::same_as<float>;
	[[nodiscard]] inline constexpr auto get_perimeter() const -> float
	{
		return (m_length + m_width) * 2;
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
