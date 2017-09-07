#include "UI/Textbox.hh"


namespace BounceBall
{
	namespace UI
	{
		Textbox::Textbox( const std::string& str )
			: mod_str_( str )
		{
			label_.setCharacterSize( 15 );
			rect_.setFillColor( { 52, 152, 219 } );
			rect_.setSize( { 256, 65 } );
		}

		void Textbox::set_label( const std::string& str )
		{
			label_.setString( str );
		}
		void Textbox::set_texture( const sf::Texture& texture )
		{
			rect_.setTexture( &texture );
		}

		void Textbox::handle_event( sf::Event e, const sf::RenderWindow& handle )
		{
			handle_click( e, handle );
			handle_text_changed( e );
		}
		void Textbox::render( sf::RenderTarget& handle )
		{
			if ( enable )
				rect_.setFillColor( { 52, 152, 219 } );
			else
				rect_.setFillColor( { 82, 132, 239 } );

			handle.draw( rect_ );
			handle.draw( label_ );
			handle.draw( text_ );
		}
		void Textbox::set_position( const sf::Vector2f& pos )
		{
			pos_ = pos;

			rect_.setPosition( pos );
			label_.setPosition( pos.x,
				pos.y + label_.getGlobalBounds( ).height - rect_.getGlobalBounds( ).height / 2 );
			text_.setPosition( pos );
			text_.move( 5, rect_.getGlobalBounds( ).height / 2.5 );
		}
		sf::Vector2f Textbox::get_size( ) const
		{
			return { rect_.getSize( ).x,
			rect_.getSize( ).y + label_.getGlobalBounds( ).height };
		}

		void Textbox::handle_click( sf::Event e, const sf::RenderWindow& handle )
		{
			auto& pos = sf::Mouse::getPosition( handle );

			if ( rect_.getGlobalBounds( ).contains( pos.x, pos.y ) )
			{
				if ( e.type == sf::Event::MouseButtonPressed )
					if ( e.mouseButton.button == sf::Mouse::Left )
						enable = true;
			}
			else
			{
				if ( e.type == sf::Event::MouseButtonPressed )
					if ( e.mouseButton.button == sf::Mouse::Left )
						enable = false;
			}

		}
		void Textbox::handle_text_changed( sf::Event e )
		{
			if ( e.type == sf::Event::TextEntered && enable )
			{
				auto& c = e.text.unicode;

				if ( c == 8 )
				{
					if ( mod_str_.length( ) > 0 )
						mod_str_.pop_back( );
				}
				else
				{
					mod_str_.push_back( c );
				}

				text_.setString( mod_str_ );
			}
		}
	}
}