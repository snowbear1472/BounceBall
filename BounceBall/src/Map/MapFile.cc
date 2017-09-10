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
			* �̰����� csv_map�� �ʱ�ȭ �� lines�� lexing�մϴ�.
			* �̰������� lex�� csv_map���� meta_data�� �н��ϴ�.
			* �̰����� meta_data�� ���� �� �б� ������ �߷��մϴ�.
			* meta_data ������ ������ �ʽ��ϴ�.
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