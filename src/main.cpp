//
// POC : Using concepts to create an interface.
// As usual, will use Shapes-like POC for that.

#include <iostream>

#include "Rectangle.hpp"
#include "Square.hpp"


static inline auto update_width( CIShape auto &shape, float const width ) -> void
{
	shape.set_width( width );
}


static inline auto display_perimeter_and_area( CIShape auto const &shape ) -> void
{
	auto const index = static_cast<std::underlying_type_t<ShapeType>>( shape.SHAPE_TYPE );
	printf( "%s ID %u - Perimeter : %.2f\n", shape.shapeName, index, shape.get_perimeter() );
	printf( "%s ID %u - Area : %.2f\n", shape.shapeName, index, shape.get_area() );
}


auto main() -> int
{
	Rectangle rect( 12.f, 15.f );
 	Square square( 5.f );

	display_perimeter_and_area( rect );
	display_perimeter_and_area( square );

	update_width( rect, 7.f );
	update_width( square, 20.f );
	printf( "=== After width update ===\n" );

	display_perimeter_and_area( rect );
	display_perimeter_and_area( square );

	return 0;
}