#include "UI/StackMenu.hh"
#include "Manager/ResourceHolder.hh"


namespace BounceBall
{
	namespace UI
	{
		constexpr int BASEY = 95;


		StackMenu::StackMenu( const sf::RenderWindow& handle )
			: base_pos_( handle.getSize( ).x / 2, BASEY )
			, base_size_( 300, 20 )
		{
			background_.setFillColor( { 100, 100, 100, 128 } );
			background_.setSize( base_size_ );
			background_.setPosition( base_pos_.x - base_size_.x / 2, BASEY - 30 );
		}
		StackMenu::StackMenu( const sf::Vector2f& pos )
			: base_pos_( pos )
			, base_size_( 300, 20 )
		{
			background_.setFillColor( { 100, 100, 100, 128 } );
			background_.setSize( base_size_ );
			background_.setPosition( pos );
		}
		StackMenu::StackMenu( StackMenu&& other )
			: widgets_( std::move( other.widgets_ ) )
			, background_( std::move( other.background_ ) )
			, base_pos_( other.base_pos_ )
			, base_size_( other.base_size_ )
		{}

		StackMenu& StackMenu::operator=( StackMenu&& other )
		{
			widgets_ = std::move( other.widgets_ );
			background_ = std::move( other.background_ );
			base_pos_ = other.base_pos_;
			base_size_ = other.base_size_;

			return *this;
		}

		void StackMenu::add_widget( std::unique_ptr<Widget> widget )
		{
			init_widget( *widget );
			widgets_.push_back( std::move( widget ) );
		}

		void StackMenu::handle_event( sf::Event e, const sf::RenderWindow& handle )
		{
			for ( auto& w : widgets_ )
				w->handle_event( e, handle );
		}
		void StackMenu::render( sf::RenderTarget& handle )
		{
			handle.draw( background_ );
			for ( auto& w : widgets_ )
				w->render( handle );
		}

		void StackMenu::init_widget( Widget& widget )
		{
			widget.set_position( { base_pos_.x - widget.get_size( ).x / 2,
			base_pos_.y } );

			base_pos_.y += widget.get_size( ).y + 25;
			base_size_.y += widget.get_size( ).y + 25;
			background_.setSize( base_size_ );
		}
	}
}