#include "Animation.hh"


namespace BounceBall
{
	Animation::Animation( size_t frame_size )
		: frame_size_( frame_size )
	{}

	void Animation::add_frame( size_t index, sf::Time delay )
	{
		sf::IntRect bounds;
		{
			bounds.top = 0;
			bounds.height = frame_size_;
			bounds.width = frame_size_;
			bounds.left = index * frame_size_;
		}

		frames_.emplace_back( bounds, delay );
	}
	const sf::IntRect& Animation::get_frame( )
	{
		if ( timer_.getElapsedTime( ) >= frames_[frame_pointer_].delay_ )
		{
			timer_.restart( );
			frame_pointer_++;

			if ( frame_pointer_ == frames_.size( ) )
				frame_pointer_ = 0;
		}

		return frames_[frame_pointer_].bounds_;
	}
}