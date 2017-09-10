#include "Map/MapFile.hh"

#include "Entities/Ball.hh"

namespace BounceBall
{
	std::string&  MapFile::replace_tokens( std::string& line )
	{
		return line;
	}


	void MapFile::parse_from_file( const std::string& path )
	{

	}
	void  MapFile::parse_from_string( string_lines lines )
	{
		/*
			* 이곳에서 csv_map을 초기화 및 lines를 lexing합니다.
			* 이곳에서는 lex한 csv_map에서 meta_data만 읽습니다.
			* 이곳에서 meta_data를 통한 맵 읽기 버전을 추론합니다.
			* meta_data 형식은 변하지 않습니다.
		*/

		std::size_t index = 0;
		csv_map buffer;

		try
		{
			buffer = parse_csv( &lines, index );
		}
		catch ( std::runtime_error )
		{
			throw std::runtime_error( error_messages_[ErrorType::WRONG_FILE] );
		}

		try
		{
			version_.parse( buffer["version"] );
			map_version_.parse( buffer["map_version"] );
			name_ = buffer["name"];
			developer_ = buffer["developer"];
			details_ = buffer["details"];
		}
		catch ( std::runtime_error )
		{
			throw std::runtime_error( error_messages_[ErrorType::META_DATA_NOT_FOUND] );
		}


		if ( map_version_ == Version( 1, 0, 0, 0 ) )
			parse_ver_1_0( buffer );
	}


	void MapFile::parse_ver_1_0( const csv_map& map )
	{
		bool charge = false;

		sf::Vector2f vbuffer;
		std::string sbuffer = "";

		for ( auto& i : map )
		{
			auto& key = i.first;
			auto& val = i.second;


			if ( *key.begin( ) == '(' && *key.end( ) == ')' ) // (5, 4)
			{
				vbuffer = parse_vector2f( i.first );

				switch ( id_tokens_[val] )
				{
				case BounceBall::MapFile::IDType::object:
					// ignore
					break;

				case BounceBall::MapFile::IDType::entity:
					//ignore
					break;

				case BounceBall::MapFile::IDType::default_ball:
					Entity::Ball ball;
					ball.parse( )

					break;
				case BounceBall::MapFile::IDType::default_block_dirt:
					break;
				case BounceBall::MapFile::IDType::default_block_potal:
					break;
				case BounceBall::MapFile::IDType::resources_object:
					break;
				case BounceBall::MapFile::IDType::resources_entity:
					break;
				default:
					break;
				}
			}
		}
	}
}