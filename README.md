# Asky - Console-Based Q&A Application

A C++ console application inspired by **Ask.fm**. It allows users to register, log in, ask and answer questions, manage questions, discover users, and interact through question threads. The project is designed using Object-Oriented Programming principles and suitable data structures to ensure maintainability, clean organization, and efficient data management.

---

## Features

* **User Management**
  Register, log in, and manage user sessions.

* **Question Management**
  Ask, receive, answer, and delete questions.

* **Question Threads**
  Organize related questions using thread IDs.

* **User Discovery**
  Browse registered users.

* **Feed**
  View questions and interactions through a simple feed.

* **Menu System**
  Console-based navigation with layered menus.

---

## Design Highlights

This project was built with a focus on clean and maintainable code. Key design principles and technical choices include:

* **Object-Oriented Programming (OOP)**
  Concepts used:

    * Encapsulation
    * Abstraction

  These principles provide a modular and organized design.

* **Single Responsibility Principle (SRP)**
  Each class or component has a specific responsibility, reducing complexity and improving maintainability.

* **Menu-Driven Architecture**
  A layered menu system provides clear navigation between the application's functionalities.

* **Efficient Data Structures**
  STL containers are selected according to the required operations:

    * `std::vector` for storing collections of users.
    * `std::map` for key-based access to questions and user data.
    * `std::set` for maintaining unique relationships.
    * `std::unordered_map` for fast key-based lookup.

---

## Technologies Used

* **Language**: C++
* **Interface**: Console-based UI
* **Paradigm**: Object-Oriented Programming
* **Standard Library**: C++ STL

---

## Future Improvements

Planned enhancements to extend the application's capabilities include:

* **Database Integration** for persistent data storage and improved scalability
* **Graphical User Interface** to improve usability.
* **Additional Features** Such as Notification System for new questions and answers