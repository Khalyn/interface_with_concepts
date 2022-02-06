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


// Interface definition

template<typename T> concept CIShape =
requires ( T &shape, T const &const_shape )
{
	// Static variables
	{ T::SHAPE_TYPE } -> std::same_as<ShapeType const>;

	// mandatory const methods
	// If the method isn't const, the constraint won't be satisfied
	{ const_shape.getArea() } -> std::same_as<float>;
	{ const_shape.getPerimeter() } -> std::same_as<float>;

	// methods
	// Require a float const parameter, and no return value
	{ shape.setWidth( std::declval<float>() ) } -> std::same_as<void>;
	{ shape.setLength( std::declval<float>() ) } -> std::same_as<void>;
};


template<typename T>
inline constexpr bool is_shape_v = CIShape<T>;
