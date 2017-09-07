#include "UI/Button.hh"


namespace BounceBall
{
	namespace UI
	{
		Button::Button( const SizeType& s )
		{
			button_.setFillColor( { 52, 152, 219 } );

			switch ( s )
			{
			case SizeType::Wide:
				button_.setSize( { 256, 64 } );
				break;

			case SizeType::Small:
				button_.setSize( { 128, 64 } );
				break;
			}
		}

		void Button::set_func( std::function<void( void )> func )
		{
			func_ = func;
		}
		void Button::set_text( const std::string& str )
		{
			text_.setString( str );
			update_text( );
		}
		void Button::set_texture( const sf::Texture& texture )
		{
			button_.setTexture( &texture );
		}

		void Button::handle_event( sf::Event e, const sf::RenderWindow& handle )
		{
			auto& pos = sf::Mouse::getPosition( handle );

			if ( button_.getGlobalBounds( ).contains( pos.x, pos.y ) )
			{
				if ( e.type == sf::Event::MouseButtonPressed )
					if ( e.mouseButton.button == sf::Mouse::Left )
						func_( );
			}
		}
		void Button::render( sf::RenderTarget& handle )
		{
			handle.draw( button_ );
			handle.draw( text_ );
		}
		void Button::set_position( const sf::Vector2f& pos )
		{
			pos_ = pos;

			button_.setPosition( pos );
			button_.setPosition( pos );

			update_text( );
		}
		sf::Vector2f Button::get_size( ) const
		{
			return button_.getSize( );
		}

		void Button::update_text( )
		{
			text_.setOrigin( text_.getGlobalBounds( ).width / 2,
				text_.getGlobalBounds( ).height / 2 );

			text_.move( button_.getGlobalBounds( ).width / 2,
				button_.getGlobalBounds( ).height / 2.5 );
		}
	}
}