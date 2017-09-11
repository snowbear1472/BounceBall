#include <memory>

#include "Manager/GameFileManager.hh"
#include "Entities/Ball.hh"
#include "Blocks/Block.hh"


namespace BounceBall
{
	namespace Manager
	{
		GameFileManager& GameFileManager::get( )
		{
			static GameFileManager instance;
			return instance;
		}


		GameFileManager::GameFileManager( )
			: dir_entity_( "res/entity" )
			, dir_object_( "res/object" )
			, extension_( "csv" )
		{}


		csv_map GameFileManager::get( const std::string& name, const Type& type )
		{
			string_lines file;
			std::size_t index = 0;

			if ( type == Type::entity )
				file = read_file( "res/entity" + name );
			else if ( type == Type::object )
				file = read_file( "res/object" + name );

			return parse_csv( &file, index );
		}
		EntityBase* GameFileManager::get_entity( const std::string& name )
		{
			EntityBase* base;

			csv_map csv = get( name, Type::entity );
			auto& val = *csv_find( &csv, "entity_name" );

			if ( val == "game:entity:default_ball" )
			{
				std::shared_ptr<Entity::Ball> ball( new Entity::Ball );
				ball->parse( &csv );

				base = dynamic_cast<Entity::Ball*>( ball.get( ) );
				return base;
			}


			return nullptr;
		}
		Object* GameFileManager::get_object( const std::string& name )
		{
			Object* base;

			csv_map csv = get( name, Type::object );
			auto& val = *csv_find( &csv, "object_name" );

			if ( val == "game:entity:default_dirt" )
			{
				std::shared_ptr<Blocks::Block> block( new Blocks::Block );
				block->parse( &csv );

				base = dynamic_cast<Blocks::Block*>( block.get( ) );
				return base;
			}


			return nullptr;
		}


		path GameFileManager::get_fullpath( const std::string& name, const Type& type )
		{
			std::string buffer = name + "." + extension_;

			switch ( type )
			{
			case BounceBall::Manager::GameFileManager::Type::entity:
				return dir_entity_ + buffer;

			case BounceBall::Manager::GameFileManager::Type::object:
				return dir_object_ + buffer;

			default:
				return "";
			}
		}
	}
}