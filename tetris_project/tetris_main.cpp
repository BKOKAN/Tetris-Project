#include <iostream>
#include <Window.hpp>
#include <Graphics.hpp>
#include <Graphics/RenderWindow.hpp>

int main()
{
	const int CELL_SIZE = 40; // size of each cell on the game board
	const int BOARD_WIDTH = 15; // width of the game board in cells
	const int BOARD_HEIGHT = 12; // height of the game board in cells
	const int BLOCK_COUNT = 7; // number of block shapes

	int main_menu_poisition = 0;
	int select_ui_position = 0;
	int how_to_play_position = 0;
	int background_position = 0;
	int blue_block1_x_position = 0;
	int blue_block1_y_position = 0;
	int blue_block2_x_position = 0;
	int blue_block3_x_position = 0;
	int blue_block3_y_position = 0;
	int blue_block4_x_position = 0;
	int blue_block4_y_position = 0;
	int dark_blue_block1_x_position = 0;
	int dark_blue_block1_y_position = 0;
	int dark_blue_block2_x_position = 0;
	int dark_blue_block2_y_position = 0;
	int dark_blue_block3_x_position = 0;
	int dark_blue_block3_y_position = 0;
	int dark_blue_block4_x_position = 0;
	int dark_blue_block4_y_position = 0;
	int orange_block1_x_position = 0;
	int orange_block1_y_position = 0;
	int orange_block2_x_position = 0;
	int orange_block2_y_position = 0;
	int orange_block3_x_position = 0;
	int orange_block3_y_position = 0;
	int orange_block4_x_position = 0;
	int orange_block4_y_position = 0;
	int yellow_block1_x_position = 0;
	int yellow_block1_y_position = 0;
	int yellow_block2_x_position = 0;
	int yellow_block2_y_position = 0;
	int yellow_block3_x_position = 0;
	int yellow_block3_y_position = 0;
	int yellow_block4_x_position = 0;
	int yellow_block4_y_position = 0;
	int green_block1_x_position = 0;
	int green_block1_y_position = 0;
	int green_block2_x_position = 0;
	int green_block2_y_position = 0;
	int green_block3_y_position = 0;
	int green_block4_x_position = 0;
	int green_block4_x_position = 0;
	int purple_block1_x_position = 0;
	int purple_block1_y_position = 0;
	int purple_block2_x_position = 0;
	int purple_block2_y_position = 0;
	int purple_block3_x_position = 0;
	int purple_block3_y_position = 0;
	int purple_block4_x_position = 0;
	int purple_block4_y_position = 0;
	int red_block1_x_position = 0;
	int red_block1_y_position = 0;
	int red_block2_x_position = 0;
	int red_block2_x_position = 0;
	int red_block3_x_position = 0;
	int red_block3_y_position = 0;
	int red_block4_x_position = 0;
	int red_block4_y_position = 0;

	sf::RenderWindow window(sf::VideoMode(CELL_SIZE * BOARD_WIDTH, CELL_SIZE * BOARD_HEIGHT), "Tetris");
	window.setFramerateLimit(60);
	
	sf::Texture main_menu;
	sf::Texture select_ui;
	sf::Texture how_to_play;
	sf::Texture background;
	sf::Texture l_block;
	sf::Texture square_block;
	sf::Texture straight4_block;
	sf::Texture t_block;
	sf::Texture z_block;
	sf::Texture mirror_z_block;
	sf::Texture mirror_l_block;
	sf::Texture blue_block;
	sf::Texture dark_blue_block;
	sf::Texture orange_block;
	sf::Texture yellow_block;
	sf::Texture green_block;
	sf::Texture purple_block;
	sf::Texture red_block;

	main_menu.loadFromFile("c:\\tetirs_sprites\\main_menu.png");
	select_ui.loadFromFile("c:\\tetirs_sprites\\select_ui.png");
	how_to_play.loadFromFile("c:\\tetirs_sprites\\how_to_play.png");
	background.loadFromFile("c:\\tetirs_sprites\\background.png");
	l_block.loadFromFile("c:\\tetirs_sprites\\l_block.png");
	mirror_l_block.loadFromFile("c:\\tetirs_sprites\\mirror_l_block.png");
	square_block.loadFromFile("c:\\tetirs_sprites\\square_block.png");
	straight4_block.loadFromFile("c:\\tetirs_sprites\\straight4_block.png");
	t_block.loadFromFile("c:\\tetirs_sprites\\t_block.png");
	z_block.loadFromFile("c:\\tetirs_sprites\\z_block.png");
	mirror_z_block.loadFromFile("c:\\tetirs_sprites\\mirror_z_block.png");
	blue_block.loadFromFile("c:\\tetirs_sprites\\tetris_blue.png");
	dark_blue_block.loadFromFile("c:\\tetirs_sprites\\tetris_dark_blue.png");
	orange_block.loadFromFile("c:\\tetirs_sprites\\tetris_orange.png");
	yellow_block.loadFromFile("c:\\tetirs_sprites\\tetris_yellow.png");
	green_block.loadFromFile("c:\\tetirs_sprites\\tetris_green.png");
	purple_block.loadFromFile("c:\\tetirs_sprites\\tetris_purple.png");
	red_block.loadFromFile("c:\\tetirs_sprites\\tetris_red.png");

	sf::Sprite sprite_main_menu;
	sf::Sprite sprite_select_ui;
	sf::Sprite sprite_how_to_play;
	sf::Sprite sprite_background;
	sf::Sprite sprite_blue_block1;
	sf::Sprite sprite_blue_block2;
	sf::Sprite sprite_blue_block3;
	sf::Sprite sprite_blue_block4;
	sf::Sprite sprite_dark_blue_block1;
	sf::Sprite sprite_dark_blue_block2;
	sf::Sprite sprite_dark_blue_block3;
	sf::Sprite sprite_dark_blue_block4;
	sf::Sprite sprite_orange_block1;
	sf::Sprite sprite_orange_block2;
	sf::Sprite sprite_orange_block3;
	sf::Sprite sprite_orange_block4;
	sf::Sprite sprite_yellow_block1;
	sf::Sprite sprite_yellow_block2;
	sf::Sprite sprite_yellow_block3;
	sf::Sprite sprite_yellow_block4;
	sf::Sprite sprite_green_block1;
	sf::Sprite sprite_green_block2;
	sf::Sprite sprite_green_block3;
	sf::Sprite sprite_green_block4;
	sf::Sprite sprite_purple_block1;
	sf::Sprite sprite_purple_block2;
	sf::Sprite sprite_purple_block3;
	sf::Sprite sprite_purple_block4;
	sf::Sprite sprite_red_block1;
	sf::Sprite sprite_red_block2;
	sf::Sprite sprite_red_block3;
	sf::Sprite sprite_red_block4;

	sprite_main_menu.setTexture(main_menu);
	sprite_main_menu.setPosition(main_menu_position, main_manu_positon);
	sprite_select_ui.setTexture(select_ui);
	sprite_select_ui.setPosition(0, 0);
	sprite_how_to_play.setTexture(how_to_play);
	sprite_how_to_play.setPosition(0, 0);
	sprite_background.setTexture(background);
	sprite_background.setPosition(0, 0);
	sprite_blue_block1.setTexture(blue_block);
	sprite_blue_block1.setPosition(0, 0);
	sprite_blue_block2.setTexture(blue_block);
	sprite_blue_block2.setPosition(0, 0);
	sprite_blue_block3.setTexture(blue_block);
	sprite_blue_block3.setPosition(0, 0);
	sprite_blue_block4.setTexture(blue_block);
	sprite_blue_block4.setPosition(0, 0);
	sprite_dark_blue_block1.setTexture(dark_blue_block);
	sprite_dark_blue_block1.setPosition(0, 0);
	sprite_dark_blue_block2.setTexture(dark_blue_block);
	sprite_dark_blue_block2.setPosition(0, 0);
	sprite_dark_blue_block3.setTexture(dark_blue_block);
	sprite_dark_blue_block3.setPosition(0, 0);
	sprite_dark_blue_block4.setTexture(dark_blue_block);
	sprite_dark_blue_block4.setPosition(0, 0);
	sprite_orange_block1.setTexture(orange_block);
	sprite_orange_block1.setPosition(0, 0);
	sprite_orange_block2.setTexture(orange_block);
	sprite_orange_block2.setPosition(0, 0);
	sprite_orange_block3.setTexture(orange_block);
	sprite_orange_block3.setPosition(0, 0);
	sprite_orange_block4.setTexture(orange_block);
	sprite_orange_block4.setPosition(0, 0);
	sprite_yellow_block1.setTexture(yellow_block);
	sprite_yellow_block1.setPosition(0, 0);
	sprite_yellow_block2.setTexture(yellow_block);
	sprite_yellow_block2.setPosition(0, 0);
	sprite_yellow_block3.setTexture(yellow_block);
	sprite_yellow_block3.setPosition(0, 0);
	sprite_yellow_block4.setTexture(yellow_block);
	sprite_yellow_block4.setPosition(0, 0);
	sprite_green_block1.setTexture(green_block);
	sprite_green_block1.setPosition(0, 0);
	sprite_green_block2.setTexture(green_block);
	sprite_green_block2.setPosition(0, 0);
	sprite_green_block3.setTexture(green_block);
	sprite_green_block3.setPosition(0, 0);
	sprite_green_block4.setTexture(green_block);
	sprite_green_block4.setPosition(0, 0);
	sprite_purple_block1.setTexture(purple_block);
	sprite_purple_block1.setPosition(0, 0);
	sprite_purple_block2.setTexture(purple_block);
	sprite_purple_block2.setPosition(0, 0);
	sprite_purple_block3.setTexture(purple_block);
	sprite_purple_block3.setPosition(0, 0);
	sprite_purple_block4.setTexture(purple_block);
	sprite_purple_block4.setPosition(0, 0);
	sprite_red_block1.setTexture(red_block);
	sprite_red_block1.setPosition(0, 0);
	sprite_red_block2.setTexture(red_block);
	sprite_red_block2.setPosition(0, 0);
	sprite_red_block3.setTexture(red_block);
	sprite_red_block3.setPosition(0, 0);
	sprite_red_block4.setTexture(red_block);
	sprite_red_block4.setPosition(0, 0);


	//playing board array
	const int playing_board[10][12] = { 0 };

	/*
	array of shapes
	const int L_BLOCK_CELLS[4][2] = {{0, 0}, {0, -1}, {0, 1}, {1, 1}};
	const int REVERSE_L_BLOCK_CELLS[4][2] = { {0, 0}, {0, -1}, {0, 1}, {1, -1} };
	const int Z_BLOCK_CELLS[4][2] = { {0, 0}, {0, -1}, {1, 0}, {1, 1} };
	const int REVERSE_Z_BLOCK_CELLS[4][2] = { {0, 0}, {0, 1}, {1, 0}, {1, -1} };
	const int SQUARE_BLOCK_CELLS[4][2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };
	const int T_BLOCK_CELLS[4][2] = { {0, 0}, {0, -1}, {0, 1}, {1, 0} };
	const int STRAIGHT_BLOCK_CELLS[4][2] = { {0, 0}, {1, 0}, {-1, 0}, {-2, 0} };
	*/

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

					if (event.type == event.KeyPressed)

					{
						if (event.key.code == sf::Keyboard::Key::Left)
						{
							
						}

						else if (event.key.code == sf::Keyboard::Key::Right)
						{
							
						}

						else if (event.key.code == sf::Keyboard::Key::Up)

						{
							
						}

						else if (event.key.code == sf::Keyboard::Key::Down)

						{

						}
				}
	}

}