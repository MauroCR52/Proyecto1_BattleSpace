#include "iostream"
#include "Facil.h"

void Facil::initWindow() {
    this->window = new RenderWindow(VideoMode(800, 600), "Facil - Battlespace", Style::Titlebar | Style::Close);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

Facil::Facil() {
    this->initWindow();
    this->initTextures();
    this->initPlayer();

}

Facil::~Facil() {
    delete this->window;
    delete this->player;

    for (auto &i : this->textures){
        delete i.second;
    }

    for (auto *i : this->bullets){
        delete i;
    }

}

void Facil::run() {
    while (this->window->isOpen()){
        this->update();
        this->render();
    }
}

void Facil::updatePollEvents(){
    Event e;
    while (this->window->pollEvent(e)) {
        if(e.Event::type == Event::Closed)
            this->window->close();
        if (e.Event::key.code == Keyboard::Escape)
            this->window->close();
    }

}

void Facil::updateInput(){
    // Mover el jugador
    if(Keyboard::isKeyPressed(Keyboard::Up))
        this->player->move(-1.f);
    if(Keyboard::isKeyPressed(Keyboard::Down))
        this->player->move(1.f);
    if (this->window->isOpen() && this->player->canAttack()){
        this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPost().x, this->player->getPost().y, 1.f, 0.f,5.f));
    }
}

void Facil::update() {

    this->updatePollEvents();
    this->updateInput();
    this->player->update();
    this->updateBullets();

}

void Facil::render() {
    this->window->clear(Color(137, 155, 176, 255));
    //Enseña las varas
    this->player->render(*this->window);

    for (auto *bullet : this->bullets){

        bullet->render(this->window);

    }

    this->window->display();

}

void Facil::initPlayer() {
    this->player = new Player();
}

void Facil::initTextures() {

    this->textures["BULLET"] = new Texture();
    this->textures["BULLET"]->loadFromFile("/home/mauluna52/CLionProjects/Proyecto1_BattleSpace/Textures/firebullet.png");

}

void Facil::updateBullets() {
    unsigned  counter = 0;
    for (auto *bullet : this->bullets){
        bullet->update();

        //Bullet culling right screen
        if (bullet->getBounds().left + bullet->getBounds().width > 800.f)
        {
            delete this->bullets.at(counter);
            this->bullets.erase(this->bullets.begin() + counter);
            --counter;
            cout << this->bullets.size() << endl;
        }
        ++counter;
    }

}

