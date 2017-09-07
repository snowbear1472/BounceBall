#include "UI/Widget.hh"


namespace BounceBall
{
	namespace UI
	{
		Widget::Text::Text( )
		{
			setCharacterSize( 20 );
			setOutlineColor( sf::Color::Black );
			setFillColor( sf::Color::White );
			setFont( Manager::ResourceHolder::get( ).fonts_.get( "³ª´®¹Ù¸¥°íµñ" ) );
		}


		bool Widget::Rectangle::is_rolled_on( const sf::RenderWindow& handle ) const
		{
			auto pos = sf::Mouse::getPosition( handle );
			return getGlobalBounds( ).contains( pos.x, pos.y );
		}
		bool Widget::Rectangle::is_clicked( sf::Event e, const sf::RenderWindow& handle )
		{
			if ( is_rolled_on( handle ) )
				if ( e.type == sf::Event::MouseButtonPressed )
					return e.mouseButton.button == sf::Mouse::Left;
			return false;
		}
	}
}