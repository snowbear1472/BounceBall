#include "Entities/Ball.hh"
#include "Manager/GameFileManager.hh"
#include <string>


namespace BounceBall
{
	namespace Entities
	{
		void Ball::handle_event( sf::Event e )
		{

		}
		void Ball::handle_input( )
		{
			auto& direction = get_directions( );
			move( direction );

			jump( );
		}
		void Ball::update( sf::Time delta_time )
		{

		}
		void Ball::fixed_update( sf::Time delta_time )
		{

		}
		void Ball::render( StateBase*& handle )
		{

		}

		const Version Ball::recommend_parse_version( ) const
		{
			return Version( 1, 0, 0, 0 );
		}
		std::string& replace_token( std::string& line )
		{
			return line;
		}

		void Ball::parse( path& file )
		{
			Player::parse( file );
		}
		void Ball::parse( const string_lines* lines )
		{
			Player::parse( lines );
		}
		void Ball::parse( const csv_map* csv )
		{
			Player::parse( csv );

			bool read = false;


			for ( auto& i : data_ )
			{
				if ( tokens_map.find( i.first ) != tokens_map.end( ) )
				{
					switch ( tokens_map[i.first] )
					{
					case BounceBall::Entities::Ball::TokenType::radius:
						if ( i.second.at( 0 ).empty( ) )
						{
							throw std::runtime_error( Entity::error_messages[Entity::ErrorType::UNKWON__SCRIPT] );
						}
						else
						{
							radius_ = std::stof( i.second.at( 0 ) );
						}
						break;

					default:
						break;
					}
				}
			}
		}

		void Ball::init( )
		{
			state_ = StateType::Stand;
			jump_state_ = JumpType::Rising;
		}
		void Ball::reset( )
		{
			parse( &data_ );
		}

		/*Player::moves Ball::get_directions( ) const
		{

		}*/

		void Ball::move( const moves& direction )
		{
			for ( auto& i : direction )
			{
				switch ( i )
				{
				case BounceBall::Entities::Player::MoveDirectionType::up:
					//ignore
					break;

				case BounceBall::Entities::Player::MoveDirectionType::down:
					//ignore
					break;

				case BounceBall::Entities::Player::MoveDirectionType::left:
					velocity_.x = move_map[MoveDirectionType::left];
					break;

				case BounceBall::Entities::Player::MoveDirectionType::right:
					velocity_.y = move_map[MoveDirectionType::right];
					break;

				default:
					break;
				}
			}


		}
		void Ball::jump( )
		{
			switch ( jump_state_ )
			{
			case BounceBall::Entities::Ball::JumpType::Rising:
				if ( jump_ >= velocity_.y )
				{
					jump_state_ = JumpType::Falling;
				}
				else if ( jump_ <= velocity_.y )
				{
					jump_ += 0.85f;
				}
				break;

			case BounceBall::Entities::Ball::JumpType::Falling:
				if ( jump_ >= 0 )
				{
					jump_state_ = JumpType::Rising;
				}
				else if ( jump_ <= velocity_.y )
				{
					jump_ -= 1.25f;
				}
				break;
			}

			shape_.move( { velocity_.x, velocity_.y + jump_ } );
		}


		BallPtr make_ball( )
		{
			return std::shared_ptr<Ball>( );
		}
	}
}