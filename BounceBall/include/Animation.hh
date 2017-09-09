#pragma once

#include <SFML/Graphics.hpp>
#include <vector>


namespace BounceBall
{
	class Animation
	{
	public:
		class Frame
		{
		public:
			Frame( const sf::IntRect& bounds, sf::Time delay )
				: bounds_( bounds )
				, delay_( delay )
			{}

			sf::IntRect bounds_;
			sf::Time delay_;
		};


	public:
		Animation( ) = default;
		Animation( size_t frame_size );

	public:
		void add_frame( size_t index, sf::Time delay );
		const sf::IntRect& get_frame( );

	private:
		sf::Clock timer_;
		std::vector<Frame> frames_;

	private:
		size_t frame_pointer_ = 0;
		const size_t frame_size_;
	};
}