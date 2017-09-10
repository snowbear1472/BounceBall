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
		csv_map buffer = parse_csv( lines, index );


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
			throw std::runtime_error( error_messages_[ErrorType::META_DATA_WRONG] );
		}



		if ( map_version_ == Version( 1, 0, 0, 0 ) )
			parse_ver_1_0( buffer );
	}


	void MapFile::parse_ver_1_0( const csv_map& map )
	{
		for ( auto& i : map )
		{

		}
	}
}