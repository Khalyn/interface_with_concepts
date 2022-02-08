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


// This can test the existence of the static variable/method.
// It's successfully differentiate static over non-static member variable/method, but there must be an easier way to do it.
template<typename T, T value> concept CIStaticMember = requires { value; };


// Interface definition
template<typename T> concept CIShape =
requires ( T &shape, T const &const_shape )
{
	// Check for a public static variable. ( const optional as all static member variables have to be const anyway )
	requires CIStaticMember<ShapeType, T::SHAPE_TYPE>;

	// Check for a public const variable.
	{ shape.shapeName }		-> std::same_as<char const *const>;

	// Check for a public variable.
	{ shape.unsafeValue }	-> std::same_as<int>;


	// Check for a public static method, which returns a ShapeType.
	requires CIStaticMember<ShapeType, T::get_shape_type()>;


	// Check for a public const method.
	// Need to use the const_shape version to require the const version of the function.
	// If the method isn't const, the constraint won't be satisfied
	{ const_shape.get_area() }		-> std::same_as<float>;
	{ const_shape.get_perimeter() }	-> std::same_as<float>;


	// Check for a public method
	// Could be const, but not required.
	// Require a float parameter, and no return value
	{ shape.set_width( std::declval<float>() ) }	-> std::same_as<void>;
	{ shape.set_length( std::declval<float>() ) }	-> std::same_as<void>;


	// Can requires another concept to be implemented
	requires EqualityComparable<T>;
};


template<typename T>
inline constexpr bool is_shape_v = CIShape<T>;
