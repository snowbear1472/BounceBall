#pragma once

#include <SFML/Graphics.hpp>
#include "Util/Utility.hh"

namespace BounceBall
{
	class Object
	{
	public:
		Object( ) = default;

	public:
		virtual void update( ) = 0;

	public:
		virtual void init( ) = 0;

	public:
		virtual void parse( const string_lines* lines ) = 0;
		virtual void parse( const csv_map* csv ) = 0;

	public:
		sf::RectangleShape shape_;
		sf::Texture texture_;

	public:
		std::string object_name_;
	};
}