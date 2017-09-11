#include "Blocks/Block.hh"


namespace BounceBall
{
	namespace Blocks
	{
		void Block::update( )
		{
			//nothing to do.
		}

		void Block::init( )
		{
			shape_.setTexture( &texture_ );
		}

		void Block::parse( const string_lines* lines )
		{
			std::size_t index = 0;
			csv_map csv = parse_csv( lines, index );

			parse( &csv );
		}
		void Block::parse( const csv_map* csv )
		{
			for ( auto& i : *csv )
			{
				for ( int j = 0; j < i.size( ); j++ )
				{
					auto& val = i[j];

					if ( val == "file_type" )
					{
						if ( i[++j] != "bounceball_script" )
							throw std::runtime_error( "script type is not bounceball_script!" );
					}
					else if ( val == "data_type" )
					{
						if ( i[++j] != "game:object:block" )
							throw std::runtime_error( "data type is not game:object:block!" );
					}
					else if ( val == "object_name" )
						object_name_ = i[++j];
					else if ( val == "size" )
						shape_.setSize( parse_vector2f( i[++j] ) );
					else if ( val == "texture" )
					{
						texture_ = Manager::ResourceHolder::get( ).textures.get( i[++j] );
						shape_.setTexture( &texture_ );

						if ( is_vector2f_str( i[j + 1] ) && is_vector2f_str( i[j + 2] ) )
						{
							auto& pos_ = to_vector2i( parse_vector2f( i[++j] ) );
							auto& size_ = to_vector2i( parse_vector2f( i[++j] ) );

							shape_.setTextureRect( { pos_, size_ } );
						}
					}
				}
			}
		}
	}
}