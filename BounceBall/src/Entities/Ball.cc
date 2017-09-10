#include "Entities/Ball.hh"


namespace BounceBall
{
	namespace Entity
	{
		Ball::Ball( StateBase*& base )
		{

		}
		Ball::~Ball( )
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

		void Ball::parse( const string_lines& lines )
		{
			std::size_t index = 0;
			auto& csv = parse_csv( &lines, index );

			parse( csv );
		}
		void Ball::parse( const csv_map& csv )
		{
			for ( auto& i : csv )
			{
				if ( i.first == "texture" )
					texture_.loadFromFile( i.second );
				else if ( i.first == "jump_limit" )
					jump_limit_ = std::stoi( i.second );
				else if ( i.first == "velocity" )
					parse_vector2f( i.second );
			}
		}
		void Ball::jump( )
		{

		}
	}
}