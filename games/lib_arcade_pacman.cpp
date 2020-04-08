/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019 [WSL: Ubuntu]
** File description:
** lib_arcade_nibbler
*/
#include <iostream>
#include <unistd.h>
#include <time.h>
#include "../src/Core.hpp"

class Snake_part
{
    public:
        Snake_part(int x, int y) {pos_x = x, pos_y = y, next = NULL;}
        ~Snake_part() {};

        int pos_x;
        int pos_y;
        Snake_part *next;
};

class Snake
{
    public:
        Snake();
        ~Snake() {empty();};

        void add_head(int x, int y);
        void remove_head();
        void empty(void);
        void move(input face);
        Snake operator=(const Snake&source);
        Snake_part *head;
        Snake_part *tail;
        int nb_part = 0;
};

Snake::Snake()
{
    head = tail = NULL;
    add_head(15, 10);
    add_head(16, 10);
    add_head(17, 10);
    add_head(18, 10);
}

void Snake::add_head(int x, int y)
{
    Snake_part * new_part = new Snake_part(x, y);
    if (new_part == NULL)
        return;
    new_part->next = head;
    head = new_part;
    if (nb_part == 0)
        tail = new_part;
    ++nb_part;
}

void Snake::remove_head()
{
    Snake_part *deleted_part = head;
    head = head->next;
    delete deleted_part;
    --nb_part;
    if (nb_part == 0)
        tail = NULL;
}

void Snake::empty(void)
{
    while (nb_part > 0)
        remove_head();
}

int move_pos_x(int x, input face)
{
    if (face == right)
        return (x + 1);
    if (face == left)
        return (x - 1);
    return x;
}

int move_pos_y(int y, input face)
{
    if (face == down)
        return (y + 1);
    if (face == up)
        return (y - 1);
    return y;
}

void Snake::move(input face)
{
    int last_pos_x;
    int last_pos_y;
    int tmp_last_pos_x;
    int tmp_last_pos_y;
    Snake_part *tmp = head->next;

    last_pos_x = head->pos_x;
    last_pos_y = head->pos_y;
    head->pos_x = move_pos_x(head->pos_x, face);
    head->pos_y = move_pos_y(head->pos_y, face);
    
    for (; tmp != NULL ; tmp = tmp->next) {
        tmp_last_pos_x = tmp->pos_x;
        tmp_last_pos_y = tmp->pos_y;
        tmp->pos_x = last_pos_x;
        tmp->pos_y = last_pos_y;
        last_pos_x = tmp_last_pos_x; 
        last_pos_y = tmp_last_pos_y; 
    }
}

class Nibbler : public IGame
{
    public:
        Nibbler();
        ~Nibbler();

        void init();
        input game_loop(Core &core);
        input move(input move);
        void snake_on_map();
        bool is_blocked();
        bool is_eaten();

        int score = 0;
        int apple_pos_x;
        int apple_pos_y;
        input snake_facing = right;
        state game_state = MENU;
        Snake *_snake = NULL;
        int basic_map[20][40];
        int game_map[20][40];
};

Nibbler::Nibbler()
{
    for (int y = 0; y != 20; y++)
        for (int x = 0; x != 40; x++)
            if (y == 0 || y == 19 || x == 0 || x == 39)
                basic_map[y][x] = 1;
            else
                basic_map[y][x] = 0;
}

Nibbler::~Nibbler()
{
    delete _snake;
}

void Nibbler::snake_on_map()
{
    for (int y = 0; y != 20; y++)
        for (int x = 0; x != 40; x++)
            game_map[y][x] = basic_map[y][x];
    game_map[_snake->head->pos_y][_snake->head->pos_x] = 3;
    Snake_part *tmp = _snake->head->next;
    for (; tmp != NULL ; tmp = tmp->next)
        game_map[tmp->pos_y][tmp->pos_x] = 4;
    game_map[apple_pos_y][apple_pos_x] = 2;
}

void Nibbler::init()
{
    if (_snake != NULL)
        delete _snake;
    _snake = new Snake();
    snake_facing = right;
    snake_on_map();
    apple_pos_x = 30;
    apple_pos_y = 10;
    score = 0;
}

input Nibbler::game_loop(Core &core)
{
    input in = undefinied;
    clock_t timer;

    srand(time(NULL));
    timer = clock();
    init();
    core.player_name = "";
    while (1) {
        switch (game_state) {
        case GAME:
            in = core.graph->get_input(in);
            if (in == make_pause)
                game_state = PAUSE;
            if ((clock() - timer) > 150000) {
                in = move(in);
                core.graph->display(game_map);
                core.graph->display_score(score);
                timer = clock();
            }
            break;

        case MENU:
            in = core.graph->menu(core);
            break;

        case PAUSE:
            in = core.graph->pause();
            if (in == restart)
                game_state = GAME;
            if (in == back_to_menu) {
                in = restart;
                game_state = MENU;
            }
            break;

        case GAME_OVER:
            core.player_name = core.graph->game_over_screen();
            if (core.player_name.compare("")) {
                game_state = MENU;
                in = restart;
                core.save_score(score);
            }
            break;
        }
        if (in == play) {
            game_state = GAME;
            in = undefinied;
        }
        if (in == next_lib) {
            core.next_graph();
            in = undefinied;
        }
        if (in == prev_lib) {
            core.prev_graph();
            in = undefinied;
        }
        if (in == game_over) {
            game_state = GAME_OVER;
        }
        if (in == restart) {
            return in;
        }
        if (in == next_game || in == prev_game || in == make_end)
            return in;
    }
}

bool Nibbler::is_eaten()
{
    if ((_snake->head->pos_x == apple_pos_x) && (_snake->head->pos_y == apple_pos_y)) {
        while (1) {
            apple_pos_x = (rand() % 38) + 1;
            apple_pos_y = (rand() % 18) + 1;
            if (game_map[apple_pos_x][apple_pos_y] == 0) {
                break;
            }
        }
        score += 100;
        return (true);
    }
    return (false);
}

bool Nibbler::is_blocked()
{
    if (_snake->head->pos_x == 0 || _snake->head->pos_y == 0 ||
    _snake->head->pos_x == 39 || _snake->head->pos_y == 19)
        return (true);
    Snake_part *tmp = _snake->head->next;
    for (; tmp != NULL ; tmp = tmp->next)
        if ((_snake->head->pos_x == tmp->pos_x) && (_snake->head->pos_y == tmp->pos_y))
            return (true);
    return (false);
}

input Nibbler::move(input move)
{
    switch (move) {
    case up:
        if (snake_facing != down)
            snake_facing = up;
        break;
    case down:
        if (snake_facing != up)
            snake_facing = down;
        break;
    case left:
        if (snake_facing != right)
            snake_facing = left;
        break;
    case right:
        if (snake_facing != left)
            snake_facing = right;
        break;
    }
    if (is_eaten())
        _snake->add_head(move_pos_x(_snake->head->pos_x, snake_facing),
        move_pos_y(_snake->head->pos_y, snake_facing));
    else
        _snake->move(snake_facing);
    snake_on_map();
    if (is_blocked())
        return (game_over);
    return (move);
}

extern "C" IGame *create() {
    Nibbler *game = new Nibbler();
    return game;
}