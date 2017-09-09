#pragma once

#include "StateBase.hh"
#include "Animation.hh"
#include "Collision.hh"


namespace BounceBall
{
	class EntityBase
	{
	public:
		EntityBase( ) = default;
		EntityBase( StateBase& state )
			: state_( &state )
		{}

	public:
		virtual ~EntityBase( ) = 0;

	public:
		virtual void handle_event( sf::Event e ) = 0;
		virtual void handle_input( ) = 0;
		virtual void update( sf::Time delta_time ) = 0;
		virtual void fixed_update( sf::Time delta_time ) = 0;
		virtual void render( sf::RenderTarget& handle ) = 0;

	private:
		StateBase* state_;

	public:
		sf::RectangleShape shape_;
		sf::Texture texture_;

	public:
		std::shared_ptr<Animation> animation_;
		std::shared_ptr<Collision> collision_;
	};
}