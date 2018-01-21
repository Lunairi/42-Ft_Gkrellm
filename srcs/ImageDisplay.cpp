/* ************************************************************************** */
/*                                                                            */
/*    ImageDisplay.cpp       _             _              :::      ::::::::   */
/*    By: mlu               | |           | |           :+:      :+:    :+:   */
/*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
/*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +/+  +:+       +/+        */
/*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +/+/+/+/+/+   +/+           */
/*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        /+/    /+/             */
/*          __/ | __/ | |                             ///   ////////.fr       */
/*         |___/ |___/|_|                                                     */
/* ************************************************************************** */

#include <Gkrellm.hpp>

void	image_display(std::vector<std::string> flags)
{
	std::vector<IMonitorModule*> 	modules;
	GraphicDisplay test(modules);

	sf::RenderWindow	window(sf::VideoMode(800, 600), "Kill me please");

	while(window.isOpen())
	{
		
	}
	(void)flags;

}