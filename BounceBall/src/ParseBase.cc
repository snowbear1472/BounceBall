#include "ParseBase.hh"


namespace BounceBall
{
	void ParseBase::parse( path& file )
	{
		if ( get_extension( file ) == "csv" && file_exist( file ) )
		{
			auto& read = read_file( file );
			parse( &read );
		}
	}
	void ParseBase::parse( const string_lines* lines )
	{
		data_ = parse_csv( lines );
		parse( &data_ );
	}
	void ParseBase::parse( const csv_map* csv )
	{
		bool read = false;


		for ( auto& i : *csv )
		{
			if ( base_tokens_map.find( i.first ) != base_tokens_map.end( ) )
			{
				switch ( base_tokens_map[i.first] )
				{
				case BounceBall::ParseBase::TokenTypeBase::file_type:
					if ( i.second.at( 0 ) != base_environ_values_map[EnvironValueTypeBase::TYPE__FILE] )
					{
						throw std::runtime_error( base_error_messages[ErrorTypeBase::UNKWON__FILE] );
					}
					break;

				case BounceBall::ParseBase::TokenTypeBase::data_type:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( base_error_messages[ErrorTypeBase::UNKWON__META_DATA] );
					}
					else
					{
						meta_data_.data_type_ = i.second.at( 0 );
					}
					break;

				case BounceBall::ParseBase::TokenTypeBase::parse_version:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( base_error_messages[ErrorTypeBase::UNKWON__META_DATA] );
					}
					else
					{
						try
						{
							meta_data_.parse_version_.parse( i.second.at( 0 ) );
						}
						catch ( const std::exception& )
						{
							throw std::runtime_error( base_error_messages[ErrorTypeBase::UNKWON__META_DATA] );
						}
					}
					break;

				case BounceBall::ParseBase::TokenTypeBase::name:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( base_error_messages[ErrorTypeBase::UNKWON__META_DATA] );
					}
					else
					{
						meta_data_.name_ = i.second.at( 0 );
					}
					break;

				case BounceBall::ParseBase::TokenTypeBase::developer:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( base_error_messages[ErrorTypeBase::UNKWON__META_DATA] );
					}
					else
					{
						meta_data_.developer_ = i.second.at( 0 );
					}
					break;

				case BounceBall::ParseBase::TokenTypeBase::details:
					if ( i.second.at( 0 ).empty( ) )
					{
						throw std::runtime_error( base_error_messages[ErrorTypeBase::UNKWON__META_DATA] );
					}
					else
					{
						meta_data_.details_ = i.second.at( 0 );
					}
					break;

				default:
					throw std::runtime_error( base_error_messages[ErrorTypeBase::UNKWON__META_DATA] );
				}

				if ( !read )
					read = true;
			}
		}

		if ( !read )
		{
			throw std::runtime_error( base_error_messages[ErrorTypeBase::NOT_FOUND__META_DATA] );
		}
	}
}