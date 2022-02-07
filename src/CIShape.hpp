#pragma once

// CIShape for Concept-Interface Shape

#include <concepts>

// enum example
enum class ShapeType
{
	Rectangle,
	Square,
	Circle
};



template<typename T> concept EqualityComparable =
requires ( T const &shape )
{
	{ shape == shape } -> std::same_as<bool>;
};


// Interface definition
template<typename T> concept CIShape =
requires ( T &shape, T const &const_shape )
{
	// Static variables
	// TODO: Despite using T::*, this version also accept non-static public variables. ( like in Rectangle.hpp )
	// |--> Read again the concepts/contraints documentation and fix the issue.
	// |--> Once fixed, add a new example with a non-static variable.
	// |--> Add a static non-const and const methods in CIShape, to see if there is a similar issue with methods.
	{ T::SHAPE_TYPE } -> std::same_as<ShapeType const>;

	// mandatory const methods
	// If the method isn't const, the constraint won't be satisfied
	{ const_shape.get_area() }		-> std::same_as<float>;
	{ const_shape.get_perimeter() }	-> std::same_as<float>;

	// methods
	// Require a float parameter, and no return value
	{ shape.set_width( std::declval<float>() ) }	-> std::same_as<void>;
	{ shape.set_length( std::declval<float>() ) }	-> std::same_as<void>;

	// Can requires another concept to be implemented
	requires EqualityComparable<T>;

	// TODO : Add example of a static methods and static const methods
};


template<typename T>
inline constexpr bool is_shape_v = CIShape<T>;
