/* ************************************************************************** */
/*                                                                            */
/*    GraphicDisplay.cpp     _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */


#include <Gkrellm.hpp>

GraphicDisplay::GraphicDisplay(std::vector<IMonitorModule*> const modules, sf::RenderWindow	&window) :
		IMonitorDisplay(), _modules(modules), _window(window), _size(70)
{
	this->_arial.loadFromFile("./fonts/arial.ttf");
	this->_trebuchet.loadFromFile("./fonts/trebuc.ttf");
	this->_courier.loadFromFile("./fonts/cour.ttf");

	this->_grey.r = 64; this->_grey.g = 64; this->_grey.b = 64;
	this->_lightgrey.r = 64; this->_lightgrey.g = 64; this->_lightgrey.b = 64;
	this->_slateblue.g = 51; this->_slateblue.b = 102;
	this->_azure.r = 51; this->_azure.g = 153; this->_azure.b = 255;
	this->_lightblue.r = 153; this->_lightblue.g = 204; this->_lightblue.b = 255;

	return ;
}

GraphicDisplay::~GraphicDisplay()
{
	_window.close();
	return ;
}

void					GraphicDisplay::fillSpace(char *str)
{
	(void)str;
	// while (this->_size < this->_col)
	// {
	// 	mvprintw(this->_x, this->_size, str);
	// 	this->_size = this->_size + 1;
	// }
	// this->_x = this->_x + 1;
	// this->_size = -1;
}

void					GraphicDisplay::renderOutput(void)
{
	this->_window.clear(sf::Color::Black);

	sf::RectangleShape r1(sf::Vector2f(600, 70));
	sf::RectangleShape r2(sf::Vector2f(600, 250));
	r2.setFillColor(_azure);
	r1.setPosition(0, 0);
	r2.setPosition(0, 70);

	sf::FloatRect tr;

	sf::Text t1;
	r1.setFillColor(sf::Color::Black);
	t1.setString(" Ft_Gkrellm ");
	tr = t1.getLocalBounds();
	t1.setPosition(125, 0);
	t1.setCharacterSize(50);
	t1.setFont(this->_courier);
	t1.setStyle(sf::Text::Bold);
	t1.setFillColor(sf::Color::White);
	this->_window.draw(r1);
	this->_window.draw(t1);

	size_t i = 0;
	size_t x = 0;
	
	r1.setFillColor(this->_grey);
	t1.setFillColor(this->_lightblue);
	r2.setFillColor(this->_slateblue);
	t1.setFont(this->_courier);
	while (i < this->_modules.size())
	{
		r1.setPosition(0, this->_size);
		t1.setString(this->_modules.at(i)->getName().c_str());
		tr = t1.getLocalBounds();
		t1.setOrigin(tr.left + tr.width/2.0f, 0);
		t1.setPosition(300, this->_size);
		this->_window.draw(r1);
		this->_window.draw(t1);
		this->_size = this->_size + 70;

		r2.setPosition(0, this->_size);
		this->_window.draw(r2);
		t1.setCharacterSize(40);
		while (x < (this->_modules.at(i)->getOutput().size()))
		{
			t1.setString(this->_modules.at(i)->getOutput().at(x).c_str());
			tr = t1.getLocalBounds();
			t1.setOrigin(tr.left + tr.width/2.0f, 0);
			t1.setPosition(300, this->_size + (x * 50));
			this->_window.draw(t1);
			x++;
		}
		t1.setCharacterSize(50);
		this->_size = this->_size + 250;
		x = 0;
		i++;
	}
	this->_window.display();

	return ;
}

void					GraphicDisplay::refreshOutput(void)
{
	size_t i = 0;

	this->_size = 70;
	while (i < (this->_modules.size()))
	{
		this->_modules.at(i)->tick();
		i++;
	}
	renderOutput();
	return ;
}
