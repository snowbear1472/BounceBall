#pragma once

#include <SFML/Graphics.hpp>

namespace BounceBall
{
	class Game;

	class StateBase
	{
		StateBase( Game& game )
			: game_( &game )
		{}


	public:
		virtual void handle_event( sf::Event e ) = 0;
		virtual void handle_input( ) = 0;
		virtual void update( sf::Time delta_time ) = 0;
		virtual void fixed_update( sf::Time delta_time ) = 0;
		virtual void render( sf::RenderTarget& handle ) = 0;

	private:
		Game* game_;
	};
}