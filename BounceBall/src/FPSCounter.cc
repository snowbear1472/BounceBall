#include "FPSCounter.hh"
#include "Manager\ResourceHolder.hh"


namespace BounceBall
{
	FPSCounter::FPSCounter( )
	{
		text_.move( 10, 10 );
		text_.setOutlineColor( sf::Color::Red );
		text_.setFillColor( { 255, 255, 255 } );
		text_.setOutlineThickness( 3 );
		text_.setFont( Manager::ResourceHolder::get( ).fonts.get( "³ª´®¹Ù¸¥°íµñ" ) );
		text_.setCharacterSize( 25 );
	}

	void FPSCounter::update( )
	{
		frame_count_++;

		if ( delay_timer_.getElapsedTime( ).asSeconds( ) > 0.2 )
		{
			fps_ = frame_count_ / fps_timer_.restart( ).asSeconds( );
			frame_count_ = 0;
			delay_timer_.restart( );
		}
	}
	void FPSCounter::draw( sf::RenderTarget& handle )
	{
		text_.setString( "FPS: " + std::to_string( fps_ ) );
		handle.draw( text_ );
	}
}