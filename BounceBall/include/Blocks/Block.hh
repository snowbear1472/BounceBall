#pragma once

#include "Object.hh"
#include "Manager/ResourceHolder.hh"


namespace BounceBall
{
	namespace Blocks
	{
		class Block : public Object
		{
		public:
			Block( ) = default;
			Block( const sf::Vector2f& size, const sf::Texture& texture );

		public:
			virtual void update( ) override;

		public:
			virtual void init( ) override;

		public:
			virtual void parse( const string_lines* lines ) override;
			virtual void parse( const csv_map* csv ) override;
		};
	}
}