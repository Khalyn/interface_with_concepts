#pragma once

#include "CIShape.hpp"

class Square
{
public:
	// Just a constructor for the example
	explicit constexpr Square( float const side )
		: m_side( side )
	{}


	//
	// CIShape Interface implementation
	//


	// { T::SHAPE_TYPE } -> std::same_as<ShapeType const>; 
	static constexpr ShapeType SHAPE_TYPE = ShapeType::Square;


	// { const_shape.get_area() } -> std::same_as<float>;
	[[nodiscard]] inline constexpr auto get_area() const -> float
	{
		return m_side * m_side;
	}


	// { const_shape.get_perimeter() } -> std::same_as<float>;
	[[nodiscard]] inline constexpr auto get_perimeter() const -> float
	{
		return m_side * 4;
	}


	// { shape.set_width( std::declval<float>() ) } -> std::same_as<void>;
	auto set_width( float const width ) -> void
	{
		m_side = width;
	}


	// { shape.set_length( std::declval<float>() ) } -> std::same_as<void>;
	auto set_length( float const length ) -> void
	{
		m_side = length;
	}


	// requires EqualityComparable<T>;
	constexpr bool operator==( Square const& rhs ) const
	{
		return m_side == rhs.m_side;
	}


private:
	float m_side;
};

// Ensure that the interface is correctly implemented
static_assert(is_shape_v<Square>, "Square doesn't implement correctly the CIShape interface.");
