// Test2.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//


#include "stdafx.h"
#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

class GameWindow : public Gosu :: Window {

public:
	Gosu::Image kblau, rahmen, kgelb, kgrau, kgrün, klila, kpink, krot, ktürkis;

	GameWindow()
		: Window(710, 960)
		, kgelb("Kugel_Gelb.png")
		, kgrau("Kugel_Grau.png")
		, kgrün("Kugel_Gruen.png")
		, klila("Kugel_Lila.png")
		, kpink("Kugel_Pink.png")
		, krot("Kugel_Rot.png")
		, ktürkis("Kugel_Tuerkies.png")
		, kblau ("Kugel_Blau.png")
		, rahmen ("Rahmen.png")
	{
		set_caption("Gosu Tutorial Game");
	}
	int x = 3;
	int y = 275;
	int z = 0;
	double rot = 0.0;

	void update() override
	{
		z = input().mouse_x();
		y = input().mouse_y();
		x = (x + 1) % 300;
		
		x = input().mouse_x();
		y = input().mouse_y();
		if (input().down(Gosu::MS_LEFT))
		{
			rot += 10;
		}
		else if (input().down(Gosu::MS_RIGHT))
		{
			rot -= 10;
		}
	}

	void draw() override
	{
		rahmen.draw_rot(20, 20, 0.0, 0.0, 0.0, 0.0);
		rahmen.draw_rot(50, 50, 0.0, 0.0, 0.0, 0.0);
		kblau.draw_rot
		(x, y, 0.0,
			rot, // Rotationswinkel in Grad
			0.0, 0.0 // Position der "Mitte"
		);
	}
};

int main()
{
	GameWindow window;
	window.show();
	printf("Hallo Welt");
}

