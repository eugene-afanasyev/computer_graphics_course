#pragma once

#include <iostream>

//glew
#include <GL/glew.h>

//sfml
#include <SFML/Window.hpp>


#include "3rd/stb/stb_image.h"
#include "utils/shaderLoader.h"
#include "src/shader_wrapper.h"

static int e3() {
  sf::ContextSettings settings;
  settings.depthBits = 24; // êîëè÷åñòâî áèòîâ áóôôåðà ãëóáèíû
  settings.stencilBits = 8; //êîëè÷åñòâî áèòîâ áóôåðà òðàôàðåòà, èñïîëüçóåòñÿ ñ áóôåðîì ãëóáèíû äëÿ îãðàíè÷åíèÿ îáëàñòè ðåíäåðèíãà
  settings.majorVersion = 4;
  settings.minorVersion = 3;
  settings.attributeFlags = sf::ContextSettings::Core;

  //sf::VideoMode(øèðèíà, âûñîòà, êîë-âî áèäëÿ äëÿ öâåòà íà 1 ïèêñåëü)
  sf::Window window(sf::VideoMode(800, 600, 32), "First Window",
                    sf::Style::Titlebar | sf::Style::Close);

  glewExperimental = GL_TRUE; // âêëþ÷èòü âñå ñîâðåìåííûå ôóíêöèè ogl

  if (GLEW_OK != glewInit()) { // âêëþ÷èòü glew
    std::cout << "Error:: glew not init =(" << std::endl;
    return -1;
  }

//  auto shaderProgram = LoadShaders("/home/eugene/CLionProjects/computer-graphics-course/res/shaders/e2.vs",
//                                   "/home/eugene/CLionProjects/computer-graphics-course/res/shaders/e2.fs");


  float vertices [] = {
    //x      y     z      u     v
    -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, // ëåâàÿ íèæíÿÿ
    -0.5f, 0.5f, 0.0f,   0.0f, 1.0f,// ëåâàÿ âåðõíÿÿ
    0.5f, 0.5f, 0.0f,   1.0f, 1.0f,// ïðàâàÿ âåðõíÿÿ
    0.5f, -0.5f, 0.0f,  1.0f, 0.0f // ïðàâàÿ íèæíÿÿ
  };

  //EBO ïîçâîëèò èñïîëüçîâàòü îäíè è òå æå âåðøèíû â ðàçíûõ òðåóãîëüíèêàõ
  unsigned int indices [] = {
    0, 1, 3, // ïåðâûé òðåóãîëüíèê
    1, 2, 3  // âòîðîé òðåóãîëüíèê
  };

  unsigned int VBO, VAO, EBO;
  glGenVertexArrays(1, &VAO); // ñãåíåðèëè id äëÿ ìàññèâîâ âåðøèí (ó íàñ ýòî îäèí id)
  glBindVertexArray(VAO); // è ñâÿçàëè ìàññèâ ñ opengl

  glGenBuffers(1, &VBO); // ñãåíåðèëè áóôåð äàííûõ ðàçìåðîì 1
  glBindBuffer(GL_ARRAY_BUFFER, VBO);// è ñâÿçàëè áóôåð ñ opengl
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // ïðîêèíóëè íàø ìàñèâ âåðøèí â opengl

  //Ñîçäàëè è ñâÿçàëè EBO
  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0); // ïðîïèñàëè ïàðàìåòðû äëÿ îáúåêòà
  glEnableVertexAttribArray(0); //òê layout ó ïîçèöèè 0

  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);


  // Çàãðóçêà è ñîçäàíèå òåêñòóðû
  unsigned int texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture); // âñå ïîñëåäóþùèå GL_TEXTURE_2D-îïåðàöèè òåïåðü áóäóò âëèÿòü íà äàííûé òåêñòóðíûé îáúåêò

  // Óñòàíîâêà ïàðàìåòðîâ íàëîæåíèÿ òåêñòóðû
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // óñòàíîâêà ìåòîäà íàëîæåíèÿ òåêñòóðû GL_REPEAT (ñòàíäàðòíûé ìåòîä íàëîæåíèÿ)
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  // Óñòàíîâêà ïàðàìåòðîâ ôèëüòðàöèè òåêñòóðû
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  // Çàãðóçêà èçîáðàæåíèÿ, ñîçäàíèå òåêñòóðû è ãåíåðèðîâàíèå ìèïìàï-óðîâíåé
  int width, height, nrChannels;
  /*
   * Ïî äåôîëòó òåêñòóðà ïåðåâåðíóòà ââåðõ íîãàìè.
   * Ýòî ïðîèñõîäèò ïîòîìó, ÷òî OpenGL îæèäàåò, ÷òî êîîðäèíàòà 0.0 íà îñè Y áóäåò
   * íàõîäèòüñÿ â íèæíåé ÷àñòè èçîáðàæåíèÿ, íî èçîáðàæåíèÿ îáû÷íî èìåþò 0.0 â âåðõíåé
   * ÷àñòè îñè Y. stbi_set_flip_vertically_on_load èñïðàâèò ýòî!
   */
  stbi_set_flip_vertically_on_load(true);

  unsigned char* data = stbi_load("/home/eugene/CLionProjects/computer-graphics-course/res/imgs/1.jpg", &width, &height, &nrChannels, 0);
  if (data) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else {
    std::cout << "Failed to load texture" << std::endl;
  }
  stbi_image_free(data);

  // öûêë ðåíäåðà
  bool isGo = true;

  ShaderWrapper sw("/home/eugene/CLionProjects/computer-graphics-course/res/shaders/e2.vs",
                   "/home/eugene/CLionProjects/computer-graphics-course/res/shaders/e2.fs");

  while (isGo) {

    // îáðàáîòêà èâåíòîâ îò SFML (òóò è ìûøü è êëàâèøè îáðàáàòûâàþòñÿ)
    sf::Event windowEvent;
    while (window.pollEvent(windowEvent)) { // îáðàáîòêà èâåíòîâ
      switch (windowEvent.type) {
        case sf::Event::Closed:
          isGo = false;
          break;
        default:
          break;
      }
    }

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //çàäàëè öâåò îò÷èñòêè
    glClear(GL_COLOR_BUFFER_BIT);                      //îò÷èñòêà ýêðàíà

    glBindTexture(GL_TEXTURE_2D, texture); //ñâÿçàëè òåêñòóðó

//    glUseProgram(shaderProgram); // óñòàíîâèëè íóæíóþ øåéäåðíóþ ïðîãðàììó
    sw.Use();
    glBindVertexArray(VAO);      // óñòàíîâèëè íóæíûé ìàññèâ äëÿ ðåíäåðèíãà
    //glDrawArrays(GL_TRIANGLES, 0, 6); //îòðèñîâàëè

    //äëÿ îòðèñîâêè ñ EBO èïîëüçóåòñÿ glDrawElements
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    window.display();
  }


  window.close();
  return 0;
}