#include "Collision.hh"
#include "Util/Utility.hh"


namespace BounceBall
{
	Collision::Collision( sf::RectangleShape& shape )
		: shape_( &shape )
	{}

	sf::Vector2f Collision::get_real_pos( ) const
	{
		auto& i = *shape_;

		auto& pos = i.getPosition( );
		auto& o = i.getOrigin( );

		return { o.x - pos.x, o.y - pos.y };
	}
	sf::Vector2f Collision::get_real_end_pos( ) const
	{
		auto& real = get_real_pos( );
		auto& size = shape_->getSize( );

		return { real.x + size.x, real.y + size.y };
	}
	bool Collision::is_collision( const Collision& col ) const
	{
		return ( collisions_.at( CollisionType::up ) || collisions_.at( CollisionType::down ) ||
			collisions_.at( CollisionType::left ) || collisions_.at( CollisionType::right ) );
	}

	void Collision::update( const Collision& col )
	{
		/* 출동 판정 방식은 다음과 같습니다.
		* 좌표에는 음수가 존재하지 않습니다.
		* 좌표는 위에서 아래로 왼쪽에서 오른쪽으로 증가합니다.
		* 모든 entity는 origin이 entity의 center로 자동 설정됩니다.
		*/


		auto& this_pos = get_real_pos( );
		auto& this_end_pos = get_real_end_pos( );

		auto& col_pos = col.get_real_pos( );
		auto& col_end_pos = col.get_real_end_pos( );


		bool up = !( this_pos.y >= col_end_pos.y );
		bool down = !( this_end_pos.y <= col_pos.y );

		bool left = !( this_pos.x <= col_end_pos.x );
		bool right = !( this_end_pos.x <= col_pos.x );


		collisions_[CollisionType::up] = up;
		collisions_[CollisionType::down] = down;
		collisions_[CollisionType::left] = left;
		collisions_[CollisionType::right] = right;

	}
}