#include "Game.hh"
#include "States\MainState.hh"


namespace BounceBall
{
	Game::Game( )
		: window_( { 1280, 720 }, "BounceBall" )
	{
		window_.setFramerateLimit( 1000 );
		push_state<States::MainState>( *this );
	}

	void Game::run( )
	{
		constexpr size_t TPS = 120;
		const sf::Time time_p_u = sf::seconds( 1.0f / float( TPS ) );
		size_t ticks = 0;

		sf::Clock timer;
		auto last_time = sf::Time::Zero;
		auto lag = sf::Time::Zero;


		while ( window_.isOpen( ) && !states_.empty( ) )
		{
			auto& state = get_current_state( );


			auto time = timer.getElapsedTime( );
			auto elapsed = time - last_time;

			last_time = time;
			lag += elapsed;


			state.handle_input( );
			state.update( elapsed );
			counter_.update( );


			while ( lag >= time_p_u )
			{
				ticks++;
				lag -= time_p_u;
				state.fixed_update( elapsed );
			}


			window_.clear( );
			state.render( window_ );
			counter_.draw( window_ );
			
			window_.display( );


			handle_event( );
			try_pop( );
		}
	}
	const sf::RenderWindow& Game::get_window( ) const
	{
		return window_;
	}
	void Game::pop_state( )
	{
		should_pop_ = true;
	}

	void Game::handle_event( )
	{
		sf::Event e;

		while ( window_.pollEvent( e ) )
		{
			get_current_state( ).handle_event( e );

			switch ( e.type )
			{
			case sf::Event::Closed:
				window_.close( );
				break;

			default:
				break;
			}
		}
	}
	void Game::try_pop( )
	{
		if ( should_pop_ )
			states_.pop_back( );
	}
	StateBase& Game::get_current_state( )
	{
		return *states_.back( );
	}
}