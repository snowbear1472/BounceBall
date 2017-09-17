#include "MapFile.hh"


namespace BounceBall
{
	MapFile::~MapFile( )
	{
		for ( auto o : objects_ )
			delete o.second;

		for ( auto e : entities_ )
			delete e.second;
	}


	const Version MapFile::recommend_parse_version( ) const
	{
		return Version( 1, 0, 0, 0 );
	}
	std::string& MapFile::replace_tokens( std::string& line )
	{

		return line;
	}


	void MapFile::parse( path& file )
	{
		ParseBase::parse( file );
	}
	void MapFile::parse( const string_lines* lines )
	{
		ParseBase::parse( lines );
	}
	void MapFile::parse( const csv_map* csv )
	{
		ParseBase::parse( csv );


		if ( meta_data_.data_type_ != environ_values_map[EnvironValueType::TYPE__DATA] )
		{
			throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
		}


		if ( meta_data_.parse_version_ == Version( 1, 0, 0, 0 ) )
		{
			parse_ver_1_0_0_0( &data_ );
		}
	}


	void MapFile::parse_ver_1_0_0_0( const csv_map* csv )
	{
		bool read = false;


		for ( auto& i : *csv )
		{
			if ( tokens_map.find( i.first ) != tokens_map.end( ) )
			{
				switch ( tokens_map[i.first] )
				{
				case BounceBall::MapFile::TokenType::map_name:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
					}
					else
					{
						map_name_ = i.second.at( 0 );
					}
					break;

				case BounceBall::MapFile::TokenType::size:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
					}
					else
					{
						map_size_ = parse_vector2f( i.second.at( 0 ) );
					}
					break;

				case BounceBall::MapFile::TokenType::display_size:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
					}
					else
					{
						display_size_ = parse_vector2f( i.second.at( 0 ) );
					}
					break;

				case BounceBall::MapFile::TokenType::background_color:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
					}
					else
					{
						try
						{
							background_color_ = parse_color( i.second.at( 0 ) );
						}
						catch ( const std::exception& )
						{
							throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
						}
					}
					break;

				case BounceBall::MapFile::TokenType::background_texture:
					if ( i.second.at( 0 ).empty( ) || i.second.at( 1 ).empty( ) || i.second.at( 2 ).empty( ) )
					{
						throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
					}
					else
					{
						try
						{
							background_texture_.loadFromFile( i.second.at( 0 ) );

							auto& pos = to_vector2i( parse_vector2f( i.second.at( 1 ) ) );
							auto& size = to_vector2i( parse_vector2f( i.second.at( 2 ) ) );

							background_texture_rect_ = { pos, size };
						}
						catch ( const std::exception& )
						{
							throw std::runtime_error( error_messages_map[ErrorType::UNKWON__SCRIPT] );
						}
					}
					break;

				case BounceBall::MapFile::TokenType::add:
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


	void MapFile::init( )
	{

	}
	void MapFile::reset( )
	{
		parse( &data_ );
	}


	MapFilePtr make_mapfile( )
	{
		return std::shared_ptr<MapFile>( );
	}
}