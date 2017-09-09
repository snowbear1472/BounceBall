#pragma once

#include "StateBase.hh"
#include "UI/StackMenu.hh"


namespace BounceBall
{
	namespace States
	{
		class MainState : public StateBase
		{
		public:
			MainState( Game& game );

		public:
			void handle_event( sf::Event e ) override;
			void handle_input( ) override;
			void update( sf::Time delta_time ) override;
			void fixed_update( sf::Time delta_time ) override;
			void render( sf::RenderTarget& handle ) override;
		};
	}
}