# minitalk-42

`minitalk` involves creating a simple inter-process communication system using UNIX signals. The goal is to implement a client-server architecture where a client can send messages to a server, which processes and acknowledges them.

## Features

Key components of the project include:

- `Signal Handling`: Using UNIX signals to communicate between processes.
- `Client and Server`: Developing both a client that sends messages and a server that receives them.
- `Acknowledgment Mechanism`: The server sends back an acknowledgment to the client upon receiving a message.
- `Multiple Clients`: The server can handle multiple clients simultaneously.

## Installation

To use `minitalk`, simply clone the repository and compile it:

   ```bash
   git clone https://github.com/your-username/minitalk-42.git
   make
   ```


## Usage

Start a server in a terminal:
   ```bash
   ./server
   ```

Then in an **other terminal**, start the client and send a message:
   ```bash
   ./client <server_pid> "Your message here"
   ```
  Replace `server_pid` with the PID of the running server.

