#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <stack>
#include <string>
#include <cctype>

#include "Entity.hh"
#include "Object.hh"
#include "Map/MapFile.hh"


namespace BounceBall
{
	class Map final
	{
	public:
		Map( ) = default;

	public:
		void init( );
		void reset( );

	public:
		BounceBall::MapFile map_file_;
	};
}