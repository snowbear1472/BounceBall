#include "Map/MapFile.hh"

#include "Entities/Ball.hh"
#include "Blocks/Block.hh"
#include "Manager/GameFileManager.hh"

namespace BounceBall
{
	MapFile::~MapFile( )
	{
		for ( auto& e : entities_ )
			delete e.second;

		for ( auto& o : objects_ )
			delete o.second;
	}


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
		const std::string* pbuffer;

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
			// data_type, game:map
			pbuffer = csv_find( &buffer, "data_type" );
			if ( *( ++pbuffer ) != "game:map" )
				throw std::runtime_error( error_messages_[ErrorType::WRONG_FILE] );

			// version, 1.0.0.0
			pbuffer = csv_find( &buffer, "version" );
			version_.parse( *( ++pbuffer ) );

			// map_version, 1.0.0.0
			pbuffer = csv_find( &buffer, "map_version" );
			map_version_.parse( *( ++pbuffer ) );

			// name
			pbuffer = csv_find( &buffer, "name" );
			name_ = *( ++pbuffer );

			// developer
			pbuffer = csv_find( &buffer, "developer" );
			developer_ = *( ++pbuffer );

			// details
			pbuffer = csv_find( &buffer, "details" );
			details_ = *( ++pbuffer );
		}
		catch ( std::runtime_error )
		{
			throw std::runtime_error( error_messages_[ErrorType::META_DATA_NOT_FOUND] );
		}


		if ( map_version_ == Version( 1, 0, 0, 0 ) )
			parse_ver_1_0( &buffer );
	}


	void MapFile::parse_ver_1_0( const csv_map* csv )
	{
		sf::Vector2f vbuffer;
		void* pbuffer = nullptr;


		for ( auto& i : *csv )
		{
			for ( int j = 0; j < i.size( ); j++ )
			{
				auto& val = i[j];


				if ( val == "map_size" )
					map_size_ = parse_vector2f( i[++j] );


				if ( *val.begin( ) == '(' && *val.end( ) == ')' )
				{
					vbuffer = parse_vector2f( i[j++] );

					auto& token = id_tokens_[i[++j]];
					switch ( token )
					{
					case BounceBall::MapFile::IDType::object:
						// ignore
						break;

					case BounceBall::MapFile::IDType::entity:
						// ignore
						break;

					case BounceBall::MapFile::IDType::default_ball:
						//entities_[vbuffer] = static_cast<Entity::Ball*>( Manager::GameFileManager::get( ).get_entity( "default_ball" ) );
						break;

					case BounceBall::MapFile::IDType::default_block_dirt:
						//objects_[vbuffer] = *( dynamic_cast<Blocks::Block*>( Manager::GameFileManager::get( ).get_object( "default_dirt" ).get( ) ) );
						break;

					case BounceBall::MapFile::IDType::default_block_potal:
						break;

					case BounceBall::MapFile::IDType::resources_object:
						//objects_[vbuffer] = static_cast<Object*>( Manager::GameFileManager::get( ).get_object( i[++j] ) );
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
}