#include <memory>

#include "Manager/GameFileManager.hh"


namespace BounceBall
{
	namespace Manager
	{
		GameFileManager& GameFileManager::get( )
		{
			static GameFileManager instance;
			return instance;
		}


		GameFile& GameFileManager::get( path& file )
		{
			for ( auto& i : res )
			{
				if ( i.path == file )
				{
					return i;
				}
			}

			add( file );

			for ( auto& i : res )
			{
				if ( i.path == file )
				{
					return i;
				}
			}

			return GameFile { "", GameFile::Type::None, csv_map( ) };
		}
		void GameFileManager::add( path& file )
		{
			auto& csv = parse_csv( &read_file( file ) );

			if ( csv.find( "file_type" ) == csv.end( ) )
			{
				throw std::runtime_error( "unkwon!: unkwon script." );
			}
			else
			{
				if ( csv.at( "file_type" ).at( 0 ) != "bounceball_script" )
				{
					throw std::runtime_error( "unkwon!: unkwon script." );
				}
			}
			if ( csv.find( "data_type" ) == csv.end( ) )
			{
				throw std::runtime_error( "unkwon!: unkwon script." );
			}
			else
			{
				auto type = csv.at( "data_type" ).at( 0 );

				GameFile data { file, GameFile::Type::Object, csv };

				if ( type == "bounceball:object" )
				{
					data.type = GameFile::Type::Object;
				}
				else if ( type == "bounceball:entity" )
				{
					data.type = GameFile::Type::Entity;
				}
				else if ( type == "bounceball:map" )
				{
					data.type = GameFile::Type::Map;
				}

				res.push_back( data );
			}
		}
	}
}