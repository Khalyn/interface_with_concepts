//
// POC : Using concepts to create an interface.
// As usual, will use Shapes-like POC for that.

#include <iostream>

#include "CIShape.hpp"


class Rectangle
{
public:
	static constexpr ShapeType SHAPE_TYPE = ShapeType::Rectangle;

	explicit constexpr Rectangle( float const length, float const width )
	: m_length( length )
	, m_width( width )
	{}


	[[nodiscard]] inline constexpr auto getArea() const -> float
	{
		return m_length * m_width;
	}


	[[nodiscard]] inline constexpr auto getPerimeter() const -> float
	{
		return ( m_length + m_width ) * 2;
	}


	auto setWidth( float const width ) -> void
	{
		m_width = width;
	}


	auto setLength( float const length ) -> void
	{
		m_length = length;
	}


private:
	float m_length;
	float m_width;
};
// Ensure that the interface is correctly implemented :
static_assert( is_shape_v<Rectangle>, "T doesn't implement correctly the CIShape interface." );


class Square
{
public:
	static constexpr ShapeType SHAPE_TYPE = ShapeType::Square;

	explicit constexpr Square( float const side )
		: m_side( side )
	{}


	[[nodiscard]] inline constexpr auto getArea() const -> float
	{
		return m_side * m_side;
	}


	[[nodiscard]] inline constexpr auto getPerimeter() const -> float
	{
		return m_side * 4;
	}


	auto setWidth( float const width ) -> void
	{
		m_side = width;
	}


	auto setLength( float const length ) -> void
	{
		m_side = length;
	}


private:
	float m_side;
};
// Ensure that the interface is correctly implemented :
static_assert(is_shape_v<Square>, "T doesn't implement correctly the CIShape interface.");


static auto display_perimeter_and_area( CIShape auto const &shape ) -> void
{
	auto const index = static_cast<std::underlying_type_t<ShapeType>>( shape.SHAPE_TYPE );
	printf( "Shape ID %u - Perimeter : %.2f\n", index, shape.getPerimeter() );
	printf( "Shape ID %u - Area : %.2f\n", index, shape.getArea() );
}


auto main() -> int
{
	constexpr Rectangle rect( 12.f, 15.f );
 	constexpr Square square( 5.f );

	display_perimeter_and_area( rect );
	display_perimeter_and_area( square );
	return 0;
}