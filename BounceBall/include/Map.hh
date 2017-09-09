#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <stack>
#include <string>
#include <cctype>

#include "EntityBase.hh"
#include "Object.hh"
#include "Map/MapFile.hh"


namespace BounceBall
{
	class Map final
	{
	public:
		Map( ) = default;

	public:
		void read_from_file( const std::string& path );
		void read_from_string( const std::vector<std::string>& lines );

	public:
		void reset( );

	public:
		BounceBall::Map::MapFile map_file_;

	public:
		std::vector<Object> objects_;
		std::vector<EntityBase> entities_;
	};
}