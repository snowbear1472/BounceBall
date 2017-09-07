#pragma once

#include <SFML/Graphics.hpp>


namespace BounceBall
{
	class FPSCounter
	{
	public:
		FPSCounter( );

	public:
		void update( );
		void draw( sf::RenderTarget& handle );

	private:
		sf::Text text_;
		sf::Font font_;

		sf::Clock delay_timer_;
		sf::Clock fps_timer_;

	private:
		float fps_ = 0;
		std::size_t frame_count_ = 0;
	};
}