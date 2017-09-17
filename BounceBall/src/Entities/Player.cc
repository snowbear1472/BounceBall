#include "Entities/Player.hh"


namespace BounceBall
{
	namespace Entities
	{
		void Player::handle_event( sf::Event e )
		{

		}
		void Player::handle_input( )
		{
			auto& direction = get_directions( );
			move( direction );
		}
		void Player::update( sf::Time delta_time )
		{

		}
		void Player::fixed_update( sf::Time delta_time )
		{

		}
		void Player::render( StateBase*& handle )
		{

		}


		std::string& Player::replace_token( std::string& line )
		{
			return line;
		}


		void Player::parse( path& file )
		{
			Entity::parse( file );
		}
		void Player::parse( const string_lines* lines )
		{
			Entity::parse( lines );
		}
		void Player::parse( const csv_map* csv )
		{
			Entity::parse( csv );

			bool read = false;


			for ( auto& i : data_ )
			{
				if ( tokens_map.find( i.first ) != tokens_map.end( ) )
				{
					switch ( tokens_map[i.first] )
					{
					case BounceBall::Entities::Player::TokenType::velocity:
						if ( i.second.at( 0 ).empty( ) )
						{
							throw std::runtime_error( Entity::error_messages_map[Entity::ErrorType::UNKWON__SCRIPT] );
						}
						else
						{
							velocity_ = parse_vector2f( i.second.at( 0 ) );
						}
						break;

					case BounceBall::Entities::Player::TokenType::key_type:
						if ( i.second.at( 0 ).empty( ) )
						{
							throw std::runtime_error( Entity::error_messages_map[Entity::ErrorType::UNKWON__SCRIPT] );
						}
						else
						{
							try
							{
								key_type_ = key_map[i.second.at( 0 )];
							}
							catch ( const std::exception& )
							{
								throw std::runtime_error( Entity::error_messages_map[Entity::ErrorType::UNKWON__SCRIPT] );
							}
						}
						break;

					default:
						throw std::runtime_error( Entity::error_messages_map[Entity::ErrorType::UNKWON__SCRIPT] );
					}

					if ( !read )
						read = true;
				}
			}

			if ( !read )
			{
				throw std::runtime_error( base_error_messages_map[ErrorTypeBase::NOT_FOUND__META_DATA] );
			}
		}


		void Player::init( )
		{

		}
		void Player::reset( )
		{
			parse( &data_ );
		}


		Player::moves Player::get_directions( ) const
		{
			moves buffer;


			switch ( key_type_ )
			{
			case BounceBall::Entities::Player::MoveKeyType::TYPE__1:
				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::W ) )
				{
					buffer.push_back( MoveDirectionType::up );
				}
				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::A ) )
				{
					buffer.push_back( MoveDirectionType::left );
				}
				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::S ) )
				{
					buffer.push_back( MoveDirectionType::down );
				}
				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::D ) )
				{
					buffer.push_back( MoveDirectionType::right );
				}
				break;

			case BounceBall::Entities::Player::MoveKeyType::TYPE__2:
				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Up ) )
				{
					buffer.push_back( MoveDirectionType::up );
				}
				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Left ) )
				{
					buffer.push_back( MoveDirectionType::left );
				}
				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Down ) )
				{
					buffer.push_back( MoveDirectionType::down );
				}
				if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Key::Right ) )
				{
					buffer.push_back( MoveDirectionType::right );
				}
				break;

			default:
				break;
			}


			return buffer;
		}


		void Player::move( const moves& direction )
		{
			for ( auto& i : direction )
			{
				switch ( i )
				{
				case BounceBall::Entities::Player::MoveDirectionType::up:
					velocity_.y = move_map[MoveDirectionType::up];
					break;

				case BounceBall::Entities::Player::MoveDirectionType::down:
					velocity_.y = move_map[MoveDirectionType::down];
					break;

				case BounceBall::Entities::Player::MoveDirectionType::left:
					velocity_.x = move_map[MoveDirectionType::left];
					break;

				case BounceBall::Entities::Player::MoveDirectionType::right:
					velocity_.x = move_map[MoveDirectionType::right];
					break;

				default:
					break;
				}
			}

			auto& pos = shape_.getPosition( );
			shape_.setPosition( { pos.x + velocity_.x, pos.y + velocity_.y } );
		}


		PlayerPtr make_player( )
		{
			return std::shared_ptr<Player>( );
		}
	}
}