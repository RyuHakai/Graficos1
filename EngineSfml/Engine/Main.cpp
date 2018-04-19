#include <SFML\Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;
int main() {

	RenderWindow window(VideoMode(512, 512), "Ventana", Style::Close | Style::Resize);
	RectangleShape player(Vector2f(32.0f, 32.0f));

	player.setPosition(206.0f, 206.0f);

	Texture playerTexture;
	playerTexture.loadFromFile("sprites.png");
	player.setTexture(&playerTexture);

	Vector2u textureSize = playerTexture.getSize();
	textureSize.x /= 12;
	textureSize.y /= 8;

	player.setTextureRect(IntRect(textureSize.x * 6, textureSize.y * 0, textureSize.x, textureSize.y));

	while (window.isOpen())
	{
		Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type) {

			case Event::Closed:
				window.close();
				cout << "La venta fue cerrada" << endl;
				break;
			case Event::Resized:
				cout << "New window width: " << evnt.size.width << " New Window heigth: " << evnt.size.height << endl;
				break;
			}
			if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
			player.move(-0.05f, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
			player.move(0.05f, 0.0f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
			player.move(0.0f, -0.05f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
			player.move(0.0f, 0.05f);
		}


		window.clear();
		window.draw(player);
		window.display();
	}

	return 0;
}