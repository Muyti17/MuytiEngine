# MUYTI Engine Architecture

## Design Principles

MUYTI Engine follows these principles:

- Performance First
- Modular Architecture
- No Hidden Magic
- Readable Code
- Platform Independence
- Extensibility

MUYTI Engine is built around independent modules.
Each module has a single responsibility and communicates with other modules through well-defined interfaces.

---

## Core

Responsible for the engine foundation.

- Application
- Memory
- Logger
- Event System
- Time
- Threading

---

## Platform

Platform abstraction layer.

Supported platforms:

- Windows
- Linux
- macOS

---

## Renderer

Rendering abstraction layer.

- RHI
- Vulkan
- DirectX 12
- Render Graph

---

## Scene

Responsible for scene management.

- Scene Manager
- Entity Management

---

## ECS

Entity Component System.

- Entity
- Component
- System

---

## Physics

Physics simulation.

- Collision
- Rigid Body
- Character Controller

---

## Audio

Audio subsystem.

- Audio Device
- Audio Mixer

---

## GUI

Custom graphical user interface.

- MuytiGUI

---

## Script

Gameplay scripting.

- C#
- MuytiScript