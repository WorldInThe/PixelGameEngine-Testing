//#include "olcPixelGameEngine.h"
//#include "Player.h"
#include "images.h"
#include <math.h>
#include <time.h>

using namespace backend;
using namespace images;


std::vector<std::vector<uint8_t>> coin_image = {
	{ 0,0,8,8,8,8,0,0 },
	{ 0,8,7,7,7,7,8,0 },
	{ 0,8,7,7,7,7,8,0 },
	{ 0,8,7,7,7,7,8,0 },
	{ 0,8,7,7,7,7,8,0 },
	{ 0,8,7,7,7,7,8,0 },
	{ 0,8,7,7,7,7,8,0 },
	{ 0,0,8,8,8,8,0,0 }
};

player p = player(newTypes::vec2(20, 180),
	.1f,
	100,
	16,
	0,
	1,
	.2f);

image sample = image(newTypes::vec2(120, 120), 16
	, std::vector<std::vector<uint8_t>>{
	{ 0,0,0,0,2,2,2,2,2,2,0,0,0,0,0,0 },
	{ 0,0,0,2,2,2,2,2,2,2,2,2,2,0,0,0 },
	{ 0,0,0,6,6,6,6,5,5,6,5,0,0,0,0,0 },
	{ 0,0,6,6,5,6,5,5,5,6,5,5,5,0,0,0 },
	{ 0,0,6,6,5,6,6,5,5,5,6,5,5,5,0,0 },
	{ 0,0,6,6,6,5,5,5,5,6,6,6,6,0,0,0 },
	{ 0,0,0,0,5,5,5,5,5,5,5,5,0,0,0,0 },
	{ 0,0,0,6,6,6,2,6,6,6,0,0,0,0,0,0 },
	{ 0,0,6,6,6,6,2,6,6,2,6,6,6,0,0,0 },
	{ 0,6,6,6,6,6,2,6,6,2,6,6,6,6,0,0 },
	{ 0,5,5,5,6,2,5,2,2,5,2,6,5,5,0,0 },
	{ 0,5,5,5,5,2,2,2,2,2,2,5,5,5,0,0 },
	{ 0,5,5,5,2,2,2,2,2,2,2,2,5,5,0,0 },
	{ 0,0,0,2,2,2,2,0,2,2,2,2,0,0,0,0 },
	{ 0,0,6,6,6,6,0,0,0,6,6,6,6,0,0,0 },
	{ 0,6,6,6,6,6,0,0,0,6,6,6,6,6,0,0 }
});

image coin = image(newTypes::vec2(100, 100), 8, coin_image);

olc::Pixel color_pallet[14] = {
	olc::BLACK,
	olc::WHITE,
	olc::RED,
	olc::BLUE,
	olc::GREEN,
	olc::Pixel(210, 180, 140),
	olc::Pixel(150, 75,	 0	),
	olc::Pixel(255, 201, 14	),
	olc::Pixel(255, 242, 0	)
};


class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "Game Testing";
	}

private:
	int time;

public:
	bool OnUserCreate() override
	{
		return true;
	}
	
	void physicsUpdate(float fElapsedTime) {
		
		p.gravityCalc();

	}

	olc::Pixel ColorRet(uint8_t val)
	{
			//Indexes the color from the palette array made earlier. Quicker and simpler than using a case statement.
		olc::Pixel color = color_pallet[val];
		return color;
	}

	void input()
	{
			// Move left if A or left is held down and when the player is on the screen
		if (GetKey(olc::LEFT).bHeld | GetKey(olc::A).bHeld && p.left() >= 0)				
		{ 
			p.MoveLeft();
			//sample.Pos.x -= .1;
		}
			
			// Move Right if D or rigth is held down and when the player is on the screen
		if (GetKey(olc::RIGHT).bHeld | GetKey(olc::D).bHeld && p.right() <= ScreenWidth())	
		{ 
			p.MoveRight(); 
			//sample.Pos.x += .1;
		}
		
			// Move Up if W or up is held down and when the player is on the screen
		if (GetKey(olc::SPACE).bHeld) { 
			p.Jump(time, .2f); 
			time++; 
		}
		else if (GetKey(olc::SPACE).bReleased) { time = 500; }
		else if (p.bottom() >= ScreenHeight()) { time = 0;	 }

	}
	
	void drawNewSprite(image img)
	{
		for (int x = img.Pos.x; x < img.Pos.x + img.size; x++)
			for (int y = img.Pos.y; y < img.Pos.y + img.size; y++)
			{
				Draw(x, y, ColorRet(img.data[y - img.Pos.y][x - img.Pos.x]));
			}
	}
	void draw()
	{
		Clear(olc::Pixel(0, 0, 0));

		sample.Pos = p.center;
		sample.Pos.x -= 8;
		sample.Pos.y -= 10;

		drawNewSprite(sample);
		drawNewSprite(coin);

		/*for (int x = sample.Pos.x; x < sample.Pos.x + sample.size; x++)
			for (int y = sample.Pos.y; y < sample.Pos.y + sample.size; y++)
			{
				Draw(x, y, ColorRet(sample.data[y- sample.Pos.y][x - sample.Pos.x]));
			}
		for (int x = coin.Pos.x; x < coin.Pos.x + coin.size; x++)
			for (int y = coin.Pos.y; y < coin.Pos.y + coin.size; y++)
			{
				Draw(x, y, ColorRet(coin.data[y - coin.Pos.y][x - coin.Pos.x]));
			}*/

	}
	
	bool OnUserUpdate(float fElapsedTime) override
	{
		physicsUpdate(fElapsedTime);

		input();
		draw();

		return (GetKey(olc::ESCAPE).bPressed ? false : true);
	}

};



int main()
{
	Example demo;
	
	if (demo.Construct(200, 200, 4, 4))
		demo.Start();
	return 0;
}

