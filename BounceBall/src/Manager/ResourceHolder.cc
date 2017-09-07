#include "Manager\ResourceHolder.hh"


namespace BounceBall
{
	namespace Manager
	{
		ResourceHolder::ResourceHolder( )
			: fonts_( "fonts", "ttf" )
			, textures_( "textures", "png" )
			, sounds_( "sfx", "ogg" )
		{}


		ResourceHolder& ResourceHolder::get( )
		{
			static ResourceHolder holder;
			return holder;
		}
	}
}