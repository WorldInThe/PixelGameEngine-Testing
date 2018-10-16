#include "Player.h"

namespace images
{
	class image
	{
	public:
		image(newTypes::vec2 _Pos, uint8_t _size, std::vector<std::vector<uint8_t>> _data)
		{
			Pos = _Pos;
			size = _size;
			data = _data;
		}
		newTypes::vec2 Pos;
		uint8_t size;
		std::vector<std::vector<uint8_t>> data;
	};
	/*class image_16
	{
	public:
		image_16(newTypes::vec2 _Pos, std::vector<std::vector<uint8_t>> _data)
		{
			Pos = _Pos;
			data = _data;
		}
		newTypes::vec2 Pos;

		std::vector<std::vector<uint8_t>> data =
		{
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
			{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

		};
	};*/
}