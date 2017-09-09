#pragma once


#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include <memory>

#include "ResourceManager.hh"
#include "NonCopyable.hh"
#include "NonMovable.hh"


namespace BounceBall
{
	namespace Manager
	{
		class ResourceHolder : public NonCopyable, public NonMovable
		{
		public:
			static ResourceHolder& get( );

			ResourceManager<sf::Font>           fonts;
			ResourceManager<sf::Texture>        textures;
			ResourceManager<sf::SoundBuffer>    soundBuffers;

		private:
			ResourceHolder( );
		};
	}
}