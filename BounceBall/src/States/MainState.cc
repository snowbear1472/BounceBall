#include "States/MainState.hh"
#include "Game.hh"


namespace BounceBall
{
	namespace States
	{
		MainState::MainState( Game& game )
			: StateBase( game )
		{

		}

		void MainState::handle_event( sf::Event e )
		{

		}
		void MainState::handle_input( )
		{}
		void MainState::update( sf::Time delta_time )
		{}
		void MainState::fixed_update( sf::Time delta_time )
		{}
		void MainState::render( sf::RenderTarget& handle )
		{}
	}
}