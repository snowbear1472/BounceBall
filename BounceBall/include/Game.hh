#pragma once

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "StateBase.hh"
#include "FPSCounter.hh"


namespace BounceBall
{
	class Game
	{
	public:
		Game( );

	public:
		void run( );

	public:
		const sf::RenderWindow& get_window( ) const;

	public:
		template<typename T_, typename... TArgs_>
		void push_state( TArgs_&&... args )
		{
			states_.push_back( std::make_unique<T_>( std::forward<TArgs_>( args )... ) );
		}
		void pop_state( );

	private:
		void handle_event( );
		void try_pop( );
		StateBase& get_current_state( );

	private:
		sf::RenderWindow window_;
		std::vector<std::unique_ptr<StateBase>> states_;
		FPSCounter counter_;

		bool should_pop_ = false;
	};
}