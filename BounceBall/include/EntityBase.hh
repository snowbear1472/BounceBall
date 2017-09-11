#pragma once

#include <cctype>

#include "StateBase.hh"
#include "Animation.hh"
#include "Collision.hh"
#include "Util/Utility.hh"
#include "Manager/ResourceHolder.hh"


namespace BounceBall
{
	class EntityBase
	{
	public:
		EntityBase( ) = default;

	public:
		virtual void handle_event( sf::Event e ) = 0;
		virtual void handle_input( ) = 0;
		virtual void update( sf::Time delta_time ) = 0;
		virtual void fixed_update( sf::Time delta_time ) = 0;
		virtual void render( StateBase*& handle ) = 0;

	public:
		virtual void init( )
		{
			shape_.setTexture( &texture_ );
		}

	public:
		virtual void parse( const string_lines* lines ) = 0;
		virtual void parse( const csv_map* csv ) = 0;

	public:
		std::string entity_name_;

	public:
		sf::RectangleShape shape_;
		sf::Texture texture_;

	public:
		std::shared_ptr<Animation> animation_;
		std::shared_ptr<Collision> collision_;
	};
}