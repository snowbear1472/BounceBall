#include "Entity.hh"


namespace BounceBall
{
	std::string& Entity::replace_token( std::string& line )
	{
		//nothing to do

		return line;
	}

	void Entity::parse( path& file )
	{
		ParseBase::parse( file );
	}
	void Entity::parse( const string_lines* lines )
	{
		ParseBase::parse( lines );
	}
	void Entity::parse( const csv_map* csv )
	{
		ParseBase::parse( csv );

		bool read = false;


		if ( meta_data_.data_type_ != environ_values_map[EnvironValueType::TYPE__DATA] )
			throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );


		for ( auto& i : data_ )
		{
			if ( tokens_map.find( i.first ) != tokens_map.end( ) )
			{
				switch ( tokens_map[i.first] )
				{
				case BounceBall::Entity::TokenType::entity_name:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
					}
					else
					{
						entity_name_ = i.second.at( 0 );
					}
					break;

				case BounceBall::Entity::TokenType::size:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
					}
					else
					{
						shape_.setSize( parse_vector2f( i.second.at( 0 ) ) );

						auto& size = shape_.getSize( );
						shape_.setOrigin( size.x / 2, size.y / 2 );
					}
					break;

				case BounceBall::Entity::TokenType::color:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
					}
					else
					{
						try
						{
							shape_.setFillColor( parse_color( i.second.at( 0 ) ) );
						}
						catch ( const std::exception& )
						{
							throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
						}
					}
					break;

				case BounceBall::Entity::TokenType::texture:
					if ( i.second.at( 0 ).empty( ) || i.second.at( 1 ).empty( ) || i.second.at( 2 ).empty( ) )
					{
						throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
					}
					else
					{
						try
						{
							texture_.loadFromFile( i.second.at( 0 ) );
							shape_.setTexture( &texture_ );

							auto& pos = to_vector2i( parse_vector2f( i.second.at( 1 ) ) );
							auto& size = to_vector2i( parse_vector2f( i.second.at( 2 ) ) );

							shape_.setTextureRect( { pos, size } );
						}
						catch ( const std::exception& )
						{
							throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
						}
					}
					break;

				case BounceBall::Entity::TokenType::animation:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
					}
					else
					{
						animation_->frame_size_ = std::stoi( i.second.at( 0 ) );
					}
					break;

				case BounceBall::Entity::TokenType::frame:
					if ( i.second.size( ) <= 0 )
					{
						throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
					}
					else
					{
						try
						{
							for ( int j = 0; j < i.second.size( ); j++ )
							{
								animation_->add_frame( j, sf::Time( sf::microseconds( std::stoi( i.second.at( j ) ) ) ) );
							}
						}
						catch ( const std::exception& )
						{
							throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
						}
					}
					break;

				default:
					throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
				}

				if ( !read )
					read = true;
			}
		}

		if ( !read )
		{
			throw std::runtime_error( error_messages_map[ErrorType::NOT_FOUND__SCRIPT] );
		}
	}
}