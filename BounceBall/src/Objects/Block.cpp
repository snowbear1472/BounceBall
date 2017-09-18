#include "Objects/Block.hh"


namespace BounceBall
{
	namespace Objects
	{
		Block::Block( const sf::Vector2f& size, const sf::Texture& texture )
		{
			shape_.setSize( size );

			texture_ = texture;
			shape_.setTexture( &texture_ );
		}

		void Block::update( sf::Time delta_time )
		{

		}
		void Block::render( StateBase*& handle )
		{

		}

		const Version Block::recommend_parse_version( ) const
		{
			return Version( 1, 0, 0, 0 );
		}
		std::string& Block::replace_token( std::string& line )
		{
			return line;
		}

		void Block::parse( path& file )
		{
			Object::parse( file );
		}
		void Block::parse( const string_lines* lines )
		{
			Object::parse( lines );
		}
		void Block::parse( const csv_map* csv )
		{
			Object::parse( csv );
		}

		void Block::init( )
		{

		}
		void Block::reset( )
		{
			parse( &data_ );
		}
	}
}