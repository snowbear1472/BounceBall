#pragma once

#include "Object.hh"
#include "Manager/ResourceHolder.hh"


namespace BounceBall
{
	namespace Objects
	{
		class Block : public Object
		{
		public:
			Block( ) = default;
			Block( const sf::Vector2f& size, const sf::Texture& texture );

		public:
			virtual void update( sf::Time delta_time ) override;
			virtual void render( StateBase*& handle ) override;

		public:
			virtual const Version recommend_parse_version( ) const override;
			virtual std::string& replace_token( std::string& line ) override;

		public:
			virtual void parse( path& file ) override;
			virtual void parse( const string_lines* lines ) override;
			virtual void parse( const csv_map* csv ) override;

		public:
			virtual void init( ) override;
			virtual void reset( ) override;
		};
	}
}