#pragma once

#include <cctype>

#include "Animation.hh"
#include "Collision.hh"
#include "Util/Utility.hh"
#include "Manager/ResourceHolder.hh"


namespace BounceBall
{
	class StateBase;

	class EntityBase
	{
	public:
		EntityBase( ) = default;
		EntityBase( StateBase*& state )
			: state_( state )
		{}

	public:
		virtual ~EntityBase( ) = 0;

	public:
		virtual void handle_event( sf::Event e ) = 0;
		virtual void handle_input( ) = 0;
		virtual void update( sf::Time delta_time ) = 0;
		virtual void fixed_update( sf::Time delta_time ) = 0;
		virtual void render( sf::RenderTarget& handle ) = 0;

	public:
		virtual void init( )
		{
			shape_.setTexture( &texture_ );
		}
		virtual void parse( const std::vector<std::string>& lines )
		{
			std::string buffer = "";


			for ( int i = 0; i < lines.size( ); i++ )
			{
				for ( int j = 0; j < lines[i].length( ); j++ )
				{
					auto& line = lines[i];
					auto& c = line[j];


					if ( std::isalpha( c ) )
					{
						buffer = read_buffer( line, j );

						if ( buffer == "texture" )
						{
							buffer = read_buffer( line, j, '"' );
							texture_ = Manager::ResourceHolder::get( ).textures.get( buffer );
						}
					}
				}
			}
		}

	private:
		StateBase* state_;

	public:
		sf::RectangleShape shape_;
		sf::Texture texture_;

	public:
		std::shared_ptr<Animation> animation_;
		std::shared_ptr<Collision> collision_;
	};
}