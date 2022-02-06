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
	{ T::SHAPE_TYPE } -> std::same_as<ShapeType const>;

	// mandatory const methods
	// If the method isn't const, the constraint won't be satisfied
	{ const_shape.get_area() } -> std::same_as<float>;
	{ const_shape.get_perimeter() } -> std::same_as<float>;

	// methods
	// Require a float parameter, and no return value
	{ shape.set_width( std::declval<float>() ) } -> std::same_as<void>;
	{ shape.set_length( std::declval<float>() ) } -> std::same_as<void>;

	// Can Requires another concept to be implemented
	requires EqualityComparable<T>;
};


template<typename T>
inline constexpr bool is_shape_v = CIShape<T>;
