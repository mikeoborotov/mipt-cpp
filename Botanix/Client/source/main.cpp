#include <iostream>
#include <SFML\Graphics.hpp>

#include "client.h"
#include "controls.h"

// Client main function
int main()
{
    // Creating game world
    World world;

    // Creating client (args: ip, port, World)
    Client client("127.0.0.1", 1234, world);

    Viewer viewer("My client"); // Creating viewer
    sf::Clock gameClock; // Game clock

    sf::Vector2f prevControls; // Previous player controls vector

    // Main cycle
    while (client.isRunning() && viewer.isOpen())
    {
        viewer.handleEvents(); // Handling events

        sf::Vector2f currControls; // Current player controls vector

        if (client.id() == 0)
        {
            // WASD for player 0
            currControls = controls_wasd();
        }
        else
        {
            // Arrow controls for others
            currControls = controls_arrows();
        }

        // Changing player's velocity to new velocity
        world.get_players()[client.id()].set_controls(currControls);
        
        // Restarting clock and updating world
        const auto dt = gameClock.restart();
        world.update(dt.asSeconds());

        // On any change (speed direction or magnitude) notify server
        if (currControls != prevControls)
        {
            client.notify_mov();
            prevControls = currControls;
        }

        // Drawing world
        viewer.draw(world);
    }

    return 0;
}