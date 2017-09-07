#pragma once


constexpr float PI = 3.14159265;


namespace BounceBall
{
	template <typename T_>
	T_ to_radians( T_ degrees )
	{
		return degrees * PI / 180;
	}

	template <typename T_>
	T_ to_degress( T_ radians )
	{
		return ( radians * 180 ) / PI;
	}
}