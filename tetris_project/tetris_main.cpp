#include <iostream>
#include <Window.hpp>
#include <Graphics.hpp>
#include <Graphics/RenderWindow.hpp>

int main()
{
	const int CELL_SIZE = 40; // size of each cell on the game board
	const int BOARD_WIDTH = 20; // width of the game board in cells
	const int BOARD_HEIGHT = 15; // height of the game board in cells
	const int BLOCK_COUNT = 7; // number of block shapes

	int main_menu_poisition = 0;
	int select_ui_position = 0;
	int how_to_play_position = 0;
	int background_position = 0;

	struct position { int x; int y; };

	// T SHAPE
	position blue_block[4];
	blue_block[0].x = 160;
	blue_block[0].y = 0;
	blue_block[1].x = blue_block[0].x;
	blue_block[1].y = blue_block[0].y - 40;
	blue_block[2].x = blue_block[0].x - 40;
	blue_block[2].y = blue_block[0].y - 40;
	blue_block[3].x = blue_block[0].x + 40;
	blue_block[3].y = blue_block[0].y - 40;

	// L SHAPE
	position red_block[4];
	red_block[0].x = 160;
	red_block[0].y = 0;
	red_block[1].x = red_block[0].x + 40;
	red_block[1].y = red_block[0].y;
	red_block[2].x = red_block[0].x;
	red_block[2].y = red_block[0].y - 40;
	red_block[3].x = red_block[0].x;
	red_block[3].y = red_block[0].y - 80;

	//Z SHAPE
	position dark_blue_block[4];
	dark_blue_block[0].x = 160;
	dark_blue_block[0].y = 0;
	dark_blue_block[1].x = dark_blue_block[0].x + 40;
	dark_blue_block[1].y = dark_blue_block[0].y;
	dark_blue_block[2].x = dark_blue_block[0].x;
	dark_blue_block[2].y = dark_blue_block[0].y - 40;
	dark_blue_block[3].x = dark_blue_block[0].x - 40;
	dark_blue_block[3].y = dark_blue_block[0].y - 40;

	//REVERSE L SHAPE
	position orange_block[4];
	orange_block[0].x = 160;
	orange_block[0].y = 0;
	orange_block[1].x = orange_block[0].x - 40;
	orange_block[1].y = orange_block[0].y;
	orange_block[2].x = orange_block[0].x;
	orange_block[2].y = orange_block[0].y - 40;
	orange_block[3].x = orange_block[0].x;
	orange_block[3].y = orange_block[0].y - 80;

	//REVERSE Z SHAPE
	position yellow_block[4];
	yellow_block[0].x = 160;
	yellow_block[0].y = 0;
	yellow_block[1].x = yellow_block[0].x - 40;
	yellow_block[1].y = yellow_block[0].y;
	yellow_block[2].x = yellow_block[0].x;
	yellow_block[2].y = yellow_block[0].y - 40;
	yellow_block[3].x = yellow_block[0].x + 40;
	yellow_block[3].y = yellow_block[0].y - 40;

	//SQUARE SHAPE
	position purple_block[4];
	purple_block[0].x = 160;
	purple_block[0].y = 0;
	purple_block[1].x = purple_block[0].x + 40;
	purple_block[1].y = purple_block[0].y;
	purple_block[2].x = purple_block[0].x + 40;
	purple_block[2].y = purple_block[0].y - 40;
	purple_block[3].x = purple_block[0].x;
	purple_block[3].y = purple_block[0].y - 40;

	//LINE SHAPE
	position green_block[4];
	green_block[0].x = 160;
	green_block[0].y = 0;
	green_block[1].x = green_block[0].x;
	green_block[1].y = green_block[0].y - 40;
	green_block[2].x = green_block[0].x;
	green_block[2].y = green_block[0].y - 80;
	green_block[3].x = green_block[0].x;
	green_block[3].y = green_block[0].y - 120;

	bool moved_left = false;
	bool moved_right = false;
	bool block_picking = false;

	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * BOARD_WIDTH, CELL_SIZE * BOARD_HEIGHT), "Tetris");
	window.setFramerateLimit(60);

	sf::Texture texture_main_menu;
	sf::Texture texture_select_ui;
	sf::Texture texture_how_to_play;
	sf::Texture texture_background;
	sf::Texture texture_blue_block;
	sf::Texture texture_dark_blue_block;
	sf::Texture texture_orange_block;
	sf::Texture texture_yellow_block;
	sf::Texture texture_green_block;
	sf::Texture texture_purple_block;
	sf::Texture texture_red_block;

	texture_main_menu.loadFromFile("c:\\tetris_sprites\\main_menu.png");
	texture_select_ui.loadFromFile("c:\\tetris_sprites\\select_ui.png");
	texture_how_to_play.loadFromFile("c:\\tetris_sprites\\how_to_play.png");
	texture_background.loadFromFile("c:\\tetris_sprites\\background.png");
	texture_blue_block.loadFromFile("c:\\tetris_sprites\\tetris_blue.png");
	texture_dark_blue_block.loadFromFile("c:\\tetris_sprites\\tetris_dark_blue.png");
	texture_orange_block.loadFromFile("c:\\tetris_sprites\\tetris_orange.png");
	texture_yellow_block.loadFromFile("c:\\tetris_sprites\\tetris_yellow.png");
	texture_green_block.loadFromFile("c:\\tetris_sprites\\tetris_green.png");
	texture_purple_block.loadFromFile("c:\\tetris_sprites\\tetris_purple.png");
	texture_red_block.loadFromFile("c:\\tetris_sprites\\tetris_red.png");

	sf::Sprite sprite_main_menu;
	sf::Sprite sprite_select_ui;
	sf::Sprite sprite_how_to_play;
	sf::Sprite sprite_background;

	sf::Sprite sprite_blue_block[4];
	sf::Sprite sprite_dark_blue_block[4];
	sf::Sprite sprite_orange_block[4];
	sf::Sprite sprite_yellow_block[4];
	sf::Sprite sprite_green_block[4];
	sf::Sprite sprite_purple_block[4];
	sf::Sprite sprite_red_block[4];

	sprite_main_menu.setTexture(texture_main_menu);
	sprite_main_menu.setPosition(main_menu_poisition, main_menu_poisition);
	sprite_select_ui.setTexture(texture_select_ui);
	sprite_select_ui.setPosition(0, 0);
	sprite_how_to_play.setTexture(texture_how_to_play);
	sprite_how_to_play.setPosition(0, 0);
	sprite_background.setTexture(texture_background);
	sprite_background.setPosition(0, 0);

	for (int i = 0; i < 4; i++)
	{
		sprite_blue_block[i].setTexture(texture_blue_block);
		sprite_dark_blue_block[i].setTexture(texture_dark_blue_block);
		sprite_orange_block[i].setTexture(texture_orange_block);
		sprite_yellow_block[i].setTexture(texture_yellow_block);
		sprite_green_block[i].setTexture(texture_green_block);
		sprite_purple_block[i].setTexture(texture_purple_block);
		sprite_red_block[i].setTexture(texture_red_block);
	}

	for (int i = 0; i < 4; i++)
	{
		sprite_blue_block[i].setPosition(blue_block[i].x, blue_block[i].y);
		sprite_dark_blue_block[i].setPosition(dark_blue_block[i].x, dark_blue_block[i].y);
		sprite_orange_block[i].setPosition(orange_block[i].x, orange_block[i].y);
		sprite_yellow_block[i].setPosition(yellow_block[i].x, yellow_block[i].y);
		sprite_green_block[i].setPosition(green_block[i].x, green_block[i].y);
		sprite_purple_block[i].setPosition(purple_block[i].x, purple_block[i].y);
		sprite_red_block[i].setPosition(red_block[i].x, red_block[i].y);
	}

	//playing board array
	const int playing_board[10][12] = { 0 };

	//array of shapes
	const int L_BLOCK_CELLS[4][2] = { {0, 0}, {0, -1}, {0, 1}, {1, 1} };
	const int REVERSE_L_BLOCK_CELLS[4][2] = { {0, 0}, {0, -1}, {0, 1}, {1, -1} };
	const int Z_BLOCK_CELLS[4][2] = { {0, 0}, {0, -1}, {1, 0}, {1, 1} };
	const int REVERSE_Z_BLOCK_CELLS[4][2] = { {0, 0}, {0, 1}, {1, 0}, {1, -1} };
	const int SQUARE_BLOCK_CELLS[4][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
	const int T_BLOCK_CELLS[4][2] = { {0, 0}, {0, -1}, {0, 1}, {1, 0} };
	const int STRAIGHT_BLOCK_CELLS[4][2] = { {0, 0}, {1, 0}, {-1, 0}, {-2, 0} };

	window.setActive();

	sf::Clock game_time = sf::Clock();
	sf::Time miliseconds = sf::milliseconds(3 * 10 * 10);

	while (window.isOpen())

	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			{

				if (event.type == event.KeyPressed)
					switch (event.key.code)
					{
					case sf::Keyboard::Left:
						for (int i = 0; i < 4; ++i)
						{
							red_block[0].x -= 40;
							blue_block[0].x -= 40;
							dark_blue_block[0].x -= 40;
							green_block[0].x -= 40;
							yellow_block[0].x -= 40;
							purple_block[0].x -= 40;
							orange_block[0].x -= 40;
						}
						break;
					case sf::Keyboard::Right:
						for (int i = 0; i < 4; ++i)
						{
							red_block[0].x += 40;
							blue_block[0].x += 40;
							dark_blue_block[0].x += 40;
							green_block[0].x += 40;
							yellow_block[0].x += 40;
							purple_block[0].x += 40;
							orange_block[0].x += 40;
						}
						break;
					case sf::Keyboard::Up:
						//rotate

						break;
					case sf::Keyboard::Down:
						//speed up falling process

						break;
					}
		    }
			window.draw(sprite_background);
			window.draw(sprite_blue_block[0]);
			window.display();
		}
	}
}