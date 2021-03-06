#pragma once

#include "Util/Utility.hh"


namespace BounceBall
{
	class ParseBase
	{
	public:
		struct MetaData
		{
			std::string data_type_;
			Version parse_version_;
			std::string name_;
			std::string developer_;
			std::string details_;
		};

	public:
		enum class TokenTypeBase
		{
			file_type,
			data_type,
			parse_version,
			name,
			developer,
			details
		};

		#define map( type ) std::make_pair( #type, type )
		std::map<std::string, TokenTypeBase> base_tokens_map
		{
			map( TokenTypeBase::file_type ),
			map( TokenTypeBase::data_type ),
			map( TokenTypeBase::parse_version ),
			map( TokenTypeBase::name ),
			map( TokenTypeBase::developer ),
			map( TokenTypeBase::details ),
		};
		#undef map

	public:
		enum class EnvironValueTypeBase
		{
			TYPE__FILE
		};

		#define map( type, str ) std::make_pair( type, str )
		std::map<EnvironValueTypeBase, std::string> base_environ_values_map
		{
			map( EnvironValueTypeBase::TYPE__FILE, "bounceball_script" )
		};
		#undef msg

	public:
		enum class ErrorTypeBase
		{
			NOT_FOUND__FILE,
			UNKWON__FILE,

			NOT_FOUND__META_DATA,
			UNKWON__META_DATA,
		};

		#define msg( type, str ) std::make_pair( type, str )
		std::map<ErrorTypeBase, std::string> base_error_messages_map
		{
			msg( ErrorTypeBase::NOT_FOUND__FILE, "not_found!: file not found." ),
			msg( ErrorTypeBase::UNKWON__FILE, "unkwon!: unkwon file." ),

			msg( ErrorTypeBase::NOT_FOUND__META_DATA, "not_found!: meta_data not found." ),
			msg( ErrorTypeBase::UNKWON__META_DATA, "unkwon!: unkwon meta_data." ),
		};
		#undef msg

	public:
		ParseBase( ) = default;

	public:
		virtual const Version recommend_parse_version( ) const = 0;
		virtual std::string& replace_token( std::string& line ) = 0;

	public:
		virtual void parse( path& file );
		virtual void parse( const string_lines* lines );
		virtual void parse( const csv_map* csv );

	public:
		MetaData meta_data_;

	protected:
		csv_map data_;
	};
}