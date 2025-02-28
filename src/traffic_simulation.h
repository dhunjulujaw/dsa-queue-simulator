#ifndef TRAFFIC_SIMULATION_H
#define TRAFFIC_SIMULATION_H

#include <SDL.h>
#include <stdbool.h>

// Constants for window and lane sizes
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define LANE_WIDTH 80
#define MAX_VEHICLES 100
#define INTERSECTION_X (WINDOW_WIDTH / 2)
#define INTERSECTION_Y (WINDOW_HEIGHT / 2)

// Enums for directions, turns, vehicle states, and light states
typedef enum {
    DIRECTION_NORTH,
    DIRECTION_SOUTH,
    DIRECTION_EAST,
    DIRECTION_WEST
} Direction;

typedef enum {
    TURN_NONE,
    TURN_LEFT,
    TURN_RIGHT
} TurnDirection;

typedef enum {
    STATE_MOVING,
    STATE_STOPPING,
    STATE_STOPPED,
    STATE_TURNING
} VehicleState;

typedef enum {
    REGULAR_CAR,
    AMBULANCE,
    POLICE_CAR,
    FIRE_TRUCK
} VehicleType;

typedef enum {
    RED,
    GREEN
} TrafficLightState;

// Vehicle structure
typedef struct {
    SDL_Rect rect;
    VehicleType type;
    Direction direction;
    TurnDirection turnDirection;
    VehicleState state;
    float speed;
    float x;
    float y;
    bool active;
    float turnAngle;
    bool isInRightLane;
    bool turnProgress;
} Vehicle;

// Traffic light structure
typedef struct {
    TrafficLightState state;
    int timer;
    SDL_Rect position;
    Direction direction;
} TrafficLight;

// Statistics structure
typedef struct {
    int vehiclesPassed;
    int totalVehicles;
    float vehiclesPerMinute;
    Uint32 startTime;
} Statistics;

// Queue data structure (for vehicles waiting in lanes)
typedef struct Node {
    Vehicle vehicle;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function declarations
void initializeTrafficLights(TrafficLight* lights);
void updateTrafficLights(TrafficLight* lights);
Vehicle* createVehicle(Direction direction);
void updateVehicle(Vehicle* vehicle, TrafficLight* lights);
void renderSimulation(SDL_Renderer* renderer, Vehicle* vehicles, TrafficLight* lights, Statistics* stats);
void renderRoads(SDL_Renderer* renderer);
void renderQueues(SDL_Renderer* renderer);

// Queue functions
void initQueue(Queue* q);
void enqueue(Queue* q, Vehicle vehicle);
Vehicle dequeue(Queue* q);
int isQueueEmpty(Queue* q);

#endif
