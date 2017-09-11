#include "Entities/Ball.hh"
#include "Manager/GameFileManager.hh"
#include <string>


namespace BounceBall
{
	namespace Entity
	{
		void Ball::handle_event( sf::Event e )
		{

		}
		void Ball::handle_input( )
		{

		}
		void Ball::update( sf::Time delta_time )
		{

		}
		void Ball::fixed_update( sf::Time delta_time )
		{

		}
		void Ball::render( StateBase*& handle )
		{

		}


		void Ball::init( )
		{

		}
		void Ball::parse( const string_lines* lines )
		{
			std::size_t index = 0;
			auto& csv = parse_csv( lines, index );

			parse( &csv );
		}
		void Ball::parse( const csv_map* csv )
		{
			for ( auto& i : *csv )
			{
				for ( int j = 0; j < i.size( ); j++ )
				{
					auto& val = i[j];

					if ( val == "data_type" )
					{
						if ( i[++j] != "bounceball:entity" )
							throw std::runtime_error( "script type is not bounceball_script!" );
					}
					else if ( val == "data_type" )
					{
						if ( i[++j] != "game:entity:ball" )
							throw std::runtime_error( "data type is not game:entity:ball!" );
					}
					else if ( val == "entity_name" )
						entity_name_ = i[++j];
					else if ( val == "velocity" )
						velocity_ = parse_vector2f( i[++j] );
					else if ( val == "radius" )
						radius_ = std::stof( i[++j] );
					else if ( val == "texture" )
					{
						texture_ = Manager::ResourceHolder::get( ).textures.get( i[++j] );
						shape_.setTexture( &texture_ );

						if ( is_vector2f_str( i[j + 1] ) && is_vector2f_str( i[j + 2] ) )
						{
							auto& pos_ = to_vector2i( parse_vector2f( i[++j] ) );
							auto& size_ = to_vector2i( parse_vector2f( i[++j] ) );

							shape_.setTextureRect( { pos_, size_ } );
						}
					}
					else if ( val == "animation" )
					{
						animation_->frame_size_ = std::stoi( i[++j] );

						std::size_t index = 0;

						while ( j < i.size( ) )
							animation_->add_frame( index++, sf::Time( sf::milliseconds( std::stof( i[++j] ) ) ) );
					}
					else if ( val == "jump_limit" )
						jump_limit_ = std::stof( i[++j] );
				}
			}
		}


		void Ball::jump( )
		{

		}
	}
}