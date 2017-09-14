#pragma once

#include <SFML/Graphics.hpp>

#include "Util/Utility.hh"
#include "Collision.hh"
#include "ParseBase.hh"


namespace BounceBall
{
	class Object : public ParseBase
	{
	public:
		Object( ) = default;

	public:
		virtual const Version recommend_parse_version( ) const override;
		virtual std::string& replace_token( std::string& line ) override;

	public:
		virtual void parse( path& file ) override;
		virtual void parse( const string_lines* lines ) override;
		virtual void parse( const csv_map* csv ) override;

	public:
		virtual void update( sf::Time delta_time ) = 0;
		virtual void render( StateBase*& handle ) = 0;

	public:
		virtual void init( ) = 0;
		virtual void reset( ) = 0;

	public:
		std::string object_name_;

	public:
		sf::RectangleShape shape_;
		sf::Texture texture_;

	public:
		std::shared_ptr<Collision> collision_;
	};
}