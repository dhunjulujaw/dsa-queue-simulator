# traffic-lights
Traffic Light 

![image](https://github.com/dhunjulujaw/dsa-queue-simulator/blob/hello-world/LujawDSA.gif)
🚦 Four-Way Junction Traffic Queue Simulator
📋 Project Overview

This project is designed to simulate vehicle movement at a four-way intersection, where traffic flow is regulated using a traffic light system. The simulation is built upon the queue data structure, ensuring an organized and realistic representation of vehicles moving through the intersection.

Each lane at the junction is represented as a queue, where vehicles arrive and wait for their turn to pass based on the traffic signals. The simulation provides a visual representation of traffic movement using the SDL2 (Simple DirectMedia Layer) library, enabling real-time graphical output.
✨ Key Features

1️⃣ Vehicle Queue Management

    Each lane at the intersection is treated as a queue where vehicles enter and wait for the green light.
    Vehicles are dequeued (released) periodically, mimicking real-world traffic behavior.

2️⃣ Priority-Based Traffic Flow

    A special priority lane is implemented in the system.
    If 10 vehicles accumulate in this priority lane, it is granted immediate passage, ensuring smooth traffic flow in high-density areas.

3️⃣ Real-Time Graphical Visualization

    The traffic simulation is displayed visually using SDL2, allowing users to observe vehicle movements dynamically.
    Vehicles are animated to enter, wait, and exit the intersection according to the implemented traffic rules.

🛠️ Prerequisites

Before running the simulation, ensure you have the following installed on your system:

    G++ or GCC compiler (for compiling the C/C++ source code)
    SDL2 Library (for graphical rendering)

🚀 How to Run the Simulation
🔹 On Windows

    Clone the Repository
    Open a terminal or command prompt and enter the following command to clone the project from GitHub:

git clone https://github.com/dhunjulujaw/dsa-queue-simulator.git
cd dsa-queue-simulator

Compile the Program
Use g++ to compile the source code while linking necessary SDL2 libraries:

g++ -o bin/generator src/generator.c src/traffic_simulation.c -lSDL2 -Iinclude -Llib -lmingw32 -lSDL2main -lSDL2

	g++ -Iinclude -Llib -o bin/main.exe src/main.c src/traffic_simulation.c -lmingw32 -lSDL2main -lSDL2

Run the Simulation
Once compiled, execute the program with the following command:

    ./bin/main.exe

📚 References

For additional resources on queue data structures, traffic simulations, or SDL2 development, refer to:

    Queue Data Structure (GeeksforGeeks)
    SDL2 Documentation
    Traffic Flow Theory (ResearchGate)
