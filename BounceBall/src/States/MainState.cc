#include "States\MainState.hh"
#include "UI/StackMenu.hh"
#include "Game.hh"


namespace BounceBall
{
	namespace States
	{
		MainState::MainState( Game& game )
			: StateBase( game )
			, test_( game.get_window( ) )
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