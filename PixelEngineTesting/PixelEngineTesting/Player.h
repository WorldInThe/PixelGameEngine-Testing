#include "Helper.h"
#include "olcPixelGameEngine.h"

using namespace olc;
using namespace newTypes;
namespace backend
{
	class rect
	{
	public:
		rect(int _x, int _y, int _width, int _height)
		{
			center.x = _x;
			center.y = _y;
			width = _width;
			height = _height;
		}
		rect(newTypes::vec2 _center, int _width, int _height)
		{
			center.x = _center.x;
			center.y = _center.y;
			width = _width;
			height = _height;
		}
		newTypes::vec2 center;
		int width, height;
		int propVal;


		//int top(){ return int(center.y - float(size / 2)); }
	};

	class player
	{
	public:

		/*player(newTypes::vec2 _center = newTypes::vec2(), float _speed = .0f, int _health = 0, int _size = 0, uint16_t _prop = 0) {
			center.x = _center.x + _size / 2;
			center.y = _center.y + _size / 2;
			speed = _speed;
			health = _health;
			size = _size;
			property = _prop;
		}*/
		player(newTypes::vec2 _center = newTypes::vec2(), float _speed = .0f, int _health = 0, int _size = 0, uint16_t _prop = 0, float _mass = 1, float _gravity = 1) {
			center.x = _center.x + _size / 2;
			center.y = _center.y + _size / 2;
			speed = _speed;
			health = _health;
			size = _size;
			property = _prop;
			mass = _mass;
			gravity = _gravity;
		}
		newTypes::vec2		center;
		float		speed;
		uint16_t	property;
		int			health;
		int			size;
		float		mass;
		float		gravity = .2f;


		void gravityCalc()
		{
			if(bottom() <= 200)
				center.y += gravity ;
		}
		
		/*bool collision(rect _item)
		{
			_item;
		}*/

		void MoveLeft() { center.x -= speed; }
		void MoveRight(){ center.x += speed; }
		void Jump(float _Time, float _Strength)		
		{
			if (_Time < 200)
			{
				center.y -= _Strength + gravity;
				
			}
		}

		int left()		{ return int(center.x - float(size / 2)); }
		int right()		{ return int(center.x + float(size / 2)); }
		int top()		{ return int(center.y - float(size / 2)); }
		int bottom()	{ return int(center.y + float(size / 2)); }

	};
}

