#include "Entities/Ball.hh"


namespace BounceBall
{
	namespace Entity
	{
		Ball::Ball( StateBase& base )
		{

		}


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
		void Ball::render( sf::RenderTarget& handle )
		{

		}

		void Ball::parse( const std::vector<std::string>& lines )
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
						else if ( buffer == "jump_limit" )
						{
							buffer = read_buffer( line, j );
							jump_limit_ = std::stoi( buffer );
						}
						else if ( buffer == "velocity" )
						{
							buffer = read_buffer_paren( line, j );
							velocity_ = parse_vector2f( buffer );
						}
					}
				}
			}
		}
		void Ball::jump( )
		{

		}
	}
}