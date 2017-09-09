#pragma once

#include <vector>
#include <string>
#include <map>

#include "Util/Utility.hh"


namespace BounceBall
{
	namespace Map
	{
		using string_lines = std::vector<std::string>;

		class MapFile final
		{
		public:
			enum class ErrorType
			{
				META_DATA_NOT_FOUND,
				META_DATA_WRONG,

				WRONG_ID,
			};

			#define msg std::make_pair(type, str)
			std::map<ErrorType, std::string> error_messages_
			{
				msg( ErrorType::META_DATA_NOT_FOUND, "can't find meta data from a map file!" ),
				msg( ErrorType::META_DATA_WRONG, "wrong meta data!" ),

				msg( ErrorType::WRONG_ID, "can't find game_id from client or resources!" ),
			};
			#undef msg

		public:
			enum class IDType
			{
				object,
				entity,

				default_ball,
				default_
			};

		public:
			MapFile( ) = default;

		public:
			void parse_from_file( const std::string& path );
			void parse_from_string( string_lines lines );

		private:
			std::string& replace_tokens( std::string& line );

		public:
			string_lines file_;

		public:
			Version version_;
			std::string name_;
			std::string developer_;
			std::string details_;

		public:
			sf::Vector2f map_size_;
		};
	}
}