#include "Map/MapFile.hh"

#include "Entities/Ball.hh"

namespace BounceBall
{
	namespace Map
	{
		std::string&  MapFile::replace_tokens( std::string& line )
		{

		}


		void MapFile::parse_from_file( const std::string& path )
		{

		}
		void  MapFile::parse_from_string( string_lines lines )
		{
			/*
				* meta data만 parse합니다.
				* 실제 map data는 meta data parse 한 후 이곳에서 맵파일 버전별로 처리됩니다.
			*/


			std::string buffer = "";
			bool loop = true;
			std::size_t index;


			for ( int i = 0; i < lines.size; i++ )
			{
				for ( int j = 0; j < lines.at( i ).length; j++ )
				{
					auto& line = lines.at( i );
					auto& c = line[j];


					if ( std::isalpha( c ) )
					{
						buffer = read_buffer( line, j );

						if ( buffer == "version" )
							version_.parse( read_buffer( line, j ) );

						else if ( buffer == "name" )
							name_ = read_buffer( line, j );

						else if ( buffer == "developer" )
							developer_ = read_buffer( line, j );

						else if ( buffer == "details" )
							details_ = read_buffer( line, j );

						else if ( buffer == "map_version" )
							map_version_.parse( read_buffer( line, j ) );

						else if ( buffer == "map_size" )
							map_size_ = parse_vector2f( read_buffer( line, j ) );
					}


					buffer = "";
				}

				if ( !loop )
				{
					index = i + 1;
					break;
				}
			}


			if ( map_version_ == Version( 1, 0, 0, 0 ) )
				parse_ver_1_0( lines, index );
		}


		void MapFile::parse_ver_1_0( const string_lines& lines, const std::size_t& index )
		{
			for ( int i = index; i < lines.size( ); i++ )
			{
				for ( int j = 0; j < lines[i].length( ); j++ )
				{
					auto& line = lines[i];
					auto& c = line[j];


					if ( c == '(' )
					{
						sf::Vector2f pos = parse_vector2f( read_buffer_paren( line, i ) );
						IDType id = id_tokens_[read_buffer( line, i )];

						if ( id == IDType::default_ball )
						{
							Entity::Ball ball;
							ball.parse( read_file( "res/entities/default_ball.csv" ) );

							entities_[pos] = ball;
						}
						else if ( id == IDType::default_block_dirt )
						{

						}

					}
				}
			}
		}
	}
}