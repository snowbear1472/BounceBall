#pragma once


#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

#include <memory>

#include "ResourceManager.hh"


namespace BounceBall
{
	namespace Manager
	{
		class ResourceHolder
		{
		public:
			static ResourceHolder& get( );

		public:
			ResourceManager<sf::Font> fonts_;
			ResourceManager<sf::Texture> textures_;
			ResourceManager<sf::SoundBuffer> sounds_;

		private:
			ResourceHolder( );
		};
	}
}