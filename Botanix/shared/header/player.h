#pragma once
#include "SFML\System.hpp"
#include "debug.h"

class Player
{
    const float RADIUS = 20.0f; // Player radius
    const int FINAL_SCORE = 10; // Score needed to win the game
    const float SPEED = 300.0f; // Pixels per second, used as a reference to calculate velocity

    int score = 0; // Player score, starting score is 0
    bool gameover = false; // Did the player reach endgame score

    sf::Vector2f pos; // Position
    sf::Vector2f v; // Velocity

    sf::Vector2f controls; // Current player controls status

public:
    // Update player position
    void update(float dt);

    // Get maximum player speed
    float get_maxspeed();

    // Get player position
    sf::Vector2f get_pos();

    // Set new player position
    void set_pos(sf::Vector2f new_pos);

    // Get player velocity
    sf::Vector2f get_vel();

    // Get player radius
    float get_rad();

    // Update player velocity to new value
    void set_vel(sf::Vector2f vel);

    // Increase player score
    void increase_score();

    // Did the player reach the score needed to win
    bool IfGameOver();

    // Get player controls
    sf::Vector2f get_controls();

    // Set player controls
    void set_controls(sf::Vector2f controls);
};