# 2D Game with C++ and Raylib and ENTT

This project is being used to learn C++ features in combination with the Raylib game programming library and the EnTT Entity-Component-System (ECS) framework.

# Dependencies

- [Raylib](https://www.raylib.com/): A simple and easy-to-use library to learn and enjoy video games programming. Raylib is highly inspired by Borland BGI graphics lib and by XNA framework. The library provides a simple and intuitive interface towards a set of powerful tools, allowing for the development of both complex and simple games and applications.

- [EnTT](https://github.com/skypjack/entt): A fast and reliable Entity-Component-System (ECS) and much more. This is a header-only library, written in modern C++, to help you quickly develop games and applications. EnTT is easy to integrate with existing code and provides a lot of features (from meta programming to event handling) to speed up development and to keep your code maintainable.

# Project structure

```
- src
  - components
  - core      
  - systems     
  - main.cpp 
```

- `src` - The project root where the source code lives.
- `src/components` - Contains the Component definitions. In an ECS paradigm, a Component is a data structure that holds the attributes of entities. It does not contain any behavior. For example, a Position component might contain "x" and "y" attributes.
- `src/core` - Core is where essential game functions and structures are defined. This could include the game loop, initialization and shutdown routines, and any utility or helper functions that aren't part of a game entity's behavior.
- `src/systems` - Contains the System implementations. Systems in ECS are where the behavior logic lives. They operate on Components, reading and writing their data. For example, a Movement system might use the data in the Position and Velocity components to update an entity's position over time.
- `main.cpp` - Main application entry point.